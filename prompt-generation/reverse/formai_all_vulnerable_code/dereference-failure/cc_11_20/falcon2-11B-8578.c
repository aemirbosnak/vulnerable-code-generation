//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE (1 << 20) // 1MB

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s source_dir dest_dir\n", argv[0]);
        return 1;
    }

    char source_dir[256], dest_dir[256];
    strcpy(source_dir, argv[1]);
    strcpy(dest_dir, argv[2]);

    // Open source and destination directories
    struct stat sb;
    if (stat(source_dir, &sb) == 0 && stat(dest_dir, &sb) == 0) {
        if (sb.st_mode & S_IFDIR) {
            if (chdir(source_dir) == -1) {
                perror("chdir");
                return 1;
            }
        } else {
            if (stat(source_dir, &sb) == 0) {
                if (stat(dest_dir, &sb) == 0) {
                    if (sb.st_mode & S_IFDIR) {
                        if (chdir(dest_dir) == -1) {
                            perror("chdir");
                            return 1;
                        }
                    }
                }
            }
        }

        // Synchronize files
        for (char *dir = "."; dir!= NULL; dir = dir[0]) {
            for (char *f = "*"; f!= NULL; f = f[0]) {
                if (stat(dir, &sb) == 0 && S_ISDIR(sb.st_mode)) {
                    if (chdir(dir) == -1) {
                        perror("chdir");
                        return 1;
                    }
                }
                char buf[MAX_FILE_SIZE];
                int len = MAX_FILE_SIZE;
                FILE *fptr = fopen(f, "r");
                if (fptr!= NULL) {
                    while (len > 0 && fgets(buf, len, fptr)!= NULL) {
                        len -= strlen(buf);
                    }
                    fclose(fptr);
                }
                char dest[MAX_FILE_SIZE];
                snprintf(dest, MAX_FILE_SIZE, "%s/%s", dest_dir, f);
                FILE *wptr = fopen(dest, "w");
                if (wptr!= NULL) {
                    fprintf(wptr, "%s", buf);
                    fclose(wptr);
                }
            }
        }
    } else {
        perror("stat");
        return 1;
    }

    return 0;
}