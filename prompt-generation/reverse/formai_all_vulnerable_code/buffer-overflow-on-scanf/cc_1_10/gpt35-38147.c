//FormAI DATASET v1.0 Category: Movie Rating System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display welcome message
void welcome() {
    printf("===========================================\n");
    printf("* Welcome to the C Movie Rating System! *\n");
    printf("===========================================\n\n");
}

// Function to display menu and get user choice
int menu() {
    int choice;
    printf("Please choose an option:\n");
    printf("1. Rate a Movie\n");
    printf("2. View Movie Ratings\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    // verify user input is valid
    while (choice < 1 || choice > 3) {
        printf("Invalid input, please try again.\n");
        printf("Please choose an option:\n");
        printf("1. Rate a Movie\n");
        printf("2. View Movie Ratings\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
    }
    return choice;
}

// Function to rate a movie and store it in a file
void rate_movie() {
    char title[50];
    int rating;

    printf("Enter the title of the movie: ");
    scanf("%s", title);

    printf("Enter a rating for the movie (1-10): ");
    scanf("%d", &rating);

    // verify rating is valid
    while (rating < 1 || rating > 10) {
        printf("Invalid rating, please try again.\n");
        printf("Enter a rating for the movie (1-10): ");
        scanf("%d", &rating);
    }

    // create a new file or append to existing file
    FILE *fp;
    fp = fopen("movie_ratings.txt", "a");
    fprintf(fp, "%s,%d\n", title, rating);
    fclose(fp);

    printf("Thank you for rating %s!\n", title);
}

// Function to view movie ratings from file
void view_ratings() {
    char line[100];
    char* title;
    char* rating;

    // open the file
    FILE *fp;
    fp = fopen("movie_ratings.txt", "r");

    // verify file is not empty
    if (fp == NULL) {
        printf("No ratings have been added yet.\n");
        return;
    }

    // display all ratings in file
    printf("===========================================\n");
    printf("             MOVIE RATINGS\n");
    printf("===========================================\n\n");
    printf("Title                | Rating\n");
    printf("-------------------------------------------\n");
    while (fgets(line, 100, fp) != NULL) {
        title = strtok(line, ",");
        rating = strtok(NULL, ",");
        printf("%-20s | %s", title, rating);
    }
    fclose(fp);
}

int main() {
    welcome();
    int choice;

    do {
        choice = menu();
        switch (choice) {
            case 1:
                rate_movie();
                break;
            case 2:
                view_ratings();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
        }
    } while (choice != 3);

    return 0;
}