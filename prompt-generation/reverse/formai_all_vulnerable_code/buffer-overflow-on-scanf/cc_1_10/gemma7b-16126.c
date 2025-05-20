//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 255

typedef struct Person
{
    char name[MAX_CHAR];
    int age;
    float height;
    float weight;
    float heartRate;
    struct Person *next;
} Person;

void addPerson(Person **head)
{
    Person *newPerson = malloc(sizeof(Person));

    printf("Enter name: ");
    scanf("%s", newPerson->name);

    printf("Enter age: ");
    scanf("%d", &newPerson->age);

    printf("Enter height: ");
    scanf("%f", &newPerson->height);

    printf("Enter weight: ");
    scanf("%f", &newPerson->weight);

    printf("Enter heart rate: ");
    scanf("%f", &newPerson->heartRate);

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

void printPeople(Person *head)
{
    while (head)
    {
        printf("%s, %d, %.2f, %.2f, %.2f\n", head->name, head->age, head->height, head->weight, head->heartRate);
        head = head->next;
    }
}

int main()
{
    Person *head = NULL;

    addPerson(&head);
    addPerson(&head);
    addPerson(&head);

    printPeople(head);

    return 0;
}