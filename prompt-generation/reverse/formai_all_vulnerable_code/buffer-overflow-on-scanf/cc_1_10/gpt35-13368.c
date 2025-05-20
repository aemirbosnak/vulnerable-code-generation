//FormAI DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // Maximum number of records that can be stored in the array

typedef struct {
    char date[11];
    float amount;
    char category[20];
} ExpenseRecord;

int numRecords = 0; // Current number of records in the array
ExpenseRecord records[MAX_RECORDS]; // Array to store expense records

void addRecord() {
    ExpenseRecord record;
    // Get user input for the new expense record
    printf("Enter date (mm/dd/yyyy): ");
    scanf("%s", record.date);
    printf("Enter amount: ");
    scanf("%f", &record.amount);
    printf("Enter category: ");
    scanf("%s", record.category);
    // Add the new record to the array
    records[numRecords++] = record;
    printf("Record added!\n");
}

void printRecords() {
    printf("   Date     |  Amount  |  Category \n");
    printf("----------------------------------\n");
    for (int i = 0; i < numRecords; i++) {
        printf("%s   %.2f     %s\n", records[i].date, records[i].amount, records[i].category);
    }
}

void saveRecords() {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return;
    }
    for (int i = 0; i < numRecords; i++) {
        fprintf(file, "%s,%f,%s\n", records[i].date, records[i].amount, records[i].category);
    }
    fclose(file);
    printf("Records saved!\n");
}

void loadRecords() {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        return;
    }
    char line[100];
    while (fgets(line, 100, file) != NULL) {
        char *token = strtok(line, ",");
        strcpy(records[numRecords].date, token);
        token = strtok(NULL, ",");
        records[numRecords].amount = atof(token);
        token = strtok(NULL, ",");
        strcpy(records[numRecords].category, token);
        numRecords++;
    }
    fclose(file);
}

int main() {
    loadRecords();
    int choice;
    do {
        printf("Expense Tracker\n");
        printf("----------------\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Save Records\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                printRecords();
                break;
            case 3:
                saveRecords();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    } while (choice != 4);
    return 0;
}