//FormAI DATASET v1.0 Category: File handling ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee {
    char name[50];
    int age;
    float salary;
};

int main() {
    FILE *fp; // File pointer
    int choice=0;

    do {
        printf("\nSelect an option:\n1. Append data\n2. Display data\n3. Exit\n\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                fp = fopen("employees.txt", "a");
                if (fp == NULL) {
                    printf("\nError opening file!\n");
                    exit(EXIT_FAILURE);
                }

                struct employee new_emp;
                printf("\nEnter name:\n");
                scanf("%s", new_emp.name);
                printf("Enter age:\n");
                scanf("%d", &new_emp.age);
                printf("Enter salary:\n");
                scanf("%f", &new_emp.salary);

                fprintf(fp, "%s %d %.2f\n", new_emp.name, new_emp.age, new_emp.salary);
                printf("\nData added to file successfully!\n");
                fclose(fp);
                break;

            case 2:
                fp = fopen("employees.txt", "r");
                if (fp == NULL) {
                    printf("\nError opening file!\n");
                    exit(EXIT_FAILURE);
                }

                printf("\n Name\t\t Age\t\t Salary\n");
                printf(" ---------------------------------\n");

                char line[100];
                while (fgets(line, sizeof(line), fp)) {
                    char *token = strtok(line, " ");
                    printf(" %s\t", token);
                    token = strtok(NULL, " ");
                    printf("\t %s\t", token);
                    token = strtok(NULL, " ");
                    printf("\t %s\n", token);
                }

                fclose(fp);
                break;

            case 3:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice. Please enter a valid choice.");
        }

    } while (choice != 3);

    return 0;
}