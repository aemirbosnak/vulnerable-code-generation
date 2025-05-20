//Falcon-180B DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    int age;
} Person;

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_LINE_SIZE];
    Person *people = NULL;
    int numPeople = 0;

    inputFile = fopen("input.txt", "r");
    if (!inputFile) {
        printf("Error opening input file.\n");
        exit(1);
    }

    outputFile = fopen("output.txt", "w");
    if (!outputFile) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, inputFile)!= NULL) {
        Person *newPerson = malloc(sizeof(Person));
        if (!newPerson) {
            printf("Error allocating memory for new person.\n");
            exit(1);
        }

        newPerson->name = strdup(line);
        newPerson->age = atoi(strtok(line, ","));
        people = realloc(people, sizeof(Person) * ++numPeople);
        people[numPeople - 1] = *newPerson;
        free(newPerson);
    }

    fprintf(outputFile, "Name,Age\n");
    for (int i = 0; i < numPeople; i++) {
        fprintf(outputFile, "%s,%d\n", people[i].name, people[i].age);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}