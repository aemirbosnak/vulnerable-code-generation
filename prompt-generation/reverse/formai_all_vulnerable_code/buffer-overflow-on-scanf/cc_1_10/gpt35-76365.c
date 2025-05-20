//FormAI DATASET v1.0 Category: Database simulation ; Style: realistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 100

struct Employee {
    char name[20];
    int age;
    float salary;
};

struct Database {
    struct Employee employees[MAX_SIZE];
    int index;
};

struct Database initiate_db() {
    struct Database db;
    db.index = 0;
    return db;
}

void add_employee(struct Database *db, struct Employee emp) {
    if(db->index >= MAX_SIZE) {
        printf("Database is full. Cannot add more employees.\n");
        return;
    }
    db->employees[db->index++] = emp;
    printf("Employee added to the database.\n");
}

void print_employees(struct Database db) {
    printf("Name \t Age \t Salary \n");
    for(int i = 0; i < db.index; i++) {
        printf("%s \t %d \t %.2f \n", db.employees[i].name, db.employees[i].age, db.employees[i].salary);
    }
}

int main() {
    struct Database db = initiate_db();
    int option = 0;

    while(1) {
        printf("Press 1 to add employee, 2 to print employees, 3 to exit: ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                struct Employee emp;
                printf("Enter employee name: ");
                scanf("%s", emp.name);
                printf("Enter employee age: ");
                scanf("%d", &emp.age);
                printf("Enter employee salary: ");
                scanf("%f", &emp.salary);
                add_employee(&db, emp);
                break;
            }
            case 2: {
                print_employees(db);
                break;
            }
            case 3: {
                printf("Exiting program.\n");
                exit(0);
            }
            default: {
                printf("Invalid option.\n");
                break;
            }
        }
    }

    return 0;
}