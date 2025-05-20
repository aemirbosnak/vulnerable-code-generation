//Falcon-180B DATASET v1.0 Category: Database querying ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    int age;
} Person;

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int main() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    Person *people = NULL;
    int num_people = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));

        Person *new_person = malloc(sizeof(Person));
        new_person->name = strdup(name);
        new_person->age = age;

        people = realloc(people, sizeof(Person) * ++num_people);
        people[num_people - 1] = *new_person;
        free(new_person);
    }

    fclose(file);

    printf("Number of people: %d\n", num_people);

    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    free(people);
    return 0;
}