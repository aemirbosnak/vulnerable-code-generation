//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void bubbleSort(Employee arr[], int n) {
    int i, j, tempID, tempSalary;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].salary < arr[j + 1].salary) {
                tempID = arr[j].id;
                tempSalary = arr[j].salary;
                arr[j].id = arr[j + 1].id;
                arr[j].salary = arr[j + 1].salary;
                arr[j + 1].id = tempID;
                arr[j + 1].salary = tempSalary;
            }
        }
    }
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int n, i;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    printf("\nEnter employee details:\n");
    for (i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        fflush(stdin);
        printf("Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strlen(employees[i].name) - 1] = '\0';
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    bubbleSort(employees, n);

    printf("\nSorted list of employees in ascending order of salary:\n");
    for (i = 0; i < n; i++) {
        printf("\nID: %d\nName: %s\nSalary: %.2f", employees[i].id, employees[i].name, employees[i].salary);
    }

    return 0;
}