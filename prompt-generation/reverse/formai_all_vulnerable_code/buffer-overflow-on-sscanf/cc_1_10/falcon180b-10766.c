//Falcon-180B DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

int main() {
    Person *people = NULL;
    int num_people = 0;
    char input[MAX_SIZE];

    // Read in number of people
    printf("Enter the number of people: ");
    if (fgets(input, MAX_SIZE, stdin) == NULL) {
        printf("Error: Failed to read input.\n");
        return 1;
    }
    sscanf(input, "%d", &num_people);

    // Allocate memory for people array
    people = malloc(num_people * sizeof(Person));
    if (people == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return 1;
    }

    // Read in people data
    for (int i = 0; i < num_people; i++) {
        printf("Enter name for person %d: ", i+1);
        if (fgets(input, MAX_SIZE, stdin) == NULL) {
            printf("Error: Failed to read input.\n");
            free(people);
            return 1;
        }
        people[i].name = strdup(input);

        printf("Enter age for person %d: ", i+1);
        if (fgets(input, MAX_SIZE, stdin) == NULL) {
            printf("Error: Failed to read input.\n");
            for (int j = 0; j < i; j++) {
                free(people[j].name);
            }
            free(people);
            return 1;
        }
        sscanf(input, "%d", &people[i].age);
    }

    // Print out people data
    printf("People:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s is %d years old.\n", people[i].name, people[i].age);
    }

    // Free memory
    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
    }
    free(people);

    return 0;
}