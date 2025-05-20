//FormAI DATASET v1.0 Category: Movie Rating System ; Style: interoperable
#include <stdio.h>

// function prototypes
void welcomeMessage();
void displayMenu();
void addMovie();
void rateMovie();
void displayRatings();
void goodbyeMessage();

// global variables
int movieCount = 0;
char movieTitles[10][50];
float movieRatings[10] = {0};

int main() {
    int choice;

    welcomeMessage();

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMovie();
                break;
            case 2:
                rateMovie();
                break;
            case 3:
                displayRatings();
                break;
            case 4:
                goodbyeMessage();
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

void welcomeMessage() {
    printf("\nWelcome to the C Movie Rating System!\n\n");
}

void displayMenu() {
    printf("\nPlease choose an option:\n");
    printf("1. Add a movie to the system\n");
    printf("2. Rate a movie\n");
    printf("3. Display movie ratings\n");
    printf("4. Exit the program\n");
}

void addMovie() {
    char title[50];

    printf("\nEnter the title of the movie: ");
    scanf("%s", title);

    // check if movie already exists
    for(int i=0; i<movieCount; i++) {
        if(strcmp(title, movieTitles[i]) == 0) {
            printf("\nMovie already exists in the system.\n");
            return;
        }
    }

    // add movie to system
    strcpy(movieTitles[movieCount], title);
    movieCount++;
    
    printf("\nMovie added successfully!\n");
}

void rateMovie() {
    char title[50];
    float rating;
    int found = 0;

    printf("\nEnter the title of the movie you want to rate: ");
    scanf("%s", title);

    // search for movie
    for(int i=0; i<movieCount; i++) {
        if(strcmp(title, movieTitles[i]) == 0) {
            found = 1;

            // get rating from user
            printf("Enter your rating (out of 10): ");
            scanf("%f", &rating);

            // update average rating
            movieRatings[i] = (movieRatings[i] + rating) / 2;

            printf("\nRating added successfully!\n");
            break;
        }
    }

    if(!found) {
        printf("\nMovie not found in the system.\n");
    }
}

void displayRatings() {
    printf("\nMovie Ratings:\n");
    printf("--------------------\n");

    for(int i=0; i<movieCount; i++) {
        printf("%s: %.1f\n", movieTitles[i], movieRatings[i]);
    }

    printf("--------------------\n");
}

void goodbyeMessage() {
    printf("\nThank you for using the C Movie Rating System!\n");
}