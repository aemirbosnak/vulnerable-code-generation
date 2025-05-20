//FormAI DATASET v1.0 Category: Database simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[50];
    int age;
    double salary;
} Record;

void display_menu() {
    printf("Database Management System\n");
    printf("1. Add record\n");
    printf("2. Delete record\n");
    printf("3. Search record\n");
    printf("4. Display all records\n");
    printf("5. Exit\n");
}

int add_record(Record* records, int* num_records) {
    if (*num_records >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached\n");
        return -1;
    }
    Record new_record;
    printf("Enter record details:\n");
    printf("ID: ");
    scanf("%d", &new_record.id);
    printf("Name: ");
    scanf("%s", new_record.name);
    printf("Age: ");
    scanf("%d", &new_record.age);
    printf("Salary: ");
    scanf("%lf", &new_record.salary);
    records[*num_records] = new_record;
    *num_records += 1;
    printf("Record added successfully!\n");
    return 0;
}

int delete_record(Record* records, int* num_records) {
    int id, i, j, found = 0;
    printf("Enter ID of record to delete: ");
    scanf("%d", &id);
    for (i = 0; i < *num_records; i++) {
        if (records[i].id == id) {
            found = 1;
            for (j = i; j < *num_records - 1; j++) {
                records[j] = records[j + 1];
            }
            *num_records -= 1;
            printf("Record deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Error: Record not found\n");
        return -1;
    }
    return 0;
}

int search_record(Record* records, int num_records) {
    int id, i, found = 0;
    printf("Enter ID of record to search: ");
    scanf("%d", &id);
    for (i = 0; i < num_records; i++) {
        if (records[i].id == id) {
            found = 1;
            printf("Record found:\n");
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            printf("Salary: %.2lf\n", records[i].salary);
            break;
        }
    }
    if (!found) {
        printf("Error: Record not found\n");
        return -1;
    }
    return 0;
}

void display_all_records(Record* records, int num_records) {
    int i;
    printf("==============================\n");
    printf("ID\tName\tAge\tSalary\n");
    printf("==============================\n");
    for (i = 0; i < num_records; i++) {
        printf("%d\t%s\t%d\t%.2lf\n", records[i].id, records[i].name, records[i].age, records[i].salary);
    }
    printf("==============================\n");
}

int main() {
    Record records[MAX_RECORDS];
    int num_records = 0;
    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                delete_record(records, &num_records);
                break;
            case 3:
                search_record(records, num_records);
                break;
            case 4:
                display_all_records(records, num_records);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}