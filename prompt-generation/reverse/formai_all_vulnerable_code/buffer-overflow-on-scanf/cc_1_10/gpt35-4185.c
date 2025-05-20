//FormAI DATASET v1.0 Category: Educational ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    float salary;
} Employee;

void print_employee(Employee emp) {
    printf("%s is %d years old and earns $%.2f a year.\n", emp.name, emp.age, emp.salary);
}

int main() {
    Employee emp1 = {"John Doe", 25, 50000.00};
    Employee emp2 = {"Jane Smith", 30, 75000.00};
    Employee emp3 = {"Bob Johnson", 45, 100000.00};

    int selection;
    do {
        printf("Select an employee to view information:\n");
        printf("1. %s\n", emp1.name);
        printf("2. %s\n", emp2.name);
        printf("3. %s\n", emp3.name);
        printf("4. Quit\n");

        scanf("%d", &selection);

        switch(selection) {
            case 1:
                print_employee(emp1);
                break;
            case 2:
                print_employee(emp2);
                break;
            case 3:
                print_employee(emp3);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid selection.\n");
                break;
        }

    } while(selection != 4);
    
    return 0;
}