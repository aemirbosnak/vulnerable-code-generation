//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to compare two files
int compare_files(const char *file1, const char *file2) {
    FILE *fp1, *fp2;
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    int cmp;

    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        return -1;
    }

    while ((cmp = fread(buffer1, 1, BUFFER_SIZE, fp1))!= 0 &&
           (cmp = fread(buffer2, 1, BUFFER_SIZE, fp2))!= 0 &&
           memcmp(buffer1, buffer2, cmp) == 0) {
        ;
    }

    if (cmp!= 0 || ferror(fp1) || ferror(fp2)) {
        fclose(fp1);
        fclose(fp2);
        return -1;
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}

// Function to synchronize files in two directories
void synchronize_directories(const char *dir1, const char *dir2) {
    DIR *dp1, *dp2;
    struct dirent *dirp1, *dirp2;

    dp1 = opendir(dir1);
    dp2 = opendir(dir2);

    if (dp1 == NULL || dp2 == NULL) {
        printf("Error: Could not open directory.\n");
        exit(1);
    }

    while ((dirp1 = readdir(dp1))!= NULL && (dirp2 = readdir(dp2))!= NULL) {
        if (strcmp(dirp1->d_name, ".") == 0 || strcmp(dirp1->d_name, "..") == 0) {
            continue;
        }

        if (strcmp(dirp2->d_name, ".") == 0 || strcmp(dirp2->d_name, "..") == 0) {
            continue;
        }

        char file1[256], file2[256];
        sprintf(file1, "%s/%s", dir1, dirp1->d_name);
        sprintf(file2, "%s/%s", dir2, dirp2->d_name);

        if (dirp1->d_type == DT_DIR && dirp2->d_type == DT_DIR) {
            synchronize_directories(file1, file2);
        } else if (dirp1->d_type == DT_REG && dirp2->d_type == DT_REG) {
            compare_files(file1, file2);
        }
    }

    closedir(dp1);
    closedir(dp2);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s directory1 directory2\n", argv[0]);
        exit(1);
    }

    synchronize_directories(argv[1], argv[2]);

    return 0;
}