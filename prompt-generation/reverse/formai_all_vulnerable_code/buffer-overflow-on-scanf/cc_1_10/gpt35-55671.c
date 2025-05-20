//FormAI DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

struct Employee {
    int emp_id;
    char emp_name[MAX_SIZE];
    char designation[MAX_SIZE];
    float salary;
};

void insert_record(struct Employee *emp, int *id, int *n) {
    printf("Enter Employee Name: ");
    fgets(emp[*id].emp_name, MAX_SIZE, stdin);
    printf("Enter Designation: ");
    fgets(emp[*id].designation, MAX_SIZE, stdin);
    printf("Enter Salary: ");
    scanf("%f", &emp[*id].salary);
    emp[*id].emp_id = *id;
    (*id)++;
    (*n)++;
}

void delete_record(struct Employee *emp, int id, int *n) {
    int emp_id, i, j, flag = 0;
    printf("Enter Employee ID: ");
    scanf("%d", &emp_id);
    for(i=0; i<*n; i++) {
        if(emp[i].emp_id == emp_id) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        for(j=i; j<*n-1; j++) {
            emp[j].emp_id = emp[j+1].emp_id;
            strcpy(emp[j].emp_name, emp[j+1].emp_name);
            strcpy(emp[j].designation, emp[j+1].designation);
            emp[j].salary = emp[j+1].salary;
        }
        (*n)--;
        printf("Record Deleted Successfully!\n");
    }
    else {
        printf("Record not Found!\n");
    }
}

void show_records(struct Employee *emp, int n) {
    int i;
    printf("Employee ID\tEmployee Name\tDesignation\tSalary\n");
    for(i=0; i<n; i++) {
        printf("%d\t%s\t%s\t%.2f\n", emp[i].emp_id, emp[i].emp_name, emp[i].designation, emp[i].salary);
    }
}

int main() {
    struct Employee emp[MAX_SIZE];
    int id = 0, n = 0, choice;
    char ch;
    do {
        printf("\nChoose an Operation:\n1. Add Record\n2. Delete Record\n3. Show Records\n4. Exit\n");
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1:
                insert_record(emp, &id, &n);
                break;
            case 2:
                delete_record(emp, id, &n);
                break;
            case 3:
                show_records(emp, n);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
        printf("Do you want to continue (Y/N)? ");
        scanf("%c", &ch);
        getchar();
    } while(ch=='Y' || ch=='y');
    return 0;
}