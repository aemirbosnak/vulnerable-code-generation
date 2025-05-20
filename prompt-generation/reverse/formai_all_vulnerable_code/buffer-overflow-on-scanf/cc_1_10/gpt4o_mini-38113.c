//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define RECORD_SIZE 256
#define FILENAME "ledger.txt"

// Function prototypes
void addRecord(const char *filename);
void viewRecords(const char *filename);
void deleteRecord(const char *filename);
void clearBuffer();

int main() {
    int choice;
    while (1) {
        printf("\n--- Decentralized Ledger System ---\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Delete Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        clearBuffer(); // Clear newline left by scanf

        switch (choice) {
            case 1:
                addRecord(FILENAME);
                break;
            case 2:
                viewRecords(FILENAME);
                break;
            case 3:
                deleteRecord(FILENAME);
                break;
            case 4:
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addRecord(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    char record[RECORD_SIZE];
    printf("Enter the record (max %d characters): ", RECORD_SIZE-1);
    fgets(record, RECORD_SIZE, stdin);
    
    fprintf(file, "%s", record);
    fclose(file);

    printf("Record added successfully!\n");
}

void viewRecords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    char buffer[RECORD_SIZE];
    printf("\n--- Ledger Records ---\n");
    while (fgets(buffer, RECORD_SIZE, file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

void deleteRecord(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Load records into memory
    char *records[MAX_RECORDS];
    int count = 0;
    char buffer[RECORD_SIZE];

    while (fgets(buffer, RECORD_SIZE, file) != NULL && count < MAX_RECORDS) {
        records[count] = strdup(buffer);
        count++;
    }
    fclose(file);

    // Display records for selection
    printf("\n--- Select Record to Delete ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s", i + 1, records[i]);
    }

    int recordNumber;
    printf("Enter the record number to delete (0 to cancel): ");
    scanf("%d", &recordNumber);
    clearBuffer(); // Clear newline left by scanf

    if (recordNumber < 1 || recordNumber > count) {
        printf("No record deleted. Operation canceled.\n");
        for (int i = 0; i < count; i++) {
            free(records[i]);
        }
        return;
    }

    // Rewrite the file without the selected record
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (i + 1 != recordNumber) {
            fprintf(file, "%s", records[i]);
        }
        free(records[i]); // Free memory allocated for each record
    }
    
    fclose(file);
    printf("Record %d deleted successfully!\n", recordNumber);
}

void clearBuffer() {
    while (getchar() != '\n'); // Clears input buffer
}