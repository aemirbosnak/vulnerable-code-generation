//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char question[100];
    char options[4][50];
    char answer;
    int marks;
};

struct Node questions[] = {
    {"What is the capital of India?", {"Delhi", "Mumbai", "Chennai", "Kolkata"}, 'A', 1},
    {"Who is the Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 'A', 1},
    {"What is the national animal of India?", {"Tiger", "Lion", "Elephant", "Peacock"}, 'A', 1},
    {"What is the national bird of India?", {"Peacock", "Sparrow", "Eagle", "Kite"}, 'A', 1},
    {"What is the national flower of India?", {"Lotus", "Rose", "Jasmine", "Marigold"}, 'A', 1}
};

int main() {
    int i, score = 0;
    char input;

    printf("Welcome to the C Online Examination System!\n\n");
    printf("Instructions:\n");
    printf("1. Read the question carefully.\n");
    printf("2. Choose the correct option from the given choices.\n");
    printf("3. Enter the corresponding letter (A, B, C, or D) to submit your answer.\n\n");

    for (i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%c. %s\n", j + 65, questions[i].options[j]);
        }
        printf("Enter your answer: ");
        scanf(" %c", &input);
        if (input == questions[i].answer) {
            score += questions[i].marks;
            printf("Correct! You earned %d marks.\n\n", questions[i].marks);
        } else {
            printf("Incorrect! The correct answer is %c.\n\n", questions[i].answer);
        }
    }

    printf("Your total score is %d out of 5.\n\n", score);

    if (score >= 3) {
        printf("Congratulations! You have passed the exam.\n");
    } else {
        printf("Sorry, you have failed the exam.\n");
    }

    return 0;
}