//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 25
#define MAX_DESCR_LENGTH 100

typedef struct Person {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCR_LENGTH];
    double net_worth;
    struct Person* next;
} Person;

void add_person(Person** head) {
    Person* new_person = malloc(sizeof(Person));
    new_person->next = NULL;

    printf("Enter name: ");
    scanf("%s", new_person->name);

    printf("Enter description: ");
    scanf("%s", new_person->description);

    printf("Enter net worth: ");
    scanf("%lf", &new_person->net_worth);

    if (*head == NULL) {
        *head = new_person;
    } else {
        (*head)->next = new_person;
    }
}

void print_persons(Person* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Description: %s\n", head->description);
        printf("Net worth: %.2lf\n", head->net_worth);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Person* head = NULL;

    add_person(&head);
    add_person(&head);
    add_person(&head);

    print_persons(head);

    return 0;
}