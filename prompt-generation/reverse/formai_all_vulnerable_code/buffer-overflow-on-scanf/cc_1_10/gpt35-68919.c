//FormAI DATASET v1.0 Category: Movie Rating System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct movie {
    char title[100];
    char director[50];
    int year;
    int rating;
} Movie;

void print_movie(Movie m) {
    printf("Title: %s\n", m.title);
    printf("Director: %s\n", m.director);
    printf("Year: %d\n", m.year);
    printf("Rating: %d/10\n", m.rating);
}

void add_movie(Movie movies[], int num_movies) {
    Movie new_movie;

    printf("Enter the movie title: ");
    fgets(new_movie.title, sizeof(new_movie.title), stdin);
    new_movie.title[strcspn(new_movie.title, "\n")] = '\0';

    printf("Enter the director's name: ");
    fgets(new_movie.director, sizeof(new_movie.director), stdin);
    new_movie.director[strcspn(new_movie.director, "\n")] = '\0';

    printf("Enter the year of release: ");
    scanf("%d", &new_movie.year);

    printf("Enter the rating out of 10: ");
    scanf("%d", &new_movie.rating);

    movies[num_movies] = new_movie;

    printf("Movie added!\n\n");
}

void print_all_movies(Movie movies[], int num_movies) {
    printf("All Movies: \n\n");

    for (int i = 0; i < num_movies; i++) {
        print_movie(movies[i]);
        printf("\n");
    }
}

void search_movie_by_title(Movie movies[], int num_movies) {
    char search_title[100];

    printf("Enter the title of the movie you want to search for: ");
    fgets(search_title, sizeof(search_title), stdin);
    search_title[strcspn(search_title, "\n")] = '\0';

    int found = 0;

    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, search_title) == 0) {
            print_movie(movies[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Movie not found.\n\n");
    }
}

void rate_movie(Movie movies[], int num_movies) {
    char title[100];

    printf("Enter the title of the movie you want to rate: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';

    int rated = 0;

    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            int rating;

            printf("Enter the new rating out of 10: ");
            scanf("%d", &rating);

            movies[i].rating = rating;

            printf("Rating updated.\n\n");
            rated = 1;
            break;
        }
    }

    if (!rated) {
        printf("Movie not found.\n\n");
    }
}

void print_menu() {
    printf("1. View all movies\n");
    printf("2. Add a movie\n");
    printf("3. Search for a movie by title\n");
    printf("4. Rate a movie\n");
    printf("5. Quit\n\n");
    printf("Enter your choice (1-5): ");
}

int main() {
    Movie movies[100];
    int num_movies = 0;
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                print_all_movies(movies, num_movies);
                break;
            case 2:
                add_movie(movies, num_movies);
                num_movies++;
                break;
            case 3:
                search_movie_by_title(movies, num_movies);
                break;
            case 4:
                rate_movie(movies, num_movies);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}