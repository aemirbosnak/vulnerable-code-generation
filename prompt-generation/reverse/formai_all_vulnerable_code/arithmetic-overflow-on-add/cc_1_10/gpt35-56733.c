//FormAI DATASET v1.0 Category: Movie Rating System ; Style: grateful
#include <stdio.h>

// Function to calculate movie rating
int rateMovie(int story, int acting, int music, int direction) {
    float avg = (story + acting + music + direction) / 4.0;
    if (avg >= 9.0) {
        return 5;   // masterful
    } else if (avg >= 8.0) {
        return 4;   // excellent
    } else if (avg >= 7.0) {
        return 3;   // good
    } else if (avg >= 6.0) {
        return 2;   // average
    } else {
        return 1;   // poor
    }
}

int main() {
    int story, acting, music, direction;
    printf("Welcome to our unique C Movie Rating System!\n");
    printf("Please rate the movie on a scale of 1 to 10 for the following categories:\n");
    printf("Story: ");
    scanf("%d", &story);
    printf("Acting: ");
    scanf("%d", &acting);
    printf("Music: ");
    scanf("%d", &music);
    printf("Direction: ");
    scanf("%d", &direction);
    printf("\n");

    int rating = rateMovie(story, acting, music, direction);
    printf("Based on your ratings, we give this movie a rating of:");

    switch(rating) {
        case 1:
            printf(" Poor\n");
            break;
        case 2:
            printf(" Average\n");
            break;
        case 3:
            printf(" Good\n");
            break;
        case 4:
            printf(" Excellent\n");
            break;
        case 5:
            printf(" Masterful\n");
            break;
        default:
            printf(" Invalid rating\n");
            break;
    }

    return 0;
}