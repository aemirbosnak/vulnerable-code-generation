//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    float ratings[100];
    int rating_count;
    float average_rating;
} Movie;

Movie movies[MAX_MOVIES];
int movie_count = 0;

void add_movie(char *title) {
    strcpy(movies[movie_count].title, title);
    movies[movie_count].rating_count = 0;
    movies[movie_count].average_rating = 0.0;
    movie_count++;
}

void rate_movie(int index, float rating) {
    if (index < 0 || index >= movie_count) {
        printf("Invalid movie index.\n");
        return;
    }
    if (movies[index].rating_count < 100) {
        movies[index].ratings[movies[index].rating_count] = rating;
        movies[index].rating_count++;
        float sum = 0.0;
        for (int i = 0; i < movies[index].rating_count; i++) {
            sum += movies[index].ratings[i];
        }
        movies[index].average_rating = sum / movies[index].rating_count;
    } else {
        printf("Maximum ratings reached for movie: %s\n", movies[index].title);
    }
}

void display_movies() {
    printf("\nList of Movies:\n");
    for (int i = 0; i < movie_count; i++) {
        printf("%d: %s - Average Rating: %.2f\n", i + 1, movies[i].title, movies[i].average_rating);
    }
}

void record_movie_rating() {
    int index;
    float rating;

    display_movies();
    printf("\nEnter the movie index to rate: ");
    scanf("%d", &index);
    index--;  // Adjust for zero-based index
    if (index < 0 || index >= movie_count) {
        printf("Error: Invalid Index.\n");
        return;
    }
    printf("Rate the movie '%s' (0-5): ", movies[index].title);
    scanf("%f", &rating);
    if (rating < 0 || rating > 5) {
        printf("Error: Rating must be between 0 and 5.\n");
        return;
    }
    rate_movie(index, rating);
    printf("Thank you for rating!\n");
}

void print_intro() {
    printf("====================================\n");
    printf("  Welcome to the Movie Rating System\n");
    printf("====================================\n\n");
    printf("Here, dear user, you shall delve into the world of cinematic experiences,\n");
    printf("where you may impart your thoughts in the form of ratings, allowing us to\n");
    printf("calculate the average sentiments towards each motion picture!\n\n");
}

int main() {
    char title[MAX_TITLE_LEN];
    int choice;

    print_intro();

    while (1) {
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. Display Movies\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                getchar(); // Clear buffer
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                add_movie(title);
                printf("Movie '%s' added successfully!\n", title);
                break;
            case 2:
                record_movie_rating();
                break;
            case 3:
                display_movies();
                break;
            case 4:
                printf("Exiting the Movie Rating System. Farewell!\n");
                exit(0);
            default:
                printf("Invalid selection. Please choose again.\n");
                break;
        }
    }
    return 0;
}