//FormAI DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

int main() {
    FILE *fp;
    char filename[] = "employee.db";
    int menuSelection = 0;

    while (1) {
        printf("1. Add Employee\n2. View Employee\n3. Edit Employee\n4. Delete Employee\n5. Exit\n");
        scanf("%d", &menuSelection);

        switch (menuSelection) {
            case 1: {
                Employee emp;
                printf("Employee ID: ");
                scanf("%d", &emp.id);
                printf("Employee Name: ");
                scanf("%s", emp.name);
                printf("Employee Age: ");
                scanf("%d", &emp.age);
                printf("Employee Salary: ");
                scanf("%f", &emp.salary);

                fp = fopen(filename, "ab");
                if (fp == NULL) {
                    printf("Error in opening file\n");
                    exit(1);
                }

                fwrite(&emp, sizeof(Employee), 1, fp);
                printf("Employee added successfully\n");

                fclose(fp);
                break;
            }
            case 2: {
                int employeeId;
                printf("Enter employee ID to view: ");
                scanf("%d", &employeeId);

                fp = fopen(filename, "rb");
                if (fp == NULL) {
                    printf("Error in opening file\n");
                    exit(1);
                }

                Employee emp;
                int found = 0;
                while(fread(&emp, sizeof(Employee), 1, fp)==1) {
                    if (emp.id == employeeId) {
                        printf("Employee ID: %d\n", emp.id);
                        printf("Employee Name: %s\n", emp.name);
                        printf("Employee Age: %d\n", emp.age);
                        printf("Employee Salary: %f\n", emp.salary);
                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    printf("Employee not found\n");
                }

                fclose(fp);
                break;
            }
            case 3: {
                int employeeId;
                printf("Enter employee ID to edit: ");
                scanf("%d", &employeeId);

                fp = fopen(filename, "r+b");
                if (fp == NULL) {
                    printf("Error in opening file\n");
                    exit(1);
                }

                Employee emp;
                int found = 0;
                while(fread(&emp, sizeof(Employee), 1, fp)==1) {
                    if (emp.id == employeeId) {
                        printf("Employee ID: %d\n", emp.id);
                        printf("Employee Name: %s\n", emp.name);
                        printf("Employee Age: %d\n", emp.age);
                        printf("Employee Salary: %f\n", emp.salary);

                        printf("\nEnter new information:\n");
                        printf("Employee Name: ");
                        scanf("%s", emp.name);
                        printf("Employee Age: ");
                        scanf("%d", &emp.age);
                        printf("Employee Salary: ");
                        scanf("%f", &emp.salary);

                        fseek(fp, -sizeof(Employee), SEEK_CUR);
                        fwrite(&emp, sizeof(Employee), 1, fp);
                        printf("Employee information modified successfully\n");
                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    printf("Employee not found\n");
                }

                fclose(fp);
                break;
            }
            case 4: {
                int employeeId;
                printf("Enter employee ID to delete: ");
                scanf("%d", &employeeId);

                fp = fopen(filename, "rb");
                if (fp == NULL) {
                    printf("Error in opening file\n");
                    exit(1);
                }

                FILE *temp = fopen("temp.db", "wb");
                Employee emp;
                int found = 0;
                while(fread(&emp, sizeof(Employee), 1, fp)==1) {
                    if (emp.id == employeeId) {
                        printf("Employee ID: %d\n", emp.id);
                        printf("Employee Name: %s\n", emp.name);
                        printf("Employee Age: %d\n", emp.age);
                        printf("Employee Salary: %f\n", emp.salary);
                        printf("\n");

                        found = 1;
                    } else {
                        fwrite(&emp, sizeof(Employee), 1, temp);
                    }
                }

                fclose(fp);
                fclose(temp);

                if (found == 0) {
                    printf("Employee not found\n");
                    remove("temp.db");
                    break;
                }

                fp = fopen(filename, "wb");
                temp = fopen("temp.db", "rb");

                while(fread(&emp, sizeof(Employee), 1, temp)==1) {
                    fwrite(&emp, sizeof(Employee), 1, fp);
                }

                printf("Employee information deleted successfully\n");

                fclose(fp);
                fclose(temp);

                remove("temp.db");
                break;
            }
            case 5: {
                printf("Thank you for using the program\n");
                exit(0);
            }
            default: {
                printf("Invalid Selection\n");
                break;
            }
        }
    }

    return 0;
}