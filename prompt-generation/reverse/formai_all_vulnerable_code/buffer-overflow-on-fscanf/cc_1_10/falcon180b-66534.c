//Falcon-180B DATASET v1.0 Category: Sorting ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[20];
    int age;
} Person;

int compare_age(const void* a, const void* b) {
    const Person* person_a = a;
    const Person* person_b = b;

    if(person_a->age > person_b->age) {
        return 1;
    } else if(person_a->age < person_b->age) {
        return -1;
    } else {
        return 0;
    }
}

int compare_name(const void* a, const void* b) {
    const Person* person_a = a;
    const Person* person_b = b;

    return strcmp(person_a->name, person_b->name);
}

int main() {
    Person people[MAX_SIZE];
    int num_people = 0;

    FILE* file = fopen("people.txt", "r");

    if(file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while(fscanf(file, "%s %d", people[num_people].name, &people[num_people].age)!= EOF) {
        num_people++;
    }

    fclose(file);

    qsort(people, num_people, sizeof(Person), compare_age);

    for(int i = 0; i < num_people; i++) {
        printf("%s %d\n", people[i].name, people[i].age);
    }

    qsort(people, num_people, sizeof(Person), compare_name);

    for(int i = 0; i < num_people; i++) {
        printf("%s %d\n", people[i].name, people[i].age);
    }

    return 0;
}