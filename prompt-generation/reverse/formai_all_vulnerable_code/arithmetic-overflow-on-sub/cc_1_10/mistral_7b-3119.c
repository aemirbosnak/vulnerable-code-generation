//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100000

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void readData(Employee *employees, int size);
void swapEmployees(Employee *emp1, Employee *emp2);
void sortEmployees(Employee *employees, int size);

int main() {
    Employee *employees = malloc(MAX_SIZE * sizeof(Employee));
    int size, i;

    printf("Enter the number of employees: ");
    scanf("%d", &size);

    readData(employees, size);

    clock_t start = clock();
    sortEmployees(employees, size);
    clock_t end = clock();

    printf("Sorting took %lf milliseconds\n", (end - start) / (double)CLOCKS_PER_SEC * 1000);

    free(employees);

    return 0;
}

void readData(Employee *employees, int size) {
    for(int i = 0; i < size; i++) {
        scanf("%d %s %f", &(employees[i].id), employees[i].name, &(employees[i].salary));
    }
}

void swapEmployees(Employee *emp1, Employee *emp2) {
    Employee temp = *emp1;
    *emp1 = *emp2;
    *emp2 = temp;
}

void sortEmployees(Employee *employees, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(employees[j].salary > employees[j+1].salary) {
                swapEmployees(&employees[j], &employees[j+1]);
            }
        }
    }
}