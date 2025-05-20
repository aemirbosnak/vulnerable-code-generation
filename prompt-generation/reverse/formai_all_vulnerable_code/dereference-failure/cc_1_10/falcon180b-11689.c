//Falcon-180B DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char name[50];
    int age;
} Person;

void read_file(FILE* file, Person people[], int* num_people) {
    char line[MAX_LINE_LENGTH];
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (i >= *num_people) {
            printf("Error: Too many people in file.\n");
            exit(1);
        }

        int j = 0;
        char* token = strtok(line, ",");
        strcpy(people[i].name, token);

        token = strtok(NULL, ",");
        people[i].age = atoi(token);

        i++;
    }

    *num_people = i;
}

void write_file(FILE* file, Person people[], int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s,%d\n", people[i].name, people[i].age);
    }
}

void sort_people(Person people[], int num_people) {
    for (int i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[j].age < people[i].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    FILE* output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    Person people[MAX_LINE_LENGTH];
    int num_people = 0;

    read_file(input_file, people, &num_people);

    sort_people(people, num_people);

    write_file(output_file, people, num_people);

    fclose(input_file);
    fclose(output_file);

    return 0;
}