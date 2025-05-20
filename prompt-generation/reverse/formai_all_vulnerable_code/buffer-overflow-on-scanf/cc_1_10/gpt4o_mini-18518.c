//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Function to read a csv file
void readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *fields[MAX_FIELDS];
        int fieldCount = 0;

        // Split the line into fields based on commas
        char *token = strtok(line, ",");
        while (token != NULL && fieldCount < MAX_FIELDS) {
            fields[fieldCount++] = strdup(token);
            token = strtok(NULL, ",");
        }

        // Display fields
        printf("Read %d fields:\n", fieldCount);
        for (int i = 0; i < fieldCount; i++) {
            printf("Field %d: %s\n", i + 1, fields[i]);
            free(fields[i]); // Free dynamically allocated memory
        }
        printf("End of line\n\n");
    }

    fclose(file);
}

// Function to write a new csv file with modified data
void writeCSV(const char *filename, const char *data[], int dataSize) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file");
        return;
    }

    for (int i = 0; i < dataSize; i++) {
        fprintf(file, "%s", data[i]);
        if (i < dataSize - 1) {
            fprintf(file, ",");
        }
    }
    fprintf(file, "\n");
    fclose(file);
    printf("Data written to %s successfully.\n", filename);
}

// Utility function to print menu options
void printMenu() {
    printf("CSV Reader Menu:\n");
    printf("1. Read a CSV file\n");
    printf("2. Write a new CSV file\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char inputFile[100], outputFile[100];
    const char *sampleData[] = {
        "Name,Age,Occupation",
        "Alice,30,Engineer",
        "Bob,25,Designer",
        "Charlie,35,Manager"
    };
    int sampleDataSize = sizeof(sampleData) / sizeof(sampleData[0]);
    
    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar(); // Clear newline character left in the buffer
        
        switch (choice) {
            case 1:
                printf("Enter the name of the CSV file to read: ");
                fgets(inputFile, sizeof(inputFile), stdin);
                inputFile[strcspn(inputFile, "\n")] = 0; // Remove newline character
                printf("Reading from file: %s\n", inputFile);
                readCSV(inputFile);
                break;
            case 2:
                printf("Enter the name of the CSV file to write: ");
                fgets(outputFile, sizeof(outputFile), stdin);
                outputFile[strcspn(outputFile, "\n")] = 0; // Remove newline character
                printf("Writing to file: %s\n", outputFile);
                writeCSV(outputFile, sampleData, sampleDataSize);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}