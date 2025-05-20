//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
} Person;

// Function to read data from file
void read_data(FILE* file, Person* people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fscanf(file, "%s %d", people[i].name, &people[i].age);
    }
}

// Function to write data to file
void write_data(FILE* file, Person* people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s %d\n", people[i].name, people[i].age);
    }
}

// Function to search for a person by name
Person* search_person(Person* people, int num_people, char* name) {
    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, name) == 0) {
            return &people[i];
        }
    }
    return NULL;
}

// Function to recover data from a corrupted file
void recover_data(FILE* file, Person* people, int num_people) {
    char name[20];
    int age;
    while (fscanf(file, "%s %d", name, &age) == 2) {
        Person* person = search_person(people, num_people, name);
        if (person == NULL) {
            fprintf(stdout, "Recovered data for %s (%d years old)\n", name, age);
            person = &people[num_people++];
            strcpy(person->name, name);
            person->age = age;
        } else {
            fprintf(stdout, "Duplicate data for %s (%d years old)\n", name, age);
        }
    }
}

int main() {
    FILE* file = fopen("data.txt", "r+");
    if (file == NULL) {
        fprintf(stdout, "Error: could not open file.\n");
        return 1;
    }

    Person people[100];
    int num_people = 0;

    // Read data from file
    read_data(file, people, num_people);

    // Recover data from corrupted file
    recover_data(file, people, num_people);

    // Write data back to file
    rewind(file);
    write_data(file, people, num_people);

    fclose(file);
    return 0;
}