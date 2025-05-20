//MISTRAL-7B DATASET v1.0 Category: Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[MAX_SIZE];
    float salary;
} Employee;

int main() {
    Employee employees[MAX_SIZE];
    int n, i;
    char searchName[MAX_SIZE];
    float searchSalary;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    printf("\nEnter Employee Details:\n");
    for (i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        scanf("%d", &employees[i].id);
        fflush(stdin);
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';
        scanf("%f", &employees[i].salary);
    }

    printf("\nSearch Employee:\n");
    printf("Enter name or salary to search: ");
    scanf("%s%f", searchName, &searchSalary);

    int found = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(searchName, employees[i].name) == 0) {
            printf("Employee %d with ID %d and salary %f found.\n", i + 1, employees[i].id, employees[i].salary);
            found = 1;
            break;
        } else if (employees[i].salary == searchSalary) {
            printf("Employee %d with ID %d and salary %f found.\n", i + 1, employees[i].id, employees[i].salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No employee found with given name or salary.\n");
    }

    return 0;
}