//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Person;

int main() {
    Person* persons = malloc(100 * sizeof(Person));

    if (persons == NULL) {
        printf("Failed to allocate memory for persons.\n");
        return 1;
    }

    FILE* file = fopen("resumes.txt", "r");
    if (file == NULL) {
        printf("Failed to open resumes file.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || line[0] == '\0') {
            continue;
        }

        char* token;
        int i = 0;
        while ((token = strtok_r(line, ",", &i))!= NULL) {
            if (strcmp(token, "name") == 0) {
                strcpy(persons[i].name, token + strlen("name: "));
            } else if (strcmp(token, "age") == 0) {
                persons[i].age = atoi(token + strlen("age: "));
            } else if (strcmp(token, "salary") == 0) {
                persons[i].salary = atof(token + strlen("salary: "));
            }
        }
    }

    fclose(file);

    // Print the parsed resumes
    printf("Parsed Resumes:\n");
    for (int i = 0; i < 100; i++) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", persons[i].name, persons[i].age, persons[i].salary);
    }

    free(persons);

    return 0;
}