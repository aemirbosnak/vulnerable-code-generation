//Falcon-180B DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

// Function to read the contents of a file into a string
char* readFile(char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    rewind(file);

    char* fileContents = malloc(fileSize + 1);
    fread(fileContents, fileSize, 1, file);
    fileContents[fileSize] = '\0';

    fclose(file);
    return fileContents;
}

// Function to write the contents of a string to a file
void writeFile(char* fileName, char* fileContents) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", fileName);
        return;
    }

    fwrite(fileContents, strlen(fileContents), 1, file);
    fclose(file);
}

// Function to prompt the user for a filename
char* promptForFileName(char* prompt) {
    char fileName[MAX_FILE_NAME_LENGTH];
    printf("%s: ", prompt);
    fgets(fileName, MAX_FILE_NAME_LENGTH, stdin);
    fileName[strcspn(fileName, "\n")] = '\0';
    return strdup(fileName);
}

// Function to prompt the user for a string
char* promptForString(char* prompt) {
    char string[MAX_LINE_LENGTH];
    printf("%s: ", prompt);
    fgets(string, MAX_LINE_LENGTH, stdin);
    string[strcspn(string, "\n")] = '\0';
    return strdup(string);
}

int main() {
    char* fileName = promptForFileName("Enter the name of the file to read:");
    char* fileContents = readFile(fileName);

    if (fileContents == NULL) {
        printf("Error: Could not read file %s.\n", fileName);
        return 1;
    }

    printf("Contents of file:\n%s", fileContents);

    char* newString = promptForString("Enter a new string to append to the file:");

    char* updatedContents = malloc(strlen(fileContents) + strlen(newString) + 2);
    strcpy(updatedContents, fileContents);
    strcat(updatedContents, "\n");
    strcat(updatedContents, newString);

    writeFile(fileName, updatedContents);
    printf("New string appended to file.\n");

    return 0;
}