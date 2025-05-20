//Falcon-180B DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function prototypes
void read_file(FILE *file, char *buffer);
void write_file(FILE *file, const char *data);
void append_file(FILE *file, const char *data);
void delete_file(const char *filename);

// Main function
int main(int argc, char *argv[]) {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    char buffer[MAX_LINE_LENGTH];
    char choice;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    printf("\nFile contents:\n");
    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        printf("%s", buffer);
    }

    printf("\n\nWhat would you like to do with the file?\n");
    printf("1. Append to file\n");
    printf("2. Delete file\n");
    printf("3. Exit\n");
    scanf(" %c", &choice);

    switch (choice) {
        case '1':
            printf("\nEnter text to append: ");
            scanf("%[^\n]", buffer);
            append_file(file, buffer);
            printf("\nText appended to file.\n");
            break;
        case '2':
            delete_file(filename);
            printf("\nFile deleted.\n");
            break;
        case '3':
            printf("\nExiting program.\n");
            break;
        default:
            printf("\nInvalid choice.\n");
    }

    fclose(file);
    return 0;
}

// Function to read file into buffer
void read_file(FILE *file, char *buffer) {
    fseek(file, 0, SEEK_SET);
    fread(buffer, sizeof(char), MAX_LINE_LENGTH, file);
    buffer[MAX_LINE_LENGTH - 1] = '\0';
}

// Function to write data to file
void write_file(FILE *file, const char *data) {
    fseek(file, 0, SEEK_SET);
    fwrite(data, sizeof(char), strlen(data), file);
}

// Function to append data to file
void append_file(FILE *file, const char *data) {
    fseek(file, 0, SEEK_END);
    write_file(file, data);
}

// Function to delete file
void delete_file(const char *filename) {
    remove(filename);
}