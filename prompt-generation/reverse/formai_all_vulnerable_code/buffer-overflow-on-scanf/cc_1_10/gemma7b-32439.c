//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[256];
    char answer[256];
    int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", "a. A person who owns and operates a business venture", 5},
    {"Which planet is the largest?", "b. Mars", 3},
    {"Who invented the telephone?", "c. Alexander Graham Bell", 4},
    {"What is the capital of France?", "d. Paris", 2},
    {"Which animal is known for its sharp eyesight?", "e. Owl", 4},
    {"What is the sound of one hand clapping?", "f. Silence", 3},
    {"Which fruit is the most popular in the world?", "g. Apple", 4},
    {"What is the meaning of the word 'entrepreneur' in Latin?", "h. A person who owns and operates a business venture", 5},
    {"Which scientist developed the theory of relativity?", "i. Albert Einstein", 4},
    {"What is the meaning of the word 'entrepreneur' in French?", "j. A person who owns and operates a business venture", 5}
};

int main() {
    int i, score = 0, totalMarks = 0;

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
        printf("a. %s\n", questions[i].answer);
        printf("b. %s\n", questions[i].answer);
        printf("c. %s\n", questions[i].answer);
        printf("d. %s\n", questions[i].answer);
        printf("e. %s\n", questions[i].answer);

        char answer;
        printf("Enter your answer: ");
        scanf("%c", &answer);

        if (answer == questions[i].answer[0]) {
            score++;
            totalMarks += questions[i].marks;
        }
    }

    printf("Your score: %d/%d", score, MAX_QUESTIONS);
    printf("\nTotal marks: %d", totalMarks);

    return 0;
}