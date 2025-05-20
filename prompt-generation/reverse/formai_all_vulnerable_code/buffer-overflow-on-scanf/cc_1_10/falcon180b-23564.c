//Falcon-180B DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FILE_NAME_LEN 256
#define MAX_NUM_FILES 1000

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    FILE* file;
} File;

int main() {
    int numFiles;
    File files[MAX_NUM_FILES];
    char line[MAX_LINE_LEN];
    char filename[MAX_FILE_NAME_LEN];

    printf("Enter number of files to open: ");
    scanf("%d", &numFiles);

    for (int i = 0; i < numFiles; i++) {
        printf("Enter file name for file %d: ", i);
        scanf("%s", filename);

        files[i].file = fopen(filename, "r");
        if (files[i].file == NULL) {
            printf("Error opening file %s\n", filename);
            exit(1);
        }

        strcpy(files[i].name, filename);
    }

    printf("Enter word to search for: ");
    scanf("%s", filename);

    for (int i = 0; i < numFiles; i++) {
        if (fseek(files[i].file, 0, SEEK_SET)!= 0) {
            printf("Error rewinding file %s\n", files[i].name);
            exit(1);
        }

        while (fgets(line, MAX_LINE_LEN, files[i].file)!= NULL) {
            if (strstr(line, filename)!= NULL) {
                printf("%s: %s", files[i].name, line);
            }
        }

        if (ferror(files[i].file)) {
            printf("Error reading file %s\n", files[i].name);
            exit(1);
        }
    }

    for (int i = 0; i < numFiles; i++) {
        fclose(files[i].file);
    }

    return 0;
}