//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    char gender;
} Person;

int main() {
    Person *people = (Person*)malloc(sizeof(Person) * 10);
    int num_people = 0;

    while (num_people < 10) {
        printf("Enter name: ");
        scanf("%s", people[num_people].name);

        printf("Enter age: ");
        scanf("%d", &people[num_people].age);

        printf("Enter gender (M/F): ");
        scanf(" %c", &people[num_people].gender);

        num_people++;
    }

    char search_name[MAX_SIZE];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    Person *found_person = NULL;
    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, search_name) == 0) {
            found_person = &people[i];
            break;
        }
    }

    if (found_person!= NULL) {
        printf("Found person with name %s, age %d and gender %c\n", found_person->name, found_person->age, found_person->gender);
    } else {
        printf("Person not found.\n");
    }

    free(people);
    return 0;
}