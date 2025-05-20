//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 5
#define MAX_QUESTIONS 5

typedef struct {
    int level;
    int num1;
    int num2;
    char operation;
    int answer;
} Question;

void generate_question(Question *q) {
    q->num1 = rand() % 10 + 1; // Random number between 1 and 10
    q->num2 = rand() % 10 + 1; // Random number between 1 and 10
    
    switch (q->level) {
        case 1:
            q->operation = '+';
            q->answer = q->num1 + q->num2;
            break;
        case 2:
            q->operation = '-';
            q->answer = q->num1 - q->num2;
            break;
        case 3:
            q->operation = '*';
            q->answer = q->num1 * q->num2;
            break;
        case 4:
            q->operation = '/';
            // Ensure the division is valid
            while (q->num2 == 0) {
                q->num2 = rand() % 10 + 1;
            }
            q->answer = q->num1 / q->num2;
            break;
        case 5:
            q->operation = '%';
            // Ensure mod is valid
            while (q->num2 == 0) {
                q->num2 = rand() % 10 + 1;
            }
            q->answer = q->num1 % q->num2;
            break;
    }
}

void display_question(Question *q) {
    printf("Level %d: What is %d %c %d?\n", q->level, q->num1, q->operation, q->num2);
}

int main() {
    srand(time(0)); // Seed for random number generation
    
    int score = 0;
    int level = 1;
    
    printf("Welcome to the Mathematical Challenge Game!\n");
    printf("You will face %d questions at each level.\n", MAX_QUESTIONS);
    printf("Let's see how far you can go!\n\n");

    for (level = 1; level <= MAX_LEVEL; level++) {
        printf("Starting Level %d\n", level);
        for (int i = 0; i < MAX_QUESTIONS; i++) {
            Question q;
            q.level = level;
            generate_question(&q);
            display_question(&q);

            int user_answer;
            printf("Your answer: ");
            scanf("%d", &user_answer);

            if (user_answer == q.answer) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect! The correct answer was %d.\n", q.answer);
            }
        }
        printf("Level %d completed! Your current score: %d\n\n", level, score);
    }

    printf("Game Over! Your final score is: %d out of %d\n", score, MAX_LEVEL * MAX_QUESTIONS);
    
    return 0;
}