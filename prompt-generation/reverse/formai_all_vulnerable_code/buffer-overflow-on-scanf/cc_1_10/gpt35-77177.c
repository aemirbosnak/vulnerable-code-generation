//FormAI DATASET v1.0 Category: Movie Rating System ; Style: peaceful
#include <stdio.h>

/* Function prototypes */
void displayMenu();
void rateMovie(int* ratings, int movieIndex);
void viewMovieRatings(int* ratings, int movieIndex);

/* Main function */
int main() {
    /* Initialize movie names and ratings */
    char* movieTitles[5] = {"The Shawshank Redemption", "The Godfather", "The Dark Knight", "The Godfather: Part II", "Pulp Fiction"};
    int movieRatings[5] = {0};

    /* Display welcome message */
    printf("Welcome to the C Movie Rating System!\n\n");

    while (1) {
        /* Display menu and get user's choice */
        displayMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        /* Handle user's choice */
        switch (choice) {
            case 1:
                printf("\n");
                for (int i = 0; i < 5; i++) {
                    printf("%d. %s - %d\n", i + 1, movieTitles[i], movieRatings[i]);
                }
                printf("\n");
                break;
            case 2:
                rateMovie(movieRatings, 0);
                break;
            case 3:
                rateMovie(movieRatings, 1);
                break;
            case 4:
                rateMovie(movieRatings, 2);
                break;
            case 5:
                rateMovie(movieRatings, 3);
                break;
            case 6:
                rateMovie(movieRatings, 4);
                break;
            case 7:
                printf("\nThank you for using the C Movie Rating System!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
}

/* Function definitions */

/* Displays the system menu */
void displayMenu() {
    printf("Main Menu\n");
    printf("---------\n");
    printf("1. View movie ratings\n");
    printf("2. Rate The Shawshank Redemption\n");
    printf("3. Rate The Godfather\n");
    printf("4. Rate The Dark Knight\n");
    printf("5. Rate The Godfather: Part II\n");
    printf("6. Rate Pulp Fiction\n");
    printf("7. Exit\n\n");
}

/* Gets user's rating for a movie and updates the rating array */
void rateMovie(int* ratings, int movieIndex) {
    int rating;
    printf("\nEnter your rating (1-10): ");
    scanf("%d", &rating);

    if (rating < 1 || rating > 10) {
        printf("Invalid rating. Please enter a rating between 1 and 10.\n");
        rateMovie(ratings, movieIndex);
        return;
    }

    ratings[movieIndex] = rating;
    printf("Thank you for rating %s.\n\n", 
    (movieIndex == 0) ? "The Shawshank Redemption" : 
    (movieIndex == 1) ? "The Godfather" : 
    (movieIndex == 2) ? "The Dark Knight" : 
    (movieIndex == 3) ? "The Godfather: Part II" : "Pulp Fiction");
}

/* Displays the user's rating of a movie */
void viewMovieRatings(int* ratings, int movieIndex) {
    printf("The current rating for %s is %d.\n\n", 
    (movieIndex == 0) ? "The Shawshank Redemption" : 
    (movieIndex == 1) ? "The Godfather" : 
    (movieIndex == 2) ? "The Dark Knight" : 
    (movieIndex == 3) ? "The Godfather: Part II" : "Pulp Fiction", ratings[movieIndex]);
}