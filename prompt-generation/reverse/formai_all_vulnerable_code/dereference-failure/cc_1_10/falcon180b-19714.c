//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

struct person {
    char name[MAX_NAME_LEN];
    int age;
};

struct person *people = NULL;
int num_people = 0;

void add_person(const char *name, int age) {
    if (num_people >= 1000) {
        printf("Fatal error: too many people!\n");
        exit(1);
    }

    struct person *new_person = malloc(sizeof(struct person));
    strncpy(new_person->name, name, MAX_NAME_LEN - 1);
    new_person->age = age;
    people = realloc(people, sizeof(struct person) * (num_people + 1));
    people[num_people++] = *new_person;
    free(new_person);
}

void print_people() {
    for (int i = 0; i < num_people; i++) {
        printf("%s (%d years old)\n", people[i].name, people[i].age);
    }
}

void find_youngest() {
    int youngest_age = 1000;
    for (int i = 0; i < num_people; i++) {
        if (people[i].age < youngest_age) {
            youngest_age = people[i].age;
        }
    }

    printf("The youngest person is %d years old.\n", youngest_age);
}

void find_oldest() {
    int oldest_age = 0;
    for (int i = 0; i < num_people; i++) {
        if (people[i].age > oldest_age) {
            oldest_age = people[i].age;
        }
    }

    printf("The oldest person is %d years old.\n", oldest_age);
}

void find_by_name(const char *name) {
    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Found %s (%d years old)\n", name, people[i].age);
            return;
        }
    }

    printf("Could not find %s\n", name);
}

int main() {
    add_person("Romeo", 25);
    add_person("Juliet", 18);
    add_person("Mercutio", 30);
    add_person("Tybalt", 20);

    print_people();

    find_youngest();
    find_oldest();

    find_by_name("Romeo");
    find_by_name("Juliet");
    find_by_name("Mercutio");
    find_by_name("Tybalt");
    find_by_name("Benvolio");

    return 0;
}