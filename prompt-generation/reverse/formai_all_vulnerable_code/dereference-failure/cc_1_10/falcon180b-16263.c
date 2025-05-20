//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct {
    int id;
    char name[32];
    int age;
} Person;

Person *create_person(int id, char *name, int age) {
    Person *person = (Person *)malloc(sizeof(Person));
    person->id = id;
    strcpy(person->name, name);
    person->age = age;
    return person;
}

void delete_person(Person *person) {
    free(person);
}

void print_person(Person *person) {
    printf("ID: %d\n", person->id);
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int main() {
    Person *person1 = create_person(1, "John", 25);
    Person *person2 = create_person(2, "Jane", 30);
    Person *person3 = create_person(3, "Bob", 20);

    print_person(person1);
    print_person(person2);
    print_person(person3);

    delete_person(person1);
    delete_person(person2);
    delete_person(person3);

    return 0;
}