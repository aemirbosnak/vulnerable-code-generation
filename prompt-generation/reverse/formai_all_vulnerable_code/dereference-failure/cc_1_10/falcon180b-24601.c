//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100
#define MAX_LINE_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} People;

void init_people(People *people) {
    people->data = NULL;
    people->size = 0;
    people->capacity = MAX_SIZE;
}

void destroy_people(People *people) {
    int i;
    for (i = 0; i < people->size; i++) {
        free(people->data[i].name);
    }
    free(people->data);
}

void add_person(People *people, const char *name, int age) {
    if (people->size >= people->capacity) {
        fprintf(stderr, "Error: People list is full.\n");
        exit(1);
    }
    Person *person = malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    people->data[people->size++] = *person;
}

int main() {
    FILE *input_file;
    char line[MAX_LINE_SIZE];
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file.\n");
        exit(1);
    }
    People people;
    init_people(&people);
    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        add_person(&people, name, age);
    }
    fclose(input_file);
    printf("Number of people: %d\n", people.size);
    return 0;
}