//FormAI DATASET v1.0 Category: Banking Record System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_RECORDS 100

typedef struct record {
    int id;
    char name[50];
    double balance;
} Record;

Record records[MAX_RECORDS];

// Method to read data from file
void readDataFromFile() {
    FILE *fp = fopen("records.dat", "r");
    int count = 0;

    if (fp == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return;
    }

    while (!feof(fp)) {
        fscanf(fp, "%d %s %lf", &records[count].id, records[count].name, &records[count].balance);
        count++;
    }

    fclose(fp);
}

// Method to write data to file
void writeDataToFile() {
    FILE *fp = fopen("records.dat", "w");
    int count = 0;

    if (fp == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return;
    }

    while (records[count].id != 0 && count < MAX_RECORDS) {
        fprintf(fp, "%d %s %lf\n", records[count].id, records[count].name, records[count].balance);
        count++;
    }

    fclose(fp);
}

// Method to add a new record
void addRecord(int id, char *name, double initialBalance) {
    int count = 0;

    while (records[count].id != 0 && count < MAX_RECORDS) {
        if (records[count].id == id) {
            printf("Record with id %d already exists\n", id);
            return;
        }

        count++;
    }

    if (count >= MAX_RECORDS) {
        printf("Maximum number of records reached\n");
        return;
    }

    records[count].id = id;
    strcpy(records[count].name, name);
    records[count].balance = initialBalance;

    printf("Record added successfully\n");

    writeDataToFile();
}

// Method to remove a record
void removeRecord(int id) {
    int count = 0;

    while (records[count].id != id && count < MAX_RECORDS) {
        count++;
    }

    if (count >= MAX_RECORDS) {
        printf("Record with id %d not found\n", id);
        return;
    }

    records[count].id = 0;
    strcpy(records[count].name, "");
    records[count].balance = 0;

    printf("Record removed successfully\n");

    writeDataToFile();
}

// Method to deposit money into a record
void deposit(int id, double amount) {
    int count = 0;

    while (records[count].id != id && count < MAX_RECORDS) {
        count++;
    }

    if (count >= MAX_RECORDS) {
        printf("Record with id %d not found\n", id);
        return;
    }

    records[count].balance += amount;

    printf("Deposit successful\n");

    writeDataToFile();
}

// Method to withdraw money from a record
void withdraw(int id, double amount) {
    int count = 0;

    while (records[count].id != id && count < MAX_RECORDS) {
        count++;
    }

    if (count >= MAX_RECORDS) {
        printf("Record with id %d not found\n", id);
        return;
    }

    if (records[count].balance - amount < 0) {
        printf("Insufficient funds\n");
        return;
    }

    records[count].balance -= amount;

    printf("Withdrawal successful\n");

    writeDataToFile();
}

int main() {
    readDataFromFile();

    int choice, id;
    double initialBalance, amount;
    char name[50];

    do {
        printf("Welcome to the Async Banking Record System\n");
        printf("-----------------------------------------\n");
        printf("1. Add new record\n");
        printf("2. Remove record\n");
        printf("3. Deposit money\n");
        printf("4. Withdraw money\n");
        printf("5. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the following details:\n");
                printf("ID: ");
                scanf("%d", &id);
                printf("Name: ");
                scanf("%s", name);
                printf("Initial balance: ");
                scanf("%lf", &initialBalance);
                addRecord(id, name, initialBalance);
                break;
            case 2:
                printf("Enter the ID of the record to remove: ");
                scanf("%d", &id);
                removeRecord(id);
                break;
            case 3:
                printf("Enter the ID of the record to deposit into: ");
                scanf("%d", &id);
                printf("Enter the amount to deposit: ");
                scanf("%lf", &amount);
                deposit(id, amount);
                break;
            case 4:
                printf("Enter the ID of the record to withdraw from: ");
                scanf("%d", &id);
                printf("Enter the amount to withdraw: ");
                scanf("%lf", &amount);
                withdraw(id, amount);
                break;
            case 5:
                printf("Exiting the Async Banking Record System...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("\n");

    } while (choice != 5);

    return 0;
}