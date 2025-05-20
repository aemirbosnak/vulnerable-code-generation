//Falcon-180B DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 100
#define MAX_NAME_SIZE 20

typedef struct {
    char name[MAX_NAME_SIZE];
    int age;
} Person;

int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int compare_ages(const void *a, const void *b) {
    Person *person_a = *(Person **)a;
    Person *person_b = *(Person **)b;

    if (person_a->age < person_b->age) {
        return -1;
    } else if (person_a->age > person_b->age) {
        return 1;
    } else {
        return 0;
    }
}

void read_people_from_file(FILE *file, Person **people, int *num_people) {
    char line[MAX_LINE_SIZE];
    Person *new_people = NULL;
    int new_num_people = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char name[MAX_NAME_SIZE];
        int age;

        if (sscanf(line, "%s %d", name, &age)!= 2) {
            printf("Invalid line format: %s\n", line);
            continue;
        }

        new_people = realloc(new_people, sizeof(Person) * (new_num_people + 1));
        new_people[new_num_people].name[0] = '\0';
        strncpy(new_people[new_num_people].name, name, MAX_NAME_SIZE - 1);
        new_people[new_num_people].age = age;
        new_num_people++;
    }

    *people = new_people;
    *num_people = new_num_people;
}

void write_people_to_file(FILE *file, Person *people, int num_people) {
    qsort(people, num_people, sizeof(Person), compare_names);

    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s %d\n", people[i].name, people[i].age);
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    Person *people = NULL;
    int num_people = 0;

    read_people_from_file(input_file, &people, &num_people);

    write_people_to_file(output_file, people, num_people);

    fclose(input_file);
    fclose(output_file);

    return 0;
}