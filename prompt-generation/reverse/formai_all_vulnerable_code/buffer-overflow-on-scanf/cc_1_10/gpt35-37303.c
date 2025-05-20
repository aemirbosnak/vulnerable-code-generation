//FormAI DATASET v1.0 Category: Movie Rating System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create structure for movie details
struct movie {
    char title[50];
    char director[50];
    int year;
    float rating;
};

// function to add a new movie to the rating system
struct movie add_movie() {
    struct movie new_movie;
    printf("Please enter the movie title: ");
    scanf("%s", new_movie.title);
    printf("Please enter the movie director: ");
    scanf("%s", new_movie.director);
    printf("Please enter the movie release year: ");
    scanf("%d", &new_movie.year);
    printf("Please enter the movie rating (out of 10): ");
    scanf("%f", &new_movie.rating);
    return new_movie;
}

// function to display details of a movie
void display_movie(struct movie movie) {
    printf("\nTitle: %s\nDirector: %s\nYear: %d\nRating: %.1f/10\n", movie.title, movie.director, movie.year, movie.rating);
}

// function to search for a movie by title
struct movie search_by_title(char query[], struct movie movies[], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(movies[i].title, query) == 0) {
            return movies[i];
        }
    }
    struct movie not_found = {"", "", 0, 0.0};
    return not_found;
}

// function to search for a movie by director
struct movie search_by_director(char query[], struct movie movies[], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(movies[i].director, query) == 0) {
            return movies[i];
        }
    }
    struct movie not_found = {"", "", 0, 0.0};
    return not_found;
}

int main() {
    int choice;
    int count = 0;
    struct movie movies[50];
    struct movie current_movie;
    char query[50];

    printf("Welcome to the Unique C Movie Rating System (UCMRS)!\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Add a new movie\n");
        printf("2. Search for a movie by title\n");
        printf("3. Search for a movie by director\n");
        printf("4. Display all movies\n");
        printf("5. Exit program\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                current_movie = add_movie();
                movies[count] = current_movie;
                count++;
                break;
            case 2:
                printf("\nPlease enter the title of the movie you are searching for: ");
                scanf("%s", query);
                current_movie = search_by_title(query, movies, count);
                if (strcmp(current_movie.title, "") == 0) {
                    printf("\nMovie not found.\n");
                } else {
                    display_movie(current_movie);
                }
                break;
            case 3:
                printf("\nPlease enter the director of the movie you are searching for: ");
                scanf("%s", query);
                current_movie = search_by_director(query, movies, count);
                if (strcmp(current_movie.title, "") == 0) {
                    printf("\nMovie not found.\n");
                } else {
                    display_movie(current_movie);
                }
                break;
            case 4:
                printf("\nAll Movies:\n");
                for (int i = 0; i < count; i++) {
                    display_movie(movies[i]);
                }
                break;
            case 5:
                printf("\nThank you for using the Unique C Movie Rating System (UCMRS)!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while(1);

    return 0;
}