//FormAI DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the banking record system
struct Record {
    int id;
    char name[50];
    char accountType[10];
    float balance;
};

// Function to add a new record
void addRecord(struct Record records[], int index) {
    // Get user input for the new record
    printf("Enter ID: ");
    scanf("%d", &records[index].id);
    printf("Enter name: ");
    scanf("%s", records[index].name);
    printf("Enter account type (savings/current): ");
    scanf("%s", records[index].accountType);
    printf("Enter opening balance: ");
    scanf("%f", &records[index].balance);
}

// Function to display all records
void displayRecords(struct Record records[], int count) {
    if (count == 0) {
        printf("No records found.\n");
    } else {
        printf("ID\tName\t\tAccount Type\tBalance\n");
        for (int i = 0; i < count; i++) {
            printf("%d\t%s\t\t%s\t\t%.2f\n", records[i].id, records[i].name, records[i].accountType, records[i].balance);
        }
    }
}

// Function to search for a record
void searchRecord(struct Record records[], int count) {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (records[i].id == id) {
            printf("ID\tName\t\tAccount Type\tBalance\n");
            printf("%d\t%s\t\t%s\t\t%.2f\n", records[i].id, records[i].name, records[i].accountType, records[i].balance);
            return;
        }
    }

    printf("Record with ID %d not found.\n", id);
}

// Function to delete a record
void deleteRecord(struct Record records[], int *count) {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (records[i].id == id) {
            // Shift all records after deleted record to the left
            for (int j = i; j < *count - 1; j++) {
                records[j] = records[j + 1];
            }

            *count -= 1;
            printf("Record with ID %d has been deleted.\n", id);
            return;
        }
    }

    printf("Record with ID %d not found.\n", id);
}

// Main function
int main() {
    struct Record records[100];
    int count = 0;
    int choice;

    do {
        printf("\n");
        printf("1. Add a new record\n");
        printf("2. Display all records\n");
        printf("3. Search for a record\n");
        printf("4. Delete a record\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(records, count);
                count += 1;
                break;

            case 2:
                displayRecords(records, count);
                break;

            case 3:
                searchRecord(records, count);
                break;

            case 4:
                deleteRecord(records, &count);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}