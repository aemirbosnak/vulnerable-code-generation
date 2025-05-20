//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

/* The following variable represents the maximum number of movies that can be rated */
#define MAX_MOVIES 100

/* The following variables represent the maximum length of the movie title and rating */
#define MAX_TITLE_LENGTH 50
#define MAX_RATING_LENGTH 3

/* Struct for a movie */
typedef struct movie {
    char title[MAX_TITLE_LENGTH];
    char rating[MAX_RATING_LENGTH];
} movie;

/* Global array of movies */
movie movies[MAX_MOVIES];

/* Global variable for the number of movies */
int num_movies = 0;

/* Function prototypes */
void add_movie();
void rate_movie();
void list_movies();

/* Main function */
int main() {
    char choice;
    do {
        printf("\nC Movie Rating System\n");
        printf("----------------------\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. List Movies\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                add_movie();
                break;
            case '2':
                rate_movie();
                break;
            case '3':
                list_movies();
                break;
            case '4':
                printf("Thank you for using the C Movie Rating System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != '4');
    return 0;
}

/* Function to add a movie */
void add_movie() {
    if(num_movies == MAX_MOVIES) {
        printf("Maximum number of movies reached. Unable to add new movie.\n");
        return;
    }
    movie new_movie;
    printf("Enter movie title: ");
    scanf(" %[^\n]s", new_movie.title);
    printf("Enter movie rating (1-10): ");
    scanf(" %s", new_movie.rating);
    if(strlen(new_movie.rating) != 1 || new_movie.rating[0] < '1' || new_movie.rating[0] > '9') {
        printf("Invalid rating. Please try again with a rating between 1 and 10.\n");
        return;
    }
    movies[num_movies++] = new_movie;
    printf("Movie added successfully!\n");
}

/* Function to rate a movie */
void rate_movie() {
    if(num_movies == 0) {
        printf("No movies have been added yet. Unable to rate movie.\n");
        return;
    }
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie you would like to rate: ");
    scanf(" %[^\n]s", title);
    int i;
    for(i = 0; i < num_movies; i++) {
        if(strcmp(title, movies[i].title) == 0) {
            printf("Enter new rating for movie %s (1-10): ", movies[i].title);
            scanf(" %s", movies[i].rating);
            if(strlen(movies[i].rating) != 1 || movies[i].rating[0] < '1' || movies[i].rating[0] > '9') {
                printf("Invalid rating. Please try again with a rating between 1 and 10.\n");
                return;
            }
            printf("Movie %s successfully rated!\n", movies[i].title);
            return;
        }
    }
    printf("Movie %s not found. Please try again.\n", title);
}

/* Function to list all movies */
void list_movies() {
    if(num_movies == 0) {
        printf("No movies have been added yet. Unable to list movies.\n");
        return;
    }
    printf("List of Movies:\n");
    printf("----------------\n");
    int i;
    for(i = 0; i < num_movies; i++) {
        printf("Movie Title: %s\n", movies[i].title);
        printf("Movie Rating: %s\n", movies[i].rating);
        printf("----------------\n");
    }
}