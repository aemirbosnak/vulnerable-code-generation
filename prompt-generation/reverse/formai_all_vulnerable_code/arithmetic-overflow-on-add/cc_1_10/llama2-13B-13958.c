//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} person_t;

person_t get_person(void);
void print_person(person_t p);
void increase_age(person_t *p, int amount);

int main(void) {
    person_t p;

    p = get_person();
    print_person(p);

    increase_age(&p, 5);
    print_person(p);

    return 0;
}

person_t get_person(void) {
    char name[MAX_NAME_LEN];
    int age;

    printf("Enter your name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline

    printf("Enter your age: ");
    scanf("%d", &age);

    return (person_t) { .name = name, .age = age };
}

void print_person(person_t p) {
    printf("Name: %s, Age: %d\n", p.name, p.age);
}

void increase_age(person_t *p, int amount) {
    p->age += amount;
    if (p->age < 0) {
        p->age = 0;
    }
}