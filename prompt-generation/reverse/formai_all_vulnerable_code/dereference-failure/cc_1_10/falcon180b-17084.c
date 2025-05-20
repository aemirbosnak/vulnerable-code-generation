//Falcon-180B DATASET v1.0 Category: Error handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    int age;
} Person;

int read_people_from_file(FILE *file, Person *people, int max_people) {
    char line[MAX_LINE_LENGTH];
    int num_people = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *name = strtok(line, ",");
        if (name == NULL) {
            fprintf(stderr, "Error: Invalid line format\n");
            return -1;
        }

        int age = atoi(strtok(NULL, ","));
        if (age <= 0) {
            fprintf(stderr, "Error: Invalid age\n");
            return -1;
        }

        if (num_people >= max_people) {
            fprintf(stderr, "Error: Maximum number of people exceeded\n");
            return -1;
        }

        people[num_people].name = strdup(name);
        people[num_people].age = age;
        num_people++;
    }

    return num_people;
}

void print_people(Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        printf("%s is %d years old.\n", people[i].name, people[i].age);
    }
}

int main() {
    FILE *file = fopen("people.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file (%d)\n", errno);
        return -1;
    }

    Person people[100];
    int num_people = read_people_from_file(file, people, sizeof(people) / sizeof(Person));

    if (num_people > 0) {
        print_people(people, num_people);
    } else {
        fprintf(stderr, "Error: No valid people found in file\n");
    }

    fclose(file);
    return 0;
}