//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    float height;
} Person;

void print_person(Person *p) {
    printf("Name: %s\nAge: %d\nHeight: %.2f\n", p->name, p->age, p->height);
}

int main() {
    Person people[MAX_SIZE];
    int num_people = 0;
    char input[MAX_SIZE];

    while (num_people < MAX_SIZE) {
        printf("Enter a name (or type 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        Person *p = &people[num_people];
        p->name = strdup(input);
        printf("Enter age: ");
        scanf("%d", &p->age);
        printf("Enter height: ");
        scanf("%f", &p->height);

        num_people++;
    }

    printf("Number of people entered: %d\n", num_people);

    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    return 0;
}