//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Person
{
    char name[MAX_NAME_LENGTH];
    int age;
    double income;
    double expenses;
    struct Person* next;
} Person;

int main()
{
    // Create a linked list of persons
    Person* head = NULL;
    Person* current = NULL;

    // Get the person's name, age, income, and expenses
    char name[MAX_NAME_LENGTH];
    int age;
    double income;
    double expenses;

    // Allocate memory for the new person
    current = (Person*)malloc(sizeof(Person));

    // Set the person's name, age, income, and expenses
    printf("Enter the person's name: ");
    scanf("%s", current->name);

    printf("Enter the person's age: ");
    scanf("%d", &current->age);

    printf("Enter the person's income: ");
    scanf("%lf", &current->income);

    printf("Enter the person's expenses: ");
    scanf("%lf", &current->expenses);

    // Add the new person to the linked list
    if (head == NULL)
    {
        head = current;
    }
    else
    {
        current->next = head;
        head = current;
    }

    // Print the list of persons
    current = head;
    while (current)
    {
        printf("Name: %s, Age: %d, Income: %.2lf, Expenses: %.2lf\n", current->name, current->age, current->income, current->expenses);
        current = current->next;
    }

    // Free the memory allocated for the new person
    free(current);

    return 0;
}