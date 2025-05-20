//FormAI DATASET v1.0 Category: Movie Rating System ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Struct to hold details of a movie
struct Movie {
    char title[100];
    char genre[50];
    int year;
    int view_count;
    float rating;
};

// Function to add a new movie to the database
void add_movie(struct Movie *movies, int *count) {
    printf("Enter the title of the movie: ");
    scanf("%[^\n]%*c", movies[*count].title);

    printf("Enter the genre of the movie: ");
    scanf("%[^\n]%*c", movies[*count].genre);

    printf("Enter the year of release of the movie: ");
    scanf("%d", &movies[*count].year);

    printf("Enter the initial view count of the movie: ");
    scanf("%d", &movies[*count].view_count);

    printf("Enter the rating of the movie: ");
    scanf("%f", &movies[*count].rating);

    *count += 1;

    printf("\nNew movie added to the database.\n\n");
}

// Function to view the details of a movie
void view_movie(struct Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Genre: %s\n", movie.genre);
    printf("Year of release: %d\n", movie.year);
    printf("View count: %d\n", movie.view_count);
    printf("Rating: %.2f\n\n", movie.rating);
}

// Function to search for a movie in the database
void search_movie(struct Movie *movies, int count) {
    char title[100];
    printf("Enter the title of the movie you want to search for: ");
    scanf("%[^\n]%*c", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            view_movie(movies[i]);
            return;
        }
    }

    printf("Movie not found in the database.\n\n");
}

// Function to rate a movie in the database
void rate_movie(struct Movie *movies, int count) {
    char title[100];
    printf("Enter the title of the movie you want to rate: ");
    scanf("%[^\n]%*c", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Current rating: %.2f\n", movies[i].rating);

            float new_rating;
            printf("Enter your new rating for the movie: ");
            scanf("%f", &new_rating);

            // Update the rating based on the number of views
            float current_rating = movies[i].rating;
            int view_count = movies[i].view_count;

            // Apply weightage to the new rating based on the number of views
            float weightage = (float) view_count / 1000;
            float weighted_rating = ((current_rating * view_count) + (new_rating * weightage)) / (view_count + weightage);

            movies[i].rating = weighted_rating;
            movies[i].view_count += 1;

            printf("Movie rating updated in the database.\n\n");
            return;
        }
    }

    printf("Movie not found in the database.\n\n");
}

int main() {
    // Create an array of movies with a maximum capacity of 1000
    struct Movie movies[1000];
    int count = 0;

    while (1) {
        printf("Welcome to the Movie Rating System\n\n");
        printf("1. Add a new movie to the database\n");
        printf("2. Search for a movie in the database\n");
        printf("3. Rate a movie in the database\n");
        printf("4. Exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie(movies, &count);
                break;
            case 2:
                search_movie(movies, count);
                break;
            case 3:
                rate_movie(movies, count);
                break;
            case 4:
                printf("Exiting the Movie Rating System...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}