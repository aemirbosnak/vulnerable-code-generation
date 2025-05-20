//FormAI DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int accountNumber;
    char name[50];
    char address[100];
    float balance;
} Record;

Record records[100];
int count = 0;

void addRecord() {
    Record record;
    printf("Enter account number: ");
    scanf("%d", &record.accountNumber);
    printf("Enter name: ");
    scanf("%s", record.name);
    printf("Enter address: ");
    scanf("%s", record.address);
    printf("Enter balance: ");
    scanf("%f", &record.balance);
    records[count] = record;
    count++;
}

void printRecords() {
    printf("Account Number\tName\tAddress\tBalance\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\t%.2f\n", records[i].accountNumber,
               records[i].name, records[i].address, records[i].balance);
    }
}

int main() {
    int choice;
    do {
        printf("Banking Record System\n");
        printf("1. Add record\n");
        printf("2. Print records\n");
        printf("3. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                printRecords();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 3);
    return 0;
}