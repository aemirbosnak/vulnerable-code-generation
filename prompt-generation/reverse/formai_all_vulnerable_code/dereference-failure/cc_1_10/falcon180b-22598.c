//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 1000
#define DELIMITER ','

typedef struct {
    char *name;
    int id;
} Person;

typedef struct {
    Person *data;
    int count;
    int capacity;
} PersonArray;

PersonArray *createPersonArray(int capacity) {
    PersonArray *array = (PersonArray *)malloc(sizeof(PersonArray));
    array->data = (Person *)malloc(capacity * sizeof(Person));
    array->count = 0;
    array->capacity = capacity;
    return array;
}

void destroyPersonArray(PersonArray *array) {
    free(array->data);
    free(array);
}

void addPerson(PersonArray *array, char *name, int id) {
    if (array->count >= array->capacity) {
        array->capacity *= 2;
        array->data = (Person *)realloc(array->data, array->capacity * sizeof(Person));
    }
    array->data[array->count] = (Person){.name = strdup(name),.id = id};
    array->count++;
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    PersonArray people = {0};

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, DELIMITER);
        while (token!= NULL) {
            if (people.count >= people.capacity) {
                people.capacity *= 2;
                people.data = (Person *)realloc(people.data, people.capacity * sizeof(Person));
            }
            addPerson(&people, token, people.count + 1);
            token = strtok(NULL, DELIMITER);
        }
    }

    fclose(file);

    for (int i = 0; i < people.count; i++) {
        printf("Name: %s, ID: %d\n", people.data[i].name, people.data[i].id);
    }

    destroyPersonArray(&people);

    return 0;
}