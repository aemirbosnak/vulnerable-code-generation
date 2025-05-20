//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100
#define MAX_FILES 10

typedef struct {
    char filename[MAX_LINE_LEN];
    int size;
    int checksum;
} FILE_INFO;

FILE_INFO files[MAX_FILES];
int file_count = 0;

int main() {
    FILE *fp;
    char line[MAX_LINE_LEN];
    int i, j;

    printf("Enter the path of the folder to scan: ");
    scanf("%s", line);

    fp = fopen(line, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strstr(line, ".c")!= NULL || strstr(line, ".h")!= NULL) {
            FILE_INFO info;
            char *filename = strtok(line, " \t\n");

            fseek(fp, 0, SEEK_SET);
            while (fgets(line, sizeof(line), fp)!= NULL) {
                if (strstr(line, "//")!= NULL || strstr(line, "#include")!= NULL) {
                    break;
                }
                if (strstr(line, "//")!= NULL || strstr(line, "#include")!= NULL) {
                    break;
                }
            }

            strncpy(info.filename, filename, MAX_LINE_LEN);
            fclose(fp);
            fp = fopen(filename, "r");
            if (fp == NULL) {
                printf("Error: Unable to open file.\n");
                return 1;
            }

            while (fgets(line, sizeof(line), fp)!= NULL) {
                if (strstr(line, "//")!= NULL || strstr(line, "#include")!= NULL) {
                    break;
                }
                if (strstr(line, "//")!= NULL || strstr(line, "#include")!= NULL) {
                    break;
                }
            }

            info.size = ftell(fp);
            rewind(fp);

            while (fgets(line, sizeof(line), fp)!= NULL) {
                if (strstr(line, "//")!= NULL || strstr(line, "#include")!= NULL) {
                    break;
                }
                if (strstr(line, "//")!= NULL || strstr(line, "#include")!= NULL) {
                    break;
                }
            }

            fseek(fp, 0, SEEK_SET);
            while (fgets(line, sizeof(line), fp)!= NULL) {
                if (strstr(line, "//")!= NULL || strstr(line, "#include")!= NULL) {
                    break;
                }
                if (strstr(line, "//")!= NULL || strstr(line, "#include")!= NULL) {
                    break;
                }
            }

            info.checksum = 0;
            while (fgets(line, sizeof(line), fp)!= NULL) {
                if (strstr(line, "//")!= NULL || strstr(line, "#include")!= NULL) {
                    break;
                }
                if (strstr(line, "//")!= NULL || strstr(line, "#include")!= NULL) {
                    break;
                }
            }

            fclose(fp);
            files[file_count++] = info;
        }
    }

    printf("Total files found: %d\n", file_count);

    return 0;
}