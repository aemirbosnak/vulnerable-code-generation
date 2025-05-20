//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_COLUMNS 100
#define MAX_LINE_LENGTH 1024

typedef struct {
    char name[MAX_LINE_LENGTH];
    int age;
} Person;

void read_csv_line(char *line, Person *persons, int *num_persons) {
    char *token;
    char delimiter[] = ",";
    int columns = 0;

    token = strtok(line, delimiter);
    while (token != NULL && columns < MAX_CSV_COLUMNS) {
        if (columns < 2) {
            strcpy(persons[*num_persons].name, token);
        } else {
            persons[*num_persons].age = atoi(token);
            (*num_persons)++;
            if (*num_persons >= MAX_CSV_COLUMNS) {
                fprintf(stderr, "Too many columns in CSV file\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, delimiter);
        columns++;
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    Person persons[MAX_CSV_COLUMNS];
    int num_persons = 0;

    file = fopen("input.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        read_csv_line(line, persons, &num_persons);
        printf("Person %d: %s, %d\n", num_persons, persons[num_persons - 1].name, persons[num_persons - 1].age);
    }

    fclose(file);

    return EXIT_SUCCESS;
}