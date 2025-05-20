//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    time_t last_modified_time;
    char content[MAX_FILE_SIZE];
} File;

int main() {
    int num_files;
    File files[100];
    char directory_name[MAX_FILE_NAME_LENGTH];

    printf("Enter the directory name: ");
    scanf("%s", directory_name);

    num_files = scandir(directory_name, &files, NULL, NULL);

    if (num_files == -1) {
        printf("Directory not found.\n");
        exit(1);
    }

    printf("Number of files: %d\n", num_files);

    for (int i = 0; i < num_files; i++) {
        printf("%s\n", files[i].file_name);
    }

    printf("Synchronization started.\n");

    for (int i = 0; i < num_files; i++) {
        char file_name[MAX_FILE_NAME_LENGTH];
        strcpy(file_name, files[i].file_name);
        strcat(file_name, ".sync");

        FILE *file_in = fopen(files[i].file_name, "r");
        if (file_in == NULL) {
            printf("File not found: %s\n", files[i].file_name);
            continue;
        }

        FILE *file_out = fopen(file_name, "w");
        if (file_out == NULL) {
            printf("Cannot create file: %s\n", file_name);
            continue;
        }

        char line[MAX_FILE_SIZE];
        while (fgets(line, MAX_FILE_SIZE, file_in)!= NULL) {
            fputs(line, file_out);
        }

        fclose(file_in);
        fclose(file_out);
    }

    printf("Synchronization completed.\n");

    return 0;
}