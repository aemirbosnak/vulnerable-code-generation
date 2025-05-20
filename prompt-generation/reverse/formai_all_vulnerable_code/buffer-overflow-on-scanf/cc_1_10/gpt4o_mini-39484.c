//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 10

typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
} Element;

Element elements[MAX_ELEMENTS] = {
    {"H", "Hydrogen", 1},
    {"He", "Helium", 2},
    {"Li", "Lithium", 3},
    {"Be", "Beryllium", 4},
    {"B", "Boron", 5},
    {"C", "Carbon", 6},
    {"N", "Nitrogen", 7},
    {"O", "Oxygen", 8},
    {"F", "Fluorine", 9},
    {"Ne", "Neon", 10}
};

void print_instructions() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Answer the following questions correctly to score points.\n");
    printf("You will be asked questions about element symbols and names.\n");
    printf("Type 'exit' to quit the quiz at any time.\n");
    printf("\n");
}

int ask_question(int index) {
    char answer[20];
    printf("What is the name of the element with symbol '%s'? ", elements[index].symbol);
    scanf("%s", answer);

    // Handle case sensitivity
    for(int i = 0; answer[i]; i++){
        answer[i] = tolower(answer[i]);
    }
    for(int i = 0; elements[index].name[i]; i++){
        elements[index].name[i] = tolower(elements[index].name[i]);
    }

    if(strcmp(answer, elements[index].name) == 0) {
        return 1; // Correct answer
    } 
    return 0; // Wrong answer
}

void start_quiz() {
    int score = 0;
    int total_questions = 5; // Number of questions to ask
    int asked_indexes[total_questions];
    int is_asked[MAX_ELEMENTS] = {0};

    // Initialize random seed
    srand(time(NULL));
    printf("Starting quiz...\n");

    for (int i = 0; i < total_questions; i++) {
        int index;
        do {
            index = rand() % MAX_ELEMENTS;
        } while (is_asked[index]); // Ensure we don't ask the same question

        is_asked[index] = 1; // Mark this index as asked
        asked_indexes[i] = index; // Store the index of asked question
        
        if (ask_question(index)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer was: %s\n", elements[index].name);
        }
        printf("\n");
    }

    printf("You scored %d out of %d.\n", score, total_questions);
}

int main() {
    char command[10];
    
    print_instructions();

    while (1) {
        printf("Type 'start' to begin the quiz or 'exit' to quit: ");
        scanf("%s", command);
        
        if (strcmp(command, "start") == 0) {
            start_quiz();
        } else if (strcmp(command, "exit") == 0) {
            printf("Thanks for participating in the Periodic Table Quiz!\n");
            break;
        } else {
            printf("Unknown command. Please type 'start' or 'exit'.\n");
        }
    }
    
    return 0;
}