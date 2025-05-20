//Falcon-180B DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void init_person(Person *p) {
    p->name = NULL;
    p->age = 0;
}

void set_name(Person *p, char *name) {
    if (p->name!= NULL) {
        free(p->name);
    }
    p->name = strdup(name);
}

void set_age(Person *p, int age) {
    p->age = age;
}

void print_person(Person *p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

int main() {
    Person *people = malloc(MAX_SIZE * sizeof(Person));
    init_person(people);

    int count = 0;

    while (count < MAX_SIZE) {
        char name[20];
        int age;

        printf("Enter name (or type 'done' to finish): ");
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter age: ");
        scanf("%d", &age);

        set_name(&people[count], name);
        set_age(&people[count], age);

        count++;
    }

    printf("People:\n");
    for (int i = 0; i < count; i++) {
        print_person(&people[i]);
    }

    free(people);

    return 0;
}