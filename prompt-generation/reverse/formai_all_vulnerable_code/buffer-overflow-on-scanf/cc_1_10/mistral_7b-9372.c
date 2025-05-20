//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define NUM_FORTUNES 5

// Array of fortunes
const char *fortunes[NUM_FORTUNES] = {
    "You will find great wealth and happiness.",
    "Your future is bright and full of promise.",
    "Be prepared for unexpected challenges.",
    "Good fortune will come to you in unexpected ways.",
    "Your hard work and dedication will pay off."
};

// Array of questions
const char *questions[MAX_QUESTIONS] = {
    "What color is the future?",
    "Which way does the wind of fortune blow?",
    "What shape is your future?",
    "What animal represents your future?",
    "What number is your fortune?",
    "What object symbolizes your future?",
    "What sound does your future make?",
    "What taste does your future have?",
    "What texture is your future?",
    "What feeling is your future?"
};

int main(void) {
    srand(time(NULL)); // Seed the random number generator

    int questionNumber = 0;
    int fortuneNumber = 0;

    printf("Welcome, traveler! I, your humble fortune teller, shall answer\n");
    printf("the following %d inquisitive questions to reveal your fortune.\n\n", MAX_QUESTIONS);

    // Ask questions and reveal fortunes
    for (questionNumber = 0; questionNumber < MAX_QUESTIONS; questionNumber++) {
        printf("\nQuestion %d: %s\n", questionNumber + 1, questions[questionNumber]);
        int answer = 0;
        scanf("%d", &answer);

        // Generate a random fortune number
        fortuneNumber = rand() % NUM_FORTUNES;

        printf("Answer: %d\n", answer);
        printf("Fortune: %s\n", fortunes[fortuneNumber]);
        printf("\n");
    }

    printf("Your journey concludes here, traveler. May your fortune be ever in your favor.\n");

    return 0;
}