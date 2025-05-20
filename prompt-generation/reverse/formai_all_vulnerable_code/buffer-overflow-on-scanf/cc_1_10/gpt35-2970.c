//FormAI DATASET v1.0 Category: Database querying ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Employee structure
struct Employee {
    int id;
    char name[50];
    char department[50];
    float salary;
};

// Function to get employee details from user
void get_employee_details(struct Employee *emp) {
    printf("Enter employee id: ");
    scanf("%d", &emp->id);
    printf("Enter employee name: ");
    scanf("%s", &emp->name);
    printf("Enter employee department: ");
    scanf("%s", &emp->department);
    printf("Enter employee salary: ");
    scanf("%f", &emp->salary);
}

// Function to print employee details
void print_employee_details(struct Employee emp) {
    printf("Employee id: %d\n", emp.id);
    printf("Employee name: %s\n", emp.name);
    printf("Employee department: %s\n", emp.department);
    printf("Employee salary: %.2f\n", emp.salary);
}

// Function to search employee by id in the database
struct Employee search_by_id(struct Employee *db, int count, int id) {
    for(int i=0 ; i<count ; i++) {
        if(db[i].id == id) {
            return db[i];
        }
    }
    struct Employee emp;
    emp.id = -1; // return -1 if employee not found
    return emp;
}

// Function to search employee by department in the database
void search_by_department(struct Employee *db, int count, char department[]) {
    int found = 0;
    for(int i=0 ; i<count ; i++) {
        if(strcmp(db[i].department, department) == 0) {
            print_employee_details(db[i]);
            found = 1;
        }
    }
    if(!found) {
        printf("No employees found in %s department.\n", department);
    }
}

int main() {
    struct Employee db[100];
    int count = 0;
    int option;

    while(1) {
        // Display menu
        printf("\n1. Add employee\n");
        printf("2. Search employee by id\n");
        printf("3. Search employee by department\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                struct Employee emp;
                get_employee_details(&emp);
                db[count++] = emp;
                printf("Employee added to database.\n");
                break;
            }
            case 2: {
                int id;
                printf("Enter employee id: ");
                scanf("%d", &id);
                struct Employee emp = search_by_id(db, count, id);
                if(emp.id == -1) {
                    printf("Employee not found.\n");
                } else {
                    print_employee_details(emp);
                }
                break;
            }
            case 3: {
                char department[50];
                printf("Enter department: ");
                scanf("%s", department);
                search_by_department(db, count, department);
                break;
            }
            case 4:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}