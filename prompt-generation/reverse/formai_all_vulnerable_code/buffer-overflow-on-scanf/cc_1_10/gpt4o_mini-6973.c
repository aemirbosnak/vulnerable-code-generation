//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 100

typedef struct {
    char title[100];
    float rating;
    int total_votes;
} Movie;

Movie movies[MAX_MOVIES];
int movie_count = 0;

void display_menu();
void add_movie();
void rate_movie();
void view_movies();
void display_movies(int index);
void clear_buffer();

int main() {
    printf("Welcome to the Movie Rating System!\n");
    display_menu();
    return 0;
}

void display_menu() {
    int choice;

    printf("\nMenu:\n");
    printf("1. Add a Movie\n");
    printf("2. Rate a Movie\n");
    printf("3. View Movies\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    clear_buffer();

    switch (choice) {
        case 1:
            add_movie();
            break;
        case 2:
            rate_movie();
            break;
        case 3:
            view_movies();
            break;
        case 4:
            printf("Exiting the program. Thank you!\n");
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
    }
    display_menu();
}

void add_movie() {
    if (movie_count >= MAX_MOVIES) {
        printf("Cannot add more movies. Maximum limit reached.\n");
        return;
    }

    printf("Enter the title of the movie: ");
    fgets(movies[movie_count].title, sizeof(movies[movie_count].title), stdin);
    
    // Remove newline character from title
    movies[movie_count].title[strcspn(movies[movie_count].title, "\n")] = '\0';

    movies[movie_count].rating = 0.0;
    movies[movie_count].total_votes = 0;
    movie_count++;

    printf("Movie added successfully!\n");
}

void rate_movie() {
    if (movie_count == 0) {
        printf("No movies available. Please add a movie first.\n");
        return;
    }

    printf("Enter the movie title to rate: ");
    char title[100];
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';

    for (int i = 0; i < movie_count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            float rating;
            printf("Enter your rating (0.0 to 5.0): ");
            scanf("%f", &rating);
            clear_buffer();

            if (rating < 0 || rating > 5) {
                printf("Invalid rating. Please rate between 0.0 to 5.0.\n");
                return;
            }

            movies[i].total_votes++;
            movies[i].rating += (rating - movies[i].rating) / movies[i].total_votes;
            printf("Rating added successfully!\n");
            return;
        }
    }

    printf("Movie not found.\n");
}

void view_movies() {
    if (movie_count == 0) {
        printf("No movies available.\n");
        return;
    }

    printf("\nCurrent Movies and Ratings:\n");
    display_movies(0);
}

void display_movies(int index) {
    if (index >= movie_count) {
        return;
    }

    printf("Title: %s, Rating: %.2f (Votes: %d)\n", 
           movies[index].title, 
           movies[index].rating, 
           movies[index].total_votes);
    
    display_movies(index + 1);
}

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}