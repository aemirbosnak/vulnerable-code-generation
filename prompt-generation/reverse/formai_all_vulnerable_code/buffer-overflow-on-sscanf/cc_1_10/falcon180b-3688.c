//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Define the data structure
typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

// Function to read the data from a CSV file
void read_data(Employee *employees, int *num_employees, FILE *fp) {
    char line[100];
    fgets(line, sizeof(line), fp); // Read the header line
    int i = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%d,%s,%d,%f", &employees[i].id, employees[i].name, &employees[i].age, &employees[i].salary);
        i++;
    }
    *num_employees = i;
}

// Function to sort the data by age
void sort_by_age(Employee *employees, int num_employees) {
    for (int i = 0; i < num_employees - 1; i++) {
        for (int j = i + 1; j < num_employees; j++) {
            if (employees[i].age > employees[j].age) {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

// Function to calculate the average salary
float calc_avg_salary(Employee *employees, int num_employees) {
    float sum = 0;
    for (int i = 0; i < num_employees; i++) {
        sum += employees[i].salary;
    }
    return sum / num_employees;
}

int main() {
    FILE *fp;
    Employee employees[100];
    int num_employees = 0;

    // Open the CSV file
    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: unable to open file.\n");
        exit(1);
    }

    // Read the data from the CSV file
    read_data(employees, &num_employees, fp);

    // Close the CSV file
    fclose(fp);

    // Sort the data by age
    sort_by_age(employees, num_employees);

    // Calculate the average salary
    float avg_salary = calc_avg_salary(employees, num_employees);

    // Print the results
    printf("Number of employees: %d\n", num_employees);
    printf("Average salary: %.2f\n", avg_salary);

    return 0;
}