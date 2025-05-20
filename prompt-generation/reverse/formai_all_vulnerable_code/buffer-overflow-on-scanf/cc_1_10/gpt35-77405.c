//FormAI DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100

// Struct to hold information about a movie
typedef struct {
    char title[50];
    char director[30];
    int year;
    float rating;
} Movie;

// Function prototypes
void addMovie(Movie movies[], int* numMovies); 
void displayMovies(Movie movies[], int numMovies); 
void searchMovie(Movie movies[], int numMovies);
void deleteMovie(Movie movies[], int* numMovies);
void updateRating(Movie movies[], int numMovies);

int main() {
    int choice, numMovies = 0;
    Movie movies[MAX_MOVIES];
    
    do {
        // Display menu
        printf("\n\n=== C MOVIE RATING SYSTEM ===\n");
        printf("1. Add movie\n");
        printf("2. Display all movies\n");
        printf("3. Search movie\n");
        printf("4. Delete movie\n");
        printf("5. Update rating\n");
        printf("0. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addMovie(movies, &numMovies);
                break;
            case 2:
                displayMovies(movies, numMovies);
                break;
            case 3:
                searchMovie(movies, numMovies);
                break;
            case 4:
                deleteMovie(movies, &numMovies);
                break;
            case 5:
                updateRating(movies, numMovies);
                break;
            case 0:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid input. Please try again.\n");
                break;
        }
    } while(choice != 0);
    
    return 0;
}

void addMovie(Movie movies[], int* numMovies) {
    // Check if there is space for a new movie
    if(*numMovies == MAX_MOVIES) {
        printf("\nError: Maximum number of movies reached.\n");
        return;
    }
    
    // Get new movie information from user
    printf("\nEnter movie information:\n");
    printf("Title (40 characters max): ");
    fflush(stdin);
    fgets(movies[*numMovies].title, 50, stdin);
    printf("Director (30 characters max): ");
    fflush(stdin);
    fgets(movies[*numMovies].director, 30, stdin);
    printf("Year: ");
    scanf("%d", &movies[*numMovies].year);
    printf("Rating (0.0 - 10.0): ");
    scanf("%f", &movies[*numMovies].rating);
    
    // Increment movie count
    (*numMovies)++;
    
    printf("\nMovie added successfully.\n");
}

void displayMovies(Movie movies[], int numMovies) {
    // Check if there are movies to display
    if(numMovies == 0) {
        printf("\nNo movies to display.\n");
        return;
    }
    
    printf("\n=== MOVIES ===\n");
    for(int i = 0; i < numMovies; i++) {
        printf("Title: %s", movies[i].title);
        printf("Director: %s", movies[i].director);
        printf("Year: %d\n", movies[i].year);
        printf("Rating: %.1f\n\n", movies[i].rating);
    }
}

void searchMovie(Movie movies[], int numMovies) {
    // Check if there are movies to search
    if(numMovies == 0) {
        printf("\nNo movies to search.\n");
        return;
    }
    
    char title[50];
    int found = 0;
    
    printf("\nEnter movie title to search for: ");
    fflush(stdin);
    fgets(title, 50, stdin);
    
    for(int i = 0; i < numMovies; i++) {
        if(strcasecmp(title, movies[i].title) == 0) {
            printf("\n=== MOVIE FOUND ===\n");
            printf("Title: %s", movies[i].title);
            printf("Director: %s", movies[i].director);
            printf("Year: %d\n", movies[i].year);
            printf("Rating: %.1f\n\n", movies[i].rating);
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("\nMovie not found.\n");
    }
}

void deleteMovie(Movie movies[], int* numMovies) {
    // Check if there are movies to delete
    if(*numMovies == 0) {
        printf("\nNo movies to delete.\n");
        return;
    }
    
    char title[50];
    int found = 0;
    
    printf("\nEnter movie title to delete: ");
    fflush(stdin);
    fgets(title, 50, stdin);
    
    for(int i = 0; i < *numMovies; i++) {
        if(strcasecmp(title, movies[i].title) == 0) {
            found = 1;
            // Shift all movies after the deleted one to the left
            for(int j = i; j < *numMovies - 1; j++) {
                strcpy(movies[j].title, movies[j+1].title);
                strcpy(movies[j].director, movies[j+1].director);
                movies[j].year = movies[j+1].year;
                movies[j].rating = movies[j+1].rating;
            }
            (*numMovies)--;
            printf("\nMovie deleted.\n");
            break;
        }
    }
    
    if(!found) {
        printf("\nMovie not found.\n");
    }
}

void updateRating(Movie movies[], int numMovies) {
    // Check if there are movies to update
    if(numMovies == 0) {
        printf("\nNo movies to update.\n");
        return;
    }
    
    char title[50];
    int found = 0;
    
    printf("\nEnter movie title to update: ");
    fflush(stdin);
    fgets(title, 50, stdin);
    
    for(int i = 0; i < numMovies; i++) {
        if(strcasecmp(title, movies[i].title) == 0) {
            printf("\nEnter new movie rating: ");
            scanf("%f", &movies[i].rating);
            printf("\nMovie rating updated.\n");
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("\nMovie not found.\n");
    }
}