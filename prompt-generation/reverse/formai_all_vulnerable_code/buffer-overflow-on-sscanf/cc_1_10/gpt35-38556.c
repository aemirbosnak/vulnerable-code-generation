//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMS 118
#define MAX_NAME_LEN 20

// Element struct
struct Element {
    int atomic_num;
    char symbol[3];
    char name[MAX_NAME_LEN];
    float atomic_weight;
};

// Function prototypes
void initialize_elements(struct Element *elements);
void start_game(struct Element *elements);

int main() {
    struct Element elements[MAX_ELEMS];
    initialize_elements(elements);
    start_game(elements);
    return 0;
}

// Initialize elements with data from file
void initialize_elements(struct Element *elements) {
    FILE *data_file = fopen("periodic_table_data.txt", "r");
    if (data_file == NULL) {
        fprintf(stderr, "Failed to open data file.\n");
        exit(1);
    }

    char line[1024];
    int i = 0;
    while (fgets(line, 1024, data_file) != NULL) {
        sscanf(line, "%d %s %s %f", &elements[i].atomic_num,
               elements[i].symbol, elements[i].name, &elements[i].atomic_weight);
        i++;
    }

    fclose(data_file);
}

// Start the game
void start_game(struct Element *elements) {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("We will give you the symbol of an element and you will need to guess its name.\n");
    printf("Enter 'quit' to exit the game.\n");

    int score = 0;
    char guess[MAX_NAME_LEN];

    // Game loop
    while (1) {
        // Generate random element
        int random_index = rand() % MAX_ELEMS;
        char *symbol = elements[random_index].symbol;
        char *name = elements[random_index].name;
        printf("\nSymbol: %s\n", symbol);

        // Get user guess
        printf("Guess: ");
        fgets(guess, MAX_NAME_LEN, stdin);
        guess[strcspn(guess, "\n")] = 0; // remove newline character

        // Check if user wants to quit
        if (strcmp(guess, "quit") == 0) {
            printf("Thanks for playing! Final score: %d\n", score);
            return;
        }

        // Check if guess is correct
        if (strcmp(guess, name) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", name);
        }
    }
}