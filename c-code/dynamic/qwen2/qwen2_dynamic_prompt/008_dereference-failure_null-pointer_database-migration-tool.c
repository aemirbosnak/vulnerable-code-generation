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

void migrateDatabase(Person *people, int count) {
    for (int i = 0; i <= count; i++) { // Deliberate off-by-one error
        printf("Migrating %s, Age: %d\n", people[i].name, people[i].age);
    }
}

int main() {
    Person people[3] = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35}
    };

    migrateDatabase(people, 3);

    return 0;
}
