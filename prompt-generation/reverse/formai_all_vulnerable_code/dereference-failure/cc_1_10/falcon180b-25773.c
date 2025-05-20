//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

int main() {
    FILE *csv_file = fopen("data.csv", "r");
    if (csv_file == NULL) {
        printf("Error: Cannot open CSV file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    Person *people = NULL;
    int num_people = 0;

    while (fgets(line, MAX_LINE_LENGTH, csv_file)!= NULL) {
        char *token = strtok(line, ",");
        if (token == NULL) {
            continue;
        }

        Person *new_person = malloc(sizeof(Person));
        if (new_person == NULL) {
            printf("Error: Cannot allocate memory for new person.\n");
            exit(1);
        }

        new_person->name = strdup(token);
        token = strtok(NULL, ",");
        new_person->age = atoi(token);
        token = strtok(NULL, ",");
        new_person->email = strdup(token);

        people = realloc(people, sizeof(Person) * ++num_people);
        if (people == NULL) {
            printf("Error: Cannot reallocate memory for people.\n");
            exit(1);
        }
        people[num_people - 1] = *new_person;
        free(new_person);
    }

    fclose(csv_file);

    for (int i = 0; i < num_people; i++) {
        printf("Name: %s\nAge: %d\nEmail: %s\n\n", people[i].name, people[i].age, people[i].email);
        free(people[i].name);
        free(people[i].email);
    }

    free(people);

    return 0;
}