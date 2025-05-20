//Falcon-180B DATASET v1.0 Category: File handling ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char *name;
    FILE *file;
} file_t;

int main() {
    int num_files;
    char input_buffer[MAX_LINE_LENGTH];
    file_t *files = malloc(sizeof(file_t));

    printf("Enter the number of files to be opened: ");
    scanf("%d", &num_files);

    for (int i = 0; i < num_files; i++) {
        printf("Enter the name of the file to be opened: ");
        scanf("%s", input_buffer);
        files[i].name = malloc(strlen(input_buffer) + 1);
        strcpy(files[i].name, input_buffer);

        files[i].file = fopen(files[i].name, "r");
        if (files[i].file == NULL) {
            printf("Error opening file %s\n", files[i].name);
            exit(1);
        }
    }

    printf("Enter the string to be searched: ");
    scanf("%s", input_buffer);

    for (int i = 0; i < num_files; i++) {
        char *line = malloc(MAX_LINE_LENGTH);
        while (fgets(line, MAX_LINE_LENGTH, files[i].file)!= NULL) {
            if (strstr(line, input_buffer)!= NULL) {
                printf("Found in file %s: %s", files[i].name, line);
            }
        }
        free(line);
    }

    for (int i = 0; i < num_files; i++) {
        fclose(files[i].file);
        free(files[i].name);
        free(files[i].file);
    }

    free(files);

    return 0;
}