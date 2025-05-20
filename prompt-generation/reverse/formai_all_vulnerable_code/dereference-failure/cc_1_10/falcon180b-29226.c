//Falcon-180B DATASET v1.0 Category: Text processing ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} person_t;

int main() {
    FILE *file;
    char line[1024];
    char delim = ',';
    person_t *people = NULL;
    int num_people = 0;

    // Open file
    file = fopen("people.csv", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read header line
    fgets(line, sizeof(line), file);

    // Read each line and add person to list
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));

        // Allocate memory for new person
        person_t *new_person = malloc(sizeof(person_t));
        new_person->name = strdup(name);
        new_person->age = age;

        // Add new person to list
        people = realloc(people, sizeof(person_t) * ++num_people);
        people[num_people - 1] = *new_person;
    }

    // Close file
    fclose(file);

    // Print list of people
    for (int i = 0; i < num_people; i++) {
        printf("%s is %d years old.\n", people[i].name, people[i].age);
    }

    // Free memory
    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
    }
    free(people);

    return 0;
}