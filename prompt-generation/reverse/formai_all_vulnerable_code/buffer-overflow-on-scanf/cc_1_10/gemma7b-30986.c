//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
    char question[255];
    char answers[MAX_ANSWERS][255];
    int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", {"A. A person who owns a business", "B. A person who is good at math", "C. A person who is creative", "D. A person who is successful"}, 1},
    {"What is the capital of France?", {"A. Paris", "B. Rome", "C. Brussels", "D. Lyon"}, 2},
    {"Which scientist invented the theory of relativity?", {"A. Albert Einstein", "B. Isaac Newton", "C. Charles Darwin", "D. Galileo Galilei"}, 3},
    {"Which country is the largest in the world?", {"A. China", "B. Canada", "C. Russia", "D. Australia"}, 4},
    {"What is the most common color of the human eye?", {"A. Blue", "B. Brown", "C. Gray", "D. Hazel"}, 5},
    {"Which planet is the largest in the solar system?", {"A. Mars", "B. Earth", "C. Jupiter", "D. Saturn"}, 6},
    {"What is the meaning of the word 'entrepreneur'?", {"A. A person who owns a business", "B. A person who is good at math", "C. A person who is creative", "D. A person who is successful"}, 1},
    {"What is the capital of France?", {"A. Paris", "B. Rome", "C. Brussels", "D. Lyon"}, 2},
    {"Which scientist invented the theory of relativity?", {"A. Albert Einstein", "B. Isaac Newton", "C. Charles Darwin", "D. Galileo Galilei"}, 3},
    {"Which country is the largest in the world?", {"A. China", "B. Canada", "C. Russia", "D. Australia"}, 4}
};

int main() {
    time_t start_time, end_time;
    int i, score = 0, totalQuestions = 0;

    start_time = time(NULL);

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s", questions[i].question);
        printf("\n");

        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%s", questions[i].answers[j]);
            printf("\n");
        }

        printf("Enter your answer: ");
        char answer[255];
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answers[questions[i].correctAnswer]) == 0) {
            score++;
        }

        totalQuestions++;
    }

    end_time = time(NULL);

    printf("Your score: %d out of %d", score, totalQuestions);
    printf("\n");
    printf("Time taken: %d seconds", end_time - start_time);

    return 0;
}