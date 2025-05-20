//FormAI DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>

//function to get user's rating
int getRating() {
    int rating;

    printf("\nHow would you rate the movie out of 10? ");
    scanf("%d", &rating);

    if (rating > 10) {
        printf("\nWoah, that's too high! Maximum rating is 10.");
        return getRating(); //recursion to prompt user again
    }

    return rating;
}

//function to display rating
void displayRating(int rating) {
    printf("\n\nThank you for rating the movie!\n");
    printf("Your rating: %d/10", rating);

    switch(rating) {
        case 10:
            printf("\nWow, perfect 10!");
            break;
        case 9:
            printf("\nAwesome, almost perfect!");
            break;
        case 8:
            printf("\nGreat, highly recommended!");
            break;
        case 7:
            printf("\nGood, definitely worth watching!");
            break;
        case 6:
            printf("\nDecent, has some entertainment value.");
            break;
        case 5:
            printf("\nAverage, not bad but not amazing either.");
            break;
        default:
            printf("\nHmm, needs some work.");
    }
}

int main() {
    printf("Welcome to our Movie Rating System!\n\n");

    int rating = getRating();
    displayRating(rating);

    return 0;
}