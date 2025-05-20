//Falcon-180B DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    char gender;
} Person;

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Gender: %c\n", person->gender);
}

int main() {
    Person *people = malloc(MAX_SIZE * sizeof(Person));
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        printf("Enter name: ");
        char *name = malloc(50 * sizeof(char));
        scanf("%s", name);

        printf("Enter age: ");
        int age;
        scanf("%d", &age);

        printf("Enter gender (M/F): ");
        char gender;
        scanf(" %c", &gender);

        people[num_people] = (Person) {
           .name = name,
           .age = age,
           .gender = gender
        };
        num_people++;
    }

    printf("All people:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    return 0;
}