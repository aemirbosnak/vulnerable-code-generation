//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

void create_person(Person *person) {
    printf("Enter name: ");
    scanf("%[^\n]", person->name);
    printf("Enter age: ");
    scanf("%d", &person->age);
}

void print_person(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
}

int compare_names(const void *a, const void *b) {
    Person person_a = *(Person *)a;
    Person person_b = *(Person *)b;
    return strcmp(person_a.name, person_b.name);
}

int main() {
    Person people[MAX_SIZE];
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        printf("Do you want to add a person? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y') {
            create_person(&people[num_people]);
            num_people++;
        } else {
            printf("Enter name to search for: ");
            char name[MAX_SIZE];
            scanf("%[^\n]", name);

            Person *result = bsearch(&name, people, num_people, sizeof(Person), compare_names);

            if (result!= NULL) {
                printf("Found person with name '%s'\n", result->name);
                print_person(*result);
            } else {
                printf("Person not found.\n");
            }
        }
    }

    return 0;
}