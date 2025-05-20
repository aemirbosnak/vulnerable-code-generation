//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    int id;
} Person;

void paranoid_search(Person *array, int size, int target_id) {
    int i;
    for (i = 0; i < size; i++) {
        if (array[i].id == target_id) {
            printf("Found person with ID %d at index %d\n", target_id, i);
            return;
        }
    }
    printf("Person with ID %d not found\n", target_id);
}

int main() {
    Person *people = malloc(MAX_SIZE * sizeof(Person));
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        Person new_person;
        printf("Enter name (or 'done' to finish): ");
        scanf("%s", new_person.name);
        if (strcmp(new_person.name, "done") == 0) {
            break;
        }
        printf("Enter age: ");
        scanf("%d", &new_person.age);
        printf("Enter ID: ");
        scanf("%d", &new_person.id);
        people[num_people] = new_person;
        num_people++;
    }

    int target_id;
    printf("Enter ID to search for: ");
    scanf("%d", &target_id);

    paranoid_search(people, num_people, target_id);

    free(people);
    return 0;
}