//FormAI DATASET v1.0 Category: Movie Rating System ; Style: grateful
#include <stdio.h>
#include <string.h>

struct movie {
    char title[50];
    int year;
    float rating;
};

void printMovies(struct movie[], int);
void addMovie(struct movie[], int*);
void deleteMovie(struct movie[], int*);
void sortMovies(struct movie[], int);

int main() {
    struct movie movies[100];
    int numOfMovies = 0;
    char userCommand[10];
    
    printf("Welcome to the Movie Rating System!\n\n");
    
    do { 
        printf("Enter a command (add, delete, sort, print, quit): ");
        scanf("%s", userCommand);
        
        if (strcmp(userCommand, "add") == 0) {
            addMovie(movies, &numOfMovies);
        } 
        else if (strcmp(userCommand, "delete") == 0) {
            deleteMovie(movies, &numOfMovies);
        } 
        else if (strcmp(userCommand, "sort") == 0) {
            sortMovies(movies, numOfMovies);
        } 
        else if (strcmp(userCommand, "print") == 0) {
            printMovies(movies, numOfMovies);
        }
    } while (strcmp(userCommand, "quit") != 0);

    printf("\nThanks for using the Movie Rating System!");

    return 0;
}

void printMovies(struct movie movies[], int numOfMovies) {
    printf("\nYour movie list:\n");
    for (int i = 0; i < numOfMovies; i++) {
        printf("%s (%d) - %0.1f/10\n", movies[i].title, movies[i].year, movies[i].rating);
    }
}

void addMovie(struct movie movies[], int *numOfMovies) {
    char title[50];
    int year;
    float rating;
    
    printf("\nEnter the movie title: ");
    scanf("%s", title);
    
    printf("Enter the movie release year: ");
    scanf("%d", &year);
    
    printf("Enter the movie rating (out of 10): ");
    scanf("%f", &rating);
    
    struct movie newMovie = {title, year, rating};
    movies[*numOfMovies] = newMovie;
    *numOfMovies += 1;
    
    printf("Movie added successfully!\n");
}

void deleteMovie(struct movie movies[], int *numOfMovies) {
    char title[50];
    int foundIndex = -1;
    
    printf("\nEnter the movie title to delete: ");
    scanf("%s", title);

    for (int i = 0; i < *numOfMovies; i++) {
        if (strcmp(title, movies[i].title) == 0) {
            foundIndex = i;
        }
    }
    
    if (foundIndex != -1) {
        for (int i = foundIndex; i < *numOfMovies - 1; i++) {
            movies[i] = movies[i + 1];
        }
        *numOfMovies -= 1;
        printf("Movie deleted successfully!\n");
    } else {
        printf("Movie not found, please try again.\n");
    }    
}

void sortMovies(struct movie movies[], int numOfMovies) {
    struct movie temp;
    
    for (int i = 0; i < numOfMovies - 1; i++) {
        for (int j = 0; j < numOfMovies - 1 - i; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
    
    printf("\nMovies sorted by rating!\n");
}