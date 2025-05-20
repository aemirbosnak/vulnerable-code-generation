//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FIELDS 100
#define DELIMITER ','

typedef struct {
    char *name;
    int age;
} Person;

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    char delimiter = DELIMITER;
    Person people[MAX_FIELDS];
    int num_people = 0;

    file = fopen("data.csv", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, &delimiter);

        while (token!= NULL) {
            if (num_people >= MAX_FIELDS) {
                printf("Error: Too many fields.\n");
                exit(1);
            }

            people[num_people].name = strdup(token);
            token = strtok(NULL, &delimiter);

            if (token == NULL) {
                printf("Error: Missing age.\n");
                exit(1);
            }

            people[num_people].age = atoi(token);
            num_people++;

            token = strtok(NULL, &delimiter);
        }
    }

    fclose(file);

    printf("Name\tAge\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s\t%d\n", people[i].name, people[i].age);
    }

    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
    }

    return 0;
}