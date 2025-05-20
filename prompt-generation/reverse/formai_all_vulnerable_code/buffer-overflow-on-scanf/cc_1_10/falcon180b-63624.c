//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int gender;
} Person;

void print_error(char *message) {
    printf("Error: %s\n", message);
}

int main() {
    Person *people = malloc(MAX_SIZE * sizeof(Person));
    if (people == NULL) {
        print_error("Failed to allocate memory for people array");
        return 1;
    }

    int num_people = 0;
    char *name;
    int age;
    int gender;

    while (1) {
        printf("Enter name (or type 'done' to finish): ");
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter age: ");
        scanf("%d", &age);

        printf("Enter gender (0 for male, 1 for female): ");
        scanf("%d", &gender);

        if (num_people >= MAX_SIZE) {
            print_error("Reached maximum number of people");
            return 1;
        }

        people[num_people].name = strdup(name);
        people[num_people].age = age;
        people[num_people].gender = gender;
        num_people++;
    }

    for (int i = 0; i < num_people; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Gender: %d\n", people[i].gender);
        printf("\n");
    }

    free(people);
    return 0;
}