//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

struct Movie {
    char title[50];
    char director[50];
    char rating[10];
};

void displayMenu() {
    printf("\n");
    printf("Welcome to the C Movie Rating System! \n");
    printf("------------------------------------ \n");
    printf("1. Add a movie \n");
    printf("2. View all movies \n");
    printf("3. Search for a movie \n");
    printf("4. Rate a movie \n");
    printf("5. Exit \n");
    printf("\n");
}

void addMovie(struct Movie movies[], int *numMovies) {
    printf("Enter the title of the movie:\n");
    scanf("%s", movies[*numMovies].title);
    printf("Enter the director of the movie:\n");
    scanf("%s", movies[*numMovies].director);
    printf("Movie added successfully! \n");
    (*numMovies)++;
}

void viewMovies(struct Movie movies[], int numMovies) {
    if (numMovies == 0) {
        printf("No movies in the system. \n");
    } else {
        printf("List of all movies: \n");
        for (int i = 0; i < numMovies; i++) {
            printf("%d. %s, directed by %s, rating: %s \n", i+1, movies[i].title, movies[i].director, movies[i].rating);
        }
    }
}

void searchMovie(struct Movie movies[], int numMovies) {
    char searchTerm[50];
    printf("Enter the name of the movie you want to search for: \n");
    scanf("%s", searchTerm);
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].title, searchTerm) == 0) {
            printf("%s, directed by %s, rating: %s \n", movies[i].title, movies[i].director, movies[i].rating);
            return;
        }
    }
    printf("Movie not found. \n");
}

void rateMovie(struct Movie movies[], int numMovies) {
    char searchTerm[50];
    char newRating[10];
    printf("Enter the name of the movie you want to rate: \n");
    scanf("%s", searchTerm);
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].title, searchTerm) == 0) {
            printf("Enter the new rating for %s: \n", movies[i].title);
            scanf("%s", newRating);
            strcpy(movies[i].rating, newRating);
            printf("Rating updated successfully! \n");
            return;
        }
    }
    printf("Movie not found. \n");
}

int main() {
    int choice = 0;
    int numMovies = 0;
    struct Movie movies[20];

    while (choice != 5) {
        displayMenu();
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &numMovies);
                break;
            case 2:
                viewMovies(movies, numMovies);
                break;
            case 3:
                searchMovie(movies, numMovies);
                break;
            case 4:
                rateMovie(movies, numMovies);
                break;
            case 5:
                printf("Thank you for using the C Movie Rating System! \n");
                break;
            default:
                printf("Invalid choice. \n");
                break;
        }
     }

    return 0;
}