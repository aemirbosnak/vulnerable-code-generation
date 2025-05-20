//FormAI DATASET v1.0 Category: Database querying ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Defining the structure for our database table
typedef struct {
    char name[20];
    int age;
    float salary;
} Employee;
 
int main() {
    // Defining and initializing variables
    int n, i, j; // variables for looping and counting
    Employee emp[100]; // array for holding employee records
    char choice; // for taking user input on whether to continue or not
    char search_name[20]; // for taking user input in search queries
    int search_age; // for taking user input in age-based search queries
    float search_salary; // for taking user input in salary-based search queries
 
    // Let's start by populating our database
    printf("Welcome to the employee database program.\n");
    printf("How many employees do you want to add? ");
    scanf("%d", &n);
 
    for (i = 0; i < n; i++) {
        printf("Please enter the details for employee #%d:\n", i+1);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Age: ");
        scanf("%d", &emp[i].age);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }
 
    // Let's provide the user with options to query the database
    printf("\nWhat would you like to do next?\n");
    printf("Press 'a' to search by name, 'b' to search by age, 'c' to search by salary, or 'q' to quit: ");
    scanf(" %c", &choice); // note the space before %c to discard any leading whitespaces
 
    while (choice != 'q') {
        switch(choice) {
            case 'a':
                printf("Please enter the name you would like to search for: ");
                scanf("%s", search_name); // taking user input
                for (i = 0; i < n; i++) {
                    if (strcmp(search_name, emp[i].name) == 0) {
                        printf("Name: %s\n", emp[i].name);
                        printf("Age: %d\n", emp[i].age);
                        printf("Salary: %.2f\n", emp[i].salary);
                        break; // once we find the employee, no need to loop anymore
                    }  
                }
                if (i == n) { // if the loop ran full but didn't find match
                    printf("No employee with this name found!\n");
                }
                break;
            case 'b':
                printf("Please enter the age you would like to search for: ");
                scanf("%d", &search_age); // taking user input
                for (i = 0; i < n; i++) {
                    if (search_age == emp[i].age) {
                        printf("Name: %s\n", emp[i].name);
                        printf("Age: %d\n", emp[i].age);
                        printf("Salary: %.2f\n", emp[i].salary);
                        break; // once we find the employee, no need to loop anymore
                    }  
                }
                if (i == n) { // if the loop ran full but didn't find match
                    printf("No employee with this age found!\n");
                }
                break;
            case 'c':
                printf("Please enter the salary you would like to search for: ");
                scanf("%f", &search_salary); // taking user input
                for (i = 0; i < n; i++) {
                    if (search_salary == emp[i].salary) {
                        printf("Name: %s\n", emp[i].name);
                        printf("Age: %d\n", emp[i].age);
                        printf("Salary: %.2f\n", emp[i].salary);
                        break; // once we find the employee, no need to loop anymore
                    }  
                }
                if (i == n) { // if the loop ran full but didn't find match
                    printf("No employee with this salary found!\n");
                }
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
        printf("\nWhat would you like to do next?\n");
        printf("Press 'a' to search by name, 'b' to search by age, 'c' to search by salary, or 'q' to quit: ");
        scanf(" %c", &choice); // again, note the space before %c to discard any leading whitespaces
    }
    printf("Thanks for using the employee database program!\n");
    return 0;
}