//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    char *occupation;
} Person;

void read_data(Person *people, int *size) {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error reading file.\n");
        exit(1);
    }

    char line[MAX_SIZE];
    int count = 0;
    while (fgets(line, MAX_SIZE, file)!= NULL) {
        char *name = strtok(line, ",");
        char *age_str = strtok(NULL, ",");
        char *occupation = strtok(NULL, ",");

        int age = atoi(age_str);
        if (count >= *size) {
            printf("Array is full. Cannot add more elements.\n");
            fclose(file);
            exit(1);
        }

        people[count] = (Person) {
           .name = strdup(name),
           .age = age,
           .occupation = strdup(occupation)
        };
        count++;
    }

    fclose(file);
    *size = count;
}

void print_data(Person *people, int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Age: %d, Occupation: %s\n", people[i].name, people[i].age, people[i].occupation);
    }
}

void search_data(Person *people, int size, char *query) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(people[i].name, query) == 0) {
            printf("Found person with name %s\n", query);
            printf("Name: %s, Age: %d, Occupation: %s\n", people[i].name, people[i].age, people[i].occupation);
            count++;
        }
    }

    if (count == 0) {
        printf("No person found with name %s.\n", query);
    }
}

int main() {
    Person *people = malloc(MAX_SIZE * sizeof(Person));
    int size = 0;

    read_data(people, &size);

    char query[MAX_SIZE];
    printf("Enter name to search: ");
    scanf("%s", query);

    search_data(people, size, query);

    free(people);
    return 0;
}