//Code Llama-13B DATASET v1.0 Category: Data recovery tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char* name;
    int age;
    float height;
    char gender;
} Person;

void read_data(char* file_path, Person* people, int* num_people) {
    FILE* file = fopen(file_path, "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file.\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        char* name = strtok(buffer, ",");
        char* age = strtok(NULL, ",");
        char* height = strtok(NULL, ",");
        char* gender = strtok(NULL, ",");

        Person person;
        person.name = name;
        person.age = atoi(age);
        person.height = atof(height);
        person.gender = gender[0];

        people[*num_people] = person;
        (*num_people)++;
    }

    fclose(file);
}

void write_data(char* file_path, Person* people, int num_people) {
    FILE* file = fopen(file_path, "w");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file.\n");
        exit(1);
    }

    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s, %d, %f, %c\n", people[i].name, people[i].age, people[i].height, people[i].gender);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }

    char* input_file_path = argv[1];
    char* output_file_path = argv[2];

    int num_people = 0;
    Person* people = (Person*)malloc(sizeof(Person) * 1000);

    read_data(input_file_path, people, &num_people);
    write_data(output_file_path, people, num_people);

    free(people);

    return 0;
}