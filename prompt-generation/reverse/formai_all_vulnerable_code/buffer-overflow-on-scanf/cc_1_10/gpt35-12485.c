//FormAI DATASET v1.0 Category: Movie Rating System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
void intro();
void menu();
void rate(short int[], short int);
float average(short int[], short int);

/* Main Function */
int main()
{
    /* Variables */
    short int numOfMovies = 0, counter = 0;
    char response = 'y';
    int rating[10];

    /* Introduction */
    intro();

    /* Main Menu */
    do
    {
        menu();

        /* Take User's Input */
        scanf("%hd", &numOfMovies);

        /* Validate User's Input */
        if (numOfMovies != 0 && numOfMovies <= 10)
        {
            for (counter = 0; counter < numOfMovies; counter++)
            {
                printf("Enter rating for movie #%d: ", counter + 1);
                scanf("%d", &rating[counter]);
            }

            /* Output Average Rating */
            rate(rating, numOfMovies);
        } 
        else
        {
            printf("Invalid Input! Please enter a value between 1 and 10.\n");
            continue;
        }

        /* Ask User for Another Input */
        printf("Do you want to rate another set of movies? (y/n): ");
        scanf(" %c", &response);

    } while (response == 'y' || response == 'Y');

    /* Exit Program */
    printf("Thank you for using our Movie Rating System! Goodbye!\n");
    return 0;
}

/* Function to Display Introduction */
void intro()
{
    printf("Welcome to our Movie Rating System!\n");
}

/* Function to Display Main Menu */
void menu()
{
    printf("\nHow many movies would you like to rate? (Maximum of 10)\n");
    printf("Enter 0 to exit.\n");
    printf("Enter Choice: ");
}

/* Function to Calculate and Display Average Rating */
void rate(short int rating[], short int numOfMovies)
{
    printf("\nAverage Rating = %.1f\n", average(rating, numOfMovies));
}

/* Function to Calculate Average Rating */
float average(short int rating[], short int numOfMovies)
{
    float total = 0, average = 0;
    short int counter = 0;

    for (counter = 0; counter < numOfMovies; counter++)
    {
        total += rating[counter];
    }

    average = total / numOfMovies;

    return average;
}