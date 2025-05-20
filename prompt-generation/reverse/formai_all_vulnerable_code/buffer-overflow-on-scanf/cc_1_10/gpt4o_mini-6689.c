//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define INITIAL_SIZE 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

void add_person(Person **people, int *current_size, int *used_size, char *name, int age) {
    if (*used_size >= *current_size) {
        *current_size *= 2;
        *people = realloc(*people, (*current_size) * sizeof(Person));
        if (*people == NULL) {
            printf("Memory allocation failure!\n");
            exit(EXIT_FAILURE);
        }
    }

    strncpy((*people)[*used_size].name, name, MAX_NAME_LENGTH - 1);
    (*people)[*used_size].name[MAX_NAME_LENGTH - 1] = '\0'; // Ensuring null termination
    (*people)[*used_size].age = age;
    (*used_size)++;
}

void display_people(Person *people, int used_size) {
    printf("\nList of People:\n");
    for (int i = 0; i < used_size; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }
}

void free_memory(Person *people) {
    free(people);
}

int main() {
    Person *people = malloc(INITIAL_SIZE * sizeof(Person));
    if (people == NULL) {
        printf("Memory allocation failure!\n");
        return EXIT_FAILURE;
    }

    int current_size = INITIAL_SIZE;
    int used_size = 0;

    while (1) {
        char name[MAX_NAME_LENGTH];
        int age;
        char choice;

        printf("Enter name (or type 'exit' to finish): ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0; // Removing newline character

        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter age: ");
        if (scanf("%d", &age) != 1) {
            printf("Invalid age input! Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }
        getchar();  // consume newline left by scanf

        add_person(&people, &current_size, &used_size, name, age);

        printf("Do you want to add another person? (y/n): ");
        choice = getchar();
        getchar();  // consume newline left by getchar

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    display_people(people, used_size);
    free_memory(people);

    return EXIT_SUCCESS;
}