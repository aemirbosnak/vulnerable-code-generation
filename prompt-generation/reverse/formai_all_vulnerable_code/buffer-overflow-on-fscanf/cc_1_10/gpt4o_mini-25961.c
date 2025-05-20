//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define DB_FILENAME "database.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float salary;
} Employee;

Employee database[MAX_RECORDS];
int record_count = 0;

void load_database();
void save_database();
void add_employee();
void display_database();
void search_employee();
void delete_employee();

int main() {
    int choice;

    load_database();

    do {
        printf("\n--- Employee Database Management ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                display_database();
                break;
            case 3:
                search_employee();
                break;
            case 4:
                delete_employee();
                break;
            case 5:
                save_database();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void load_database() {
    FILE *file = fopen(DB_FILENAME, "r");
    if (file == NULL) {
        printf("No existing database found, starting fresh.\n");
        return;
    }
    while (fscanf(file, "%d %49s %f", &database[record_count].id, database[record_count].name, &database[record_count].salary) == 3) {
        record_count++;
        if (record_count >= MAX_RECORDS) {
            break;
        }
    }
    fclose(file);
}

void save_database() {
    FILE *file = fopen(DB_FILENAME, "w");
    for (int i = 0; i < record_count; i++) {
        fprintf(file, "%d %s %.2f\n", database[i].id, database[i].name, database[i].salary);
    }
    fclose(file);
}

void add_employee() {
    if (record_count >= MAX_RECORDS) {
        printf("Database is full, cannot add more employees.\n");
        return;
    }
    Employee emp;
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Employee Name: ");
    scanf("%s", emp.name);
    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);
    database[record_count] = emp;
    record_count++;
    printf("Employee added successfully!\n");
}

void display_database() {
    if (record_count == 0) {
        printf("No employees in the database.\n");
        return;
    }
    printf("\n--- Employee List ---\n");
    for (int i = 0; i < record_count; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", database[i].id, database[i].name, database[i].salary);
    }
}

void search_employee() {
    int id;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            printf("Employee found: ID: %d, Name: %s, Salary: %.2f\n", database[i].id, database[i].name, database[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void delete_employee() {
    int id, i, j;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            for (j = i; j < record_count - 1; j++) {
                database[j] = database[j + 1]; // Shift records left
            }
            record_count--;
            printf("Employee with ID %d deleted successfully!\n", id);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}