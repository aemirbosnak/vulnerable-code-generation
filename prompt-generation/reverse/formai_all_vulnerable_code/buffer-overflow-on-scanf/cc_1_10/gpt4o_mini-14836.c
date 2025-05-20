//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 256
#define FILE_NAME "visonary_text.txt"

// Function prototypes
void writeVisionaryText();
void readVisionaryText();
void appendVisionaryText();

int main() {
    int choice;

    do {
        printf("\n--- Visionary Text Handler ---\n");
        printf("1. Write Visionary Text\n");
        printf("2. Read Visionary Text\n");
        printf("3. Append Visionary Text\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character after the integer input

        switch (choice) {
            case 1:
                writeVisionaryText();
                break;
            case 2:
                readVisionaryText();
                break;
            case 3:
                appendVisionaryText();
                break;
            case 4:
                printf("Exiting the Visionary Text Handler...\n");
                break;
            default:
                printf("Invalid option. Please choose between 1-4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void writeVisionaryText() {
    FILE *file;
    char buffer[MAX_BUFFER];

    file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    printf("Enter visionary text (type 'END' to finish):\n");
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (strncmp(buffer, "END", 3) == 0) break;
        fprintf(file, "%s", buffer);
    }

    fclose(file);
    printf("Visionary text written to %s successfully!\n", FILE_NAME);
}

void readVisionaryText() {
    FILE *file;
    char buffer[MAX_BUFFER];

    file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    printf("\n--- Visionary Text ---\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

void appendVisionaryText() {
    FILE *file;
    char buffer[MAX_BUFFER];

    file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Error opening file for appending");
        return;
    }

    printf("Enter additional visionary text (type 'END' to finish):\n");
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (strncmp(buffer, "END", 3) == 0) break;
        fprintf(file, "%s", buffer);
    }

    fclose(file);
    printf("Additional visionary text appended to %s successfully!\n", FILE_NAME);
}