//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function declarations
void display_menu();
void get_movie_rating(int *rating);
void display_movie_rating(int rating);

int main() {
    int rating;

    // Get movie rating from user
    get_movie_rating(&rating);

    // Display movie rating
    display_movie_rating(rating);

    return 0;
}

// Function to display menu
void display_menu() {
    printf("\nWelcome to the Movie Rating System!\n");
    printf("Please select an option:\n");
    printf("1. Get movie rating\n");
    printf("2. Display movie rating\n");
    printf("3. Exit\n");
}

// Function to get movie rating from user
void get_movie_rating(int *rating) {
    int choice;

    printf("\nEnter your choice of movie rating:\n");
    printf("1. Excellent\n");
    printf("2. Good\n");
    printf("3. Average\n");
    printf("4. Below average\n");
    printf("5. Poor\n");

    scanf("%d", &choice);

    *rating = choice;
}

// Function to display movie rating
void display_movie_rating(int rating) {
    printf("\nThe movie rating is: ");

    switch(rating) {
        case 1:
            printf("Excellent\n");
            break;
        case 2:
            printf("Good\n");
            break;
        case 3:
            printf("Average\n");
            break;
        case 4:
            printf("Below average\n");
            break;
        case 5:
            printf("Poor\n");
            break;
        default:
            printf("Invalid rating\n");
            break;
    }
}