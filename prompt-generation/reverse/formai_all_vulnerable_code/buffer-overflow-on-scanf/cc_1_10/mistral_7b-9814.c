//MISTRAL-7B DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LEN 100
#define NUM_ELEM 10

typedef struct {
    char name[MAX_LEN];
    int age;
} Person;

bool is_valid_name(const char *name) {
    int len = strlen(name);
    if (len < 1 || len > MAX_LEN) {
        return false;
    }
    for (int i = 0; i < len; ++i) {
        if (!isalpha(name[i]) && name[i] != '_') {
            return false;
        }
    }
    return true;
}

void print_person(const Person *person) {
    printf("%s (%d years old)\n", person->name, person->age);
}

int main() {
    srand(time(NULL));

    Person people[NUM_ELEM];

    for (int i = 0; i < NUM_ELEM; ++i) {
        char name[MAX_LEN];
        printf("Enter name %d: ", i + 1);
        scanf("%s", name);
        while (!is_valid_name(name)) {
            printf("Invalid name. Please enter a name that is: \n1. Between 1 and %d characters long.\n2. Consists only of letters and underscores.\n", MAX_LEN);
            printf("Enter name %d: ", i + 1);
            scanf("%s", name);
        }
        strcpy(people[i].name, name);
        people[i].age = rand() % 100 + 1;
    }

    printf("\nList of people:\n");
    for (int i = 0; i < NUM_ELEM; ++i) {
        print_person(&people[i]);
    }

    return 0;
}