//FormAI DATASET v1.0 Category: File handling ; Style: shape shifting
#include <stdio.h>
#include <string.h>

#define MAX_CHARS 1000

void readInput(char *input) {
    printf("Enter text: ");
    fgets(input, MAX_CHARS, stdin);
}

void writeToFile(char *fileName, char *input) {
    FILE *file = fopen(fileName, "w");
    fprintf(file, "%s", input);
    fclose(file);
    printf("File written successfully!\n");
}

void readFromFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    char fileContents[MAX_CHARS];
    fgets(fileContents, MAX_CHARS, file);
    fclose(file);
    printf("File contents: %s\n", fileContents);
}

int main() {
    char input[MAX_CHARS], fileName[MAX_CHARS];

    printf("Welcome to Shape-shifting file handling program!\n");
    printf("What would you like to do?\n1. Write to file\n2. Read from file\n");

    int option;
    scanf("%d", &option);

    switch(option) {
        case 1:
            // Writing to file
            readInput(input);
            printf("Enter file name (including extension): ");
            scanf("%s", fileName);
            writeToFile(fileName, input);
            break;

        case 2:
            // Reading from file
            printf("Enter file name (including extension): ");
            scanf("%s", fileName);
            readFromFile(fileName);
            break;

        default:
            printf("Invalid option selected. Exiting program.\n");
            return 0;
    }

    return 0;
}