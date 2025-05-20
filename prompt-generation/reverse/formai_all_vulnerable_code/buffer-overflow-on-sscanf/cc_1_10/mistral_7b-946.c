//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WIDTH 256
#define MAX_FIELDS 128

typedef struct {
    char name[MAX_WIDTH];
    int age;
    char gender;
    double income;
} Person;

void csv_parse(FILE *fp, Person *people, size_t *num_people) {
    char line[MAX_WIDTH];
    char *token;
    size_t index = 0;

    *num_people = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%[^,],%d,%c,%lf", people[index].name, &people[index].age, &people[index].gender, &people[index].income);
        (*num_people)++;
    }
}

int main(int argc, char **argv) {
    FILE *csv_file;
    Person people[MAX_FIELDS];
    size_t num_people = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv-file>\n", argv[0]);
        return 1;
    }

    csv_file = fopen(argv[1], "r");
    if (csv_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    csv_parse(csv_file, people, &num_people);
    fclose(csv_file);

    printf("Parsed %ld records:\n", num_people);

    for (size_t i = 0; i < num_people; ++i) {
        printf("Name: %s, Age: %d, Gender: %c, Income: %f\n", people[i].name, people[i].age, people[i].gender, people[i].income);
    }

    return 0;
}