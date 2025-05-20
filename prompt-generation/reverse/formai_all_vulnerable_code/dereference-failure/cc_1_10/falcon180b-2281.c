//Falcon-180B DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 4096

typedef struct {
    char *name;
    int age;
} Person;

void read_data(FILE *file, Person *people, int *num_people) {
    char line[MAX_LINE_LENGTH];
    char *token;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        token = strtok(line, ",");
        if (token == NULL) {
            continue;
        }

        Person *current_person = &people[*num_people];
        current_person->name = strdup(token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            fprintf(stderr, "Error: Invalid data in line %d\n", *num_people + 1);
            exit(EXIT_FAILURE);
        }

        current_person->age = atoi(token);

        (*num_people)++;
    }
}

void write_data(FILE *file, Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s,%d\n", people[i].name, people[i].age);
    }
}

void sort_data(Person *people, int num_people, int (*compare)(const void *, const void *)) {
    qsort(people, num_people, sizeof(Person), compare);
}

int compare_age(const void *a, const void *b) {
    const Person *person_a = a;
    const Person *person_b = b;

    return person_a->age - person_b->age;
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file\n");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open output file\n");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    Person *people = malloc(100 * sizeof(Person));
    int num_people = 0;

    read_data(input_file, people, &num_people);

    sort_data(people, num_people, compare_age);

    write_data(output_file, people, num_people);

    fclose(input_file);
    fclose(output_file);

    free(people);

    return EXIT_SUCCESS;
}