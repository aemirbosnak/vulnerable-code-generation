//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
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

void addPerson(Person** head)
{
    Person* newPerson = malloc(sizeof(Person));

    printf("Enter name: ");
    scanf("%s", newPerson->name);

    printf("Enter age: ");
    scanf("%d", &newPerson->age);

    printf("Enter income: ");
    scanf("%lf", &newPerson->income);

    printf("Enter expenses: ");
    scanf("%lf", &newPerson->expenses);

    newPerson->next = NULL;

    if (*head == NULL)
    {
        *head = newPerson;
    }
    else
    {
        (*head)->next = newPerson;
    }
}

void printPersons(Person* head)
{
    while (head)
    {
        printf("Name: %s\n", head->name);
        printf("Age: %d\n", head->age);
        printf("Income: %.2lf\n", head->income);
        printf("Expenses: %.2lf\n", head->expenses);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    Person* head = NULL;

    addPerson(&head);
    addPerson(&head);
    addPerson(&head);

    printPersons(head);

    return 0;
}