//FormAI DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 50
#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[STR_SIZE];
    int age;
    float salary;
} Employee;

typedef struct {
    Employee records[MAX_RECORDS];
    int count;
} Database;

void add_employee(Database* db, Employee e) {
    if (db->count >= MAX_RECORDS) {
        printf("Database full, cannot add more employees.\n");
        return;
    }
    db->records[db->count++] = e;
    printf("Employee added successfully.\n");
}

void search_employee(Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Employee found:\n");
            printf("ID: %d\n", db->records[i].id);
            printf("Name: %s\n", db->records[i].name);
            printf("Age: %d\n", db->records[i].age);
            printf("Salary: %.2f\n", db->records[i].salary);
            return;
        }
    }
    printf("Employee not found.\n");
}

void delete_employee(Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            printf("Employee with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Employee not found.\n");
}

void list_employees(Database* db) {
    printf("Employee list:\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%s\t%d\t%.2f\n", db->records[i].id, db->records[i].name, db->records[i].age, db->records[i].salary);
    }
}

void menu() {
    printf("\nEmployee Database\n");
    printf("1. Add Employee\n");
    printf("2. Search Employee\n");
    printf("3. Delete Employee\n");
    printf("4. List Employees\n");
    printf("5. Exit\n");
    printf("Enter option: ");
}

int main() {
    Database db = {0};
    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                Employee e;
                printf("Enter employee ID: ");
                scanf("%d", &e.id);
                printf("Enter employee name: ");
                scanf("%s", e.name);
                printf("Enter employee age: ");
                scanf("%d", &e.age);
                printf("Enter employee salary: ");
                scanf("%f", &e.salary);
                add_employee(&db, e);
                break;
            }
            case 2: {
                int id;
                printf("Enter employee ID to search: ");
                scanf("%d", &id);
                search_employee(&db, id);
                break;
            }
            case 3: {
                int id;
                printf("Enter employee ID to delete: ");
                scanf("%d", &id);
                delete_employee(&db, id);
                break;
            }
            case 4:
                list_employees(&db);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
                break;
        }
    }
    return 0;
}