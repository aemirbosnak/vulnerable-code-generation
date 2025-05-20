//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char question[100];
    char options[4][50];
    char answer;
} Question;

Question questions[] = {
    {"What is the capital of India?", {"New Delhi", "Mumbai", "Chennai", "Kolkata"}, 'A'},
    {"Who is the father of Indian constitution?", {"Mahatma Gandhi", "Jawaharlal Nehru", "B.R. Ambedkar", "Sardar Patel"}, 'C'},
    {"What is the largest ocean in the world?", {"Atlantic Ocean", "Pacific Ocean", "Indian Ocean", "Arctic Ocean"}, 'B'},
    {"Who is the author of the famous novel 'To Kill a Mockingbird'?", {"Harper Lee", "Jane Austen", "Charles Dickens", "George Orwell"}, 'A'},
    {"What is the chemical symbol for gold?", {"Au", "Ag", "Fe", "Cu"}, 'A'},
};

int main() {
    int score = 0;
    char answer;

    printf("Welcome to the Online Examination System!\n");

    for (int i = 0; i < 5; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);

        for (int j = 0; j < 4; j++) {
            printf("Option %c: %s\n", 'A' + j, questions[i].options[j]);
        }

        printf("Enter your answer: ");
        scanf(" %c", &answer);

        if (answer == questions[i].answer) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("\nYour score is %d out of 5.\n", score);

    if (score >= 3) {
        printf("Congratulations! You have passed the exam.\n");
    } else {
        printf("Sorry, you have failed the exam.\n");
    }

    return 0;
}