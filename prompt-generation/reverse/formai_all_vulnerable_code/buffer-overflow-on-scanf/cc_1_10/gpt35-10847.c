//FormAI DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int id;
    float salary;
} Employee;

int main() {
    FILE *fptr;
    char filename[20], name[30];
    int i, id, numEmployees;
    float salary;

    printf("Enter the file name: ");
    scanf("%s", filename);

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    Employee employees[numEmployees];

    // Add employees to the database
    for (i = 0; i < numEmployees; i++) {
        printf("Enter the name of employee %d: ", i+1);
        scanf("%s", name);
        strcpy(employees[i].name, name);

        printf("Enter the id of employee %d: ", i+1);
        scanf("%d", &id);
        employees[i].id = id;

        printf("Enter the salary of employee %d: ", i+1);
        scanf("%f", &salary);
        employees[i].salary = salary;
    }

    // Write the employees to the database file
    fptr = fopen(filename, "wb");
    fwrite(employees, sizeof(Employee), numEmployees, fptr);
    fclose(fptr);

    // Read the employees from the database file
    fptr = fopen(filename, "rb");
    fread(employees, sizeof(Employee), numEmployees, fptr);

    // Display the employees
    for (i = 0; i < numEmployees; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("ID: %d\n", employees[i].id);
        printf("Salary: %.2f\n", employees[i].salary);
    }

    fclose(fptr);

    return 0;
}