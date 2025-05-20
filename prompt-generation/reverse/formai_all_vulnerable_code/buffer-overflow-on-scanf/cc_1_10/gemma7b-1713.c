//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 10

typedef struct Record {
    char name[20];
    int age;
    float salary;
} Record;

Record records[MAX_RECORDS];

void addRecord() {
    Record newRecord;

    printf("Enter name: ");
    scanf("%s", newRecord.name);

    printf("Enter age: ");
    scanf("%d", &newRecord.age);

    printf("Enter salary: ");
    scanf("%f", &newRecord.salary);

    records[MAX_RECORDS - 1] = newRecord;
}

void printRecords() {
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (records[i].name[0] != '\0') {
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            printf("Salary: %.2f\n", records[i].salary);
            printf("\n");
        }
    }
}

int main() {
    int choice;

    printf("Welcome to the Employee Database!\n");

    while (1) {
        printf("Enter 1 to add a record, 2 to print records, or 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                printRecords();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}