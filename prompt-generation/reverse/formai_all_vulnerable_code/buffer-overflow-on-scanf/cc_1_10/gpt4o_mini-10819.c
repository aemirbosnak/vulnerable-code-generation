//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int ratings[10];
    int rating_count;
} Movie;

Movie movie_list[MAX_MOVIES];
int movie_count = 0;

void add_movie() {
    if (movie_count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }

    printf("Enter the name of the movie: ");
    fgets(movie_list[movie_count].name, NAME_LENGTH, stdin);
    movie_list[movie_count].name[strcspn(movie_list[movie_count].name, "\n")] = 0; // Remove newline
    movie_list[movie_count].rating_count = 0;
    movie_count++;

    printf("Movie '%s' added successfully!\n", movie_list[movie_count - 1].name);
}

void rate_movie() {
    char name[NAME_LENGTH];
    printf("Enter the name of the movie to rate: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (int i = 0; i < movie_count; i++) {
        if (strcmp(movie_list[i].name, name) == 0) {
            if (movie_list[i].rating_count >= 10) {
                printf("Maximum number of ratings reached for '%s'!\n", movie_list[i].name);
                return;
            }
            int rating;
            printf("Enter rating (1-10): ");
            scanf("%d", &rating);
            getchar(); // Consume leftover newline

            if (rating < 1 || rating > 10) {
                printf("Invalid rating! Please enter a value between 1 and 10.\n");
                return;
            }

            movie_list[i].ratings[movie_list[i].rating_count] = rating;
            movie_list[i].rating_count++;

            printf("Rating of %d added for '%s'!\n", rating, movie_list[i].name);
            return;
        }
    }

    printf("Movie '%s' not found!\n", name);
}

void show_average_rating() {
    char name[NAME_LENGTH];
    printf("Enter the name of the movie to see average rating: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline
    
    for (int i = 0; i < movie_count; i++) {
        if (strcmp(movie_list[i].name, name) == 0) {
            if (movie_list[i].rating_count == 0) {
                printf("No ratings available for '%s'.\n", movie_list[i].name);
                return;
            }

            int total = 0;
            for (int j = 0; j < movie_list[i].rating_count; j++) {
                total += movie_list[i].ratings[j];
            }

            float average = (float) total / movie_list[i].rating_count;
            printf("The average rating for '%s' is %.2f.\n", movie_list[i].name, average);
            return;
        }
    }

    printf("Movie '%s' not found!\n", name);
}

void display_menu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add Movie\n");
    printf("2. Rate Movie\n");
    printf("3. Show Average Rating\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume leftover newline

        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                rate_movie();
                break;
            case 3:
                show_average_rating();
                break;
            case 4:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}