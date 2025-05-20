//Falcon-180B DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef struct employee {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    float salary;
} Employee;

void read_employees_from_file(Employee *employees, FILE *file) {
    int num_employees = 0;
    rewind(file);
    while (fscanf(file, "%s %s %f\n", employees[num_employees].name, employees[num_employees].address, &employees[num_employees].salary) == 3) {
        num_employees++;
    }
    printf("Read %d employees from file.\n", num_employees);
}

void write_employees_to_file(Employee *employees, FILE *file) {
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        if (employees[i].name[0]!= '\0') {
            fprintf(file, "%s %s %.2f\n", employees[i].name, employees[i].address, employees[i].salary);
        }
    }
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    FILE *file;

    // Open file for reading
    file = fopen("employees.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file for reading.\n");
        exit(1);
    }

    // Read employees from file
    read_employees_from_file(employees, file);

    // Sort employees by salary
    for (int i = 0; i < MAX_EMPLOYEES - 1; i++) {
        for (int j = i + 1; j < MAX_EMPLOYEES; j++) {
            if (employees[j].salary < employees[i].salary) {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }

    // Write employees to file
    file = fopen("employees.txt", "w");
    if (file == NULL) {
        printf("Error: could not open file for writing.\n");
        exit(1);
    }
    write_employees_to_file(employees, file);
    fclose(file);

    printf("Employees sorted by salary and written to file.\n");

    return 0;
}