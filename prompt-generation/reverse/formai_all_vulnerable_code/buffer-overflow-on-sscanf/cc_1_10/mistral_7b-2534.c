//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 100
#define MAX_LENGTH 256

typedef struct {
    char name[MAX_LENGTH];
    int age;
    char gender;
    double weight;
} Person;

void read_csv(FILE *file, Person *people, int *num_people) {
    char line[MAX_LENGTH];
    char *token;
    int i = 0;

    *num_people = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        Person person;
        sscanf(line, "%s %d %c %lf", person.name, &person.age, &person.gender, &person.weight);

        if (strlen(person.name) > 0 && strlen(person.name) < MAX_LENGTH) {
            people[*num_people] = person;
            (*num_people)++;
        }
    }
}

int main() {
    FILE *file;
    Person people[MAX_FIELDS];
    int num_people;

    file = fopen("data.csv", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_csv(file, people, &num_people);
    fclose(file);

    printf("Read %d people from the CSV file.\n", num_people);

    for (int i = 0; i < num_people; i++) {
        printf("%s (%d years old, %c, %.2f kg)\n", people[i].name, people[i].age, people[i].gender, people[i].weight);
    }

    return 0;
}