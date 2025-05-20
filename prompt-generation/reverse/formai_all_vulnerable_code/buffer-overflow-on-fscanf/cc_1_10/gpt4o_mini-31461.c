//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_FIELD_LENGTH 256

typedef struct {
    char name[MAX_FIELD_LENGTH];
    int age;
    float salary;
} Employee;

void loadEmployees(const char *filename, Employee employees[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (*count < MAX_RECORDS && fscanf(file, "%[^,],%d,%f\n", employees[*count].name, &employees[*count].age, &employees[*count].salary) == 3) {
        (*count)++;
    }
    
    fclose(file);
}

void filterByAge(const Employee employees[], int count, int minAge, int maxAge) {
    printf("Employees aged between %d and %d:\n", minAge, maxAge);
    printf("Name\t\tAge\tSalary\n");
    for (int i = 0; i < count; i++) {
        if (employees[i].age >= minAge && employees[i].age <= maxAge) {
            printf("%s\t%d\t%.2f\n", employees[i].name, employees[i].age, employees[i].salary);
        }
    }
}

void calculateAverageSalary(const Employee employees[], int count) {
    float totalSalary = 0.0f;
    for (int i = 0; i < count; i++) {
        totalSalary += employees[i].salary;
    }
    float averageSalary = count ? totalSalary / count : 0.0f;
    printf("Average Salary of Employees: %.2f\n", averageSalary);
}

void sortEmployeesBySalary(Employee employees[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (employees[j].salary > employees[j + 1].salary) {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
    printf("Employees sorted by Salary:\n");
    printf("Name\t\tAge\tSalary\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <data_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Employee employees[MAX_RECORDS];
    int employeeCount = 0;
    
    loadEmployees(argv[1], employees, &employeeCount);
    filterByAge(employees, employeeCount, 30, 50);
    calculateAverageSalary(employees, employeeCount);
    sortEmployeesBySalary(employees, employeeCount);

    return 0;
}