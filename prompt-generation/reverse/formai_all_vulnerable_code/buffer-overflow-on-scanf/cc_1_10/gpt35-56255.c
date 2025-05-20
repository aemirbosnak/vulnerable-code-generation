//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    int num_questions = 10;
    int score = 0;
    char yes_or_no = 'n';

    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("You will be asked %d questions.\n", num_questions);

    // Loop for each question
    for (int i = 1; i <= num_questions; i++) {
        int atomic_number = rand() % 118 + 1; // Generate a random atomic number between 1 and 118
        char symbol;
        char name[20];

        // Use switch statement to get the symbol and name of the element
        switch (atomic_number) {
            case 1:
                symbol = 'H';
                strcpy(name, "Hydrogen");
                break;
            case 2:
                symbol = 'He';
                strcpy(name, "Helium");
                break;
            case 3:
                symbol = 'Li';
                strcpy(name, "Lithium");
                break;
            // More cases for the rest of the elements...
            default:
                break;
        }

        printf("\nQuestion %d: What is the symbol for %s (Atomic Number %d)?\n", i, name, atomic_number);
        printf("Your answer: ");
        char answer[3];
        scanf("%s", answer);

        // Check if the answer is correct and increment score accordingly
        if (toupper(answer[0]) == toupper(symbol) && (answer[1] == '\0' || answer[1] == '\n')) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %c.\n", symbol);
        }

        // Ask if the user wants to continue playing
        if (i != num_questions) {
            printf("Do you want to continue playing? (y/n)\n");
            scanf(" %c", &yes_or_no);
            if (toupper(yes_or_no) == 'N') {
                printf("Thank you for playing the C Periodic Table Quiz!\n");
                printf("Your final score is %d/%d.\n", score, num_questions);
                return 0;
            }
        }
    }

    printf("Congratulations! You have completed the C Periodic Table Quiz!\n");
    printf("Your final score is %d/%d.\n", score, num_questions);

    return 0;
}