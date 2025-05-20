//Falcon-180B DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[50];
    int id;
    float salary;
};

void write_to_file(struct Employee *employee, FILE *file) {
    fprintf(file, "%s %d %.2f\n", employee->name, employee->id, employee->salary);
}

struct Employee read_from_file(FILE *file) {
    struct Employee employee;
    fscanf(file, "%s %d %.2f", employee.name, &employee.id, &employee.salary);
    return employee;
}

int main() {
    FILE *file;
    struct Employee employee;
    char choice;

    file = fopen("employees.txt", "a+");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    do {
        printf("\n1. Add employee\n2. Read employees\n3. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter employee name: ");
                scanf("%s", employee.name);
                printf("Enter employee ID: ");
                scanf("%d", &employee.id);
                printf("Enter employee salary: ");
                scanf("%f", &employee.salary);
                write_to_file(&employee, file);
                printf("Employee added successfully\n");
                break;

            case '2':
                rewind(file);
                while (!feof(file)) {
                    employee = read_from_file(file);
                    printf("%s %d %.2f\n", employee.name, employee.id, employee.salary);
                }
                break;

            case '3':
                fclose(file);
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice!= '3');

    return 0;
}