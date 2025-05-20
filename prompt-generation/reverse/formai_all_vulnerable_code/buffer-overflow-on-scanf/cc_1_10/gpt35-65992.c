//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void welcome() {
    printf("Welcome to the Periodic Table Quiz! \n\n");
    printf("Are you ready to test your knowledge of the elements? \n\n");
    printf("Enter 'yes' to start or 'no' to quit: ");
}

// Function to handle user input
int handle_input() {
    char input[10];
    scanf("%s", input);

    if(strcmp(input, "yes") == 0) {
        printf("\nGreat, let's get started! \n\n");
        return 1;
    } else if(strcmp(input, "no") == 0) {
        printf("\nSorry to see you go. Goodbye! \n");
        return 0;
    } else {
        printf("\nInvalid input. Please try again. \n\n");
        welcome();
        handle_input();
    }
}

int main() {
    int play = 1;

    printf("Please enter your name: \n");
    char name[20];
    scanf("%s", name);

    printf("Hello, %s! \n", name);

    // Welcome user and handle input
    welcome();
    play = handle_input();

    while(play) {
        // Set up the quiz
        char elements[10][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne"};
        int correct = 0;
        int num_elements = 10;

        // Shuffle the order of the elements
        for(int i = 0; i < num_elements; i++) {
            int j = rand() % num_elements;
            char temp[3];
            strcpy(temp, elements[i]);

            strcpy(elements[i], elements[j]);
            strcpy(elements[j], temp);
        }

        // Present the quiz to the user
        printf("\nHere are 10 random elements. Can you correctly identify them? \n\n");
        for(int i = 0; i < num_elements; i++) {
            printf("%d. ", i+1);
            char guess[3];
            scanf("%s", guess);

            if(strcmp(guess, elements[i]) == 0) {
                printf("Correct! \n");
                correct++;
            } else {
                printf("Incorrect. The correct answer was %s. \n", elements[i]);
            }
        }

        // Present the user with their score
        printf("\nYou got %d out of %d correct. \n", correct, num_elements);

        // Check if the user wants to play again
        printf("\nWould you like to play again? Enter 'yes' to continue or 'no' to quit: \n");
        play = handle_input();
    }

    return 0;
}