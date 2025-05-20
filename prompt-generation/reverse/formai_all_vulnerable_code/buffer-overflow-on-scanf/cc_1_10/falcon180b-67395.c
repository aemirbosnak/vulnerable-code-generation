//Falcon-180B DATASET v1.0 Category: File handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    char *address;
    int age;
} Person;

int main() {
    FILE *file;
    char filename[50];
    char line[MAX_LINE_LENGTH];
    char delimiter = ',';
    Person people[100];
    int num_people = 0;

    printf("Enter the name of the CSV file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, &delimiter);

        if (num_people >= 100) {
            printf("Maximum number of people reached.\n");
            break;
        }

        if (token == NULL) {
            continue;
        }

        people[num_people].name = strdup(token);

        token = strtok(NULL, &delimiter);

        if (token == NULL) {
            printf("Missing address for person.\n");
            continue;
        }

        people[num_people].address = strdup(token);

        token = strtok(NULL, &delimiter);

        if (token == NULL) {
            printf("Missing age for person.\n");
            continue;
        }

        people[num_people].age = atoi(token);

        num_people++;
    }

    fclose(file);

    printf("Number of people: %d\n", num_people);

    for (int i = 0; i < num_people; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Address: %s\n", people[i].address);
        printf("Age: %d\n\n", people[i].age);
    }

    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
        free(people[i].address);
    }

    free(people);

    return 0;
}