//FormAI DATASET v1.0 Category: Movie Rating System ; Style: mind-bending
#include <stdio.h>

int main() {

    int userRating;
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please enter your rating for the movie (0-100): ");
    scanf("%d", &userRating);

    if (userRating > 100 || userRating < 0) {
        printf("Error: Invalid Rating entered. Please enter a rating between 0 and 100.\n");
    }
    else {
        printf("Your entered rating is %d.\n", userRating);

        printf("Calculating unique movie rating...\n");
        int uniqueRating = userRating / 2;
        if (uniqueRating >= 98) {
            printf("This movie is a real gem! We rate it a double rainbow out of 10.\n");
        }
        else if (uniqueRating >= 90) {
            printf("This movie is a masterpiece! We rate it a unicorn out of 10.\n");
        }
        else if (uniqueRating >= 80) {
            printf("This movie is amazing! We rate it an alien invasion out of 10.\n");
        }
        else if (uniqueRating >= 70) {
            printf("This movie is really good! We rate it a mermaid out of 10.\n");
        }
        else if (uniqueRating >= 60) {
            printf("This movie is good. We rate it a talking dog out of 10.\n");
        }
        else if (uniqueRating >= 50) {
            printf("This movie is average. We rate it a tree out of 10.\n");
        }
        else if (uniqueRating >= 40) {
            printf("This movie is below average. We rate it a flat tire out of 10.\n");
        }
        else if (uniqueRating >= 30) {
            printf("This movie is bad. We rate it a hurricane out of 10.\n");
        }
        else if (uniqueRating >= 20) {
            printf("This movie is really bad. We rate it a zombie apocalypse out of 10.\n");
        }
        else if (uniqueRating >= 10) {
            printf("This movie is terrible. We rate it a meteor impact out of 10.\n");
        }
        else {
            printf("This movie is the worst thing ever. We rate it a black hole out of 10.\n");
        }
    }

    return 0;
}