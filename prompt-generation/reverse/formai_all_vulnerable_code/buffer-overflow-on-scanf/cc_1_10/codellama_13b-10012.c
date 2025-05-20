//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store banking records
struct Record {
    int id;
    char name[100];
    int balance;
};

// Function to add a new record
void addRecord(struct Record *record) {
    int id = record->id;
    char name[100];
    int balance = record->balance;

    printf("Enter the name: ");
    scanf("%s", name);

    printf("Enter the balance: ");
    scanf("%d", &balance);

    record->id = id;
    strcpy(record->name, name);
    record->balance = balance;
}

// Function to display all records
void displayRecords(struct Record *record) {
    int id = record->id;
    char name[100];
    int balance = record->balance;

    printf("ID: %d\n", id);
    printf("Name: %s\n", name);
    printf("Balance: %d\n", balance);
}

int main() {
    struct Record *record = malloc(sizeof(struct Record));

    // Add a new record
    addRecord(record);

    // Display all records
    displayRecords(record);

    return 0;
}