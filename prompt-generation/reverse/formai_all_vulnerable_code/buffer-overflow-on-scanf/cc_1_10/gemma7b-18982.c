//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[50];
    int age;
    double salary;
} Record;

Record records[MAX_RECORDS];

void initializeRecords() {
    for (int i = 0; i < MAX_RECORDS; i++) {
        records[i].name[0] = '\0';
        records[i].age = 0;
        records[i].salary = 0.0;
    }
}

void addRecord() {
    Record newRecord;

    printf("Enter name: ");
    scanf("%s", newRecord.name);

    printf("Enter age: ");
    scanf("%d", &newRecord.age);

    printf("Enter salary: ");
    scanf("%lf", &newRecord.salary);

    int i = 0;
    while (records[i].name[0] != '\0') {
        i++;
    }

    records[i] = newRecord;
}

void printRecords() {
    for (int i = 0; records[i].name[0] != '\0'; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Age: %d\n", records[i].age);
        printf("Salary: %.2lf\n", records[i].salary);
        printf("--------------------\n");
    }
}

int main() {
    initializeRecords();

    char choice;

    printf("Enter 'a' to add a record, 'p' to print records: ");
    scanf("%c", &choice);

    switch (choice) {
        case 'a':
            addRecord();
            break;
        case 'p':
            printRecords();
            break;
        default:
            printf("Invalid input.\n");
    }

    return 0;
}