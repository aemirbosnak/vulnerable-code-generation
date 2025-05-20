//FormAI DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ExpenseRecord {
    int id;
    char date[11];
    char category[20];
    char description[50];
    double amount;
};

void addExpenseRecord() {
    FILE *fptr;
    fptr = fopen("expense.dat", "ab");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return;
    }

    struct ExpenseRecord record;
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", record.date);
    fflush(stdin);

    printf("Enter expense category: ");
    scanf("%s", record.category);
    fflush(stdin);

    printf("Enter expense description: ");
    scanf("%[^\n]", record.description);
    fflush(stdin);

    printf("Enter expense amount: ");
    scanf("%lf", &record.amount);
    fflush(stdin);

    record.id = rand();

    fwrite(&record, sizeof(struct ExpenseRecord), 1, fptr);
    printf("Expense record added successfully!\n\n");
    fclose(fptr);
}

void viewExpenseRecords() {
    FILE *fptr;
    fptr = fopen("expense.dat", "rb");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return;
    }

    struct ExpenseRecord record;

    printf("------------------------\n");
    printf("ID     | Date       | Category    | Description                    | Amount\n");
    printf("------------------------\n");
    while (fread(&record, sizeof(struct ExpenseRecord), 1, fptr) == 1) {
        printf("%06d | %s | %-11s | %-30s | $%0.2f\n", record.id, record.date, record.category, record.description, record.amount);
    }
    printf("------------------------\n\n");
    fclose(fptr);
}

void searchExpenseRecords() {
    char search[20];
    printf("Enter search query: ");
    scanf("%s", search);
    fflush(stdin);

    FILE *fptr;
    fptr = fopen("expense.dat", "rb");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return;
    }

    struct ExpenseRecord record;
    int count = 0;

    printf("------------------------\n");
    printf("ID     | Date       | Category    | Description                    | Amount\n");
    printf("------------------------\n");
    while (fread(&record, sizeof(struct ExpenseRecord), 1, fptr) == 1) {
        if (strstr(record.date, search) != NULL || strstr(record.category, search) != NULL || strstr(record.description, search) != NULL) {
            printf("%06d | %s | %-11s | %-30s | $%0.2f\n", record.id, record.date, record.category, record.description, record.amount);
            count++;
        }
    }
    printf("------------------------\n");
    if (count == 0) {
        printf("No records found.\n\n");
    } else {
        printf("%d record(s) found.\n\n", count);
    }
    fclose(fptr);
}

int main() {
    while (1) {
        int choice;
        printf("Expense Tracker - Main Menu\n");
        printf("1. Add Expense Record\n");
        printf("2. View Expense Records\n");
        printf("3. Search Expense Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                addExpenseRecord();
                break;
            case 2:
                viewExpenseRecords();
                break;
            case 3:
                searchExpenseRecords();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n\n");
        }
    }

    return 0;
}