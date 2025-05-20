//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLUMNS 100
#define MAX_LENGTH 256

typedef struct {
    char name[MAX_LENGTH];
    int age;
} Person;

void skip_whitespace(FILE *file) {
    int c;
    while ((c = fgetc(file)) != EOF && isspace(c)) {}
    ungetc(c, file);
}

void read_line(FILE *file, char *buffer, size_t size) {
    size_t i = 0;
    int c;
    while ((c = fgetc(file)) != EOF && i < size - 1) {
        buffer[i++] = c;
        if (c == '\n') {
            buffer[i] = '\0';
            break;
        }
    }
    buffer[i] = '\0';
}

int parse_csv_line(FILE *file, Person *person, size_t index) {
    char name[MAX_LENGTH];
    char *comma;
    int age;

    skip_whitespace(file);

    read_line(file, name, sizeof(name));

    if (index > 0 && strcmp(name, "")) {
        person[index - 1].name[strlen(person[index - 1].name)] = ',';
    }

    strcpy(person[index].name, name);

    skip_whitespace(file);

    if (sscanf(file, "%d%n", &age, &index) != 1) {
        return -1;
    }

    fseek(file, index, SEEK_SET);

    person[index].age = age;

    return 0;
}

int read_csv_file(const char *filename, Person *persons, size_t max_persons) {
    FILE *file;
    size_t index = 0;

    file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    while (index < max_persons - 1 && parse_csv_line(file, persons, index) == 0) {}

    fclose(file);

    if (ferror(file)) {
        perror("Error reading file");
        return -1;
    }

    return index + 1;
}

int main() {
    Person people[MAX_COLUMNS];
    size_t num_people;

    if (read_csv_file("people.csv", people, MAX_COLUMNS) < 0) {
        perror("Error reading file");
        return 1;
    }

    for (size_t i = 0; i < num_people; i++) {
        printf("%s (%d years old)\n", people[i].name, people[i].age);
    }

    return 0;
}