//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    int age;
    float weight;
} Person;

void read_csv(FILE *file, Person *persons, int *num_persons) {
    char line[1024];
    char *token;
    int row = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%[^,],%d,%f", persons[row].name, &persons[row].age, &persons[row].weight);
        row++;

        if (*num_persons < row) {
            Person *new_persons = realloc(persons, (row + 1) * sizeof(Person));
            if (new_persons == NULL) {
                fprintf(stderr, "Out of memory\n");
                exit(EXIT_FAILURE);
            }
            persons = new_persons;
            *num_persons = row;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int num_persons = 0;
    Person *persons = malloc(sizeof(Person));
    if (persons == NULL) {
        fprintf(stderr, "Out of memory\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    read_csv(file, persons, &num_persons);
    fclose(file);

    printf("Loaded %d persons from CSV file:\n", num_persons);

    for (int i = 0; i < num_persons; i++) {
        printf("%s (%d years, %.2f kg)\n", persons[i].name, persons[i].age, persons[i].weight);
    }

    free(persons);
    return EXIT_SUCCESS;
}