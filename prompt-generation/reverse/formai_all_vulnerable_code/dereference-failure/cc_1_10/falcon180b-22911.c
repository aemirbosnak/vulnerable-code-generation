//Falcon-180B DATASET v1.0 Category: File handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    int age;
    char *address;
} person_t;

void read_file(FILE *fp, person_t *people, int *count) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        person_t *person = (person_t *) malloc(sizeof(person_t));
        person->name = strtok(line, ",");
        person->age = atoi(strtok(NULL, ","));
        person->address = strtok(NULL, ",");
        people[*count] = *person;
        (*count)++;
    }
}

void write_file(FILE *fp, person_t people[], int count) {
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%d,%s\n", people[i].name, people[i].age, people[i].address);
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int count = 0;
    person_t people[100];
    read_file(input_file, people, &count);

    printf("Total number of records: %d\n", count);

    write_file(output_file, people, count);

    fclose(input_file);
    fclose(output_file);

    return 0;
}