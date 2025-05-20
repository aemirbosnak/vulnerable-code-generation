//Falcon-180B DATASET v1.0 Category: File handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    int age;
} Person;

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char delimiter = ',';
    Person *people = NULL;
    int num_people = 0;
    int i;

    printf("Enter the name of the CSV file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_people == 0) {
            // First line contains column names
            char *token = strtok(line, ",");
            while (token!= NULL) {
                if (strcmp(token, "name") == 0) {
                    delimiter = ',';
                } else if (strcmp(token, "age") == 0) {
                    delimiter = ',';
                }
                token = strtok(NULL, ",");
            }
        } else {
            // Subsequent lines contain data
            char *name = strtok(line, delimiter);
            int age = atoi(strtok(NULL, delimiter));

            Person *new_person = malloc(sizeof(Person));
            new_person->name = strdup(name);
            new_person->age = age;
            people = realloc(people, sizeof(Person) * ++num_people);
            people[num_people - 1] = *new_person;
            free(new_person);
        }
    }

    fclose(file);

    printf("Name\tAge\n");
    for (i = 0; i < num_people; i++) {
        printf("%s\t%d\n", people[i].name, people[i].age);
    }

    free(people);

    return 0;
}