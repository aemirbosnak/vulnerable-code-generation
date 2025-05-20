//FormAI DATASET v1.0 Category: Movie Rating System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */
#define MAX_MOVIES 100
#define MAX_RATINGS 5

/* Structures */
struct movie {
    char title[100];
    char director[100];
    int year;
    float avg_rating;
    int num_ratings;
    int ratings[MAX_RATINGS];
};

/* Function Prototypes */
void addMovie(struct movie movies[], int *num_movies);
void rateMovie(struct movie movies[], int num_movies);
void printMovies(struct movie movies[], int num_movies);
void searchMovies(struct movie movies[], int num_movies);
void printMenu();

/* Main Function */
int main() {
    struct movie movies[MAX_MOVIES];
    int num_movies = 0;
    int choice;
    
    do {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMovie(movies, &num_movies);
                break;
            case 2:
                rateMovie(movies, num_movies);
                break;
            case 3:
                printMovies(movies, num_movies);
                break;
            case 4:
                searchMovies(movies, num_movies);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}

/* Function to Add a Movie */
void addMovie(struct movie movies[], int *num_movies) {
    if (*num_movies < MAX_MOVIES) {
        struct movie new_movie;
        
        printf("Enter movie title: ");
        scanf(" %[^\n]s", new_movie.title);
        
        printf("Enter movie director: ");
        scanf(" %[^\n]s", new_movie.director);
        
        printf("Enter year of release: ");
        scanf("%d", &new_movie.year);
        
        new_movie.avg_rating = 0;
        new_movie.num_ratings = 0;
        
        movies[*num_movies] = new_movie;
        *num_movies += 1;
        
        printf("Movie added successfully!\n");
    } else {
        printf("Maximum number of movies reached. Cannot add more movies.\n");
    }
}

/* Function to Rate a Movie */
void rateMovie(struct movie movies[], int num_movies) {
    char movie_title[100];
    int rating;
    int i, movie_index = -1;
    
    printf("Enter movie title to rate: ");
    scanf(" %[^\n]s", movie_title);
    
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movie_title, movies[i].title) == 0) {
            movie_index = i;
            break;
        }
    }
    
    if (movie_index != -1) {
        printf("Enter rating (1-5): ");
        scanf("%d", &rating);
        
        if (rating >= 1 && rating <= 5) {
            movies[movie_index].ratings[movies[movie_index].num_ratings] = rating;
            movies[movie_index].num_ratings += 1;
            
            float total_rating = 0;
            for (i = 0; i < movies[movie_index].num_ratings; i++) {
                total_rating += movies[movie_index].ratings[i];
            }
            
            movies[movie_index].avg_rating = total_rating / movies[movie_index].num_ratings;
            
            printf("Rating added successfully!\n");
        } else {
            printf("Invalid rating. Please rate between 1-5.\n");
        }
    } else {
        printf("Movie not found. Please check the title and try again.\n");
    }
}

/* Function to Print All Movies */
void printMovies(struct movie movies[], int num_movies) {
    int i, j;
    
    if (num_movies > 0) {
        printf("%-30s | %-20s | %-4s | %-6s | %-10s\n", "Title", "Director", "Year", "Avg. Rating", "No. Ratings");
        
        for (i = 0; i < num_movies; i++) {
            printf("%-30s | %-20s | %-4d | %-6.2f     | %-10d\n", movies[i].title, movies[i].director, movies[i].year, movies[i].avg_rating, movies[i].num_ratings);
        }
    } else {
        printf("No movies to display.\n");
    }
}

/* Function to Search for a Movie */
void searchMovies(struct movie movies[], int num_movies) {
    char search_term[100];
    int found = 0;
    int i, j;
    
    printf("Enter search term: ");
    scanf(" %[^\n]s", search_term);
    
    for (i = 0; i < num_movies; i++) {
        if (strstr(movies[i].title, search_term) != NULL) {
            printf("%-30s | %-20s | %-4s | %-6s | %-10s\n", "Title", "Director", "Year", "Avg. Rating", "No. Ratings");
            printf("%-30s | %-20s | %-4d | %-6.2f     | %-10d\n", movies[i].title, movies[i].director, movies[i].year, movies[i].avg_rating, movies[i].num_ratings);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No movies found matching the search term.\n");
    }
}

/* Function to Print Menu */
void printMenu() {
    printf("C Movie Rating System\n");
    printf("======================\n");
    printf("1. Add a movie\n");
    printf("2. Rate a movie\n");
    printf("3. View all movies\n");
    printf("4. Search for a movie\n");
    printf("5. Quit\n");
    printf("Enter your choice (1-5): ");
}