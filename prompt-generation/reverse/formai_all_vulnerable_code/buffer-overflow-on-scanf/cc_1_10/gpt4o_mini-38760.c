//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define MAX_QUESTIONS 5
#define MAX_LENGTH 100

typedef struct {
    char element[MAX_LENGTH];
    char symbol[MAX_LENGTH];
    int atomic_number;
} Element;

Element periodic_table[MAX_QUESTIONS] = {
    {"Hydrogen", "H", 1},
    {"Helium", "He", 2},
    {"Lithium", "Li", 3},
    {"Beryllium", "Be", 4},
    {"Boron", "B", 5}
};

void print_welcome_message() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Test your knowledge of chemical elements.\n\n");
}

void ask_question(int index) {
    printf("Question %d: What is the symbol for %s? ", index + 1, periodic_table[index].element);
}

int check_answer(int index, char *user_answer) {
    return strcmp(user_answer, periodic_table[index].symbol) == 0;
}

void play_quiz() {
    char answer[MAX_LENGTH];
    int score = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        ask_question(i);
        scanf("%s", answer);
        
        if (check_answer(i, answer)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %s.\n", periodic_table[i].symbol);
        }
    }

    printf("\nYour final score: %d out of %d\n", score, MAX_QUESTIONS);
}

int main() {
    print_welcome_message();
    play_quiz();

    return 0;
}