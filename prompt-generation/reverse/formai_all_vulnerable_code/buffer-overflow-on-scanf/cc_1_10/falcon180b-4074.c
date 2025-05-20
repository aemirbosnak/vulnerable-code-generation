//Falcon-180B DATASET v1.0 Category: File handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a valid filename
int isValidFilename(char *filename) {
    int i;
    for (i = 0; i < strlen(filename); i++) {
        if (!isalpha(filename[i]) &&!isdigit(filename[i]) && filename[i]!= '_') {
            return 0;
        }
    }
    return 1;
}

// Function to read a file into memory
char *readFile(char *filename) {
    FILE *file;
    long filesize;
    char *buffer;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    filesize = ftell(file);
    rewind(file);

    buffer = malloc(filesize + 1);
    if (buffer == NULL) {
        printf("Error: could not allocate memory for file %s\n", filename);
        exit(1);
    }

    fread(buffer, filesize, 1, file);
    fclose(file);

    buffer[filesize] = '\0';
    return buffer;
}

// Function to write a string to a file
void writeFile(char *filename, char *data) {
    FILE *file;

    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: could not open file %s for writing\n", filename);
        exit(1);
    }

    fwrite(data, strlen(data), 1, file);
    fclose(file);
}

int main() {
    char filename[100];
    char *buffer;
    int choice;

    printf("Welcome to the Retro File Handler!\n");
    printf("Please enter a filename (up to 99 characters): ");
    scanf("%s", filename);

    if (!isValidFilename(filename)) {
        printf("Error: invalid filename\n");
        exit(1);
    }

    buffer = readFile(filename);
    printf("File contents:\n%s\n", buffer);

    printf("What would you like to do with the file?\n");
    printf("1. Save changes\n");
    printf("2. Discard changes\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter new file contents:\n");
        fgets(buffer, 1000, stdin);
        writeFile(filename, buffer);
        printf("File saved successfully!\n");
    } else {
        printf("Changes discarded.\n");
    }

    free(buffer);
    return 0;
}