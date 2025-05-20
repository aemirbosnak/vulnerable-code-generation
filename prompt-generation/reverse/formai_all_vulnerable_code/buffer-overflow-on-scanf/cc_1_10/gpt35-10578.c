//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct {
    char *name;
    int age;
    float salary;
} Employee;

int main() {
    char filename[MAX_BUFFER_SIZE];
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    FILE *file = fopen(filename, "r");

    // Check if file was opened successfully
    if (file == NULL) {
        printf("Failed to open file %s\n", filename);
        return 1;
    }

    // Read the header line
    char header[MAX_BUFFER_SIZE];
    fgets(header, MAX_BUFFER_SIZE, file);

    // Initialize employee array
    int num_employees = 0;
    Employee employees[MAX_BUFFER_SIZE];

    // Loop through each line and read employee data
    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, MAX_BUFFER_SIZE, file)) {
        // Split the line into tokens
        char *token;
        char *tokens[3];
        token = strtok(buffer, ",");
        int i = 0;
        while (token != NULL) {
            tokens[i++] = token;
            token = strtok(NULL, ",");
        }

        // Parse employee data
        Employee employee;
        employee.name = tokens[0];
        employee.age = atoi(tokens[1]);
        employee.salary = atof(tokens[2]);
        employees[num_employees] = employee;

        // Increment the number of employees
        num_employees++;
    }

    // Close the file
    fclose(file);

    // Print the employee data
    printf("Name,Age,Salary\n");
    for (int i = 0; i < num_employees; i++) {
        printf("%s,%d,%.02f\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    return 0;
}