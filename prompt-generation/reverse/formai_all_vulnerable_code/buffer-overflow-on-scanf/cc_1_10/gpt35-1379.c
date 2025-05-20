//FormAI DATASET v1.0 Category: Database simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void addEmployee(Employee *db, int *size) {
    if (*size == MAX_SIZE) {
        printf("Error: database is full!\n");
        return;
    }
    printf("Enter employee ID: ");
    scanf("%d", &db[*size].id);
    printf("Enter employee name: ");
    getchar();
    fgets(db[*size].name, 50, stdin);
    printf("Enter employee salary: ");
    scanf("%f", &db[*size].salary);
    (*size)++;
}

void searchEmployee(Employee *db, int size) {
    int id, i;
    printf("Enter employee ID to search: ");
    scanf("%d", &id);
    for (i = 0; i < size; i++) {
        if (db[i].id == id) {
            printf("Employee found!\n");
            printf("ID: %d\n", db[i].id);
            printf("Name: %s", db[i].name);
            printf("Salary: $%.2f\n", db[i].salary);
            return;
        }
    }
    printf("Employee not found in database!\n");
}

void deleteEmployee(Employee *db, int *size) {
    int id, i;
    printf("Enter employee ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < *size; i++) {
        if (db[i].id == id) {
            memmove(&db[i], &db[i + 1], (*size - i - 1) * sizeof(Employee));
            (*size)--;
            printf("Employee with ID %d has been deleted from the database.\n", id);
            return;
        }
    }
    printf("Employee with ID %d not found in database!\n", id);
}

void printDatabase(Employee *db, int size) {
    int i;
    if (size == 0) {
        printf("Database is empty!\n");
        return;
    }
    printf("ID\tName\tSalary\n");
    for (i = 0; i < size; i++) {
        printf("%d\t%s\t$%.2f\n", db[i].id, db[i].name, db[i].salary);
    }
}

int main() {
    Employee db[MAX_SIZE];
    int size = 0;
    int choice = 0;
    while (choice != 5) {
        printf("\n1. Add Employee\n");
        printf("2. Search Employee\n");
        printf("3. Delete Employee\n");
        printf("4. Print Database\n");
        printf("5. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmployee(db, &size);
                break;
            case 2:
                searchEmployee(db, size);
                break;
            case 3:
                deleteEmployee(db, &size);
                break;
            case 4:
                printDatabase(db, size);
                break;
            case 5:
                printf("Quitting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}