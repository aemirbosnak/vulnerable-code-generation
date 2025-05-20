//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
#include <stdio.h>

// define constants for movie ratings
#define EXCELLENT 5
#define GOOD 4
#define OKAY 3
#define POOR 2
#define TERRIBLE 1

// function declarations
void displayMenu();
void rateMovie();

int main()
{
    // display welcome message and menu
    printf("Welcome to the Unique C Movie Rating System!\n");
    displayMenu();

    // rate movies until user quits
    char userInput;
    do
    {
        rateMovie();
        printf("Rate another movie? (y/n): ");
        scanf(" %c", &userInput);
    } while (userInput == 'y' || userInput == 'Y');

    printf("Thank you for using the Unique C Movie Rating System!\n");
    return 0;
}

// function to display the rating menu
void displayMenu()
{
    printf("Please rate the movie on a scale of 1 to 5:\n");
    printf("%d - Terrible\n", TERRIBLE);
    printf("%d - Poor\n", POOR);
    printf("%d - Okay\n", OKAY);
    printf("%d - Good\n", GOOD);
    printf("%d - Excellent\n", EXCELLENT);
}

// function to prompt the user for a movie rating and display a message based on the rating
void rateMovie()
{
    int rating;
    printf("Enter your rating (1-5): ");
    scanf("%d", &rating);
    switch (rating)
    {
        case TERRIBLE:
            printf("We're sorry you didn't like the movie.\n");
            break;
        case POOR:
            printf("We appreciate your feedback.\n");
            break;
        case OKAY:
            printf("Thank you for your rating.\n");
            break;
        case GOOD:
            printf("We're glad you enjoyed the movie!\n");
            break;
        case EXCELLENT:
            printf("Wow, thanks for your excellent rating!\n");
            break;
        default:
            printf("Invalid rating.\n");
    }
}