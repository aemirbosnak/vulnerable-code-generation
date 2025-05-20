//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct employee {
   char name[30];
   int id;
   int age;
   float salary;
} Employee;

int main() {
    int option, num, i, j, flag;
    Employee *database = NULL;

    printf("Welcome to the Employee Database Simulation Program!\n");

    while(1) {
        printf("\nEnter the number of employees you want to add: ");
        scanf("%d", &num);

        if(num <= 0) {
            printf("Invalid number of employees entered. Please enter a number greater than zero.\n");
            continue;
        }

        if(database == NULL) {
            database = (Employee *) malloc(sizeof(Employee)*num);
        } else {
            database = (Employee *) realloc(database, sizeof(Employee) * (num + i));
        }

        if(database == NULL) {
            printf("Sorry, insufficient memory. Try again later.");
            exit(0);
        }

        for(j = i; j < i + num; ++j) {
            printf("\nEnter details of employee #%d:\n", j+1);
            printf("\tName: ");
            scanf("%s", database[j].name);
            printf("\tID: ");
            scanf("%d", &database[j].id);
            printf("\tAge: ");
            scanf("%d", &database[j].age);
            printf("\tSalary: ");
            scanf("%f", &database[j].salary);
        }

        i += num;

        printf("\nPress 1 to add more employees, 2 to search an employee, 3 to delete an employee, 4 to display database, 5 to update an employee's details, and 6 to exit: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                continue;
                break;
            case 2:
                printf("\nEnter ID of employee you want to search: ");
                int id;
                scanf("%d", &id);
                flag = 0;
                for(j = 0; j < i; ++j) {
                    if(id == database[j].id) {
                        printf("\nEmployee found:\n");
                        printf("\tName: %s\n\tID: %d\n\tAge: %d\n\tSalary: %.2f", database[j].name, database[j].id, database[j].age, database[j].salary);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                    printf("\nSorry, employee with ID %d not found.", id);
                break;
            case 3:
                printf("\nEnter ID of employee you want to delete: ");
                scanf("%d", &id);
                flag = 0;
                for(j = 0; j < i; ++j) {
                    if(id == database[j].id) {
                        flag = 1;
                        for(int k = j; k < i - 1; ++k) {
                            database[k] = database[k+1];
                        }
                        i--;
                        database = (Employee *)realloc(database, sizeof(Employee)*i);

                        printf("\nEmployee with ID %d deleted successfully!", id);
                    }
                }
                if(flag == 0)
                    printf("\nSorry, employee with ID %d not found.", id);
                break;
            case 4:
                printf("\nThe database contains %d employees:\n", i);
                for(j = 0; j < i; ++j) {
                    printf("\nEmployee #%d:\n", j+1);
                    printf("\tName: %s\n\tID: %d\n\tAge: %d\n\tSalary: %.2f", database[j].name, database[j].id, database[j].age, database[j].salary);
                }
                break;
            case 5:
                printf("\nEnter ID of employee you want to update: ");
                scanf("%d", &id);
                flag = 0;
                for(j = 0; j < i; ++j) {
                    if(id == database[j].id) {
                        printf("\nEnter updated details of employee #%d:\n", id);
                        printf("\tName: ");
                        scanf("%s", database[j].name);
                        printf("\tAge: ");
                        scanf("%d", &database[j].age);
                        printf("\tSalary: ");
                        scanf("%f", &database[j].salary);
                        flag = 1;
                    }
                }
                if(flag == 0)
                    printf("\nSorry, employee with ID %d not found.", id);
                break;
            case 6:
                printf("\nThank you for using the Employee Database Simulation Program!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid input, please try again.");
                break;
        }
    }

    return 0;
}