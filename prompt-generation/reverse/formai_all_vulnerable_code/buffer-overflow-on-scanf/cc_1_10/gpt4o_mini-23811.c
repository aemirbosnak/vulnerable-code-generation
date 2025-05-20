//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define INITIAL_CAPACITY 2

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

typedef struct {
    Person *people;
    size_t size;
    size_t capacity;
} PersonList;

void initPersonList(PersonList *list) {
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    list->people = malloc(list->capacity * sizeof(Person));
    if (list->people == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

void freePersonList(PersonList *list) {
    free(list->people);
    list->people = NULL;
    list->size = 0;
    list->capacity = 0;
}

void addPerson(PersonList *list, const char *name, int age) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->people = realloc(list->people, list->capacity * sizeof(Person));
        if (list->people == NULL) {
            fprintf(stderr, "Memory reallocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }
    strncpy(list->people[list->size].name, name, MAX_NAME_LENGTH);
    list->people[list->size].name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    list->people[list->size].age = age;
    list->size++;
}

void printPeople(const PersonList *list) {
    printf("People List:\n");
    for (size_t i = 0; i < list->size; i++) {
        printf("Name: %s, Age: %d\n", list->people[i].name, list->people[i].age);
    }
}

int main() {
    PersonList list;
    initPersonList(&list);

    char buffer[MAX_NAME_LENGTH];
    int age;
    char cont = 'y';

    while (cont == 'y' || cont == 'Y') {
        printf("Enter name: ");
        fgets(buffer, MAX_NAME_LENGTH, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character

        printf("Enter age: ");
        scanf("%d", &age);
        getchar(); // Consume the leftover newline
        
        addPerson(&list, buffer, age);

        printf("Do you want to add another person? (y/n): ");
        scanf(" %c", &cont);
        getchar(); // Consume the leftover newline
    }

    printPeople(&list);
    freePersonList(&list);

    return 0;
}