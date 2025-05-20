//Falcon-180B DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char name[MAX_LINE_SIZE];
    int age;
} Person;

void read_people_from_file(FILE* file, Person* people) {
    char line[MAX_LINE_SIZE];
    int num_people = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (num_people >= MAX_LINE_SIZE) {
            printf("Error: too many people in file\n");
            exit(1);
        }

        sscanf(line, "%s %d", people[num_people].name, &people[num_people].age);
        num_people++;
    }
}

void write_people_to_file(FILE* file, Person* people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s %d\n", people[i].name, people[i].age);
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    FILE* output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files\n");
        exit(1);
    }

    Person people[MAX_LINE_SIZE];
    int num_people = 0;

    read_people_from_file(input_file, people);

    for (int i = 0; i < num_people; i++) {
        people[i].age *= 2;
    }

    write_people_to_file(output_file, people, num_people);

    fclose(input_file);
    fclose(output_file);

    return 0;
}