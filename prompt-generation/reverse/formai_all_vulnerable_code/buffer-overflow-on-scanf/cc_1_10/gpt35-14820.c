//FormAI DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct Record {
    int id;
    char name[50];
    int age;
};

// Global variables
struct Record database[MAX_RECORDS];
int num_records = 0;

// Function to add a new record to the database
void addRecord() {
    if (num_records >= MAX_RECORDS) {
        printf("Error: Database is full\n");
        return;
    }
    
    struct Record newRecord;
    newRecord.id = num_records + 1;
    
    printf("Enter name: ");
    fgets(newRecord.name, 50, stdin);
    
    printf("Enter age: ");
    scanf("%d", &newRecord.age);
    getchar();
    
    database[num_records] = newRecord;
    num_records++;
}

// Function to search for a record by ID
void searchRecord() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    getchar();
    
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            printf("Record found:\n");
            printf("ID: %d\n", database[i].id);
            printf("Name: %s", database[i].name);
            printf("Age: %d\n", database[i].age);
            return;
        }
    }
    
    printf("Record not found\n");
}

// Function to print all records in the database
void printDatabase() {
    printf("ID   | Name                  | Age\n");
    printf("-----------------------------------\n");
    
    for (int i = 0; i < num_records; i++) {
        printf("%-4d | %-20s | %d\n", database[i].id, database[i].name, database[i].age);
    }
}

int main() {
    printf("Welcome to the database simulation program\n");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add record\n");
        printf("2. Search record\n");
        printf("3. Print all records\n");
        printf("4. Quit\n");
        printf("Enter option: ");
        
        int option;
        scanf("%d", &option);
        getchar();
        
        switch(option) {
            case 1:
                addRecord();
                break;
            case 2:
                searchRecord();
                break;
            case 3:
                printDatabase();
                break;
            case 4:
                printf("Quitting program\n");
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }
    
    return 0;
}