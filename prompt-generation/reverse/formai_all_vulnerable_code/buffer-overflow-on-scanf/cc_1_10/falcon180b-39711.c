//Falcon-180B DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    char gender;
    struct person *next;
} person_t;

person_t *create_person(char *name, int age, char gender) {
    person_t *person = (person_t *) malloc(sizeof(person_t));
    person->name = strdup(name);
    person->age = age;
    person->gender = gender;
    person->next = NULL;
    return person;
}

void delete_person(person_t *person) {
    free(person->name);
    free(person);
}

void append_person(person_t **head, person_t *person) {
    person_t *temp = *head;
    if (*head == NULL) {
        *head = person;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = person;
}

void print_list(person_t *head) {
    while (head!= NULL) {
        printf("Name: %s, Age: %d, Gender: %c\n", head->name, head->age, head->gender);
        head = head->next;
    }
}

int main() {
    person_t *head = NULL;
    char name[50];
    int age;
    char gender;

    while (1) {
        printf("Enter name (or type 'exit' to quit): ");
        scanf("%s", name);
        if (strcmp(name, "exit") == 0) {
            break;
        }
        printf("Enter age: ");
        scanf("%d", &age);
        printf("Enter gender (M/F): ");
        scanf(" %c", &gender);

        person_t *person = create_person(name, age, gender);
        append_person(&head, person);
    }

    print_list(head);

    while (head!= NULL) {
        person_t *temp = head;
        head = head->next;
        delete_person(temp);
    }

    return 0;
}