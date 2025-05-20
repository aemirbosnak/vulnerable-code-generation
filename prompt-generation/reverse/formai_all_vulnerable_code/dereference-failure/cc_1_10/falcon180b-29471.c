//Falcon-180B DATASET v1.0 Category: Error handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    int id;
} Person;

int main() {
    Person *people = (Person *) malloc(MAX_SIZE * sizeof(Person));
    int num_people = 0;

    while (1) {
        printf("Enter name (or type 'done' to finish): ");
        char name[50];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter age: ");
        int age;
        scanf("%d", &age);

        printf("Enter ID: ");
        int id;
        scanf("%d", &id);

        if (num_people >= MAX_SIZE) {
            printf("Error: Maximum number of people reached.\n");
            return 1;
        }

        people[num_people].name = strdup(name);
        people[num_people].age = age;
        people[num_people].id = id;
        num_people++;
    }

    printf("Number of people: %d\n", num_people);

    for (int i = 0; i < num_people; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("ID: %d\n", people[i].id);
        printf("\n");
    }

    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
    }
    free(people);

    return 0;
}