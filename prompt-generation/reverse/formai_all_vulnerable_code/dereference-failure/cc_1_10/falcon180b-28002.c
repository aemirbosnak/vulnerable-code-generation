//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    char *name;
    int age;
} Person;

void read_people(FILE *file, Person *people, int *count) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        Person person = {name, age};
        people[*count] = person;
        (*count)++;
    }
}

void print_people(Person *people, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s is %d years old.\n", people[i].name, people[i].age);
    }
}

int main() {
    FILE *file = fopen("romeo_and_juliet.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Person people[100];
    int count = 0;

    read_people(file, people, &count);

    fclose(file);

    if (count == 0) {
        printf("Error: No people found in file.\n");
        return 1;
    }

    print_people(people, count);

    return 0;
}