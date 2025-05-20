//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

Person *people = NULL;
int num_people = 0;

void add_person(const char *name, int age, const char *email) {
    Person *person = (Person *) malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    person->email = strdup(email);

    people = (Person *) realloc(people, sizeof(Person) * (num_people + 1));
    people[num_people] = *person;
    num_people++;
}

void print_people() {
    int i;
    for (i = 0; i < num_people; i++) {
        printf("%s (%d) - %s\n", people[i].name, people[i].age, people[i].email);
    }
}

void search_people(const char *name) {
    int i;
    for (i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Found %s (%d) - %s\n", people[i].name, people[i].age, people[i].email);
            return;
        }
    }

    printf("Not found\n");
}

int main() {
    add_person("John Doe", 30, "johndoe@example.com");
    add_person("Jane Doe", 25, "janedoe@example.com");

    print_people();

    search_people("John Doe");
    search_people("Jane Doe");
    search_people("Bob Smith");

    return 0;
}