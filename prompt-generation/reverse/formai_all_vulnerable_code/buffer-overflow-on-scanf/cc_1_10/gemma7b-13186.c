//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[256];
    char answer[256];
    int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", "A person who starts and operates a business venture", 5},
    {"Who is the President of the United States?", "Joe Biden", 3},
    {"What is the chemical formula for sulfuric acid?", "H2SO4", 4},
    {"What is the capital of France?", "Paris", 2},
    {"What is the sound of one hand clapping?", "Silence", 1},
    {"Which planet is known for its many volcanoes?", "Earth", 4},
    {"What is the meaning of the word 'entrepreneur' in Latin?", "A person who is skilled in business", 5},
    {"What is the square root of 16?", "4", 3},
    {"What is the most populous country in the world?", "China", 5},
    {"What is the meaning of the word 'entrepreneur' in Arabic?", "A person who is capable of starting and managing a business", 5}
};

int main() {
    int i, score = 0;

    printf("Welcome to the Future of Education!\n");
    printf("Please select a difficulty level:**\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");

    int difficulty = 0;
    scanf("%d", &difficulty);

    for (i = 0; i < MAX_QUESTIONS; i++) {
        if (difficulty == 1) {
            printf("%s\n", questions[i].question);
            printf("Enter your answer: ");
            char answer[256];
            scanf("%s", answer);

            if (strcmp(answer, questions[i].answer) == 0) {
                score++;
            }
        }
    }

    printf("Your total score is: %d", score);

    return 0;
}