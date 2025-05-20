//FormAI DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct database {
    int id;
    char name[50];
    int age;
    float salary;
};

struct database employee[MAX_SIZE];
int count = 0;

void add_employee() {
    if(count < MAX_SIZE) {
        printf("Enter employee ID: ");
        scanf("%d", &employee[count].id);
        printf("Enter employee name: ");
        scanf("%s", employee[count].name);
        printf("Enter employee age: ");
        scanf("%d", &employee[count].age);
        printf("Enter employee salary: ");
        scanf("%f", &employee[count].salary);
        count++;
    } else {
        printf("Database full!\n");
    }
}

void display_employee(int id) {
    for(int i = 0; i < count; i++) {
        if(employee[i].id == id) {
            printf("ID: %d\n", employee[i].id);
            printf("Name: %s\n", employee[i].name);
            printf("Age: %d\n", employee[i].age);
            printf("Salary: %.2f\n", employee[i].salary);
            return;
        }
    }
    printf("Employee not found!\n"); 
}

void display_all_employees() {
    for(int i = 0; i < count; i++) {
        printf("ID: %d\n", employee[i].id);
        printf("Name: %s\n", employee[i].name);
        printf("Age: %d\n", employee[i].age);
        printf("Salary: %.2f\n\n", employee[i].salary);
    }
}

void remove_employee(int id) {
    for(int i = 0; i < count; i++) {
        if(employee[i].id == id) {
            for(int j = i; j < count-1; j++) {
                employee[j] = employee[j+1];
            }
            count--;
            printf("Employee removed successfully!\n");
            return;
        }
    }
    printf("Employee not found!\n");
}

int main() {
    int option = 0;
    int id = 0;
    while(option != 5) {
        printf("Choose an option:\n");
        printf("1. Add employee\n");
        printf("2. Display employee\n");
        printf("3. Display all employees\n");
        printf("4. Remove employee\n");
        printf("5. Exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_employee();
                break;
            case 2:
                printf("Enter employee ID: ");
                scanf("%d", &id);
                display_employee(id);
                break;
            case 3:
                display_all_employees();
                break;
            case 4:
                printf("Enter employee ID: ");
                scanf("%d", &id);
                remove_employee(id);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}