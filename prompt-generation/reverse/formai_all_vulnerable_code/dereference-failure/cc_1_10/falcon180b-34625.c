//Falcon-180B DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for our data
typedef struct {
    char *name;
    int age;
} Person;

// Function to initialize a Person struct
void init_person(Person *p) {
    p->name = NULL;
    p->age = 0;
}

// Function to allocate memory for a Person struct
Person *create_person(char *name, int age) {
    Person *p = (Person *) malloc(sizeof(Person));
    if (p == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    init_person(p);
    p->name = strdup(name);
    p->age = age;
    return p;
}

// Function to print a Person struct
void print_person(Person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
}

// Function to free memory allocated for a Person struct
void destroy_person(Person *p) {
    free(p->name);
    free(p);
}

int main() {
    Person *p1 = create_person("John", 25);
    Person *p2 = create_person("Jane", 30);
    Person *p3 = create_person("Bob", 40);

    print_person(p1);
    print_person(p2);
    print_person(p3);

    destroy_person(p1);
    destroy_person(p2);
    destroy_person(p3);

    return 0;
}