//Falcon-180B DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char* name;
    int age;
} Person;

void read_file(FILE* file, Person* people, int max_people, int* num_people) {
    char line[MAX_LINE_LENGTH];
    char* token;
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL && i < max_people) {
        token = strtok(line, ",");
        if (token == NULL) {
            continue;
        }

        people[i].name = strdup(token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Invalid line format: %s\n", line);
            exit(1);
        }

        people[i].age = atoi(token);
        i++;
    }

    *num_people = i;
}

void write_file(FILE* file, Person* people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s,%d\n", people[i].name, people[i].age);
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    FILE* output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    Person people[100];
    int num_people = 0;

    read_file(input_file, people, 100, &num_people);

    for (int i = 0; i < num_people; i++) {
        printf("%s is %d years old\n", people[i].name, people[i].age);
    }

    write_file(output_file, people, num_people);

    fclose(input_file);
    fclose(output_file);

    return 0;
}