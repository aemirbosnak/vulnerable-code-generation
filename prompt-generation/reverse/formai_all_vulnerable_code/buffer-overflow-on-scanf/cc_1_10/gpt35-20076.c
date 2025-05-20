//FormAI DATASET v1.0 Category: Movie Rating System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the rating based on the user's input
int calculateRating(int rating) {
    int newRating;

    switch(rating) {
        case 1:
            newRating = 5;
            break;
        case 2:
            newRating = 10;
            break;
        case 3:
            newRating = 15;
            break;
        case 4:
            newRating = 20;
            break;
        case 5:
            newRating = 25;
            break;
        default:
            newRating = -1;
            printf("Error: Invalid rating.\n");
            break;
    }

    return newRating;
}

int main() {
    int movieRating, updatedRating;
    
    printf("Welcome to our unique movie rating system!\n");
    printf("Please rate the movie you watched on a scale of 1 - 5: ");

    while(1) {
        // Get user input for movie rating
        scanf("%d", &movieRating);
        getchar();

        // Check for invalid input
        if(movieRating < 1 || movieRating > 5) {
            printf("Invalid input. Please enter a number between 1 and 5: ");
        }
        else {
            // Calculate the updated rating using the calculateRating function
            updatedRating = calculateRating(movieRating);

            // Print the updated rating
            if(updatedRating != -1) {
                printf("The new rating for the movie is: %d\n", updatedRating);
            }

            // Ask if the user wants to rate another movie or exit the program
            printf("Would you like to rate another movie? (y/n): ");
            char answer = getchar();

            if(answer == 'n') {
                printf("Thank you for using our movie rating system!\n");
                break;
            }
            else {
                printf("Please rate the next movie you watched on a scale of 1 - 5: ");
            }
        }
    }

    return 0;
}