//Falcon-180B DATASET v1.0 Category: Memory management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    char name[50];
    int age;
} Person;

Person *create_person(int id, char *name, int age) {
    Person *new_person = (Person *) malloc(sizeof(Person));
    if (new_person == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    new_person->id = id;
    strcpy(new_person->name, name);
    new_person->age = age;
    return new_person;
}

void delete_person(Person *person) {
    free(person);
}

int main() {
    Person *people[MAX_SIZE];
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        printf("Enter person ID: ");
        int id = 0;
        scanf("%d", &id);

        if (id == 0) {
            printf("Exiting...\n");
            break;
        }

        char name[50];
        printf("Enter person name: ");
        scanf("%s", name);

        int age = 0;
        printf("Enter person age: ");
        scanf("%d", &age);

        Person *new_person = create_person(id, name, age);
        people[num_people++] = new_person;
    }

    printf("List of people:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%d: %s (%d years old)\n", people[i]->id, people[i]->name, people[i]->age);
    }

    for (int i = 0; i < num_people; i++) {
        delete_person(people[i]);
    }

    return 0;
}