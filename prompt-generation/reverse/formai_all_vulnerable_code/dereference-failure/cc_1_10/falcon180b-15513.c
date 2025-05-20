//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

// Function for comparing two files
int compare_files(const char *file1, const char *file2) {
    FILE *fp1, *fp2;
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    int cmp;

    fp1 = fopen(file1, "rb");
    fp2 = fopen(file2, "rb");

    if (fp1 == NULL || fp2 == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    while ((cmp = fread(buffer1, 1, BUFFER_SIZE, fp1)) > 0) {
        if (fread(buffer2, 1, BUFFER_SIZE, fp2)!= cmp) {
            fprintf(stderr, "Files are different\n");
            fclose(fp1);
            fclose(fp2);
            return 1;
        }

        if (memcmp(buffer1, buffer2, cmp)!= 0) {
            fprintf(stderr, "Files are different\n");
            fclose(fp1);
            fclose(fp2);
            return 1;
        }
    }

    if (cmp!= 0) {
        fprintf(stderr, "Files are different\n");
        fclose(fp1);
        fclose(fp2);
        return 1;
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}

// Function for synchronizing files in a directory
void sync_files(const char *dir1, const char *dir2) {
    DIR *dp1, *dp2;
    struct dirent *ep1, *ep2;
    char path1[1024], path2[1024];

    dp1 = opendir(dir1);
    dp2 = opendir(dir2);

    if (dp1 == NULL || dp2 == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", strerror(errno));
        exit(1);
    }

    while ((ep1 = readdir(dp1))!= NULL || (ep2 = readdir(dp2))!= NULL) {
        if (ep1!= NULL) {
            sprintf(path1, "%s/%s", dir1, ep1->d_name);
        } else {
            ep1 = readdir(dp1);
            continue;
        }

        if (ep2!= NULL) {
            sprintf(path2, "%s/%s", dir2, ep2->d_name);
        } else {
            ep2 = readdir(dp2);
            continue;
        }

        if (strcmp(path1, path2) == 0) {
            if (ep1->d_type == DT_DIR && ep2->d_type == DT_DIR) {
                sync_files(path1, path2);
            } else if (ep1->d_type == DT_REG && ep2->d_type == DT_REG) {
                compare_files(path1, path2);
            }
        }
    }

    closedir(dp1);
    closedir(dp2);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s source_dir target_dir\n", argv[0]);
        exit(1);
    }

    sync_files(argv[1], argv[2]);

    return 0;
}