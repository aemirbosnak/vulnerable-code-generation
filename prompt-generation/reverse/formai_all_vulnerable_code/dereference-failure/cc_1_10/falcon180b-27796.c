//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char name[50];
    int age;
    float height;
    char eye_color[10];
} person;

// function to create a new person
person* create_person(char* name, int age, float height, char* eye_color) {
    person* new_person = (person*) malloc(sizeof(person));
    strcpy(new_person->name, name);
    new_person->age = age;
    new_person->height = height;
    strcpy(new_person->eye_color, eye_color);
    return new_person;
}

// function to print person details
void print_person(person* person) {
    printf("name: %s\n", person->name);
    printf("age: %d\n", person->age);
    printf("height: %f\n", person->height);
    printf("eye color: %s\n", person->eye_color);
}

// function to compare two people based on height
int compare_height(person* a, person* b) {
    if (a->height > b->height) {
        return 1;
    } else if (a->height < b->height) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    // create two people
    person* person1 = create_person("john", 25, 1.8, "blue");
    person* person2 = create_person("jane", 23, 1.7, "green");

    // print their details
    print_person(person1);
    print_person(person2);

    // sort them by height
    person* temp = person1;
    person1 = person2;
    person2 = temp;

    // print their details again
    print_person(person1);
    print_person(person2);

    return 0;
}