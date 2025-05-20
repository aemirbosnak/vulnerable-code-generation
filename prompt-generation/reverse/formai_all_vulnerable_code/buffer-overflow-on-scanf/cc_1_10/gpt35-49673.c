//FormAI DATASET v1.0 Category: Movie Rating System ; Style: complex
#include <stdio.h>

struct movie {
    char title[50];
    char director[50];
    int release_year;
    char genre[20];
    int rating;
};

void display_menu() {
    printf("\n1. Add a new movie\n");
    printf("2. Rate a movie\n");
    printf("3. View movie details\n");
    printf("4. View movie ratings\n");
    printf("5. View all movies\n");
    printf("6. Exit\n");
}

void add_movie(struct movie *movies, int *num_movies) {
    fflush(stdin);
    printf("\nEnter movie title: ");
    fgets(movies[*num_movies].title, 50, stdin);
    printf("Enter movie director: ");
    fgets(movies[*num_movies].director, 50, stdin);
    printf("Enter release year: ");
    scanf("%d", &movies[*num_movies].release_year);
    fflush(stdin);
    printf("Enter genre: ");
    fgets(movies[*num_movies].genre, 20, stdin);
    printf("\nMovie added successfully!\n\n");
    (*num_movies)++;
}

void rate_movie(struct movie *movies, int num_movies) {
    char title[50];
    int rating, i, found = 0;
    printf("\nEnter movie title to rate: ");
    fflush(stdin);
    fgets(title, 50, stdin);
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Enter rating (out of 10): ");
            scanf("%d", &rating);
            movies[i].rating = rating;
            printf("\nMovie rated successfully!\n\n");
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nSorry, movie not found.\n\n");
    }
}

void view_movie_details(struct movie *movies, int num_movies) {
    char title[50];
    int i, found = 0;
    printf("\nEnter movie title to view details: ");
    fflush(stdin);
    fgets(title, 50, stdin);
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("\nTitle: %s", movies[i].title);
            printf("Director: %s", movies[i].director);
            printf("Release year: %d\n", movies[i].release_year);
            printf("Genre: %s", movies[i].genre);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nSorry, movie not found.\n\n");
    }
}

void view_movie_ratings(struct movie *movies, int num_movies) {
    int i, found = 0;
    printf("\n--- Movie Ratings ---\n");
    for (i = 0; i < num_movies; i++) {
        if (movies[i].rating != 0) {
            printf("%s - %d/10\n", movies[i].title, movies[i].rating);
            found = 1;
        }
    }
    if (found == 0) {
        printf("\nNo ratings available.\n\n");
    }
}

void view_all_movies(struct movie *movies, int num_movies) {
    int i;
    printf("\n--- All Movies ---\n");
    for (i = 0; i < num_movies; i++) {
        printf("%s\n", movies[i].title);
    }
    printf("\n");
}

int main() {
    int choice, num_movies = 0;
    struct movie movies[100];
    
    do {
        display_menu();
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_movie(movies, &num_movies);
                break;
            case 2:
                rate_movie(movies, num_movies);
                break;
            case 3:
                view_movie_details(movies, num_movies);
                break;
            case 4:
                view_movie_ratings(movies, num_movies);
                break;
            case 5:
                view_all_movies(movies, num_movies);
                break;
            case 6:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    } while (choice != 6);
    
    return 0;
}