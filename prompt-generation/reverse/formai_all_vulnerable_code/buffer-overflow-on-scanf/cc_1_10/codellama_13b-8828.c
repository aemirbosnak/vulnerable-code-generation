//Code Llama-13B DATASET v1.0 Category: Periodic Table Quiz ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_QUESTIONS 10
#define MAX_ANSWER_LENGTH 100

struct Element {
    char symbol[3];
    char name[20];
    char atomic_number[3];
};

struct Question {
    char question[MAX_ANSWER_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
};

struct Element elements[MAX_ELEMENTS] = {
    {"H", "Hydrogen", "1"},
    {"He", "Helium", "2"},
    {"Li", "Lithium", "3"},
    {"Be", "Beryllium", "4"},
    {"B", "Boron", "5"},
    {"C", "Carbon", "6"},
    {"N", "Nitrogen", "7"},
    {"O", "Oxygen", "8"},
    {"F", "Fluorine", "9"},
    {"Ne", "Neon", "10"},
    // ...
};

struct Question questions[MAX_QUESTIONS] = {
    {"What is the atomic number of Carbon?", "6"},
    {"What is the symbol of Helium?", "He"},
    {"What is the name of the element with atomic number 100?", "Gold"},
    // ...
};

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
        fflush(stdout);
        char answer[MAX_ANSWER_LENGTH];
        scanf("%s", answer);
        if (strcmp(answer, questions[i].answer) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect, the correct answer is %s\n", questions[i].answer);
        }
    }

    return 0;
}