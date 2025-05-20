//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELDS 5

typedef struct {
    char name[MAX_FIELDS];
    int age;
    float salary;
    char address[MAX_FIELDS];
} Record;

Record database[MAX_RECORDS];
int currentRecord = 0;

void addRecord() {
    if (currentRecord >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", database[currentRecord].name);

    printf("Enter age: ");
    scanf("%d", &database[currentRecord].age);

    printf("Enter salary: ");
    scanf("%f", &database[currentRecord].salary);

    printf("Enter address: ");
    scanf("%s", database[currentRecord].address);

    currentRecord++;
    printf("Record added successfully!\n");
}

void displayDatabase() {
    if (currentRecord == 0) {
        printf("Database is empty!\n");
        return;
    }

    printf("\n%-15s %-5s %-10s %-20s\n", "Name", "Age", "Salary", "Address");
    for (int i = 0; i < currentRecord; i++) {
        printf("%-15s %-5d %-10.2f %-20s\n", database[i].name, database[i].age, database[i].salary, database[i].address);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nDatabase Simulation Program\n");
        printf("1. Add Record\n");
        printf("2. Display Database\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayDatabase();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}