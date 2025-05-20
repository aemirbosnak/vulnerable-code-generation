//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: retro
#include <stdio.h>

// Function to display menu
void displayMenu() {
    printf("\n\nWelcome to the C Movie Rating System\n\n");
    printf("1. Enter Movie Details\n");
    printf("2. Display Ratings\n");
    printf("3. Exit\n");
}

// Function to get movie details from user
void getMovieDetails() {
    char movieName[50];
    int year;
    float rating;

    printf("\nEnter Movie Name: ");
    scanf("%s", movieName);

    printf("Enter Release Year: ");
    scanf("%d", &year);

    printf("Enter Rating (out of 10): ");
    scanf("%f", &rating);

    // Save movie details in a file
    FILE *file = fopen("movies.txt", "a");
    fprintf(file, "%s %d %.2f\n", movieName, year, rating);
    fclose(file);

    printf("\nMovie details saved successfully!\n");
}

// Function to display all movie ratings
void displayRatings() {
    FILE *file = fopen("movies.txt", "r");

    if (file == NULL) {
        printf("\nNo ratings available.\n");
        return;
    }

    printf("\n\nMovie Ratings:\n");
    printf("-----------------\n");

    char movieName[50];
    int year;
    float rating;

    while (fscanf(file, "%s %d %.2f", movieName, &year, &rating)!= EOF) {
        printf("%s (%d) - %.2f\n", movieName, year, rating);
    }

    fclose(file);
}

// Main function
int main() {
    int choice;

    do {
        system("clear"); // Clear console in retro style
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            getMovieDetails();
            break;

        case 2:
            displayRatings();
            break;

        case 3:
            printf("\nExiting...\n");
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}