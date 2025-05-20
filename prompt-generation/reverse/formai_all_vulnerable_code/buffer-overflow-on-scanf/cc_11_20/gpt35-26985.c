//FormAI DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

int main() {
    FILE *fp;
    Employee emp, emp2;
    int choice = 0;

    while (choice != 4) {
        printf("\nDatabase Simulation\n");
        printf("1. Add employee\n");
        printf("2. Display all employees\n");
        printf("3. Search employee by ID\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter employee details:\n");
                printf("ID: ");
                scanf("%d", &emp.id);
                printf("Name: ");
                scanf("%s", emp.name);
                printf("Salary: ");
                scanf("%f", &emp.salary);

                fp = fopen("employees.dat", "ab");
                fwrite(&emp, sizeof(emp), 1, fp);
                fclose(fp);

                printf("\nEmployee added successfully!\n");
                break;

            case 2:
                fp = fopen("employees.dat", "rb");
                if (fp == NULL) {
                    printf("\nNo employees found!\n");
                    break;
                }

                printf("\nAll employees:\n");
                printf("ID\tName\t\tSalary\n");
                while (fread(&emp2, sizeof(emp2), 1, fp)) {
                    printf("%d\t%s\t\t%.2f\n", emp2.id, emp2.name, emp2.salary);
                }
                fclose(fp);
                break;

            case 3:
                printf("\nEnter employee ID to search: ");
                int search_id;
                scanf("%d", &search_id);

                fp = fopen("employees.dat", "rb");
                if (fp == NULL) {
                    printf("\nNo employees found!\n");
                    break;
                }

                while (fread(&emp2, sizeof(emp2), 1, fp)) {
                    if (emp2.id == search_id) {
                        printf("\nEmployee Found:\n");
                        printf("ID\tName\t\tSalary\n");
                        printf("%d\t%s\t\t%.2f\n", emp2.id, emp2.name, emp2.salary);
                        break;
                    }
                }
                fclose(fp);
                break;

            case 4:
                printf("\nExiting database simulation...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}