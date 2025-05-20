//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float height;
    char gender;
} Person;

void readPerson(FILE *fp, Person *person) {
    fscanf(fp, "%s %d %f %c", person->name, &person->age, &person->height, &person->gender);
}

void writePerson(FILE *fp, Person person) {
    fprintf(fp, "%s %d %.2f %c\n", person.name, person.age, person.height, person.gender);
}

void loadPeople(char *filename, Person people[], int *numPeople) {
    FILE *fp = fopen(filename, "r");
    int i = 0;

    if (fp == NULL) {
        printf("Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%s %d %f %c", people[i].name, &people[i].age, &people[i].height, &people[i].gender) != EOF) {
        i++;
    }

    *numPeople = i;
    fclose(fp);
}

void savePeople(char *filename, Person people[], int numPeople) {
    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numPeople; i++) {
        writePerson(fp, people[i]);
    }

    fclose(fp);
}

int main() {
    Person newPerson = {"John Doe", 25, 1.80, 'M'};
    Person people[MAX_SIZE];
    int numPeople = 0;
    char filename[] = "people.dat";

    // Write new person to file
    savePeople(filename, &newPerson, 1);

    // Load all people from file
    loadPeople(filename, people, &numPeople);

    printf("Loaded %d people from file:\n", numPeople);

    for (int i = 0; i < numPeople; i++) {
        printf("%s %d %.2f %c\n", people[i].name, people[i].age, people[i].height, people[i].gender);
    }

    // Add a new person to the file
    newPerson.age = 30;
    savePeople(filename, &newPerson, numPeople + 1);

    loadPeople(filename, people, &numPeople);

    printf("Loaded %d people from file:\n", numPeople);

    for (int i = 0; i < numPeople; i++) {
        printf("%s %d %.2f %c\n", people[i].name, people[i].age, people[i].height, people[i].gender);
    }

    return 0;
}