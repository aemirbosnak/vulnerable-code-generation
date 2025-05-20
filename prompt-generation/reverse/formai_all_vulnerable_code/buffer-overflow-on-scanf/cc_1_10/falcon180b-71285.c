//Falcon-180B DATASET v1.0 Category: Sorting ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_STRING_SIZE 50

typedef struct {
    char name[MAX_STRING_SIZE];
    int age;
} Person;

int compare_by_age(const void* a, const void* b) {
    Person* person_a = (Person*)a;
    Person* person_b = (Person*)b;

    if (person_a->age > person_b->age) {
        return 1;
    } else if (person_a->age < person_b->age) {
        return -1;
    } else {
        return 0;
    }
}

void print_person(Person person) {
    printf("Name: %s, Age: %d\n", person.name, person.age);
}

int main() {
    Person people[MAX_SIZE];
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        printf("Enter a name (or type 'done' to finish): ");
        scanf("%s", people[num_people].name);

        if (strcmp(people[num_people].name, "done") == 0) {
            break;
        }

        printf("Enter an age: ");
        scanf("%d", &people[num_people].age);

        num_people++;
    }

    qsort(people, num_people, sizeof(Person), compare_by_age);

    printf("Sorted by age:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    return 0;
}