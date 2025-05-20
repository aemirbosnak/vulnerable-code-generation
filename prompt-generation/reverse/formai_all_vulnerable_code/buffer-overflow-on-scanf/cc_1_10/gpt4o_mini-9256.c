//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATA_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
} Employee;

void inputEmployeeData(Employee *employees, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for employee %d: ", i + 1);
        scanf("%s", employees[i].name);
        printf("Enter age for employee %d: ", i + 1);
        scanf("%d", &employees[i].age);
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &employees[i].salary);
    }
}

void displayEmployeeData(const Employee *employees, int count) {
    printf("\nEmployee Data:\n");
    printf("%-20s %-5s %-10s\n", "Name", "Age", "Salary");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-5d %-10.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }
}

float calculateAverageSalary(const Employee *employees, int count) {
    float totalSalary = 0.0;
    for (int i = 0; i < count; i++) {
        totalSalary += employees[i].salary;
    }
    return totalSalary / count;
}

void findHighestSalary(const Employee *employees, int count) {
    float highestSalary = employees[0].salary;
    char highestEarner[MAX_NAME_LENGTH];
    strcpy(highestEarner, employees[0].name);

    for (int i = 1; i < count; i++) {
        if (employees[i].salary > highestSalary) {
            highestSalary = employees[i].salary;
            strcpy(highestEarner, employees[i].name);
        }
    }
    printf("Highest Salary: %.2f by %s\n", highestSalary, highestEarner);
}

void findAgeGroupCount(const Employee *employees, int count) {
    int ageGroup[10] = {0}; // 10 Age groups: 0-9, 10-19,..., 90-99+

    for (int i = 0; i < count; i++) {
        if (employees[i].age < 100) {
            ageGroup[employees[i].age / 10]++;
        }
    }

    printf("\nAge Group Distribution:\n");
    for (int i = 0; i < 10; i++) {
        printf("%2d-%2d: %d\n", i * 10, i * 10 + 9, ageGroup[i]);
    }
}

int main() {
    Employee employees[MAX_RECORDS];
    int count;

    printf("Enter the number of employees (Max %d): ", MAX_RECORDS);
    scanf("%d", &count);

    if (count <= 0 || count > MAX_RECORDS) {
        printf("Invalid number of employees!\n");
        return 1;
    }

    inputEmployeeData(employees, count);
    displayEmployeeData(employees, count);

    float averageSalary = calculateAverageSalary(employees, count);
    printf("\nAverage Salary: %.2f\n", averageSalary);

    findHighestSalary(employees, count);
    findAgeGroupCount(employees, count);

    return 0;
}