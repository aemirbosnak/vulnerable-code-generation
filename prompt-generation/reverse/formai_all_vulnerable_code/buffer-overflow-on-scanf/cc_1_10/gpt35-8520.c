//FormAI DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>

// Struct to hold movie details
typedef struct {
    char title[50];
    char genre[20];
    int year;
} movie;

// Function to get and print movie details
void getMovieDetails(movie *m) {
    printf("Enter movie title: \n");
    scanf("%s", m->title);
    printf("Enter movie genre: \n");
    scanf("%s", m->genre);
    printf("Enter movie release year: \n");
    scanf("%d", &m->year);
    printf("\n");
    printf("Movie details:\n");
    printf("Title: %s\n", m->title);
    printf("Genre: %s\n", m->genre);
    printf("Release Year: %d\n", m->year);
    printf("\n");
}

// Function to get and print movie rating
void rateMovie(movie m) {
    int rating;
    printf("Rate the movie on a scale of 1-10: \n");
    scanf("%d", &rating);
    printf("You rated \"%s\" with a rating of %d/10\n", m.title, rating);
    printf("\n");
}

int main(void) {
    int choice;
    movie m;
    while (1) {
        printf("Enter choice:\n");
        printf("1 - Add movie details\n");
        printf("2 - Rate a movie\n");
        printf("3 - Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                getMovieDetails(&m);
                break;
            case 2:
                rateMovie(m);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}