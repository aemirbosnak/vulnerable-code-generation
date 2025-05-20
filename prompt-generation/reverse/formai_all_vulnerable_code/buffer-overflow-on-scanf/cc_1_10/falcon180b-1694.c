//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[100];
    int rating;
} Movie;

void addMovie(Movie* movies, int numMovies, char* name, int rating) {
    if (numMovies == 100) {
        printf("Error: Maximum number of movies reached.\n");
        return;
    }
    strcpy(movies[numMovies].name, name);
    movies[numMovies].rating = rating;
    numMovies++;
}

void sortMovies(Movie* movies, int numMovies) {
    for (int i = 0; i < numMovies - 1; i++) {
        for (int j = i + 1; j < numMovies; j++) {
            if (movies[i].rating < movies[j].rating) {
                Movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
}

void printMovies(Movie* movies, int numMovies) {
    for (int i = 0; i < numMovies; i++) {
        printf("%s: %d\n", movies[i].name, movies[i].rating);
    }
}

int main() {
    int numMovies = 0;
    Movie movies[100];
    
    while (1) {
        printf("\n1. Add movie\n2. Sort movies\n3. Print movies\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char name[100];
                int rating;
                printf("Enter movie name: ");
                scanf("%s", name);
                printf("Enter movie rating: ");
                scanf("%d", &rating);
                addMovie(movies, numMovies, name, rating);
                break;
            }
            case 2: {
                sortMovies(movies, numMovies);
                break;
            }
            case 3: {
                printMovies(movies, numMovies);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }
    
    return 0;
}