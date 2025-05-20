//Falcon-180B DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    int age;
} Person;

int compare_persons(const void *a, const void *b) {
    Person *person_a = (Person *)a;
    Person *person_b = (Person *)b;

    if (person_a->age > person_b->age) {
        return 1;
    } else if (person_a->age < person_b->age) {
        return -1;
    } else {
        return 0;
    }
}

void read_people_from_file(const char *filename, Person **people, int *num_people) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        Person *person = malloc(sizeof(Person));
        person->name = strdup(line);
        sscanf(line, "%s %d", person->name, &person->age);

        *people = realloc(*people, sizeof(Person) * (*num_people + 1));
        (*people)[*num_people] = *person;
        (*num_people)++;
    }

    fclose(file);
}

void write_people_to_file(const char *filename, const Person *people, int num_people) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s %d\n", people[i].name, people[i].age);
    }

    fclose(file);
}

void sort_people(Person *people, int num_people) {
    qsort(people, num_people, sizeof(Person), compare_persons);
}

int main() {
    const char *input_filename = "people.txt";
    const char *output_filename = "sorted_people.txt";

    Person *people = NULL;
    int num_people = 0;

    read_people_from_file(input_filename, &people, &num_people);
    sort_people(people, num_people);
    write_people_to_file(output_filename, people, num_people);

    for (int i = 0; i < num_people; i++) {
        printf("%s %d\n", people[i].name, people[i].age);
    }

    free(people);
    return 0;
}