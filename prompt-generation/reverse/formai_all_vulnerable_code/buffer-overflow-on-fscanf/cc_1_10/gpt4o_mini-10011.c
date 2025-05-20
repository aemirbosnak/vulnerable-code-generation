//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char address[MAX_ADDRESS_LENGTH];
    float salary;
} Employee;

// Function prototypes
void load_data(Employee employees[], int *count);
void display_data(const Employee employees[], int count);
void filter_by_age(const Employee employees[], int count, int age_limit);
void write_report(const Employee employees[], int count);

int main() {
    Employee employees[MAX_RECORDS];
    int count = 0;

    // Load employee data from the text file
    load_data(employees, &count);

    // Display the loaded data
    printf("Loaded Employee Data:\n");
    display_data(employees, count);

    // Filter employees over a certain age
    int age_limit = 30;
    printf("\nEmployees older than %d:\n", age_limit);
    filter_by_age(employees, count, age_limit);

    // Write the report to a text file
    write_report(employees, count);

    return 0;
}

void load_data(Employee employees[], int *count) {
    FILE *file = fopen("employee_data.txt", "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%d %49s %d %99[^\n] %f", 
                  &employees[*count].id, 
                  employees[*count].name, 
                  &employees[*count].age,
                  employees[*count].address,
                  &employees[*count].salary) != EOF) {
        (*count)++;
        if (*count >= MAX_RECORDS) {
            break;
        }
    }

    fclose(file);
}

void display_data(const Employee employees[], int count) {
    printf("%-5s %-20s %-5s %-30s %-10s\n", "ID", "Name", "Age", "Address", "Salary");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-5d %-30s $%-9.2f\n", 
               employees[i].id, 
               employees[i].name, 
               employees[i].age, 
               employees[i].address, 
               employees[i].salary);
    }
}

void filter_by_age(const Employee employees[], int count, int age_limit) {
    printf("%-5s %-20s %-5s %-30s %-10s\n", "ID", "Name", "Age", "Address", "Salary");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        if (employees[i].age > age_limit) {
            printf("%-5d %-20s %-5d %-30s $%-9.2f\n", 
                   employees[i].id, 
                   employees[i].name, 
                   employees[i].age, 
                   employees[i].address, 
                   employees[i].salary);
        }
    }
}

void write_report(const Employee employees[], int count) {
    FILE *file = fopen("employee_report.txt", "w");
    if (!file) {
        perror("Unable to create report file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Employee Report:\n");
    fprintf(file, "%-5s %-20s %-5s %-30s %-10s\n", "ID", "Name", "Age", "Address", "Salary");
    fprintf(file, "-----------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%-5d %-20s %-5d %-30s $%-9.2f\n", 
                employees[i].id, 
                employees[i].name, 
                employees[i].age, 
                employees[i].address, 
                employees[i].salary);
    }

    fclose(file);
    printf("Report written to employee_report.txt\n");
}