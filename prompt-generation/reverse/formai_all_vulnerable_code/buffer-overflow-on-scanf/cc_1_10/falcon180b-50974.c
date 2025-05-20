//Falcon-180B DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void init_person(Person *p) {
    p->name = NULL;
    p->age = 0;
}

void free_person(Person *p) {
    if (p->name!= NULL) {
        free(p->name);
        p->name = NULL;
    }
}

int main() {
    Person *people[MAX_SIZE];
    int num_people = 0;
    char input[100];
    while (true) {
        printf("Enter a name (or type 'quit' to exit): ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        if (num_people >= MAX_SIZE) {
            printf("Error: too many people.\n");
            continue;
        }
        Person *p = malloc(sizeof(Person));
        if (p == NULL) {
            printf("Error: out of memory.\n");
            continue;
        }
        init_person(p);
        people[num_people] = p;
        num_people++;
    }
    for (int i = 0; i < num_people; i++) {
        free_person(people[i]);
    }
    return 0;
}