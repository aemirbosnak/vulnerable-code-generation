//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *email;
    int age;
} Person;

Person *people = NULL;
int num_people = 0;

void read_csv_file(FILE *file) {
    char line[MAX_LINE_LENGTH];
    char *token;
    Person *curr_person = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        num_people++;
        people = realloc(people, num_people * sizeof(Person));

        curr_person = &people[num_people - 1];
        curr_person->name = NULL;
        curr_person->email = NULL;
        curr_person->age = 0;

        token = strtok(line, ",");
        while (token!= NULL) {
            if (curr_person->name == NULL) {
                curr_person->name = strdup(token);
            } else if (curr_person->email == NULL) {
                curr_person->email = strdup(token);
            } else if (curr_person->age == 0) {
                curr_person->age = atoi(token);
            }

            token = strtok(NULL, ",");
        }
    }
}

void print_people() {
    int i;

    for (i = 0; i < num_people; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Email: %s\n", people[i].email);
        printf("Age: %d\n\n", people[i].age);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;

    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    read_csv_file(file);
    fclose(file);

    print_people();

    return 0;
}