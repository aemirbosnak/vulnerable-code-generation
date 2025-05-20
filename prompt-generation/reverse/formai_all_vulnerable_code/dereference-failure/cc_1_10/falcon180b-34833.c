//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    int age;
    float salary;
} Person;

int main() {
    FILE *csv_file = fopen("data.csv", "r");
    if (csv_file == NULL) {
        printf("Error opening CSV file.\n");
        return 1;
    }

    char line[MAX_LINE_SIZE];
    Person *people = NULL;
    int num_people = 0;

    while (fgets(line, MAX_LINE_SIZE, csv_file)!= NULL) {
        char *token = strtok(line, ",");
        if (token == NULL) {
            continue;
        }
        Person *new_person = malloc(sizeof(Person));
        new_person->name = strdup(token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Invalid CSV format.\n");
            return 1;
        }
        new_person->age = atoi(token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Invalid CSV format.\n");
            return 1;
        }
        new_person->salary = atof(token);
        people = realloc(people, sizeof(Person) * ++num_people);
        people[num_people - 1] = *new_person;
        free(new_person);
    }

    for (int i = 0; i < num_people; i++) {
        printf("%s is %d years old and earns $%.2f.\n", people[i].name, people[i].age, people[i].salary);
    }

    free(people);
    fclose(csv_file);
    return 0;
}