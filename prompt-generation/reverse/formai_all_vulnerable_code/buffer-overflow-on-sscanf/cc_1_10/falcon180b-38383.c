//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_ELEMENTS 118 // the number of elements in the periodic table
#define MAX_ATTEMPTS 5 // the number of attempts the user has to guess the element

typedef struct {
    char symbol[3];
    char name[50];
    int atomic_number;
    char category[20];
} element;

void load_elements(element elements[]) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error loading elements");
        exit(1);
    }

    while (fgets(line, 100, fp)!= NULL) {
        sscanf(line, "%s %s %d %s", elements[i].symbol, elements[i].name, &elements[i].atomic_number, elements[i].category);
        i++;
    }

    fclose(fp);
}

int main() {
    srand(time(NULL)); // initialize the random number generator with the current time
    int score = 0;
    int attempts = 0;
    char user_input[20];
    element element_to_guess;
    element elements[MAX_ELEMENTS];

    // load the elements from a file
    load_elements(elements);

    // pick a random element for the user to guess
    int random_index = rand() % MAX_ELEMENTS;
    element_to_guess = elements[random_index];

    // hide the element by replacing the name with underscores
    int name_length = strlen(element_to_guess.name);
    for (int i = 0; i < name_length; i++) {
        element_to_guess.name[i] = '_';
    }

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Guess the name of the element based on its symbol, category, and atomic number.\n");
    printf("You have %d attempts.\n", MAX_ATTEMPTS);

    while (attempts < MAX_ATTEMPTS && score == 0) {
        printf("Attempt %d:\n", attempts + 1);
        printf("Symbol: %s\n", element_to_guess.symbol);
        printf("Category: %s\n", element_to_guess.category);
        printf("Atomic Number: %d\n", element_to_guess.atomic_number);

        fgets(user_input, 20, stdin);
        user_input[strcspn(user_input, "\n")] = '\0'; // remove newline character from user input

        if (strcmp(user_input, element_to_guess.name) == 0) {
            printf("Congratulations! You guessed the element correctly.\n");
            score = 1;
        } else {
            printf("Incorrect guess. Try again.\n");
        }

        attempts++;
    }

    if (score == 1) {
        printf("You scored %d out of %d attempts.\n", score, MAX_ATTEMPTS);
    } else {
        printf("Sorry, you ran out of attempts. The correct answer was %s.\n", element_to_guess.name);
    }

    return 0;
}