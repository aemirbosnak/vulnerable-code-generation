//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

void read_csv_file(FILE *fp, Person *people, int num_people) {
    char line[MAX_LINE_LENGTH];
    char delimiter = ',';
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (i >= num_people) {
            break;
        }

        char *token = strtok(line, &delimiter);
        if (token == NULL) {
            continue;
        }

        people[i].name = strdup(token);

        token = strtok(NULL, &delimiter);
        if (token == NULL) {
            continue;
        }

        people[i].age = atoi(token);

        token = strtok(NULL, &delimiter);
        if (token == NULL) {
            continue;
        }

        people[i].email = strdup(token);

        i++;
    }
}

void print_people(Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Email: %s\n\n", people[i].email);
    }
}

int main() {
    FILE *fp;
    fp = fopen("people.csv", "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Person people[10];
    int num_people = 0;

    while (fscanf(fp, "%s %d %s\n", people[num_people].name, &people[num_people].age, people[num_people].email)!= EOF) {
        num_people++;
    }

    fclose(fp);

    read_csv_file(fp, people, num_people);

    print_people(people, num_people);

    return 0;
}