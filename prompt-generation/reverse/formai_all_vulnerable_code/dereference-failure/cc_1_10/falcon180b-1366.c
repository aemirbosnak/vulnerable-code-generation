//Falcon-180B DATASET v1.0 Category: Error handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char *name;
    int age;
    int height;
    int weight;
} Person;

typedef struct {
    Person *people;
    int count;
    int capacity;
} Village;

void create_village(Village *village) {
    village->people = (Person*)malloc(sizeof(Person) * 10);
    village->count = 0;
    village->capacity = 10;
}

void add_person(Village *village, char *name, int age, int height, int weight) {
    if (village->count >= village->capacity) {
        printf("Error: Village is full! ");
        return;
    }

    Person *person = &village->people[village->count];
    strncpy(person->name, name, MAX_LINE_SIZE);
    person->age = age;
    person->height = height;
    person->weight = weight;

    village->count++;
}

void list_people(Village *village) {
    if (village->count == 0) {
        printf("Error: Village is empty! ");
        return;
    }

    printf("People in the village:\n");
    for (int i = 0; i < village->count; i++) {
        Person *person = &village->people[i];
        printf("Name: %s\n", person->name);
        printf("Age: %d\n", person->age);
        printf("Height: %d\n", person->height);
        printf("Weight: %d\n", person->weight);
        printf("\n");
    }
}

void destroy_village(Village *village) {
    free(village->people);
    village->people = NULL;
    village->count = 0;
    village->capacity = 0;
}

int main() {
    Village village;
    create_village(&village);

    add_person(&village, "Sir William", 35, 180, 90);
    add_person(&village, "Lady Isabella", 30, 170, 70);
    add_person(&village, "Sir Richard", 25, 190, 100);

    list_people(&village);

    destroy_village(&village);

    return 0;
}