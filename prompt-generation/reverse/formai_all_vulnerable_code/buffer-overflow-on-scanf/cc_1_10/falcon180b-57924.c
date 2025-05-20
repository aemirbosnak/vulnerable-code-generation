//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

int main() {
    Person people[MAX_SIZE];
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        Person *new_person = (Person *) malloc(sizeof(Person));
        if (new_person == NULL) {
            printf("Error: Out of memory\n");
            exit(1);
        }

        printf("Enter name: ");
        new_person->name = (char *) malloc(sizeof(char) * 100);
        scanf("%s", new_person->name);

        printf("Enter age: ");
        scanf("%d", &(new_person->age));

        people[num_people++] = *new_person;
        free(new_person);
    }

    printf("Enter search age: ");
    int search_age;
    scanf("%d", &search_age);

    int count = 0;
    for (int i = 0; i < num_people; i++) {
        if (people[i].age == search_age) {
            printf("%s is %d years old\n", people[i].name, search_age);
            count++;
        }
    }

    if (count == 0) {
        printf("No one is %d years old\n", search_age);
    }

    return 0;
}