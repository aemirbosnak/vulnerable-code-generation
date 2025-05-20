//FormAI DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int age;
    float salary;
} Employee;

int main() {
    FILE *fp, *fp2;
    Employee e;
    int choice, found=0;
    char searchName[20];

    // Create a new binary file for writing
    fp = fopen("employees.dat", "wb");

    if (fp == NULL) {
        printf("Error creating file\n");
        exit(1);
    }

    // Get employee details from user and write to file
    do {
        printf("Enter employee name: ");
        scanf("%s", e.name);
        printf("Enter employee age: ");
        scanf("%d", &e.age);
        printf("Enter employee salary: ");
        scanf("%f", &e.salary);

        fwrite(&e, sizeof(Employee), 1, fp);

        printf("Do you want to add another employee? (1/0): ");
        scanf("%d", &choice);
    } while (choice == 1);

    fclose(fp);

    // Open the file for reading
    fp = fopen("employees.dat", "rb");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read the contents of the file and display them
    printf("\nEmployee Details:\n");
    while (fread(&e, sizeof(Employee), 1, fp)) {
        printf("\nName: %s\nAge: %d\nSalary: %f\n", e.name, e.age, e.salary);
    }
    printf("\n");

    fclose(fp);

    // Search for an employee by name
    printf("Enter the name of the employee you want to search: ");
    scanf("%s", searchName);

    fp = fopen("employees.dat", "rb");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Search for the employee by name and display their details
    while (fread(&e, sizeof(Employee), 1, fp)) {
        if (strcmp(e.name, searchName) == 0) {
            printf("\nName: %s\nAge: %d\nSalary: %f\n", e.name, e.age, e.salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee not found\n");
    }

    fclose(fp);

    // Copy the contents of one file to another
    fp = fopen("employees.dat", "rb");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fp2 = fopen("employee_copy.dat", "wb");

    if (fp2 == NULL) {
        printf("Error creating file\n");
        exit(1);
    }

    while (fread(&e, sizeof(Employee), 1, fp)) {
        fwrite(&e, sizeof(Employee), 1, fp2);
    }

    printf("\nContents copied to employee_copy.dat\n");

    fclose(fp);
    fclose(fp2);

    return 0;
}