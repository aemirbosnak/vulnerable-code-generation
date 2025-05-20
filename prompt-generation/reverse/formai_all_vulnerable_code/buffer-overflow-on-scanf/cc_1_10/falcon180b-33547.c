//Falcon-180B DATASET v1.0 Category: Database querying ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_QUERY_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} Person;

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

void read_person(Person *person) {
    printf("Enter name: ");
    scanf("%s", person->name);
    printf("Enter age: ");
    scanf("%d", &person->age);
}

int main() {
    Person *people = NULL;
    int num_people = 0;
    char query[MAX_QUERY_LEN];

    // Read in data
    while (1) {
        printf("Enter a person (name age): ");
        scanf("%s %d", query, &num_people);
        if (num_people == 0) {
            break;
        }
        people = realloc(people, sizeof(Person) * num_people);
        for (int i = 0; i < num_people; i++) {
            read_person(&people[i]);
        }
    }

    // Query data
    while (1) {
        printf("Enter a query (name=value or age=value): ");
        scanf("%s", query);
        if (strcmp(query, "quit") == 0) {
            break;
        }
        int num_matches = 0;
        for (int i = 0; i < num_people; i++) {
            if (strcmp(people[i].name, query) == 0) {
                print_person(&people[i]);
                num_matches++;
            } else if (atoi(query) == people[i].age) {
                print_person(&people[i]);
                num_matches++;
            }
        }
        if (num_matches == 0) {
            printf("No matches found.\n");
        }
    }

    free(people);
    return 0;
}