//FormAI DATASET v1.0 Category: Database querying ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee{
    char name[50];
    int age;
    double salary;
};

void addEmployee(struct Employee emp, FILE *fp){
    fwrite(&emp, sizeof(struct Employee), 1, fp);
}

void displayEmployees(FILE *fp){
    struct Employee emp;
    rewind(fp);
    printf("\n\nEmployee List\n");
    printf("Name\t\tAge\t\tSalary\n");
    while(fread(&emp, sizeof(struct Employee), 1, fp) == 1){
        printf("%s\t\t%d\t\t%.2f\n", emp.name, emp.age, emp.salary);
    }
}

void searchEmployee(char name[], FILE *fp){
    struct Employee emp;
    int found = 0;
    rewind(fp);
    while(fread(&emp, sizeof(struct Employee), 1, fp) == 1){
        if(strcmp(name, emp.name) == 0){
            found = 1;
            printf("\n\n");
            printf("Name\t\tAge\t\tSalary\n");
            printf("%s\t\t%d\t\t%.2f\n", emp.name, emp.age, emp.salary);
        }
    }
    if(found == 0){
        printf("\n\n Employee with name '%s' not found", name);
    }
}

void updateEmployee(char name[], FILE *fp){
    struct Employee emp;
    int found = 0;
    rewind(fp);
    while(fread(&emp, sizeof(struct Employee), 1, fp) == 1){
        if(strcmp(name, emp.name) == 0){
            found = 1;
            printf("\nEnter new name, age and salary for %s:\n", name);
            scanf("%s %d %lf", emp.name, &emp.age, &emp.salary);
            fseek(fp, -sizeof(struct Employee), SEEK_CUR);
            fwrite(&emp, sizeof(struct Employee), 1, fp);
            printf("\nRecord updated for employee: %s\n", name);
            break;
        }
    }
    if(found == 0){
        printf("\n\n Employee with name '%s' not found", name);
    }
}

void deleteEmployee(char name[], FILE *fp){
    struct Employee emp;
    FILE *temp;
    temp = fopen("temp.bin", "wb");
    rewind(fp);
    while(fread(&emp, sizeof(struct Employee), 1, fp) == 1){
        if(strcmp(name, emp.name) != 0){
            fwrite(&emp, sizeof(struct Employee), 1, temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("Employees.bin");
    rename("temp.bin", "Employees.bin");
    printf("\nRecord deleted for employee: %s\n", name);
}

int main(){
    struct Employee emp;
    int choice;
    char name[50];
    FILE *fp;
    fp = fopen("Employees.bin", "ab+");
    if(fp == NULL){
        printf("Error opening file!");
        exit(1);
    }
    while(1){
        printf("\n\n");
        printf("Employee Database\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter name, age and salary for the employee:\n");
                scanf("%s %d %lf", emp.name, &emp.age, &emp.salary);
                addEmployee(emp, fp);
                printf("\nRecord added successfully");
                break;

            case 2:
                displayEmployees(fp);
                break;

            case 3:
                printf("\nEnter name of employee to search: ");
                scanf("%s", name);
                searchEmployee(name, fp);
                break;

            case 4:
                printf("\nEnter name of employee to update: ");
                scanf("%s", name);
                updateEmployee(name, fp);
                break;

            case 5:
                printf("\nEnter name of employee to delete: ");
                scanf("%s", name);
                deleteEmployee(name, fp);
                break;

            case 6:
                fclose(fp);
                exit(0);

            default:
                printf("\n\nInvalid choice");
                break;
        }
    }
    return 0;
}