//Falcon-180B DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char *name;
    int age;
} Person;

void read_person(FILE *file, Person *person) {
    fscanf(file, "%s %d", person->name, &person->age);
}

void write_person(FILE *file, const Person *person) {
    fprintf(file, "%s %d\n", person->name, person->age);
}

void free_person(Person *person) {
    free(person->name);
    free(person);
}

int main() {
    FILE *file = fopen("people.txt", "w+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Person *people = malloc(10 * sizeof(Person));
    if (people == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < 10; ++i) {
        sprintf(people[i].name, "Person %d", i + 1);
        people[i].age = i + 1;
        write_person(file, &people[i]);
    }

    fseek(file, 0, SEEK_SET);

    Person temp_person;
    while (fscanf(file, "%s %d", temp_person.name, &temp_person.age)!= EOF) {
        printf("%s is %d years old.\n", temp_person.name, temp_person.age);
        free_person(&temp_person);
    }

    free(people);
    fclose(file);

    return 0;
}