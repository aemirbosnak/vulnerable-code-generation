//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: calm
#include <stdio.h>
#include <string.h>

// Define the atomic weight constants
#define H 1.008
#define He 4.003
#define Li 6.941
#define Be 9.012
#define B 10.81
#define C 12.01
#define N 14.01
#define O 16.00
#define F 19.00
#define Ne 20.18

// Define the atomic symbol and name arrays
char *symbol[] = {
    "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne"
};

char *name[] = {
    "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron",
    "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon"
};

// Define the answer key
int answers[] = {
    H, He, Li, Be, B, C, N, O, F, Ne
};

int main() {

    printf("Welcome to the Periodic Table Quiz!\n\n");

    // Loop through all the questions
    for (int i = 0; i < 10; i++) {
        // Print the question
        printf("What is the atomic weight of %s?\n", name[i]);

        // Get the user's answer
        double user_answer;
        printf("Enter your answer: ");
        scanf("%lf", &user_answer);

        // Check if the user's answer is correct
        if (user_answer == answers[i]) {
            printf("Correct!\n\n");
        } else {
            printf("Sorry, the correct answer is %.3lf\n\n", answers[i]);
        }   
    }

    printf("Congratulations! You completed the quiz.\n");

    return 0;
}