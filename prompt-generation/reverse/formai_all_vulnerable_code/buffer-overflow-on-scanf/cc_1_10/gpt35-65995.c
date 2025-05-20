//FormAI DATASET v1.0 Category: Banking Record System ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Record {
    char name[50];
    int account_num;
    float balance;
};

void printWelcome() {
    printf("Welcome to Happy Banking Record System!\n");
}

void addRecord(struct Record* records, int* num_records) {
    printf("\nEnter Name: ");
    scanf("%s", records[*num_records].name);
    printf("Enter Account Number: ");
    scanf("%d", &(records[*num_records].account_num));
    printf("Enter Balance: ");
    scanf("%f", &(records[*num_records].balance));
    printf("Record added successfully!\n");
    (*num_records)++;
}

void viewRecords(struct Record* records, int num_records) {
    printf("\n-----Viewing Records-----\n");
    for (int i = 0; i < num_records; i++) {
        printf("\nRecord %d:\n", i+1);
        printf("Name: %s\n", records[i].name);
        printf("Account Number: %d\n", records[i].account_num);
        printf("Balance: %.2f\n", records[i].balance);
    }
}

void deleteRecord(struct Record* records, int* num_records, int index) {
    for (int i = index; i < (*num_records)-1; i++) {
        records[i] = records[i+1];
    }
    (*num_records)--;
    printf("Record deleted successfully!\n");
}

int main() {
    printWelcome();
    struct Record records[100];
    int num_records = 0;
    while (1) {
        printf("\n-----Main Menu-----\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Delete Record\n");
        printf("4. Quit\n");
        int choice;
        printf("Enter Choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            addRecord(records, &num_records);
        }
        else if (choice == 2) {
            viewRecords(records, num_records);
        }
        else if (choice == 3) {
            printf("Enter index of record to delete: ");
            int index;
            scanf("%d", &index);
            deleteRecord(records, &num_records, index-1);
        }
        else if (choice == 4) {
            printf("Thank you for using Happy Banking Record System!\n");
            break;
        }
        else {
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}