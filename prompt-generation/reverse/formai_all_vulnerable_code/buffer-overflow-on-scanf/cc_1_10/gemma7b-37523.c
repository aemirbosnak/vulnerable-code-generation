//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question
{
    char question[256];
    char answers[MAX_ANSWERS][256];
    int correctAnswer;
} Question;

Question questions[] =
{
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and manages a business", "b. A person who is good at math", "c. A person who is good at science", "d. A person who is good at engineering"}, 1},
    {"Which planet is the largest?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 2},
    {"What is the chemical symbol for gold?", {"a. Au", "b. Ag", "c. Cu", "d. Fe"}, 3},
    {"Which scientist invented the theory of relativity?", {"a. Isaac Newton", "b. Albert Einstein", "c. Charles Darwin", "d. Galileo Galilei"}, 4},
    {"Which animal is the largest predator on Earth?", {"a. Lion", "b. Tiger", "c. Great White Shark", "d. Polar Bear"}, 5},
    {"What is the most common color of hair in the world?", {"a. Black", "b. Brown", "c. Blonde", "d. Red"}, 6},
    {"Which city is the capital of France?", {"a. Paris", "b. Lyon", "c. Marseille", "d. Rome"}, 7},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and manages a business", "b. A person who is good at math", "c. A person who is good at science", "d. A person who is good at engineering"}, 8},
    {"Which scientist invented the theory of relativity?", {"a. Isaac Newton", "b. Albert Einstein", "c. Charles Darwin", "d. Galileo Galilei"}, 9},
    {"What is the most common color of hair in the world?", {"a. Black", "b. Brown", "c. Blonde", "d. Red"}, 10}
};

int main()
{
    time_t start, end;
    int score = 0;
    int i;

    start = time(NULL);

    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i].question);

        printf("Enter your answer: ");
        char answer[256];
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answers[questions[i].correctAnswer]) == 0)
        {
            score++;
        }
    }

    end = time(NULL);

    printf("Your score: %d/%d", score, MAX_QUESTIONS);

    printf("\nTime taken: %.2f seconds", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}