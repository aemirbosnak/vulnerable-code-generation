//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float ratings[10];
    int rating_count;
} Movie;

Movie movies[MAX_MOVIES];
int movie_count = 0;

void add_movie() {
    if (movie_count >= MAX_MOVIES) {
        printf("Cannot add more movies. Maximum limit reached.\n");
        return;
    }
    
    printf("Enter movie title: ");
    scanf(" %[^\n]", movies[movie_count].title);
    movies[movie_count].rating_count = 0;
    movie_count++;
    printf("Movie added successfully!\n");
}

void rate_movie() {
    char title[MAX_TITLE_LENGTH];
    float rating;

    printf("Enter the title of the movie you want to rate: ");
    scanf(" %[^\n]", title);
    
    for (int i = 0; i < movie_count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            if (movies[i].rating_count >= 10) {
                printf("Rating limit reached for this movie.\n");
                return;
            }
            printf("Enter your rating (0 to 10): ");
            scanf("%f", &rating);
            if (rating < 0 || rating > 10) {
                printf("Invalid rating. Please enter a rating between 0 and 10.\n");
                return;
            }
            movies[i].ratings[movies[i].rating_count] = rating;
            movies[i].rating_count++;
            printf("Thank you for rating!\n");
            return;
        }
    }
    printf("Movie not found!\n");
}

void view_average_ratings() {
    printf("Average Ratings:\n");
    for (int i = 0; i < movie_count; i++) {
        float total = 0.0;
        for (int j = 0; j < movies[i].rating_count; j++) {
            total += movies[i].ratings[j];
        }
        float average = movies[i].rating_count > 0 ? total / movies[i].rating_count : 0;
        printf("Movie: %s, Average Rating: %.2f\n", movies[i].title, average);
    }
}

void print_menu() {
    printf("Movie Rating System\n");
    printf("====================\n");
    printf("1. Add Movie\n");
    printf("2. Rate Movie\n");
    printf("3. View Average Ratings\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option;

    do {
        print_menu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                add_movie();
                break;
            case 2:
                rate_movie();
                break;
            case 3:
                view_average_ratings();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);

    return 0;
}