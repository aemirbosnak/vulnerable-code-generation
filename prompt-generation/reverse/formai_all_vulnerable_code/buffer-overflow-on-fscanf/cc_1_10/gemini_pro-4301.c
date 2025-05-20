//GEMINI-pro DATASET v1.0 Category: File handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} employee;

int main() {
    // Open a file for writing
    FILE *fp = fopen("employees.txt", "w");

    // Check if the file was opened successfully
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Create an array of employees
    employee employees[] = {
        {"John Smith", 30, 50000.00},
        {"Jane Doe", 25, 40000.00},
        {"Mark Jones", 40, 60000.00}
    };

    // Write the array of employees to the file
    for (int i = 0; i < 3; i++) {
        fprintf(fp, "%s %d %.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    // Close the file
    fclose(fp);

    // Open the file for reading
    fp = fopen("employees.txt", "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the array of employees from the file
    for (int i = 0; i < 3; i++) {
        fscanf(fp, "%s %d %f", employees[i].name, &employees[i].age, &employees[i].salary);
    }

    // Close the file
    fclose(fp);

    // Print the array of employees
    for (int i = 0; i < 3; i++) {
        printf("%s %d %.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    return EXIT_SUCCESS;
}