//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10
#define NUM_ELEMENTS 118

struct element {
    char name[3];
    char symbol[3];
    int atomic_number;
    char category[10];
};

struct question {
    char question[50];
    int correct_answer;
};

struct element elements[NUM_ELEMENTS] = {
    {"H", "H", 1, "Nonmetal"},
    {"He", "He", 2, "Noble gas"},
    {"Li", "Li", 3, "Metal"},
    {"Be", "Be", 4, "Metalloid"},
    {"B", "B", 5, "Metalloid"},
    {"C", "C", 6, "Nonmetal"},
    {"N", "N", 7, "Nonmetal"},
    {"O", "O", 8, "Nonmetal"},
    {"F", "F", 9, "Nonmetal"},
    {"Ne", "Ne", 10, "Noble gas"}
};

struct question questions[NUM_QUESTIONS] = {
    {"What element has the symbol 'H' and is a nonmetal?", 1},
    {"What element has the symbol 'He' and is a noble gas?", 2},
    {"What element has the symbol 'Li' and is a metal?", 3},
    {"What element has the symbol 'Be' and is a metalloid?", 4},
    {"What element has the symbol 'B' and is a metalloid?", 5},
    {"What element has the symbol 'C' and is a nonmetal?", 6},
    {"What element has the symbol 'N' and is a nonmetal?", 7},
    {"What element has the symbol 'O' and is a nonmetal?", 8},
    {"What element has the symbol 'F' and is a nonmetal?", 9},
    {"What element has the symbol 'Ne' and is a noble gas?", 10}
};

int main() {
    srand(time(NULL));
    int score = 0;
    int i;

    for (i = 0; i < NUM_QUESTIONS; i++) {
        int random_index = rand() % NUM_ELEMENTS;
        int correct_answer = elements[random_index].atomic_number;
        int user_answer;

        printf("%s\n", questions[i].question);
        scanf("%d", &user_answer);

        if (user_answer == correct_answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", correct_answer);
        }
    }

    printf("Your final score is %d out of %d.\n", score, NUM_QUESTIONS);

    return 0;
}