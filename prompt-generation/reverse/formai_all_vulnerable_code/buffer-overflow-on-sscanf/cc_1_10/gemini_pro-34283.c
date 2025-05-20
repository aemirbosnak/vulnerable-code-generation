//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *gender;
    char *occupation;
} person;

person *people;
int num_people;

void load_data() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        perror("Error opening data file");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *name, *age, *gender, *occupation;
        if (sscanf(line, "%s,%s,%s,%s", name, age, gender, occupation) != 4) {
            fprintf(stderr, "Error parsing data line: %s", line);
            continue;
        }

        person new_person;
        new_person.name = strdup(name);
        new_person.age = atoi(age);
        new_person.gender = strdup(gender);
        new_person.occupation = strdup(occupation);

        people = realloc(people, (num_people + 1) * sizeof(person));
        people[num_people++] = new_person;
    }

    fclose(fp);
}

void free_data() {
    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
        free(people[i].gender);
        free(people[i].occupation);
    }
    free(people);
}

void print_data() {
    for (int i = 0; i < num_people; i++) {
        printf("%s,%d,%s,%s\n", people[i].name, people[i].age, people[i].gender, people[i].occupation);
    }
}

int main() {
    load_data();
    print_data();
    free_data();
    return 0;
}