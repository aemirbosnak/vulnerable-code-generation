//FormAI DATASET v1.0 Category: Database querying ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the maximum of two integers
int max(int a, int b)
{
    return a>b ? a : b;
}

// Define a structure to store employee details
struct Employee {
    int id;
    char name[50];
    int age;
    float salary;
};

// Define a function to query the database for employee details based on certain criteria
void query_database(struct Employee employees[], int n, int min_age, float min_salary, char search_name[])
{
    // Define a flag to check if any matching employee is found
    int flag = 0;
    
    // Loop through all the employees in the database
    for(int i = 0; i < n; i++)
    {
        if(employees[i].age >= min_age && employees[i].salary >= min_salary)
        {
            if(search_name[0] == '\0' || strcmp(employees[i].name, search_name) == 0)
            {
                // Print the employee details
                printf("ID: %d\n", employees[i].id);
                printf("Name: %s\n", employees[i].name);
                printf("Age: %d\n", employees[i].age);
                printf("Salary: %.2f\n", employees[i].salary);
                
                // Set the flag to 1 to indicate a matching employee has been found
                flag = 1;
            }
        }
    }
    
    // If no matching employee is found, print the following message
    if(flag == 0)
    {
        printf("No matching employee found.\n");
    }
}

// Main function
int main()
{
    // Define an array of employee structs
    struct Employee employees[5];
    
    // Initialize the employee details
    employees[0].id = 1;
    strcpy(employees[0].name, "John");
    employees[0].age = 30;
    employees[0].salary = 50000.00;
    
    employees[1].id = 2;
    strcpy(employees[1].name, "Mary");
    employees[1].age = 25;
    employees[1].salary = 60000.00;
    
    employees[2].id = 3;
    strcpy(employees[2].name, "David");
    employees[2].age = 35;
    employees[2].salary = 70000.00;
    
    employees[3].id = 4;
    strcpy(employees[3].name, "Alex");
    employees[3].age = 28;
    employees[3].salary = 55000.00;
    
    employees[4].id = 5;
    strcpy(employees[4].name, "Sarah");
    employees[4].age = 32;
    employees[4].salary = 80000.00;
    
    // Get the user input for the query criteria
    int min_age, choice;
    float min_salary;
    char search_name[50];
    
    printf("Enter minimum age: ");
    scanf("%d", &min_age);
    
    printf("Enter minimum salary: ");
    scanf("%f", &min_salary);
    
    printf("\nDo you want to search for a particular name? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);
    
    if(choice == 1)
    {
        printf("Enter name to search: ");
        scanf("%s", search_name);
    }
    else
    {
        search_name[0] = '\0';
    }
    
    // Call the query_database function
    query_database(employees, 5, min_age, min_salary, search_name);
    
    return 0;
}