//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 10

typedef struct {
    char name[30];
    char symbol[3];
    int atomic_number;
} Element;

Element periodic_table[MAX_ELEMENTS] = {
    {"Hydrogen", "H", 1},
    {"Helium", "He", 2},
    {"Lithium", "Li", 3},
    {"Beryllium", "Be", 4},
    {"Boron", "B", 5},
    {"Carbon", "C", 6},
    {"Nitrogen", "N", 7},
    {"Oxygen", "O", 8},
    {"Fluorine", "F", 9},
    {"Neon", "Ne", 10}
};

void display_quiz_instructions() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked questions about the elements.\n");
    printf("Answer the questions to the best of your ability!\n");
    printf("Let's see how much you know about the elements of the periodic table.\n\n");
}

void ask_question(int index) {
    printf("Question %d: What is the chemical symbol for %s?\n", index + 1, periodic_table[index].name);
}

int main() {
    int score = 0;
    char user_answer[3];
    
    display_quiz_instructions();
    
    for(int i = 0; i < MAX_ELEMENTS; i++) {
        ask_question(i);
        
        printf("Your answer: ");
        scanf("%s", user_answer);
        
        // Convert answer to uppercase for case-insensitivity
        for (int j = 0; user_answer[j]; j++) {
            user_answer[j] = toupper(user_answer[j]);
        }
        
        if (strcmp(user_answer, periodic_table[i].symbol) == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n\n", periodic_table[i].symbol);
        }
    }
    
    printf("You scored %d out of %d!\n", score, MAX_ELEMENTS);
    
    if (score == MAX_ELEMENTS) {
        printf("Excellent! You are a master of the periodic table!\n");
    } else if (score >= MAX_ELEMENTS / 2) {
        printf("Good job! You have a solid understanding of the elements.\n");
    } else {
        printf("Keep studying! The periodic table has many wonders to explore.\n");
    }

    return 0;
}