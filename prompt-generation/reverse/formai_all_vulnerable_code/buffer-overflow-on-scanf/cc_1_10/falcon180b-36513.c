//Falcon-180B DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100
#define MAX_NUM_FILES 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    FILE *fp;
    time_t last_modified_time;
} File;

int main() {
    int num_files = 0;
    File files[MAX_NUM_FILES];

    while (num_files < MAX_NUM_FILES) {
        printf("Enter file name (or 'done' to finish): ");
        char filename[MAX_FILE_NAME_LENGTH];
        scanf("%s", filename);
        if (strcmp(filename, "done") == 0) {
            break;
        }

        FILE *fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Error: could not open file '%s'\n", filename);
            continue;
        }

        File file;
        strcpy(file.name, filename);
        file.fp = fp;
        file.last_modified_time = time(NULL);
        files[num_files++] = file;

        fclose(fp);
    }

    if (num_files == 0) {
        printf("No files specified.\n");
        return 1;
    }

    printf("Enter search term: ");
    char search_term[MAX_LINE_LENGTH];
    scanf("%s", search_term);

    for (int i = 0; i < num_files; i++) {
        if (files[i].fp == NULL) {
            continue;
        }

        char line[MAX_LINE_LENGTH];
        while (fgets(line, MAX_LINE_LENGTH, files[i].fp)!= NULL) {
            if (strstr(line, search_term)!= NULL) {
                printf("Found match in file '%s':\n%s", files[i].name, line);
            }
        }

        fclose(files[i].fp);
    }

    return 0;
}