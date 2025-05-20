//FormAI DATASET v1.0 Category: Movie Rating System ; Style: artistic
#include <stdio.h>

// function to get user input for movie ratings
int getRating() {
    int rating;
    printf("Please enter a rating from 1 to 10: ");
    scanf("%d", &rating);
    if(rating < 1 || rating > 10) {
        // error message for invalid rating input
        printf("Invalid rating. Please enter a rating between 1 and 10.\n");
        return getRating();
    }
    return rating;
}

// function to display movie rating based on user input
void displayRating(int rating) {
    printf("The movie rating is: ");
    switch(rating) {
        case 1:
            printf("Terrible\n");
            break;
        case 2:
            printf("Poor\n");
            break;
        case 3:
            printf("Below average\n");
            break;
        case 4:
            printf("Average\n");
            break;
        case 5:
            printf("Above average\n");
            break;
        case 6:
            printf("Good\n");
            break;
        case 7:
            printf("Very good\n");
            break;
        case 8:
            printf("Excellent\n");
            break;
        case 9:
            printf("Outstanding\n");
            break;
        case 10:
            printf("Masterpiece\n");
            break;
    }
}

int main() {
    // prompt user for movie rating
    int rating = getRating();
    // display movie rating
    displayRating(rating);
    return 0;
}