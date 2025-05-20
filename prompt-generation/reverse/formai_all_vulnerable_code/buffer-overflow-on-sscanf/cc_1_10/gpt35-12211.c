//FormAI DATASET v1.0 Category: Data mining ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100 // Maximum string length to be used in the program
#define MAX_BUF_SIZE 50 // Maximum size of the buffer to read the file

typedef struct {
    int id;
    char name[MAX_STR_LEN];
    int age;
    float salary;
} Employee; // Employee struct definition

void read_file(Employee *employees, int *n_employees) {
    FILE *fp;
    char buf[MAX_BUF_SIZE];

    fp = fopen("employee_data.txt", "r"); // Open the file for reading

    // If there is an error opening the file, print the error message and exit
    if (fp == NULL) {
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }

    // Read each line of the file and populate the Employee struct array
    while (fgets(buf, MAX_BUF_SIZE, fp) != NULL) {
        sscanf(buf, "%d,%[^,],%d,%f", &employees[*n_employees].id, employees[*n_employees].name,
               &employees[*n_employees].age, &employees[*n_employees].salary);
        (*n_employees)++;
    }

    // Close the file
    fclose(fp);
}

void print_employees(Employee *employees, int n_employees) {
    for (int i = 0; i < n_employees; i++) {
        printf("%d,%s,%d,%.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
    }
}

int main() {
    Employee employees[100]; // Array to store employee data
    int n_employees = 0; // Number of employees in the array

    read_file(employees, &n_employees); // Read the employee data from file

    printf("Employees:\n");
    print_employees(employees, n_employees);

    return 0;
}