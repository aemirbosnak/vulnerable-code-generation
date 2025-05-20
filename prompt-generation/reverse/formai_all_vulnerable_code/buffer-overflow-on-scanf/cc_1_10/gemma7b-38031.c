//Gemma-7B DATASET v1.0 Category: Database querying ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct employee {
    char name[50];
    int age;
    double salary;
} employee;

// Define the function to query the database
void query_database(employee *employees, int num_employees) {
    // Get the user input
    char query[100];
    printf("Enter your query: ");
    scanf("%s", query);

    // Parse the user input
    char *keywords = strtok(query, " ");
    int num_keywords = 0;
    while (keywords) {
        num_keywords++;
        keywords = strtok(NULL, " ");
    }

    // Search for employees who match the query
    int i = 0;
    for (i = 0; i < num_employees; i++) {
        int match = 0;
        // Check if the employee's name matches the query
        if (strstr(employees[i].name, keywords) != NULL) {
            match = 1;
        }
        // Check if the employee's age matches the query
        if (employees[i].age == atoi(keywords)) {
            match = 1;
        }
        // Check if the employee's salary matches the query
        if (employees[i].salary == atof(keywords)) {
            match = 1;
        }

        // If the employee matches the query, print their information
        if (match) {
            printf("Name: %s\n", employees[i].name);
            printf("Age: %d\n", employees[i].age);
            printf("Salary: %.2lf\n", employees[i].salary);
            printf("\n");
        }
    }
}

int main() {
    // Create an array of employees
    employee employees[] = {
        {"John Doe", 25, 50000},
        {"Jane Doe", 30, 60000},
        {"Peter Pan", 12, 40000},
        {"Mary Poppins", 20, 30000}
    };

    // Get the number of employees
    int num_employees = 4;

    // Query the database
    query_database(employees, num_employees);

    return 0;
}