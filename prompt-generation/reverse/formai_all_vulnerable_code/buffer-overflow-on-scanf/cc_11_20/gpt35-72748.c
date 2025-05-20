//FormAI DATASET v1.0 Category: Movie Rating System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int userRating;
    char movieTitle[50];
    
    printf("Welcome to our unique C Movie Rating System!\n");
    printf("Please enter the movie title: ");
    fgets(movieTitle, 50, stdin);
    
    printf("\n");
    printf("Please rate %s out of 10: ", movieTitle);
    scanf("%d", &userRating);
    
    if (userRating < 0 || userRating > 10) {
        printf("\n");
        printf("Invalid rating. Please enter a rating between 0 and 10.\n");
        printf("Please rate %s out of 10: ", movieTitle);
        scanf("%d", &userRating);
    }
    
    printf("\n");
    
    switch(userRating) {
        case 0:
        case 1:
        case 2:
            printf("We're sorry to hear you didn't enjoy %s.\n", movieTitle);
            printf("We rate it as a 1-star movie.\n");
            break;
        case 3:
        case 4:
            printf("Thanks for your rating of %s.\n", movieTitle);
            printf("We rate it as a 2-star movie.\n");
            break;
        case 5:
        case 6:
            printf("Thanks for your rating of %s.\n", movieTitle);
            printf("We rate it as a 3-star movie.\n");
            break;
        case 7:
        case 8:
            printf("Thanks for your rating of %s.\n", movieTitle);
            printf("We rate it as a 4-star movie.\n");
            break;
        case 9:
        case 10:
            printf("Wow! Thanks for your high rating of %s!\n", movieTitle);
            printf("We rate it as a 5-star movie.\n");
            break;
    }
    
    return 0;
}