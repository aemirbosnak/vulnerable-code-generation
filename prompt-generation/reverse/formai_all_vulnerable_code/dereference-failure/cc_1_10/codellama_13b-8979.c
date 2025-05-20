//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
/*
 * Building a CSV Reader example program in a innovative style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int age;
    float height;
    float weight;
} Person;

Person* read_csv(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    // Read the first line to get the number of records
    char* line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, fp);
    if (read == -1) {
        fprintf(stderr, "Error reading from file %s\n", filename);
        exit(1);
    }

    int num_records = atoi(line);
    Person* people = malloc(num_records * sizeof(Person));

    // Read the rest of the lines and store the data in the array
    for (int i = 0; i < num_records; i++) {
        read = getline(&line, &len, fp);
        if (read == -1) {
            fprintf(stderr, "Error reading from file %s\n", filename);
            exit(1);
        }

        Person* person = &people[i];
        char* name = strtok(line, ",");
        person->name = strdup(name);
        person->age = atoi(strtok(NULL, ","));
        person->height = atof(strtok(NULL, ","));
        person->weight = atof(strtok(NULL, ","));
    }

    fclose(fp);
    return people;
}

int main() {
    Person* people = read_csv("people.csv");

    for (int i = 0; i < 5; i++) {
        printf("Name: %s, Age: %d, Height: %f, Weight: %f\n", people[i].name, people[i].age, people[i].height, people[i].weight);
    }

    return 0;
}