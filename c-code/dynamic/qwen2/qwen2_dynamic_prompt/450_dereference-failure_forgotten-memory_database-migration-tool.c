#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} Person;

void migrateDatabase(Person **people, int count) {
    for (int i = 0; i < count; i++) {
        if (people[i] != NULL) {
            printf("Migrating %s, age %d\n", people[i]->name, people[i]->age);
            free(people[i]); // Freeing allocated memory
        }
    }
}

int main() {
    Person *people[3];
    people[0] = malloc(sizeof(Person));
    people[1] = malloc(sizeof(Person));
    people[2] = NULL;

    strcpy(people[0]->name, "Alice");
    people[0]->age = 30;

    strcpy(people[1]->name, "Bob");
    people[1]->age = 25;

    migrateDatabase(people, 3);

    // Dereferencing freed memory
    printf("%s is %d years old.\n", people[0]->name, people[0]->age); // Vulnerability

    return 0;
}
