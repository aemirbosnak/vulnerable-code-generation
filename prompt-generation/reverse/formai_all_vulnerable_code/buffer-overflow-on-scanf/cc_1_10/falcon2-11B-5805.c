//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rating;
    char* title;
    char* director;
} Movie;

int main() {
    Movie movie1 = {5, "The Godfather", "Francis Ford Coppola"};
    Movie movie2 = {4, "Pulp Fiction", "Quentin Tarantino"};
    Movie movie3 = {3, "Jaws", "Steven Spielberg"};
    Movie movie4 = {2, "Batman & Robin", "Joel Schumacher"};
    Movie movie5 = {1, "Transformers: Revenge of the Fallen", "Michael Bay"};

    Movie movies[5];
    movies[0] = movie1;
    movies[1] = movie2;
    movies[2] = movie3;
    movies[3] = movie4;
    movies[4] = movie5;

    int numMovies = 5;

    int choice = 0;

    while (choice!= 3) {
        printf("1. Display all movies\n2. Add a movie\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Movie Rating System\n\n");
                for (int i = 0; i < numMovies; i++) {
                    printf("%d. %s (%s)\n", i + 1, movies[i].title, movies[i].director);
                }
                break;
            case 2:
                printf("Enter rating: ");
                scanf("%d", &movies[numMovies].rating);
                printf("Enter title: ");
                scanf("%s", movies[numMovies].title);
                printf("Enter director: ");
                scanf("%s", movies[numMovies].director);
                numMovies++;
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}