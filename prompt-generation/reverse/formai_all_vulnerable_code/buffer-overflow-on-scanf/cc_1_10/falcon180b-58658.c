//Falcon-180B DATASET v1.0 Category: File handling ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FILE_NAME_SIZE 100

// Function prototypes
void read_file(FILE* file, char* line);
void write_file(FILE* file, char* line);
void append_file(FILE* file, char* line);

int main() {
    char file_name[MAX_FILE_NAME_SIZE];
    char line[MAX_LINE_SIZE];
    char choice;

    printf("Enter file name: ");
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    do {
        printf("\nEnter your choice:\n");
        printf("1. Read file\n");
        printf("2. Write file\n");
        printf("3. Append file\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                read_file(file, line);
                printf("\n%s\n", line);
                break;
            case '2':
                printf("Enter line to write: ");
                scanf("%[^\n]", line);
                write_file(file, line);
                break;
            case '3':
                printf("Enter line to append: ");
                scanf("%[^\n]", line);
                append_file(file, line);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    fclose(file);

    return 0;
}

void read_file(FILE* file, char* line) {
    fgets(line, MAX_LINE_SIZE, file);
}

void write_file(FILE* file, char* line) {
    fputs(line, file);
    fputc('\n', file);
}

void append_file(FILE* file, char* line) {
    fseek(file, 0, SEEK_END);
    fputs(line, file);
    fputc('\n', file);
}