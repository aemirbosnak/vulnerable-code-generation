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
        printf("Migrating data for %s\n", people[i]->name);
        // Deliberate dereference failure
        free(people[i]);  // Freeing the pointer before accessing it again
    }
}

int main() {
    Person *people[3];
    people[0] = (Person *)malloc(sizeof(Person));
    people[1] = (Person *)malloc(sizeof(Person));
    people[2] = (Person *)malloc(sizeof(Person));

    strcpy(people[0]->name, "Alice");
    people[0]->age = 30;

    strcpy(people[1]->name, "Bob");
    people[1]->age = 25;

    strcpy(people[2]->name, "Charlie");
    people[2]->age = 35;

    migrateDatabase(people, 3);

    // Attempt to access freed memory
    printf("%s is %d years old.\n", people[0]->name, people[0]->age);  // Dereference failure

    return 0;
}
