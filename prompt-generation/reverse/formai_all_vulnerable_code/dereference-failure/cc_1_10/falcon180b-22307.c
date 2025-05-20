//Falcon-180B DATASET v1.0 Category: Recursive ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    struct person *next;
} person;

person *head = NULL;

void add_person(char *name, int age) {
    person *new_person = (person *)malloc(sizeof(person));
    new_person->name = strdup(name);
    new_person->age = age;
    new_person->next = NULL;

    if (head == NULL) {
        head = new_person;
    } else {
        person *current_person = head;
        while (current_person->next!= NULL) {
            current_person = current_person->next;
        }
        current_person->next = new_person;
    }
}

void print_list(person *current_person) {
    if (current_person == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Name: %s\nAge: %d\n", current_person->name, current_person->age);
    print_list(current_person->next);
}

int main() {
    add_person("Alice", 25);
    add_person("Bob", 30);
    add_person("Charlie", 35);

    print_list(head);

    return 0;
}