//FormAI DATASET v1.0 Category: Movie Rating System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a movie
typedef struct {
    char title[50];
    char director[50];
    char genre[20];
    float rating;
} Movie;

// Define a function to display the list of movies
void displayMovies(Movie *movies, int count) {
    printf("\n--------------------------------------------------\n");
    printf("|  Title                                 | Rating |");
    printf("\n--------------------------------------------------\n");
    for(int i = 0; i < count; i++) {
        printf("| %-40s |   %.1f  |\n", movies[i].title, movies[i].rating);
    }
    printf("--------------------------------------------------\n");
}

// Define a function to add a new movie to the list
void addMovie(Movie *movies, int *count) {
    char title[50], director[50], genre[20];
    float rating;
    printf("Enter the title of the movie: ");
    scanf("%s", title);
    printf("Enter the director of the movie: ");
    scanf("%s", director);
    printf("Enter the genre of the movie: ");
    scanf("%s", genre);
    printf("Enter your rating for the movie (out of 10): ");
    scanf("%f", &rating);
    Movie newMovie = {title, director, genre, rating};
    movies[*count] = newMovie;
    (*count)++;
    printf("%s added to the list.\n", title);
}

// Define a function to rate a movie
void rateMovie(Movie *movies, int count) {
    char title[50];
    float rating;
    int found = 0;
    printf("Enter the title of the movie to rate: ");
    scanf("%s", title);
    for(int i = 0; i < count; i++) {
        if(strcmp(movies[i].title, title) == 0) {
            found = 1;
            printf("Enter your rating for %s (out of 10): ", title);
            scanf("%f", &rating);
            movies[i].rating = rating;
            printf("Thank you for your rating.\n");
            break;
        }
    }
    if(!found) {
        printf("%s not found in the list.\n", title);
    }
}

// Define a function to sort the movies by rating
void sortMovies(Movie *movies, int count) {
    Movie temp;
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - i - 1; j++) {
            if(movies[j].rating < movies[j + 1].rating) {
                temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}

int main() {
    int count = 0, choice;
    Movie movies[50];
    printf("Welcome to the C Movie Rating System!\n");
    do {
        printf("\n\nMenu Options:\n");
        printf("1. Display list of movies\n");
        printf("2. Add a new movie\n");
        printf("3. Rate a movie\n");
        printf("4. Sort movies by rating\n");
        printf("5. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                displayMovies(movies, count);
                break;
            case 2:
                addMovie(movies, &count);
                break;
            case 3:
                rateMovie(movies, count);
                break;
            case 4:
                sortMovies(movies, count);
                printf("Movies sorted by rating.\n");
                break;
            case 5:
                printf("Thank you for using the C Movie Rating System!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(choice != 5);
    return 0;
}