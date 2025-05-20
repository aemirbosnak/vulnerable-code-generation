//FormAI DATASET v1.0 Category: Online Examination System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct Question {
    char question[200];
    char options[4][50];
    int correctOption;
};
typedef struct Question Question;

int getAnswer(int lower, int upper) {
    int num = rand() % (upper - lower + 1) + lower;
    printf("Enter your answer (1-4): ");
    int answer = 0;
    scanf("%d", &answer);
    while (answer < 1 || answer > 4) {
        printf("Invalid input. Enter your answer (1-4): ");
        scanf("%d", &answer);
    }
    if (answer == num) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect. The correct option is %d.\n", num);
        return 0;
    }
}

void printQuestion(Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i+1, q.options[i]);
    }
}

int main() {
    int points = 0;
    Question questions[5] = {
        {"What is the capital of France?", {"Paris", "Lyon", "Bordeaux", "Marseille"}, 1},
        {"What is the biggest planet in our solar system?", {"Jupiter", "Saturn", "Neptune", "Uranus"}, 1},
        {"What is the tallest mammal in the world?", {"Giraffe", "Elephant", "Horse", "Deer"}, 1},
        {"What is the smallest country in the world?", {"Vatican City", "Maldives", "Monaco", "Liechtenstein"}, 1},
        {"What is the national bird of Australia?", {"Emu", "Kiwi", "Kookaburra", "Cockatoo"}, 3}
    };
    printf("Welcome to the Online Examination System!\n");
    printf("You will be asked 5 questions, and you have to answer each of them correctly.\n");
    printf("Each question carries 1 point.\n");
    printf("Get ready to take the test!\n");
    for (int i = 0; i < 5; i++) {
        printQuestion(questions[i]);
        points += getAnswer(1, 4);
    }
    printf("You scored %d points out of 5.\n", points);
    if (points == 5) {
        printf("Excellent! You are a genius.\n");
    } else if (points >= 3) {
        printf("Good job! You have passed the exam.\n");
    } else {
        printf("Better luck next time. You have failed the exam.\n");
    }
    return 0;
}