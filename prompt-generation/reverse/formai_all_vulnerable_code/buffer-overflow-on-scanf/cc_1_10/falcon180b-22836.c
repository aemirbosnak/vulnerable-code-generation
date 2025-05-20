//Falcon-180B DATASET v1.0 Category: File handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    int age;
} Person;

int main() {
    FILE *file;
    char filename[MAX_LINE_SIZE];
    Person *people = NULL;
    int num_people = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(filename, MAX_LINE_SIZE, file)!= NULL) {
        char *line = strdup(filename);
        Person *person = malloc(sizeof(Person));

        person->name = strtok(line, ",");
        person->age = atoi(strtok(NULL, ","));

        people = realloc(people, sizeof(Person) * ++num_people);
        people[num_people - 1] = *person;
        free(person);
    }

    fclose(file);

    printf("Number of people: %d\n", num_people);

    for (int i = 0; i < num_people; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }

    free(people);
    return 0;
}