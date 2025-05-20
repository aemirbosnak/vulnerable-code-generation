//FormAI DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

/* Function prototypes */
void writeToFile(FILE *file, char *msg);
void readFromFile(FILE *file);

int main() {
    FILE *file;
    char fileName[MAX_SIZE], msg[MAX_SIZE], choice;

    printf("Enter file name: ");
    scanf("%s", fileName);

    /* Opening the file in write mode */
    file = fopen(fileName, "w");

    if (file == NULL) {
        printf("File not found!");
        exit(1);
    } else {
        printf("File opened successfully!\n");
    }

    /* Write to file */
    do {
        printf("\nEnter message: ");
        scanf(" %[^\n]", msg);

        writeToFile(file, msg);

        printf("\nDo you want to enter another message? (Y/N) ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    fclose(file);

    /* Opening the file in read mode */
    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("File not found!");
        exit(1);
    } else {
        printf("\nReading from file: %s\n", fileName);

        /* Read from file */
        readFromFile(file);
    }

    fclose(file);

    return 0;
}

/* Function to write to file */
void writeToFile(FILE *file, char *msg) {
    fprintf(file, "%s\n", msg);
}

/* Function to read from file */
void readFromFile(FILE *file) {
    char line[MAX_SIZE];

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
}