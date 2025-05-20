//FormAI DATASET v1.0 Category: File handling ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_AGE 120

struct Person {
    char name[MAX_NAME_LENGTH];
    int age;
};

void write_person_struct_to_file(struct Person* person, FILE* file) {
    fwrite(person->name, sizeof(char), MAX_NAME_LENGTH, file);
    fwrite(&person->age, sizeof(int), 1, file);
}

void read_person_struct_from_file(struct Person* person, FILE* file) {
    fread(person->name, sizeof(char), MAX_NAME_LENGTH, file);
    fread(&person->age, sizeof(int), 1, file);
}

void parse_args(int argc, char** argv, char* read_file_name, char* write_file_name) {
    if (argc < 3) {
        printf("Usage: %s <read_file> <write_file>\n", argv[0]);
        exit(1);
    }
    strcpy(read_file_name, argv[1]);
    strcpy(write_file_name, argv[2]);
}

int main(int argc, char** argv) {
    char read_file_name[MAX_NAME_LENGTH];
    char write_file_name[MAX_NAME_LENGTH];
    FILE* read_file;
    FILE* write_file;
    struct Person* person;
    int num_people;

    parse_args(argc, argv, read_file_name, write_file_name);

    // Open input and output files
    read_file = fopen(read_file_name, "rb");
    if (read_file == NULL) {
        printf("Error: could not open file '%s'\n", read_file_name);
        exit(1);
    }
    write_file = fopen(write_file_name, "wb");
    if (write_file == NULL) {
        printf("Error: could not open file '%s'\n", write_file_name);
        fclose(read_file); // Clean up read file handle
        exit(1);
    }

    // Read input file and write to output file
    printf("Reading from file '%s' and writing to file '%s'\n", read_file_name, write_file_name);
    fread(&num_people, sizeof(int), 1, read_file);
    printf("Number of people: %d\n", num_people);
    for (int i = 0; i < num_people; i++) {
        person = malloc(sizeof(struct Person));
        if (person == NULL) {
            printf("Error: out of memory\n");
            fclose(read_file); // Clean up file handles
            fclose(write_file);
            exit(1);
        }
        read_person_struct_from_file(person, read_file);
        printf("Person %d: name='%s', age=%d\n", i+1, person->name, person->age);
        person->age += 1; // Increment age by 1
        write_person_struct_to_file(person, write_file);
        free(person); // Clean up person struct
    }

    // Clean up file handles
    fclose(read_file);
    fclose(write_file);

    printf("Done!\n");
    return 0;
}