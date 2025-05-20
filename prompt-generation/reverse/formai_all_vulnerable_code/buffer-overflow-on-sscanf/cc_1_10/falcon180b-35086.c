//Falcon-180B DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_LINE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char address[MAX_LINE_LEN];
} Person;

void read_people(FILE *file, Person people[], int *num_people) {
    char line[MAX_LINE_LEN];
    fgets(line, MAX_LINE_LEN, file); // read first line (header)
    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        Person person;
        sscanf(line, "%s %d %s", person.name, &person.age, person.address);
        people[*num_people] = person;
        (*num_people)++;
    }
}

void write_people(FILE *file, Person people[], int num_people) {
    fprintf(file, "Name\tAge\tAddress\n");
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s\t%d\t%s\n", people[i].name, people[i].age, people[i].address);
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    Person people[100];
    int num_people = 0;
    read_people(input_file, people, &num_people);

    write_people(output_file, people, num_people);

    fclose(input_file);
    fclose(output_file);

    return 0;
}