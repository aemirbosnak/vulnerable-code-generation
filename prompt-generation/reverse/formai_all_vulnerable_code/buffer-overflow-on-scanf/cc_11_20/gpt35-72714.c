//FormAI DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>
#include <stdlib.h>

struct movie {
    char title[50];
    char director[50];
    int year;
    float rating;
};

int main() {
    int choice, numMovies = 0, i;
    struct movie *movies;
    
    // allocate memory for at least one movie
    movies = malloc(sizeof(struct movie));
    
    while (1) {
        printf("\n");
        printf("1. Add new movie\n");
        printf("2. View all movies\n");
        printf("3. Rate a movie\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // reallocate memory for one more movie
                numMovies++;
                movies = realloc(movies, numMovies * sizeof(struct movie));
                
                printf("Enter title of movie: ");
                scanf("%s", movies[numMovies - 1].title);
                
                printf("Enter director of movie: ");
                scanf("%s", movies[numMovies - 1].director);
                
                printf("Enter year of movie: ");
                scanf("%d", &movies[numMovies - 1].year);
                
                printf("Enter rating of movie: ");
                scanf("%f", &movies[numMovies - 1].rating);
                break;
                
            case 2:
                if (numMovies == 0) {
                    printf("No movies to display.\n");
                } else {
                    printf("%-50s%-50s%-10s%-10s\n", "Title", "Director", "Year", "Rating");
                    for (i = 0; i < numMovies; i++) {
                        printf("%-50s%-50s%-10d%-10.1f\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
                    }
                }
                break;
                
            case 3:
                if (numMovies == 0) {
                    printf("No movies to rate.\n");
                } else {
                    char title[50];
                    printf("Enter title of movie to rate: ");
                    scanf("%s", title);
                    
                    for (i = 0; i < numMovies; i++) {
                        if (strcmp(title, movies[i].title) == 0) {
                            printf("Current rating of %s is %.1f.\n", movies[i].title, movies[i].rating);
                            
                            printf("Enter new rating (0.0 - 10.0): ");
                            scanf("%f", &movies[i].rating);
                            break;
                        }
                    }
                    
                    if (i == numMovies) {
                        printf("No movie with title \"%s\" found.\n", title);
                    }
                }
                break;
                
            case 4:
                free(movies);
                return 0;
            
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}