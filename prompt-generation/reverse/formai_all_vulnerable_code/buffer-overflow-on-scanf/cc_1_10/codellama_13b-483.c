//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 150

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

int compare_people(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    return strcmp(p1->name, p2->name);
}

void display_people(Person *people, int num_people) {
    printf("Name\tAge\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s\t%d\n", people[i].name, people[i].age);
    }
}

int main() {
    Person people[MAX_AGE];
    int num_people = 0;

    while (1) {
        char name[MAX_NAME_LENGTH];
        int age;

        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter age: ");
        scanf("%d", &age);

        if (age < 0) {
            break;
        }

        strcpy(people[num_people].name, name);
        people[num_people].age = age;
        num_people++;
    }

    printf("Sorting people by name...\n");
    qsort(people, num_people, sizeof(Person), compare_people);

    display_people(people, num_people);

    return 0;
}