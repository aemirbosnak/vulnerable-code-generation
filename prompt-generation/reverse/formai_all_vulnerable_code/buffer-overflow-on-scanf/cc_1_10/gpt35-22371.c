//FormAI DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>

// Function to calculate the rating based on the user's input
int calculateRating(int stars) {
    int rating;
    switch(stars) {
        case 1:
            rating = 1;
            break;
        case 2:
            rating = 2;
            break;
        case 3:
            rating = 3;
            break;
        case 4:
            rating = 4;
            break;
        case 5:
            rating = 5;
            break;
        default:
            printf("Invalid input! Please enter a rating from 1-5.\n");
            rating = -1;
    }
    return rating;
}

// Function to print a cheerful message based on the movie rating
void printMessage(int rating) {
    switch(rating) {
        case 1:
            printf("Yikes! That was a terrible movie. Better luck next time!\n");
            break;
        case 2:
            printf("Eh, it was okay. You might want to try something else.\n");
            break;
        case 3:
            printf("Pretty good! A solid flick that's worth checking out.\n");
            break;
        case 4:
            printf("Wow! That was amazing. One of the best movies I've ever seen!\n");
            break;
        case 5:
            printf("Stop the press! We have a new champion. The greatest movie of all time!\n");
            break;
    }
}

int main() {
    int stars;
    printf("Welcome to our C Movie Rating System! Please enter a rating from 1-5:\n");
    scanf("%d", &stars);
    int rating = calculateRating(stars);
    if (rating != -1) {
        printMessage(rating);
    }
    return 0;
}