//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 5
#define MAX_OPTIONS 4
#define BUFFER_SIZE 100

typedef struct {
    char question[BUFFER_SIZE];
    char options[MAX_OPTIONS][BUFFER_SIZE];
    int correctAnswerIndex;
} Question;

void printWelcomeMessage() {
    printf("-----------------------------------------------------\n");
    printf("        Welcome to the Wacky Online Exam! \n");
    printf("-----------------------------------------------------\n");
    printf("Make sure your brain is switched ON before proceeding!\n");
    printf("-----------------------------------------------------\n");
}

void displayQuestion(Question q) {
    printf("\nQuestion: %s\n", q.question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("\t%d. %s\n", i + 1, q.options[i]);
    }
}

int checkAnswer(Question q, int answer) {
    return answer == q.correctAnswerIndex + 1; // Adding 1 for user-friendly indexing
}

void printResult(int score) {
    printf("\nCongratulations! You scored %d out of %d!\n", score, MAX_QUESTIONS);
    if (score == MAX_QUESTIONS) {
        printf("You are a genius! Go get a medal!\n");
    } else if (score >= MAX_QUESTIONS / 2) {
        printf("Not bad! But I wouldn't trust you with my pet goldfish!\n");
    } else {
        printf("Uh-oh! Looks like you need to brush up on your knowledge. Time to hit the books!\n");
    }
}

void thankYouMessage() {
    printf("\nThanks for taking the Wacky Online Exam!\n");
    printf("Clap your hands, wiggle your toes, and do a happy dance!\n");
}

int main() {
    printWelcomeMessage();

    Question questions[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Lisbon"}, 2},
        {"What is 2 + 2?", {"3", "4", "22", "42"}, 1},
        {"Which animal is known as the 'King of the Jungle'?", {"Elephant", "Lion", "Tiger", "Bear"}, 1},
        {"What do you call a bear with no teeth?", {"A gummy bear", "A teddy bear", "A toothless bear", "A funny bear"}, 0},
        {"In which sport do you hit a shuttlecock?", {"Tennis", "Badminton", "Baseball", "Fencing"}, 1}
    };

    int score = 0;
    int answer;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        displayQuestion(questions[i]);
        printf("Your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &answer);

        if (checkAnswer(questions[i], answer)) {
            printf("Correct! Aren't you a smart cookie?\n");
            score++;
        } else {
            printf("Oops! Wrong answer. Is your brain taking a vacation?\n");
        }
    }

    printResult(score);
    thankYouMessage();

    return 0;
}