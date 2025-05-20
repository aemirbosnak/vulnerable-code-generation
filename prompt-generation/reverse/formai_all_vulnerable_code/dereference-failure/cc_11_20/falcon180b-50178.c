//Falcon-180B DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char *file_name;
    FILE *file;
} File;

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <file_name> <operation>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    char *operation = argv[2];

    File file;
    file.file_name = file_name;
    file.file = fopen(file_name, "r+");
    if (file.file == NULL) {
        printf("Error opening file: %s\n", file_name);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char *search_string = NULL;
    char *replace_string = NULL;
    int line_number = 0;

    if (strcmp(operation, "read") == 0) {
        while (fgets(line, MAX_LINE_LENGTH, file.file)!= NULL) {
            printf("%d: %s", line_number++, line);
        }
    } else if (strcmp(operation, "write") == 0) {
        printf("Enter line to write: ");
        fgets(line, MAX_LINE_LENGTH, stdin);
        fseek(file.file, 0, SEEK_END);
        fputs(line, file.file);
    } else if (strcmp(operation, "search") == 0) {
        printf("Enter search string: ");
        scanf("%s", search_string);
        while (fgets(line, MAX_LINE_LENGTH, file.file)!= NULL) {
            if (strstr(line, search_string)!= NULL) {
                printf("%d: %s", line_number++, line);
            }
            line_number++;
        }
    } else if (strcmp(operation, "replace") == 0) {
        printf("Enter search string: ");
        scanf("%s", search_string);
        printf("Enter replace string: ");
        scanf("%s", replace_string);
        rewind(file.file);
        while (fgets(line, MAX_LINE_LENGTH, file.file)!= NULL) {
            if (strstr(line, search_string)!= NULL) {
                strcpy(line, replace_string);
            }
            fputs(line, file.file);
        }
    }

    fclose(file.file);
    return 0;
}