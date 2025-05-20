//FormAI DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 20

struct Employee {
    int id;
    char name[MAX_LEN];
    int age;
    float salary;
};

int main() {
    // Initialize the database
    struct Employee db[5];
    db[0] = (struct Employee) {1, "John", 28, 50000};
    db[1] = (struct Employee) {2, "Sarah", 32, 70000};
    db[2] = (struct Employee) {3, "Mike", 26, 40000};
    db[3] = (struct Employee) {4, "Peter", 34, 90000};
    db[4] = (struct Employee) {5, "Linda", 29, 60000};

    // Display all employees in the database
    printf("Current employees in the database:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d %s %d %.2f\n", db[i].id, db[i].name, db[i].age, db[i].salary);
    }
    printf("\n");

    // Add a new employee to the database
    struct Employee new_employee = {6, "Tom", 31, 80000};
    db[5] = new_employee;
    printf("New employee added to the database:\n");
    printf("%d %s %d %.2f\n", db[5].id, db[5].name, db[5].age, db[5].salary);
    printf("\n");

    // Update an existing employee's salary
    int employee_id = 2; // Sarah's id is 2
    for (int i = 0; i < 5; i++) {
        if (db[i].id == employee_id) {
            db[i].salary = db[i].salary * 1.1; // Increase salary by 10%
            printf("Sarah's salary updated to %.2f\n", db[i].salary);
            printf("\n");
            break;
        }
    }

    // Remove an employee from the database
    int employee_id_to_remove = 4; // Peter's id is 4
    for (int i = 0; i < 5; i++) {
        if (db[i].id == employee_id_to_remove) {
            for (int j = i; j < 5; j++) {
                db[j] = db[j+1];
            }
            printf("Employee with id %d removed from the database\n", employee_id_to_remove);
            printf("\n");
            break;
        }
    }

    // Display all employees in the database after modifications
    printf("Employees in the database after modifications:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d %s %d %.2f\n", db[i].id, db[i].name, db[i].age, db[i].salary);
    }
    printf("\n");

    return 0;
}