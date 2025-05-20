//Falcon-180B DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    int height;
} Person;

int main() {
    Person *people = (Person*) malloc(MAX_SIZE * sizeof(Person));
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        printf("Enter name: ");
        char name[100];
        scanf("%s", name);

        printf("Enter age: ");
        int age;
        scanf("%d", &age);

        printf("Enter height: ");
        int height;
        scanf("%d", &height);

        people[num_people].name = (char*) malloc(strlen(name) + 1);
        strcpy(people[num_people].name, name);
        people[num_people].age = age;
        people[num_people].height = height;

        num_people++;
    }

    printf("Number of people: %d\n", num_people);

    for (int i = 0; i < num_people; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Height: %d\n\n", people[i].height);
    }

    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
    }

    free(people);

    return 0;
}