//FormAI DATASET v1.0 Category: Database simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[50];
    char address[100];
    float salary;
} Employee;

typedef struct {
    Employee employees[MAX_SIZE];
    int size;
} EmployeeDatabase;

void addEmployee(EmployeeDatabase *database, int id, char *name, char *address, float salary) {
    Employee employee = {id, "", "", salary};
    strcpy(employee.name, name);
    strcpy(employee.address, address);
    database->employees[database->size++] = employee;
}

Employee *findEmployeeById(EmployeeDatabase *database, int id) {
    for(int i = 0; i < database->size; i++) {
        if(database->employees[i].id == id) {
            return &database->employees[i];
        }
    }
    return NULL;
}

void displayEmployeeDetails(Employee *employee) {
    printf("ID: %d\n", employee->id);
    printf("Name: %s\n", employee->name);
    printf("Address: %s\n", employee->address);
    printf("Salary: %.2f\n", employee->salary);
}

int main() {
    EmployeeDatabase database = { {}, 0 };
    addEmployee(&database, 1, "John", "123 Main St", 50000.00);
    addEmployee(&database, 2, "Jane", "456 High St", 60000.00);
    addEmployee(&database, 3, "Bob", "789 Park Ave", 70000.00);

    printf("Enter employee ID to search: ");
    int id;
    scanf("%d", &id);

    Employee *employee = findEmployeeById(&database, id);
    if(employee != NULL) {
        displayEmployeeDetails(employee);
    }
    else {
        printf("Employee not found.\n");
    }

    return 0;
}