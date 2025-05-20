//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Function to display the rating of a movie
void display_rating(int rating) {
    printf("The movie is rated: ");

    switch(rating) {
        case 1:
            printf("R - Restricted\n");
            break;
        case 2:
            printf("NC-17 - No One 17 and Under Admitted\n");
            break;
        case 3:
            printf("PG-13 - Parents Strongly Cautioned\n");
            break;
        case 4:
            printf("PG - Parental Guidance Suggested\n");
            break;
        case 5:
            printf("G - General Audiences\n");
            break;
        default:
            printf("Invalid rating!\n");
    }
}

int main() {
    int score, rating;

    // Prompt user to enter the score of the movie
    printf("[CRYPTIC MOVIE RATING SYSTEM] Enter the score of the movie (out of 100): ");
    scanf("%d", &score);

    // Determine the rating based on the score
    if(score >= 90) {
        rating = 1;
    }
    else if(score >= 80 && score < 90) {
        rating = 2;
    }
    else if(score >= 70 && score < 80) {
        rating = 3;
    }
    else if(score >= 60 && score < 70) {
        rating = 4;
    }
    else if(score >= 50 && score < 60) {
        rating = 5;
    }
    else {
        rating = 0;
    }

    // Display the rating of the movie
    display_rating(rating);

    return 0;
}