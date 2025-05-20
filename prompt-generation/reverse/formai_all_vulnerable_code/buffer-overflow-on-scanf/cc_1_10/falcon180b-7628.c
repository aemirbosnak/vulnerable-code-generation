//Falcon-180B DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    int id;
} Person;

int compare_name(const void *a, const void *b) {
    Person *person1 = (Person *)a;
    Person *person2 = (Person *)b;

    return strcmp(person1->name, person2->name);
}

int compare_age(const void *a, const void *b) {
    Person *person1 = (Person *)a;
    Person *person2 = (Person *)b;

    return person1->age - person2->age;
}

int compare_id(const void *a, const void *b) {
    Person *person1 = (Person *)a;
    Person *person2 = (Person *)b;

    return person1->id - person2->id;
}

int main() {
    Person people[MAX_SIZE];
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        printf("Enter name: ");
        char name[50];
        scanf("%s", name);

        printf("Enter age: ");
        int age;
        scanf("%d", &age);

        printf("Enter id: ");
        int id;
        scanf("%d", &id);

        people[num_people].name = strdup(name);
        people[num_people].age = age;
        people[num_people].id = id;

        num_people++;
    }

    printf("Enter sorting method:\n1. Sort by name\n2. Sort by age\n3. Sort by id\n");
    int method;
    scanf("%d", &method);

    switch (method) {
        case 1:
            qsort(people, num_people, sizeof(Person), compare_name);
            break;
        case 2:
            qsort(people, num_people, sizeof(Person), compare_age);
            break;
        case 3:
            qsort(people, num_people, sizeof(Person), compare_id);
            break;
        default:
            printf("Invalid method\n");
            return 1;
    }

    printf("Sorted list:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s %d %d\n", people[i].name, people[i].age, people[i].id);
    }

    return 0;
}