//FormAI DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void display_menu();
void rate_movie();
void view_ratings();
void exit_program();

// global variables
int num_ratings = 0;
int total_rating = 0;
float avg_rating = 0.0;

// main function
int main() {
    char choice;
    do {
        display_menu();
        printf("\n\tEnter choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                rate_movie();
                break;
            case '2':
                view_ratings();
                break;
            case '3':
                exit_program();
                break;
            default:
                printf("\n\tInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != '3');
    return 0;
}

// function implementations
void display_menu() {
    system("clear"); // clear console screen
    printf("\n\t**** Welcome to the C Movie Rating System ****\n");
    printf("\n\t1. Rate movie");
    printf("\n\t2. View ratings");
    printf("\n\t3. Exit program");
}

void rate_movie() {
    int rating;
    printf("\n\tEnter rating (1-10): ");
    scanf("%d", &rating);
    if (rating >= 1 && rating <= 10) {
        num_ratings++;
        total_rating += rating;
        avg_rating = (float)total_rating / num_ratings;
        printf("\n\tThank you for rating the movie!\n");
    } else {
        printf("\n\tInvalid rating. Please enter a number between 1 and 10.\n");
    }
}

void view_ratings() {
    printf("\n\tNumber of ratings: %d", num_ratings);
    printf("\n\tTotal rating: %d", total_rating);
    printf("\n\tAverage rating: %.2f\n", avg_rating);
    if (avg_rating >= 8.0) {
        printf("\n\tThis movie has an excellent rating!\n");
    } else if (avg_rating >= 6.0 && avg_rating < 8.0) {
        printf("\n\tThis movie has a good rating.\n");
    } else if (avg_rating >= 4.0 && avg_rating < 6.0) {
        printf("\n\tThis movie has an average rating.\n");
    } else {
        printf("\n\tThis movie has a poor rating.\n");
    }
}

void exit_program() {
    printf("\n\tThank you for using the C Movie Rating System. Goodbye!\n");
}