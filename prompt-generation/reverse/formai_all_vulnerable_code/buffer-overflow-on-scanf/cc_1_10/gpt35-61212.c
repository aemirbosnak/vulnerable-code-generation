//FormAI DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>

// function prototypes
void displayIntro();
void displayMenu();
void rateMovie();
void viewRating();

int main() {
    int choice;

    displayIntro();
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                rateMovie();
                break;
            case 2:
                viewRating();
                break;
            case 3:
                printf("Thanks for using our movie rating system!");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// display introduction message
void displayIntro() {
    printf("Welcome to the futuristic Movie Rating System!\n\n");
    printf("In this system, you can rate the movies you've watched and view the ratings of other users.\n\n");
}

// display main menu
void displayMenu() {
    printf("Please choose an option:\n");
    printf("1. Rate a movie\n");
    printf("2. View movie ratings\n");
    printf("3. Quit\n");
}

// rate a movie
void rateMovie() {
    char title[50];
    int rating;

    printf("Please enter the title of the movie you want to rate:\n");
    scanf("%[^\n]s", title);
    printf("Please enter your rating (out of 10):\n");
    scanf("%d", &rating);

    FILE *file;
    file = fopen("ratings.txt", "a");
    fprintf(file, "%s: %d\n", title, rating);
    fclose(file);

    printf("Thank you for your rating!\n");
}

// view all movie ratings
void viewRating() {
    printf("Here are the movie ratings:\n");

    FILE *file;
    file = fopen("ratings.txt", "r");

    if (file) {
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }
        fclose(file);
    } else {
        printf("No ratings found.\n");
    }
}