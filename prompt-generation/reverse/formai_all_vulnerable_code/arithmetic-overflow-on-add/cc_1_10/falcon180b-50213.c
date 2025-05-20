//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

struct Movie {
    char title[50];
    int rating;
    int numRatings;
};

void addMovie(struct Movie *movies, int numMovies) {
    printf("Enter movie title: ");
    scanf("%s", movies[numMovies].title);
    movies[numMovies].rating = 0;
    movies[numMovies].numRatings = 0;
    numMovies++;
}

void rateMovie(struct Movie *movies, int numMovies, int index) {
    printf("Enter rating (1-5): ");
    int rating;
    scanf("%d", &rating);
    movies[index].rating += rating;
    movies[index].numRatings++;
}

void displayMovies(struct Movie *movies, int numMovies) {
    printf("Movie\tRating\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s\t%d\n", movies[i].title, movies[i].rating / movies[i].numRatings);
    }
}

int main() {
    struct Movie movies[MAX_MOVIES];
    int numMovies = 0;

    while (numMovies < MAX_MOVIES) {
        printf("1. Add movie\n2. Rate movie\n3. Display movies\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, numMovies);
                break;
            case 2:
                printf("Enter movie index: ");
                int index;
                scanf("%d", &index);
                rateMovie(movies, numMovies, index);
                break;
            case 3:
                displayMovies(movies, numMovies);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}