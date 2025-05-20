//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

Person people[MAX_SIZE];
int num_people = 0;

void add_person(char *name, int age) {
    if (num_people >= MAX_SIZE) {
        printf("Error: Maximum number of people reached!\n");
        return;
    }
    people[num_people].name = malloc(strlen(name) + 1);
    strcpy(people[num_people].name, name);
    people[num_people].age = age;
    num_people++;
}

void search_people(char *query) {
    int i;
    char *name;
    char *token;
    int age;
    char *age_str;

    printf("Searching for people:\n");
    for (i = 0; i < num_people; i++) {
        name = people[i].name;
        age_str = strchr(name, '(');
        if (age_str!= NULL) {
            age_str++;
            age = atoi(age_str);
        } else {
            age = -1;
        }
        if (strstr(name, query)!= NULL && age >= 18) {
            printf("%s (%d years old)\n", name, age);
        }
    }
}

int main() {
    add_person("John Doe", 25);
    add_person("Jane Smith", 30);
    add_person("Bob Johnson", 40);
    add_person("Alice Brown", 22);
    add_person("Charlie Green", 19);

    printf("All people:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s (%d years old)\n", people[i].name, people[i].age);
    }

    search_people("Doe");
    search_people("Smith");
    search_people("Johnson");
    search_people("Brown");
    search_people("Green");

    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
    }

    return 0;
}