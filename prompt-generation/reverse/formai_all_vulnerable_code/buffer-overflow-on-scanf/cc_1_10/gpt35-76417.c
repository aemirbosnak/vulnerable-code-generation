//FormAI DATASET v1.0 Category: Text processing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void printCentered(char* str);
void printLowerCase(char* str);

int main() {
    char fileName[100];
    FILE* filePointer;
    char line[MAX_LINE_LENGTH];
    char fileContents[MAX_LINE_LENGTH];
    char* word;
    int count = 0;

    printf("Enter file name: ");
    scanf("%s", fileName);

    filePointer = fopen(fileName, "r");

    if (filePointer == NULL) {
        printf("Unable to open file %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, filePointer) != NULL) {
        strcat(fileContents, line);
    }

    printf("\nOriginal text:\n%s\n", fileContents);

    printCentered(fileContents);

    printf("\nLowercase text:\n");
    printLowerCase(fileContents);

    printf("\nWord count: ");
    word = strtok(fileContents, " ,.\n");
    while (word != NULL) {
        count++;
        word = strtok(NULL, " ,.\n");
    }
    printf("%d\n", count);

    fclose(filePointer);
    return 0;
}

void printCentered(char* str) {
    int length = strlen(str);
    int i;

    printf("\nCentered text:\n");

    for (i = 0; i < (MAX_LINE_LENGTH - length) / 2; i++) {
        printf(" ");
    }

    printf("%s\n", str);
}

void printLowerCase(char* str) {
    char* ptr = str;

    while (*ptr) {
        putchar(tolower(*ptr));
        ptr++;
    }
}