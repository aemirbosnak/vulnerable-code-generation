//FormAI DATASET v1.0 Category: Database querying ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char address[50];
    int age;
    float salary;
} Employee;

void InsertData(Employee *e, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter employee %d details:\n", i + 1);
        printf("Name: ");
        scanf("%s", e[i].name);
        printf("Address: ");
        scanf("%s", e[i].address);
        printf("Age: ");
        scanf("%d", &e[i].age);
        printf("Salary: ");
        scanf("%f", &e[i].salary);
    }
}

void DisplayData(Employee *e, int n) {
    printf("\nEmployee Details:\n");
    printf("------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", e[i].name);
        printf("Address: %s\n", e[i].address);
        printf("Age: %d\n", e[i].age);
        printf("Salary: %.2f\n", e[i].salary);
        printf("------------------------------\n");
    }
}

void SortData(Employee *e, int n) {
    Employee temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(e[i].name, e[j].name) > 0) {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    Employee *e = (Employee *)malloc(n * sizeof(Employee));
    InsertData(e, n);
    DisplayData(e, n);
    SortData(e, n);
    printf("\nSorted Employee Details:\n");
    printf("------------------------------\n");
    DisplayData(e, n);
    free(e);
    return 0;
}