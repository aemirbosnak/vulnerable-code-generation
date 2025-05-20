//FormAI DATASET v1.0 Category: Database querying ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int id;
    char name[50];
    int age;
    float salary;
};

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct employee *employees = (struct employee*) malloc(n * sizeof(struct employee));

    for(int i = 0; i < n; i++) {
        printf("\nEnter the details of employee %d: ", i+1);
        printf("\nEnter the ID: ");
        scanf("%d", &(employees+i)->id);
        printf("Enter the Name: ");
        scanf("%s", &(employees+i)->name);
        printf("Enter the Age: ");
        scanf("%d", &(employees+i)->age);
        printf("Enter the Salary: ");
        scanf("%f", &(employees+i)->salary);
    }

    int choice;
    printf("\nEnter the number of the selected operation: ");
    printf("\n1. Search for employees by name.");
    printf("\n2. Search for employees by age.");
    printf("\n3. Search for employees by salary.");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            char search_name[50];
            printf("\nEnter the name you want to search for: ");
            scanf("%s", search_name);

            for(int i = 0; i < n; i++) {
                if(strcmp(search_name, (employees+i)->name) == 0) {
                    printf("\nEmployee found!\n");
                    printf("ID: %d\n", (employees+i)->id);
                    printf("Name: %s\n", (employees+i)->name);
                    printf("Age: %d\n", (employees+i)->age);
                    printf("Salary: %f\n", (employees+i)->salary);
                }
            }
            break;
        }
        case 2: {
            int search_age;
            printf("\nEnter the age you want to search for: ");
            scanf("%d", &search_age);

            for(int i = 0; i < n; i++) {
                if(search_age == (employees+i)->age) {
                    printf("\nEmployee found!\n");
                    printf("ID: %d\n", (employees+i)->id);
                    printf("Name: %s\n", (employees+i)->name);
                    printf("Age: %d\n", (employees+i)->age);
                    printf("Salary: %f\n", (employees+i)->salary);
                }
            }
            break;
        }
        case 3: {
            float search_salary;
            printf("\nEnter the salary you want to search for: ");
            scanf("%f", &search_salary);

            for(int i = 0; i < n; i++) {
                if(search_salary == (employees+i)->salary) {
                    printf("\nEmployee found!\n");
                    printf("ID: %d\n", (employees+i)->id);
                    printf("Name: %s\n", (employees+i)->name);
                    printf("Age: %d\n", (employees+i)->age);
                    printf("Salary: %f\n", (employees+i)->salary);
                }
            }
            break;
        }
        default:
            printf("\nInvalid Choice.\n");
    }

    free(employees);
    return 0;
}