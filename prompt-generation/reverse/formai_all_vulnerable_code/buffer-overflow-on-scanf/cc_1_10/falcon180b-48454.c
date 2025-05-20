//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char* name;
    int age;
} Person;

int compare_names(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int compare_ages(const void* a, const void* b) {
    Person* p1 = *(Person**)a;
    Person* p2 = *(Person**)b;
    if (p1->age < p2->age) {
        return -1;
    } else if (p1->age > p2->age) {
        return 1;
    } else {
        return 0;
    }
}

void print_person(Person* p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

int main() {
    Person* people[MAX_SIZE];
    int num_people = 0;
    char input[100];

    while (1) {
        printf("Enter a name (or type 'quit' to exit): ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        people[num_people] = malloc(sizeof(Person));
        people[num_people]->name = strdup(input);
        people[num_people]->age = rand() % 100;
        num_people++;
    }

    qsort(people, num_people, sizeof(Person*), compare_names);

    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    qsort(people, num_people, sizeof(Person*), compare_ages);

    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    return 0;
}