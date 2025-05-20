//FormAI DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>

/* Function prototypes */
int getRating();
void printRating(int rating);

/* Main function */
int main()
{
    int movieRating = getRating();   /* Get user rating */
    printRating(movieRating);   /* Display user rating */

    return 0;   /* Exit program */
}

/* Function to get user rating */
int getRating()
{
    int rating;

    printf("Please rate this movie out of 10: ");
    scanf("%d", &rating);

    /* Validate user input */
    while (rating < 0 || rating > 10)
    {
        printf("Invalid rating. Please enter a rating between 0 and 10: ");
        scanf("%d", &rating);
    }

    return rating;
}

/* Function to display user rating */
void printRating(int rating)
{
    printf("Your movie rating is: ");

    /* Display rating using a switch statement */
    switch (rating)
    {
        case 0:
            printf("Terrible\n");
            break;
        case 1:
        case 2:
            printf("Poor\n");
            break;
        case 3:
        case 4:
            printf("Fair\n");
            break;
        case 5:
        case 6:
            printf("Average\n");
            break;
        case 7:
        case 8:
            printf("Good\n");
            break;
        case 9:
            printf("Excellent\n");
            break;
        case 10:
            printf("Perfect\n");
            break;
    }
}