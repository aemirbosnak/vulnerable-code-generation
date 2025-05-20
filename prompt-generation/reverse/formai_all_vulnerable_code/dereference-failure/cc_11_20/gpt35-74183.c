//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    char address[50];
    int age;
    double salary;
} Employee;

int main() {
    FILE *fp;
    Employee emp;
    char ch;
    int choice, id, found = 0;

    fp = fopen("employee.dat", "a+");

    if (fp == NULL) {
        printf("Error: Could not open file!");
        return 1;
    }

    do {
        printf("\nDATABASE MENU\n");
        printf("1. ADD EMPLOYEE\n");
        printf("2. SEARCH EMPLOYEE\n");
        printf("3. DISPLAY EMPLOYEES\n");
        printf("4. UPDATE EMPLOYEE\n");
        printf("5. DELETE EMPLOYEE\n");
        printf("6. EXIT\n");

        printf("Enter your choice [1-6]: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter Employee Details:\n");
                printf("ID: ");
                scanf("%d", &emp.id);

                printf("Name: ");
                scanf("%s", emp.name);

                printf("Address: ");
                scanf("%s", emp.address);

                printf("Age: ");
                scanf("%d", &emp.age);

                printf("Salary: ");
                scanf("%lf", &emp.salary);

                fwrite(&emp, sizeof(Employee), 1, fp);
                printf("\nEmployee added Successfully!\n");

                break;
            
            case 2:
                printf("\nEnter Employee ID to Search: ");
                scanf("%d", &id);

                while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
                    if (id == emp.id) {
                        printf("\nEmployee Details:\n");
                        printf("ID: %d\n", emp.id);
                        printf("Name: %s\n", emp.name);
                        printf("Address: %s\n", emp.address);
                        printf("Age: %d\n", emp.age);
                        printf("Salary: %.2lf\n", emp.salary);

                        found = 1;
                    }
                }

                if (!found) {
                    printf("Employee not Found!\n");
                }

                break;

            case 3:
                rewind(fp);
                printf("\nEMPLOYEES LIST:\n\n");
                printf("ID\t\tNAME\t\tADDRESS\t\tAGE\t\tSALARY\n");
                printf("--------------------------------------------------------\n");

                while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
                    printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2lf\n", emp.id, emp.name, emp.address, emp.age, emp.salary);
                }

                break;

            case 4:
                printf("\nEnter Employee ID to Update: ");
                scanf("%d", &id);

                rewind(fp);
                while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
                    if (id == emp.id) {
                        printf("\nEnter New Details:\n");
                        printf("Name: ");
                        scanf("%s", emp.name);

                        printf("Address: ");
                        scanf("%s", emp.address);

                        printf("Age: ");
                        scanf("%d", &emp.age);

                        printf("Salary: ");
                        scanf("%lf", &emp.salary);

                        fseek(fp, -sizeof(Employee), SEEK_CUR);
                        fwrite(&emp, sizeof(Employee), 1, fp);

                        printf("\nEmployee Details Updated Successfully!\n");

                        break;
                    }
                }

                if (!found) {
                    printf("Employee not Found!\n");
                }

                break;

            case 5:
                printf("\nEnter Employee ID to Delete: ");
                scanf("%d", &id);

                FILE *fp_temp = fopen("employee_temp.dat", "w");

                rewind(fp);
                while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
                    if (id != emp.id) {
                        fwrite(&emp, sizeof(Employee), 1, fp_temp);
                    }
                }

                fclose(fp_temp);
                remove("employee.dat");
                rename("employee_temp.dat", "employee.dat");

                printf("\nEmployee Deleted Successfully!\n");

                break;

            case 6:
                fclose(fp);
                printf("\nThank You for Using Employee Database Management System!\n");
                break;
            
            default:
                printf("Invalid choice, Please try again!\n");
        }

        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    return 0;
}