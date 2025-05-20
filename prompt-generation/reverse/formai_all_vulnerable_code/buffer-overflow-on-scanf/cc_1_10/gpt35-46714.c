//FormAI DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct Record {
    int id;
    char name[50];
    int age;
    float salary;
};
typedef struct Record Record;

int numRecords = 0;
Record database[MAX_RECORDS];

void addRecord(int id, char* name, int age, float salary) {
    if(numRecords >= MAX_RECORDS) {
        printf("Database is full, cannot add any more records.\n");
        return;
    }

    database[numRecords].id = id;
    strcpy(database[numRecords].name, name);
    database[numRecords].age = age;
    database[numRecords].salary = salary;

    numRecords++;
    printf("Record added successfully!\n");
}

void removeRecord(int id) {
    int index = -1;
    for(int i = 0; i < numRecords; i++) {
        if(database[i].id == id) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Record not found.\n");
        return;
    }

    for(int i = index; i < numRecords-1; i++) {
        database[i] = database[i+1];
    }

    numRecords--;
    printf("Record removed successfully!\n");
}

void displayRecord(int id) {
    for(int i = 0; i < numRecords; i++) {
        if(database[i].id == id) {
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Salary: $%.2f\n", database[i].salary);
            return;
        }
    }

    printf("Record not found.\n");
}

void displayAllRecords() {
    for(int i = 0; i < numRecords; i++) {
        printf("ID: %d\n", database[i].id);
        printf("Name: %s\n", database[i].name);
        printf("Age: %d\n", database[i].age);
        printf("Salary: $%.2f\n", database[i].salary);
        printf("\n");
    }
}

int main() {
    int choice, id, age;
    float salary;
    char name[50];

    printf("Welcome to the Database Simulator program!\n");

    do {
        printf("\n");
        printf("Choose an option:\n\n");
        printf("1. Add record\n");
        printf("2. Remove record\n");
        printf("3. Display record\n");
        printf("4. Display all records\n");
        printf("5. Exit\n\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);

                printf("Enter name: ");
                scanf("%s", name);

                printf("Enter age: ");
                scanf("%d", &age);

                printf("Enter salary: ");
                scanf("%f", &salary);

                addRecord(id, name, age, salary);
                break;

            case 2:
                printf("Enter ID: ");
                scanf("%d", &id);

                removeRecord(id);
                break;

            case 3:
                printf("Enter ID: ");
                scanf("%d", &id);

                displayRecord(id);
                break;

            case 4:
                displayAllRecords();
                break;

            case 5:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }

    } while(choice != 5);

    return 0;
}