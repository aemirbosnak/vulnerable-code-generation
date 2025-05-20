//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_ELEMENTS 10

struct Element {
    char symbol[3];
    char name[20];
    int atomic_number;
};

struct Element elements[NUM_ELEMENTS] = {
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

int main() {
    int score = 0;
    srand(time(NULL));
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions.\n", NUM_ELEMENTS);
    
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        int rand_index = rand() % NUM_ELEMENTS;
        struct Element rand_element = elements[rand_index];
        
        printf("\n%d. What is the symbol for %s?\n", i+1, rand_element.name);
        char user_answer[3];
        scanf("%s", user_answer);
        
        if (strcmp(user_answer, rand_element.symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct symbol is %s.\n", rand_element.symbol);
        }
    }
    
    printf("\nQuiz complete! You got %d out of %d.\n", score, NUM_ELEMENTS);
    
    return 0;
}