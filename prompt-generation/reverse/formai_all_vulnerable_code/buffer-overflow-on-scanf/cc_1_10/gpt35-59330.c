//FormAI DATASET v1.0 Category: Movie Rating System ; Style: careful
#include<stdio.h>
#include<stdlib.h>

/* Function to validate user input and return a rating between 1-10 */
int validate_input(char rating[]) {
    int num = atoi(rating); // Convert string to integer
    if(num > 0 && num < 11) {
        return num;
    }
    else {
        printf("Invalid input. Please enter a rating between 1-10: ");
        scanf("%s", rating);
        validate_input(rating);
    }
}

int main() {
    char movie_name[50];
    char user_rating[5];
    int rating;
    char choice;

    printf("Welcome to the C Movie Rating System!\n\n");

    // Get movie name from user
    printf("Please enter the name of the movie you would like to rate: ");
    fgets(movie_name, 50, stdin);

    // Get user rating for the movie
    printf("Please enter your rating (between 1-10) for the movie %s: ", movie_name);
    scanf("%s", user_rating);

    // Validate user rating input
    rating = validate_input(user_rating);

    // Display movie name and rating
    printf("Thank you for rating the movie %s.\n", movie_name);
    printf("Your rating for the movie is %d out of 10.\n", rating);

    // Ask user if they would like to rate another movie
    printf("\nWould you like to rate another movie? (Y/N): ");
    scanf(" %c", &choice);

    // Loop until user chooses not to rate another movie
    while(choice == 'Y' || choice == 'y') {
        printf("\nPlease enter the name of the movie you would like to rate: ");
        getchar(); // clear input buffer
        fgets(movie_name, 50, stdin);

        printf("Please enter your rating (between 1-10) for the movie %s: ", movie_name);
        scanf("%s", user_rating);
        rating = validate_input(user_rating);

        // Display movie name and rating
        printf("Thank you for rating the movie %s.\n", movie_name);
        printf("Your rating for the movie is %d out of 10.\n", rating);

        printf("\nWould you like to rate another movie? (Y/N): ");
        scanf(" %c", &choice);
    }

    printf("\nThank you for using the C Movie Rating System!\n");

    return 0;
}