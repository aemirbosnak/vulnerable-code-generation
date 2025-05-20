//FormAI DATASET v1.0 Category: Database simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 

struct employee {
    int id;
    char name[20];
    int age;
    int salary;
};

struct table {
    int record_count;
    struct employee records[MAX_RECORDS];
};

// Function to add a new employee record to the database
void add_record(struct table *t) {
    if (t->record_count >= MAX_RECORDS) {
        printf("Cannot add record. Maximum limit reached.\n");
        return;
    }

    struct employee new_record;

    printf("Enter ID: ");
    scanf("%d", &new_record.id);

    printf("Enter Name: ");
    scanf("%s", &new_record.name);

    printf("Enter Age: ");
    scanf("%d", &new_record.age);

    printf("Enter Salary: ");
    scanf("%d", &new_record.salary);

    t->records[t->record_count++] = new_record;
}

// Function to print all employee records in the database
void print_records(struct table *t) {
    if (t->record_count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("ID\tName\tAge\tSalary\n");

    for (int i = 0; i < t->record_count; i++) {
        printf("%d\t%s\t%d\t%d\n", 
               t->records[i].id, 
               t->records[i].name, 
               t->records[i].age, 
               t->records[i].salary);
    }
}

// Function to search for an employee record based on ID
void search_record(struct table *t) {
    if (t->record_count == 0) {
        printf("No records found.\n");
        return;
    }

    int search_id;
    printf("Enter ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < t->record_count; i++) {
        if (t->records[i].id == search_id) {
            printf("ID\tName\tAge\tSalary\n");
            printf("%d\t%s\t%d\t%d\n", 
                   t->records[i].id, 
                   t->records[i].name, 
                   t->records[i].age, 
                   t->records[i].salary);
            return;
        }
    }

    printf("Record not found.\n");
}

// Function to delete an employee record based on ID
void delete_record(struct table *t) {
    if (t->record_count == 0) {
        printf("No records found.\n");
        return;
    }

    int delete_id;
    printf("Enter ID to delete: ");
    scanf("%d", &delete_id);

    for (int i = 0; i < t->record_count; i++) {
        if (t->records[i].id == delete_id) {
            for (int j = i; j < t->record_count - 1; j++) {
                t->records[j] = t->records[j+1];
            }
            t->record_count--;
            printf("Record with ID %d deleted successfully.\n", delete_id);
            return;
        }
    }

    printf("Record not found.\n");
}

// Function to update an employee record based on ID
void update_record(struct table *t) {
    if (t->record_count == 0) {
        printf("No records found.\n");
        return;
    }

    int update_id;
    printf("Enter ID to update: ");
    scanf("%d", &update_id);

    for (int i = 0; i < t->record_count; i++) {
        if (t->records[i].id == update_id) {
            printf("Enter New Name: ");
            scanf("%s", &t->records[i].name);

            printf("Enter New Age: ");
            scanf("%d", &t->records[i].age);

            printf("Enter New Salary: ");
            scanf("%d", &t->records[i].salary);

            printf("Record with ID %d updated successfully.\n", update_id);
            return;
        }
    }

    printf("Record not found.\n");
}

int main() {
    struct table employee_table;
    employee_table.record_count = 0;

    int choice;

    while (1) {
        printf("Please select an option:\n");
        printf("1. Add Record\n");
        printf("2. Print Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Update Record\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record(&employee_table);
                break;

            case 2:
                print_records(&employee_table);
                break;

            case 3:
                search_record(&employee_table);
                break;

            case 4:
                delete_record(&employee_table);
                break;

            case 5:
                update_record(&employee_table);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}