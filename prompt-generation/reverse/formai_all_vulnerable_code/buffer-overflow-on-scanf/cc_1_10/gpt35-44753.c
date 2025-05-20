//FormAI DATASET v1.0 Category: Movie Rating System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie {
    char title[100];
    char director[100];
    int year;
    double rating;
    char genre[20];
};

void printMenu() {
    printf("\n**** C MOVIE RATING SYSTEM ****\n\n");
    printf("1. Add a movie\n");
    printf("2. View movie list\n");
    printf("3. Search for a movie\n");
    printf("4. Rate a movie\n");
    printf("5. Exit\n");
    printf("\nEnter your choice: ");
}

int main() {
    int choice, numMovies = 0;
    char title[100], director[100], genre[20];
    int year;
    double rating;
    struct movie *movies = malloc(sizeof(struct movie)); // Dynamic array of movies
    
    printf("Welcome to the C Movie Rating System!\n");

    do {
        printMenu();
        scanf("%d", &choice);
        fflush(stdin);

        switch(choice) {
            case 1: // Add a movie
                printf("\nEnter movie title: ");
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                printf("Enter director name: ");
                fgets(director, 100, stdin);
                director[strcspn(director, "\n")] = 0;
                printf("Enter release year: ");
                scanf("%d", &year);
                printf("Enter genre: ");
                fgets(genre, 20, stdin);
                genre[strcspn(genre, "\n")] = 0;
                printf("Enter rating (out of 10): ");
                scanf("%lf", &rating);

                numMovies++;
                movies = realloc(movies, numMovies * sizeof(struct movie)); // Expand the array
                strcpy(movies[numMovies - 1].title, title);
                strcpy(movies[numMovies - 1].director, director);
                movies[numMovies - 1].year = year;
                strcpy(movies[numMovies - 1].genre, genre);
                movies[numMovies - 1].rating = rating;

                printf("\nMovie added successfully!\n");
                break;

            case 2: // View movie list
                printf("\n**** MOVIE LIST ****\n");
                if(numMovies == 0) {
                    printf("\nNo movies in the list!\n");
                } else {
                    for(int i = 0; i < numMovies; i++) {
                        printf("\n%d. %s (%d) - %s - %.1lf/10", i+1, movies[i].title, movies[i].year, movies[i].director, movies[i].rating);
                    }
                }
                break;

            case 3: // Search for a movie
                if(numMovies == 0) {
                    printf("\nNo movies in the list!\n");
                } else {
                    char searchTitle[100];
                    printf("\nEnter movie title to search: ");
                    fgets(searchTitle, 100, stdin);
                    searchTitle[strcspn(searchTitle, "\n")] = 0;
                    int found = 0;
                    for(int i = 0; i < numMovies; i++) {
                        if(strcmp(movies[i].title, searchTitle) == 0) {
                            found = 1;
                            printf("\n%d. %s (%d) - %s - %.1lf/10", i+1, movies[i].title, movies[i].year, movies[i].director, movies[i].rating);
                        }
                    }
                    if(found == 0) {
                        printf("\nMovie not found!\n");
                    }
                }
                break;

            case 4: // Rate a movie
                if(numMovies == 0) {
                    printf("\nNo movies in the list!\n");
                } else {
                    int rateIndex;
                    double newRating;
                    printf("\nEnter movie index to rate: ");
                    scanf("%d", &rateIndex);
                    printf("Enter new rating (out of 10): ");
                    scanf("%lf", &newRating);
                    movies[rateIndex - 1].rating = newRating;
                    printf("\nMovie rating updated successfully!\n");
                }
                break;

            case 5: // Exit
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }

    } while(choice != 5);

    free(movies); // Free the memory allocated for the dynamic array
    return 0;
}