//FormAI DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// defining struct for expense record
typedef struct {
    char category[20];
    float amount;
    char date[11];
} Record;

// function to display all records in the file
void displayRecords(FILE *fp) {
    Record r;
    printf("\nCategory\tAmount\t\tDate\n");
    printf("------------------------------------------\n");
    while(fread(&r, sizeof(r), 1, fp) == 1) {
        printf("%s\t\t$%.2f\t\t%s\n", r.category, r.amount, r.date);
    }
}

// function to add a new record to the file
void addRecord(FILE *fp) {
    Record r;
    printf("\nEnter the following details:\nCategory: ");
    scanf("%s", r.category);
    printf("Amount: ");
    scanf("%f", &r.amount);
    printf("Date (in DD/MM/YYYY format): ");
    scanf("%s", r.date);
    fwrite(&r, sizeof(r), 1, fp);
    printf("\nRecord added successfully!\n");
}

// function to search and display records by category
void searchByCategory(FILE *fp) {
    Record r;
    char searchCategory[20];
    printf("\nEnter category to search for: ");
    scanf("%s", searchCategory);
    printf("\nSearch Results:\n");

    while(fread(&r, sizeof(r), 1, fp) == 1) {
        if(strcmp(r.category, searchCategory) == 0) {
            printf("%s\t\t$%.2f\t\t%s\n", r.category, r.amount, r.date);
        }
    }
}

int main() {
    FILE *fp;
    fp = fopen("expenses.dat", "rb+");

    if(fp == NULL) {
        fp = fopen("expenses.dat", "wb");
        if(fp == NULL) {
            printf("Error creating file!");
            exit(1);
        }
    }

    int choice;
    do {
        printf("\nExpense Tracker\n");
        printf("1. Display All Records\n");
        printf("2. Add New Record\n");
        printf("3. Search By Category\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayRecords(fp);
                break;
            case 2:
                addRecord(fp);
                break;
            case 3:
                searchByCategory(fp);
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice != 4);

    fclose(fp);
    return 0;
}