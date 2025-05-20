//FormAI DATASET v1.0 Category: Movie Rating System ; Style: surprised
#include <stdio.h>

//function to calculate rating score based on user input
int calculateRatingScore(int acting, int storyline, int effects) {
    int ratingScore = ((acting * 3) + (storyline * 2) + effects) / 6;
    return ratingScore;
}

int main() {
    //variable declarations
    char movieTitle[50];
    int acting = 0, storyline = 0, effects = 0, ratingScore = 0;
    char reviewerName[20];
    char review[200];

    //get user input for movie title
    printf("Enter the movie title: ");
    scanf("%[^\n]s", movieTitle);
    getchar();

    //get user input for movie ratings
    printf("Rate the acting on a scale of 1-10: ");
    scanf("%d", &acting);
    printf("Rate the storyline on a scale of 1-10: ");
    scanf("%d", &storyline);
    printf("Rate the special effects on a scale of 1-10: ");
    scanf("%d", &effects);

    //calculate rating score using calculateRatingScore function
    ratingScore = calculateRatingScore(acting, storyline, effects);

    //get user input for reviewer name and review
    printf("Enter your name as the reviewer: ");
    scanf("%[^\n]s", reviewerName);
    getchar();
    printf("Write a short review of the movie: ");
    scanf("%[^\n]s", review);
    getchar();

    //print movie title, rating score, reviewer name, and review
    printf("\n\n************************************************************\n");
    printf("************* MOVIE RATING SYSTEM *********************\n");
    printf("************************************************************\n\n");
    printf("MOVIE TITLE: %s\n", movieTitle);
    printf("RATING SCORE: %d\n", ratingScore);
    printf("REVIEWER NAME: %s\n", reviewerName);
    printf("REVIEW: %s\n", review);
    printf("\n\n************************************************************\n");
    printf("******************** THANK YOU ******************************\n");
    printf("************************************************************\n\n");

    return 0;
}