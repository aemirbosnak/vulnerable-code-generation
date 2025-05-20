//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10
#define RECORD_SIZE 100

typedef struct {
    char name[50];
    int age;
    float salary;
} Record;

Record database[MAX_RECORDS];
int count = 0;

void create(Record record) {
    if (count < MAX_RECORDS) {
        database[count] = record;
        count++;
        printf("Record created successfully.\n");
    } else {
        printf("Database is full.\n");
    }
}

void read(int index) {
    if (index >= 0 && index < count) {
        printf("Name: %s\n", database[index].name);
        printf("Age: %d\n", database[index].age);
        printf("Salary: %.2f\n", database[index].salary);
    } else {
        printf("Invalid index.\n");
    }
}

void update(int index, Record newRecord) {
    if (index >= 0 && index < count) {
        database[index] = newRecord;
        printf("Record updated successfully.\n");
    } else {
        printf("Invalid index.\n");
    }
}

void delete(int index) {
    if (index >= 0 && index < count) {
        for (int i = index; i < count - 1; i++) {
            database[i] = database[i + 1];
        }
        count--;
        printf("Record deleted successfully.\n");
    } else {
        printf("Invalid index.\n");
    }
}

int main() {
    Record newRecord;
    int choice, index;

    printf("Database Management System\n");

    while (1) {
        printf("\n1. Create\n2. Read\n3. Update\n4. Delete\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", newRecord.name);
                printf("Enter age: ");
                scanf("%d", &newRecord.age);
                printf("Enter salary: ");
                scanf("%f", &newRecord.salary);
                create(newRecord);
                break;
            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                read(index);
                break;
            case 3:
                printf("Enter index: ");
                scanf("%d", &index);
                printf("Enter new name: ");
                scanf("%s", newRecord.name);
                printf("Enter new age: ");
                scanf("%d", &newRecord.age);
                printf("Enter new salary: ");
                scanf("%f", &newRecord.salary);
                update(index, newRecord);
                break;
            case 4:
                printf("Enter index: ");
                scanf("%d", &index);
                delete(index);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}