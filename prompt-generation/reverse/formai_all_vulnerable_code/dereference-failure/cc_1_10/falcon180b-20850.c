//Falcon-180B DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

typedef struct {
    char name[MAX_LINE_LENGTH];
    int age;
} Person;

void read_data(FILE *file, Person *people, int *num_people) {
    char line[MAX_LINE_LENGTH];
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (i == *num_people) {
            printf("Error: Too many lines in file.\n");
            exit(1);
        }

        if (sscanf(line, "%s %d", people[i].name, &people[i].age)!= 2) {
            printf("Error: Invalid data format.\n");
            exit(1);
        }

        i++;
    }

    *num_people = i;
}

void write_data(FILE *file, Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s %d\n", people[i].name, people[i].age);
    }
}

int main() {
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    Person people[100];
    int num_people = 0;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    read_data(input_file, people, &num_people);

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    write_data(output_file, people, num_people);

    fclose(input_file);
    fclose(output_file);

    printf("Data successfully written to output file.\n");

    return 0;
}