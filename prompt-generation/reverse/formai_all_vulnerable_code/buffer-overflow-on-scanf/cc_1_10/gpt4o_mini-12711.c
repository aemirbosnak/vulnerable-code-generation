//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 5
#define MAX_ELEMENTS 5

typedef struct {
    char name[20];
    char symbol[3];
    int atomic_number;
} Element;

Element elements[MAX_ELEMENTS] = {
    {"Hydrogen", "H", 1},
    {"Helium", "He", 2},
    {"Lithium", "Li", 3},
    {"Beryllium", "Be", 4},
    {"Boron", "B", 5}
};

void display_instructions() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be quizzed on various elements from the periodic table.\n");
    printf("Try to answer the questions correctly. Let’s have some fun!\n");
    printf("Good luck!\n\n");
}

void ask_question(int index) {
    printf("Question %d: What is the symbol of %s? ", index + 1, elements[index].name);
}

int check_answer(char *answer, int index) {
    return strcmp(answer, elements[index].symbol) == 0;
}

void display_score(int score) {
    printf("Your final score: %d out of %d\n", score, MAX_QUESTIONS);
    if (score == MAX_QUESTIONS) {
        printf("You're a periodic table master! 🎉\n");
    } else if (score >= MAX_QUESTIONS / 2) {
        printf("Good job! You have a decent knowledge of elements! 👍\n");
    } else {
        printf("Keep studying and try again! 📚\n");
    }
}

int main() {
    srand(time(NULL));  // Seed for random generator
    char answer[10];
    int score = 0;
    int asked_indices[MAX_QUESTIONS] = {-1};

    display_instructions();

    // Randomly select questions
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int random_index;
        do {
            random_index = rand() % MAX_ELEMENTS;
        } while (memchr(asked_indices, random_index, i * sizeof(int)) != NULL);
        asked_indices[i] = random_index;

        ask_question(i);
        scanf("%s", answer);

        if (check_answer(answer, random_index)) {
            printf("Correct! 🎉\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n\n", elements[random_index].symbol);
        }
    }

    display_score(score);
    return 0;
}