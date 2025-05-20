//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char movie[50];
    int rating;
    printf("Enter the movie title: ");
    gets(movie);
    printf("Enter the movie rating (1-10): ");
    scanf("%d", &rating);
    if (rating < 1 || rating > 10) {
        printf("Invalid rating! Please enter a rating between 1 and 10.\n");
        return 1;
    }
    else if (rating == 1) {
        printf("This movie is so bad it's good!\n");
    }
    else if (rating == 2) {
        printf("This movie is terrible!\n");
    }
    else if (rating == 3) {
        printf("This movie is so-so.\n");
    }
    else if (rating == 4) {
        printf("This movie is pretty good.\n");
    }
    else if (rating == 5) {
        printf("This movie is good.\n");
    }
    else if (rating == 6) {
        printf("This movie is pretty awesome.\n");
    }
    else if (rating == 7) {
        printf("This movie is amazing!\n");
    }
    else if (rating == 8) {
        printf("This movie is a masterpiece!\n");
    }
    else if (rating == 9) {
        printf("This movie is perfect!\n");
    }
    else if (rating == 10) {
        printf("This movie is the best movie ever made!\n");
    }
    else {
        printf("Invalid rating! Please enter a rating between 1 and 10.\n");
    }
    return 0;
}