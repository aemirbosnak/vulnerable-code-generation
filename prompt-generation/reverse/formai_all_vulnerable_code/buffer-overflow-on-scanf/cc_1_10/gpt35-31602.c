//FormAI DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

struct bank_record {
    char name[MAX_SIZE];
    int account_number;
    float balance;
};

void print_record(struct bank_record record);
void add_record(struct bank_record records[], int *count);
void search_record(struct bank_record records[], int count);
void delete_record(struct bank_record records[], int *count);

int main() {
    struct bank_record records[MAX_SIZE];
    int choice, count = 0;
    do {
        printf("\n\nBank Record System");
        printf("\n1. Add Record");
        printf("\n2. Search Record");
        printf("\n3. Delete Record");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_record(records, &count);
                break;
            case 2:
                search_record(records, count);
                break;
            case 3:
                delete_record(records, &count);
                break;
            case 4:
                printf("\nExiting program...");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again!");
                break;
        }
    } while (choice != 4);
    return 0;
}

void print_record(struct bank_record record) {
    printf("\nName: %s", record.name);
    printf("\nAccount Number: %d", record.account_number);
    printf("\nBalance: $%.2f", record.balance);
}

void add_record(struct bank_record records[], int *count) {
    struct bank_record record;
    printf("\nEnter name: ");
    getchar();
    fgets(record.name, MAX_SIZE, stdin);
    printf("Enter account number: ");
    scanf("%d", &record.account_number);
    printf("Enter balance: ");
    scanf("%f", &record.balance);
    records[*count] = record;
    *count += 1;
    printf("\nRecord added successfully!");
}

void search_record(struct bank_record records[], int count) {
    char name[MAX_SIZE];
    printf("\nEnter name to search for: ");
    getchar();
    fgets(name, MAX_SIZE, stdin);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].name, name) == 0) {
            found = 1;
            printf("\nRecord found: ");
            print_record(records[i]);
        }
    }
    if (!found) {
        printf("\nRecord not found!");
    }
}

void delete_record(struct bank_record records[], int *count) {
    char name[MAX_SIZE];
    printf("\nEnter name to delete: ");
    getchar();
    fgets(name, MAX_SIZE, stdin);
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(records[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                records[j] = records[j + 1];
            }
            *count -= 1;
            printf("\nRecord deleted successfully!");
            break;
        }
    }
    if (!found) {
        printf("\nRecord not found!");
    }
}