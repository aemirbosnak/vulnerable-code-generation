//Falcon-180B DATASET v1.0 Category: File handling ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int age;
} person_t;

void read_people(person_t *people, int max_people, FILE *file) {
    int count = 0;
    person_t person;

    while (fscanf(file, "%s %d\n", person.name, &person.age) == 2 && count < max_people) {
        people[count++] = person;
    }
}

void write_people(person_t *people, int num_people, FILE *file) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s %d\n", people[i].name, people[i].age);
    }
}

void sort_people(person_t *people, int num_people) {
    for (int i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[j].age < people[i].age) {
                person_t temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    person_t people[100];
    int num_people = 0;

    read_people(people, 100, input_file);
    num_people = fclose(input_file);

    sort_people(people, num_people);

    write_people(people, num_people, output_file);
    fclose(output_file);

    return 0;
}