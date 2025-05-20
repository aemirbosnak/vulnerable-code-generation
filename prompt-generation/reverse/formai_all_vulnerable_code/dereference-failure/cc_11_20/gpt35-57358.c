//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void recursive_sync(char *dir1, char *dir2);

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s directory1 directory2\n", argv[0]);
        exit(1);
    }

    char *dir1 = argv[1];
    char *dir2 = argv[2];

    recursive_sync(dir1, dir2);

    return 0;
}

void recursive_sync(char *dir1, char *dir2) {
    DIR *dp1, *dp2;
    struct dirent *dirp1, *dirp2;
    struct stat st1, st2;
    char file1[512], file2[512];

    if ((dp1 = opendir(dir1)) == NULL) {
        fprintf(stderr, "Cannot open directory: %s\n", dir1);
        return;
    }

    if ((dp2 = opendir(dir2)) == NULL) {
        fprintf(stderr, "Cannot open directory: %s\n", dir2);
        return;
    }

    while ((dirp1 = readdir(dp1)) != NULL) {
        if (strcmp(dirp1->d_name, ".") == 0 || strcmp(dirp1->d_name, "..") == 0) {
            continue;
        }

        snprintf(file1, sizeof(file1), "%s/%s", dir1, dirp1->d_name);
        snprintf(file2, sizeof(file2), "%s/%s", dir2, dirp1->d_name);

        if (stat(file1, &st1) == -1) {
            fprintf(stderr, "Cannot get file status: %s\n", file1);
            continue;
        }

        if (stat(file2, &st2) == -1) {
            fprintf(stderr, "Cannot get file status: %s\n", file2);
            continue;
        }

        if (S_ISDIR(st1.st_mode) && S_ISDIR(st2.st_mode)) {
            recursive_sync(file1, file2);
        } else if (S_ISREG(st1.st_mode) && S_ISREG(st2.st_mode)) {
            if (st1.st_size == st2.st_size) {
                FILE *f1 = fopen(file1, "rb");
                FILE *f2 = fopen(file2, "rb");

                if (f1 == NULL) {
                    fprintf(stderr, "Cannot open file: %s\n", file1);
                    continue;
                }

                if (f2 == NULL) {
                    fprintf(stderr, "Cannot open file: %s\n", file2);
                    fclose(f1);
                    continue;
                }

                char *buffer1 = (char *) malloc(st1.st_size);
                char *buffer2 = (char *) malloc(st2.st_size);

                if (buffer1 == NULL || buffer2 == NULL) {
                    fprintf(stderr, "Cannot allocate memory\n");
                    fclose(f1);
                    fclose(f2);
                    continue;
                }

                fread(buffer1, 1, st1.st_size, f1);
                fread(buffer2, 1, st2.st_size, f2);

                if (memcmp(buffer1, buffer2, st1.st_size) != 0) {
                    fprintf(stdout, "Files %s and %s are different\n", file1, file2);
                }

                free(buffer1);
                free(buffer2);
                fclose(f1);
                fclose(f2);
            } else {
                fprintf(stdout, "Files %s and %s are different\n", file1, file2);
            }
        }
    }

    while ((dirp2 = readdir(dp2)) != NULL) {
        if (strcmp(dirp2->d_name, ".") == 0 || strcmp(dirp2->d_name, "..") == 0) {
            continue;
        }

        snprintf(file1, sizeof(file1), "%s/%s", dir1, dirp2->d_name);
        snprintf(file2, sizeof(file2), "%s/%s", dir2, dirp2->d_name);

        if (stat(file1, &st1) == -1 && stat(file2, &st2) != -1) {
            fprintf(stdout, "Creating file %s from %s\n", file1, file2);
            FILE *f1 = fopen(file1, "wb");
            FILE *f2 = fopen(file2, "rb");

            if (f1 == NULL) {
                fprintf(stderr, "Cannot open file: %s\n", file1);
                continue;
            }

            if (f2 == NULL) {
                fprintf(stderr, "Cannot open file: %s\n", file2);
                fclose(f1);
                continue;
            }

            char *buffer = (char *) malloc(st2.st_size);

            if (buffer == NULL) {
                fprintf(stderr, "Cannot allocate memory\n");
                fclose(f1);
                fclose(f2);
                continue;
            }

            fread(buffer, 1, st2.st_size, f2);
            fwrite(buffer, 1, st2.st_size, f1);

            free(buffer);
            fclose(f1);
            fclose(f2);
        } else if (S_ISDIR(st2.st_mode)) {
            snprintf(file1, sizeof(file1), "%s/%s", dir1, dirp2->d_name);
            mkdir(file1, st2.st_mode);
            recursive_sync(file1, file2); // synchronize newly created directory
        }
    }

    closedir(dp1);
    closedir(dp2);
}