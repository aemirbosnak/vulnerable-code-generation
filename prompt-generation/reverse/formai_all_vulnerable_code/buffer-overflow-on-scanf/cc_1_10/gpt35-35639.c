//FormAI DATASET v1.0 Category: Online Examination System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char text[100];
    char choices[4][50];
    int answer;
};

void display_question(struct Question q) {
    printf("%s\n", q.text);
    for (int i = 0; i < 4; i++) {
        printf("%c) %s\n", 'A' + i, q.choices[i]);
    }
}

int main() {
    struct Question q1 = {
        .text = "What is the capital of France?",
        .choices = {"Paris", "Madrid", "London", "Berlin"},
        .answer = 0
    };

    struct Question q2 = {
        .text = "What is the largest planet in our solar system?",
        .choices = {"Venus", "Jupiter", "Saturn", "Mars"},
        .answer = 1
    };

    struct Question q3 = {
        .text = "What is the only continent on Earth where penguins live natively?",
        .choices = {"Europe", "Asia", "Antarctica", "Australia"},
        .answer = 2
    };

    struct Question q4 = {
        .text = "What is the national animal of Japan?",
        .choices = {"Panda", "Lion", "Eagle", "None of the above"},
        .answer = 3
    };

    struct Question questions[4] = {q1, q2, q3, q4};

    int score = 0;
    for (int i = 0; i < 4; i++) {
        printf("\nQuestion %d:\n", i+1);
        display_question(questions[i]);

        char choice;
        do {
            printf("Enter your answer (A/B/C/D): ");
            scanf(" %c", &choice);
        } while (choice < 'A' || choice > 'D');
        printf("\n");

        int answer_index = choice - 'A';
        if (answer_index == questions[i].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %c)\n", 'A' + questions[i].answer);
        }
    }

    printf("You scored %d out of 4.\n", score);

    return 0;
}