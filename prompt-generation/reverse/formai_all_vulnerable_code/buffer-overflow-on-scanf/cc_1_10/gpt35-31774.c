//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_ELEMENTS 118

// Element structure
typedef struct {
    char symbol[3];
    char name[30];
    int atomicNumber;
    float atomicMass;
} Element;

// Array of elements
Element elements[NUM_ELEMENTS] = {
    {"H", "Hydrogen", 1, 1.008},
    {"He", "Helium", 2, 4.003},
    {"Li", "Lithium", 3, 6.941},
    {"Be", "Beryllium", 4, 9.012},
    // ... and so on for the rest of the periodic table
};

// Thread function for asking quiz questions
void* askQuestion(void* arg) {
    int* score = (int*) arg;
    int questionNumber = 0;
    int numCorrect = 0;

    // Ask 10 questions
    while (questionNumber < 10) {
        // Pick a random element
        int randomIndex = rand() % NUM_ELEMENTS;
        Element questionElement = elements[randomIndex];

        // Ask the question
        printf("Question %d: What is the symbol for %s?\n", questionNumber+1, questionElement.name);

        // Get user input
        char answer[3];
        scanf("%s", answer);

        // Check if the answer is correct
        if (strcmp(answer, questionElement.symbol) == 0) {
            printf("Correct!\n");
            numCorrect++;
        } else {
            printf("Wrong! The answer was %s.\n", questionElement.symbol);
        }

        questionNumber++;
    }

    // Update user's score
    *score = numCorrect;

    // Exit thread
    pthread_exit(NULL);
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Create two threads for two users
    pthread_t threadA, threadB;
    int scoreA = 0, scoreB = 0;
    int* scoreAPtr = &scoreA;
    int* scoreBPtr = &scoreB;
    pthread_create(&threadA, NULL, askQuestion, (void*) scoreAPtr);
    pthread_create(&threadB, NULL, askQuestion, (void*) scoreBPtr);

    // Wait for threads to finish
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);

    // Print results
    printf("User A score: %d\n", scoreA);
    printf("User B score: %d\n", scoreB);

    // Determine winner
    if (scoreA > scoreB) {
        printf("User A wins!\n");
    } else if (scoreB > scoreA) {
        printf("User B wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}