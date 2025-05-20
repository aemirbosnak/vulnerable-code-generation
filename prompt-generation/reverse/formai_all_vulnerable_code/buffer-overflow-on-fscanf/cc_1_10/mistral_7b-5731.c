//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_CHAR 256
#define FILE_NAME "input.txt"

typedef struct {
    char name[MAX_CHAR];
    int age;
    char gender;
} Person;

void readFile(FILE *file) {
    Person person;
    while (fread(&person, sizeof(Person), 1, file) > 0) {
        printf("Name: %s, Age: %d, Gender: %c\n", person.name, person.age, person.gender);
    }
}

void writeFile(FILE *file, Person person) {
    fwrite(&person, sizeof(Person), 1, file);
}

int main() {
    FILE *file;
    Person people[10];

    file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        fscanf(file, "%s %d %c", people[i].name, &people[i].age, &people[i].gender);
    }

    readFile(file);

    fclose(file);

    file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Error opening file for write");
        return 1;
    }

    strcpy(people[0].name, "John Doe");
    people[0].age = 30;
    people[0].gender = 'M';

    writeFile(file, people[0]);

    fclose(file);

    file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    readFile(file);

    fclose(file);

    return 0;
}