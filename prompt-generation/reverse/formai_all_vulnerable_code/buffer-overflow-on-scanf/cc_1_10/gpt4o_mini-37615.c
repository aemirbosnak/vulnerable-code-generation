//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float salary;
} Employee;

typedef struct {
    Employee employees[MAX_RECORDS];
    int count;
} Database;

// Function Prototypes
void addEmployee(Database *db);
void deleteEmployee(Database *db);
void displayEmployees(const Database *db);
void saveToFile(const Database *db, const char *filename);
void loadFromFile(Database *db, const char *filename);

int main() {
    Database db;
    db.count = 0;
    int choice;
    const char *filename = "employees.dat";

    loadFromFile(&db, filename);

    do {
        printf("\n=== Employee Database ===\n");
        printf("1. Add Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Display Employees\n");
        printf("4. Save & Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(&db);
                break;
            case 2:
                deleteEmployee(&db);
                break;
            case 3:
                displayEmployees(&db);
                break;
            case 4:
                saveToFile(&db, filename);
                printf("Database saved. Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addEmployee(Database *db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more employees.\n");
        return;
    }
    Employee emp;
    emp.id = db->count + 1; // Assign sequential IDs
    printf("Enter employee name: ");
    getchar(); // Consume newline left by previous input
    fgets(emp.name, MAX_NAME_LENGTH, stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Remove newline character
    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);
    db->employees[db->count++] = emp;
    printf("Employee added: ID=%d, Name=%s, Salary=%.2f\n", emp.id, emp.name, emp.salary);
}

void deleteEmployee(Database *db) {
    int id, found = 0;
    printf("Enter employee ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < db->count; i++) {
        if (db->employees[i].id == id) {
            found = 1;
            for (int j = i; j < db->count - 1; j++) {
                db->employees[j] = db->employees[j + 1];
            }
            db->count--;
            printf("Employee with ID %d deleted.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void displayEmployees(const Database *db) {
    if (db->count == 0) {
        printf("No employees to display.\n");
        return;
    }
    printf("\n=== Employee List ===\n");
    printf("ID\tName\t\tSalary\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%s\t%.2f\n", db->employees[i].id, db->employees[i].name, db->employees[i].salary);
    }
}

void saveToFile(const Database *db, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error saving database to file.\n");
        return;
    }
    fwrite(db, sizeof(Database), 1, file);
    fclose(file);
}

void loadFromFile(Database *db, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file) {
        fread(db, sizeof(Database), 1, file);
        fclose(file);
        printf("Database loaded from %s. %d employees found.\n", filename, db->count);
    } else {
        printf("No database file found. Starting fresh...\n");
    }
}