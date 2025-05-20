//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
} person_t;

person_t *data = NULL;
int num_persons = 0;

void init() {
    data = (person_t *)malloc(MAX_SIZE * sizeof(person_t));
    if (data == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    num_persons = 0;
}

void add_person(char *name, int age) {
    if (num_persons >= MAX_SIZE) {
        printf("Error: Maximum number of persons reached.\n");
        return;
    }
    strcpy(data[num_persons].name, name);
    data[num_persons].age = age;
    num_persons++;
}

void search_person(char *name) {
    int i;
    for (i = 0; i < num_persons; i++) {
        if (strcmp(data[i].name, name) == 0) {
            printf("Person found: %s, age: %d\n", data[i].name, data[i].age);
            return;
        }
    }
    printf("Person not found.\n");
}

int main() {
    init();
    add_person("John", 25);
    add_person("Jane", 30);
    add_person("Bob", 40);
    search_person("John");
    search_person("Alice");
    search_person("Bob");
    return 0;
}