//Falcon-180B DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count words in a string
int countWords(char* str) {
    int count = 0;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to read a file and count words
void countFileWords(FILE* file, char* filename) {
    char buffer[1024];
    int count = 0;
    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        count += countWords(buffer);
    }
    printf("Total words in %s: %d\n", filename, count);
}

// Function to write to a file
void writeToFile(FILE* file, char* str) {
    fputs(str, file);
}

// Function to replace words in a file
void replaceWords(FILE* file, char* oldWord, char* newWord) {
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        char* token = strtok(buffer, " ");
        while (token!= NULL) {
            if (strcmp(token, oldWord) == 0) {
                strcpy(token, newWord);
            }
            token = strtok(NULL, " ");
        }
        fputs(buffer, file);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found\n");
        return 1;
    }

    // Count words in file
    countFileWords(file, filename);

    // Replace words in file
    char oldWord[100];
    char newWord[100];
    printf("Enter old word: ");
    scanf("%s", oldWord);
    printf("Enter new word: ");
    scanf("%s", newWord);
    replaceWords(file, oldWord, newWord);

    // Write to file
    char str[100];
    printf("Enter string to write: ");
    scanf("%s", str);
    writeToFile(file, str);

    // Close file
    fclose(file);
    return 0;
}