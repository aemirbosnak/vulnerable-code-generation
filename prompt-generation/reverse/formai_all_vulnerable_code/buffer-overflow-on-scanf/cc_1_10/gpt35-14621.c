//FormAI DATASET v1.0 Category: Database simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100

typedef struct {
    char name[20];
    int age;
    float salary;
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void add_record() {
    Record new_record;
    printf("Enter name: ");
    scanf("%s", new_record.name);
    printf("Enter age: ");
    scanf("%d", &new_record.age);
    printf("Enter salary: ");
    scanf("%f", &new_record.salary);
    database[num_records++] = new_record;
    printf("Record added successfully.\n");
}

void search_record() {
    char search_name[20];
    int found = 0;
    printf("Enter name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, search_name) == 0) {
            printf("Name: %s\nAge: %d\nSalary: %.2f\n", database[i].name, database[i].age, database[i].salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record not found.\n");
    }
}

void delete_record() {
    char delete_name[20];
    int found = 0;
    printf("Enter name to delete: ");
    scanf("%s", delete_name);
    for (int i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, delete_name) == 0) {
            for (int j = i; j < num_records - 1; j++) {
                database[j] = database[j+1];
            }
            num_records--;
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Record deleted successfully.\n");
    } else {
        printf("Record not found.\n");
    }
}

void print_database() {
    for (int i = 0; i < num_records; i++) {
        printf("Name: %s\nAge: %d\nSalary: %.2f\n\n", database[i].name, database[i].age, database[i].salary);
    }
}

int main() {
    int choice;
    printf("Welcome to the database simulation program.\n");
    while (1) {
        printf("Choose an action:\n");
        printf("1. Add record\n");
        printf("2. Search record\n");
        printf("3. Delete record\n");
        printf("4. Print database\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                search_record();
                break;
            case 3:
                delete_record();
                break;
            case 4:
                print_database();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}