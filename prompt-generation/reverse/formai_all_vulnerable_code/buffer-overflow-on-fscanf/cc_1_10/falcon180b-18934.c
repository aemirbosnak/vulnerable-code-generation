//Falcon-180B DATASET v1.0 Category: Educational ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void init_person(Person *person) {
    person->name = NULL;
    person->age = 0;
}

void set_name(Person *person, char *name) {
    strcpy(person->name, name);
}

void set_age(Person *person, int age) {
    person->age = age;
}

int get_age(Person *person) {
    return person->age;
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

void read_person(Person *person, FILE *file) {
    fscanf(file, "%s %d", person->name, &person->age);
}

void write_person(Person *person, FILE *file) {
    fprintf(file, "%s %d\n", person->name, person->age);
}

int compare_age(const void *a, const void *b) {
    Person *person_a = (Person *)a;
    Person *person_b = (Person *)b;

    return (person_a->age - person_b->age);
}

void sort_people(Person *people, int num_people) {
    qsort(people, num_people, sizeof(Person), compare_age);
}

int main() {
    FILE *file;
    Person people[MAX_SIZE];
    int num_people = 0;

    file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s %d", people[num_people].name, &people[num_people].age)!= EOF) {
        num_people++;
    }

    fclose(file);

    sort_people(people, num_people);

    file = fopen("sorted_people.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (int i = 0; i < num_people; i++) {
        write_person(&people[i], file);
    }

    fclose(file);

    return 0;
}