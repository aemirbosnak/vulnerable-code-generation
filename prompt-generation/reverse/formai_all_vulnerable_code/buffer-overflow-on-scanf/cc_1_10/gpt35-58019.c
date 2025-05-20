//FormAI DATASET v1.0 Category: Movie Rating System ; Style: creative
#include <stdio.h>

// Global variables to keep track of movie ratings
int ratings[5] = {0}; // initialize to all zeros
char movie_titles[5][50] = {"\0"}; // initialize to empty strings

// Function to add a movie and its rating
void add_movie_rating() {
    char title[50];
    printf("Enter movie title: ");
    scanf("%s", title);

    int rating;
    printf("Enter movie rating (1-10): ");
    scanf("%d", &rating);

    // Check if rating is valid
    if (rating < 1 || rating > 10) {
        printf("Invalid rating. Please enter a number between 1 and 10.\n");
        return;
    }

    // Check if title already exists
    for (int i = 0; i < 5; i++) {
        if (strcmp(movie_titles[i], title) == 0) {
            printf("Movie already exists in the database.\n");
            return;
        }
    }

    // Find first empty slot in ratings array
    int empty_slot = -1;
    for (int i = 0; i < 5; i++) {
        if (ratings[i] == 0) {
            empty_slot = i;
            break;
        }
    }

    // Check if ratings array is full
    if (empty_slot == -1) {
        printf("Database is full. Cannot add another movie rating.\n");
        return;
    }

    // Add movie and rating to arrays
    strcpy(movie_titles[empty_slot], title);
    ratings[empty_slot] = rating;

    printf("Movie rating added successfully.\n");
}

// Function to display all movie ratings
void display_movie_ratings() {
    printf("----- MOVIE RATINGS -----\n");
    for (int i = 0; i < 5; i++) {
        if (ratings[i] != 0) {
            printf("%s: %d\n", movie_titles[i], ratings[i]);
        }
    }
    printf("-------------------------\n");
}

// Main function
int main() {
    printf("Welcome to the C Movie Rating System!\n");

    // Main loop
    while (1) {
        printf("Enter 1 to add a movie rating, 2 to display all ratings, or 3 to exit: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie_rating();
                break;
            case 2:
                display_movie_ratings();
                break;
            case 3:
                printf("Thanks for using the C Movie Rating System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
                break;
        }
    }
}