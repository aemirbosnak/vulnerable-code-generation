//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[256];
    char answer[256];
    int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", "A person who starts and manages a business venture", 5},
    {"Which scientist invented the theory of relativity?", "Albert Einstein", 4},
    {"What is the capital of France?", "Paris", 3},
    {"Who was the first president of the United States?", "George Washington", 4},
    {"What is the most common color of hair in the world?", "Black", 3},
    {"Which animal is known for its intelligence?", "Humans", 5},
    {"What is the sound of one hand clapping?", "Silence", 4},
    {"Which planet is the largest?", "Jupiter", 3},
    {"What is the meaning of the word 'entrepreneur' in a synonym?", "A person who takes risks to start and develop a business", 4},
    {"Who was the first astronaut to walk on the moon?", "Neil Armstrong", 5}
};

int main() {
    int i, marks, score = 0;
    char answer;

    system("clear");

    printf("Welcome to the C Online Examination System!\n");
    printf("------------------------\n");

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);

        printf("Enter your answer: ");
        scanf("%c", &answer);

        if (answer == questions[i].answer[0]) {
            marks = questions[i].marks;
            score += marks;
            printf("Congratulations! You have earned %d marks.\n", marks);
        } else {
            printf("Sorry, your answer is incorrect. The correct answer is: %s\n", questions[i].answer);
        }
    }

    printf("Your total score is: %d\n", score);
    printf("Thank you for participating in the C Online Examination System!\n");

    return 0;
}