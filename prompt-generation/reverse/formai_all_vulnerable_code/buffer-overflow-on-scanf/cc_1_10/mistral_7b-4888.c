//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define FILE_NAME "input.txt"

void print_menu() {
    printf("\n------------------\n");
    printf("| File Handling   |\n");
    printf("| Menu            |\n");
    printf("------------------\n");
    printf("| 1. Read File    |\n");
    printf("| 2. Write File   |\n");
    printf("| 3. Append File  |\n");
    printf("| 4. Delete File  |\n");
    printf("| 5. Exit         |\n");
    printf("------------------\n");
}

int read_file(char *filename) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        printf("Line %d: %s", ++line_number, line);
    }

    fclose(file);
    return 0;
}

int write_file(char *filename) {
    FILE *file;
    char *message = "Hello, World!";

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open file %s for writing\n", filename);
        return 1;
    }

    fprintf(file, "%s", message);
    fclose(file);
    return 0;
}

int append_file(char *filename) {
    FILE *file;
    char *message = "Appended line.";

    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error: Unable to open file %s for appending\n", filename);
        return 1;
    }

    fprintf(file, "%s\n", message);
    fclose(file);
    return 0;
}

int delete_file(char *filename) {
    int result;

    result = remove(filename);
    if (result != 0) {
        printf("Error: Unable to delete file %s\n", filename);
        return 1;
    }

    return 0;
}

int main() {
    char choice;

    do {
        print_menu();
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                read_file(FILE_NAME);
                break;
            case '2':
                write_file(FILE_NAME);
                break;
            case '3':
                append_file(FILE_NAME);
                break;
            case '4':
                delete_file(FILE_NAME);
                break;
            case '5':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != '5');

    return 0;
}