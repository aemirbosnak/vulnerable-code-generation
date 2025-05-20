//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    int age;
    char secret[MAX_LENGTH];
} Person;

void readPersonData(Person *person, FILE *file) {
    fgets(person->name, MAX_LENGTH, file);
    person->name[strcspn(person->name, "\n")] = '\0';

    fscanf(file, "%d", &person->age);

    fgets(person->secret, MAX_LENGTH, file);
    person->secret[strcspn(person->secret, "\n")] = '\0';

    if (feof(file)) {
        perror("Unexpected end of file");
        exit(EXIT_FAILURE);
    }
}

void printPersonData(Person person) {
    printf("%s (%d years old)\n", person.name, person.age);
    printf("Secret: %s\n", person.secret);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");

    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Person persons[10];

    for (int i = 0; i < 10; i++) {
        if (fscanf(file, "%s %d %s", persons[i].name, &persons[i].age, persons[i].secret) != 3) {
            if (feof(file)) {
                fprintf(stderr, "Error reading data from file\n");
                fclose(file);
                exit(EXIT_FAILURE);
            } else {
                perror("Error reading format of data");
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }

        readPersonData(&persons[i], file);
    }

    for (int i = 0; i < 10; i++) {
        printPersonData(persons[i]);
    }

    fclose(file);
    return EXIT_SUCCESS;
}