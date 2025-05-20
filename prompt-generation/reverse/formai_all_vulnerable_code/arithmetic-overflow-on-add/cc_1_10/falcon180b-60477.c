//Falcon-180B DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char name[MAX_LINE_LENGTH];
    int age;
} Person;

void read_file(FILE *file, Person *person) {
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        printf("Error reading file\n");
        exit(1);
    }
    sscanf(line, "%s %d", person->name, &person->age);
}

void write_file(FILE *file, Person *person) {
    fprintf(file, "%s %d\n", person->name, person->age);
}

void print_person(Person *person) {
    printf("%s is %d years old\n", person->name, person->age);
}

int main() {
    FILE *file = fopen("people.txt", "r+");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    Person person;
    read_file(file, &person);
    print_person(&person);

    person.age++;
    write_file(file, &person);

    rewind(file);
    Person new_person;
    read_file(file, &new_person);
    print_person(&new_person);

    fclose(file);
    return 0;
}