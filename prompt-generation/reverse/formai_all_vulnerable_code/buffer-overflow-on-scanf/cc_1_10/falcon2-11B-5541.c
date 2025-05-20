//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char name[MAX_LINE_LENGTH];
    int age;
    float salary;
} Employee;

typedef struct {
    Employee* employees;
    int num_employees;
    int* indices;
    int* frequencies;
} Pattern;

void print_employee(Employee* employee) {
    printf("%s, %d, %f\n", employee->name, employee->age, employee->salary);
}

void print_pattern(Pattern* pattern) {
    printf("Number of employees: %d\n", pattern->num_employees);
    for (int i = 0; i < pattern->num_employees; i++) {
        printf("Employee %d: %s, %d, %f\n", i, pattern->employees[i].name, pattern->employees[i].age, pattern->employees[i].salary);
    }
}

void print_frequency_table(int* frequencies, int num_employees) {
    for (int i = 0; i < num_employees; i++) {
        printf("%s: %d\n", (i? "and " : ""), frequencies[i]);
    }
}

void find_patterns(Employee* employees, int num_employees, int* indices, int* frequencies) {
    Pattern patterns[100];
    int num_patterns = 0;

    for (int i = 0; i < num_employees; i++) {
        if (indices[i] == -1) {
            Employee employee = employees[i];
            int index = num_patterns;
            patterns[index].employees = (Employee*)realloc(patterns[index].employees, (num_patterns + 1) * sizeof(Employee));
            patterns[index].employees[num_patterns] = employee;
            patterns[index].num_employees++;
            indices[i] = index;
            frequencies[index]++;
        }
    }

    for (int i = 0; i < num_patterns; i++) {
        int num_matches = 0;
        int num_unique = 0;

        for (int j = 0; j < num_employees; j++) {
            if (indices[j] == i) {
                num_matches++;
                if (patterns[i].employees[num_patterns - 1].name!= employees[j].name) {
                    num_unique++;
                }
            }
        }

        if (num_matches > 1) {
            printf("Pattern %d: %d employees, %d unique\n", i, num_matches, num_unique);
            print_pattern(&patterns[i]);
        }
    }
}

int main() {
    Employee employees[100];
    int num_employees = 0;

    while (scanf("%s %d %f", employees[num_employees].name, &employees[num_employees].age, &employees[num_employees].salary)!= EOF) {
        num_employees++;
    }

    int indices[num_employees];
    int frequencies[num_employees];

    for (int i = 0; i < num_employees; i++) {
        indices[i] = -1;
        frequencies[i] = 0;
    }

    find_patterns(employees, num_employees, indices, frequencies);

    for (int i = 0; i < num_employees; i++) {
        printf("%s: %d\n", employees[i].name, frequencies[indices[i]]);
    }

    return 0;
}