//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 100

struct movie {
    char title[50];
    char genre[20];
    float rating;
};

int main() {
    struct movie movies[MAX_RATINGS];
    int num_ratings = 0;
    char user_input[50];

    printf("Welcome to the C Movie Rating System!\n");
    printf("Enter 'EXIT' at any time to quit.\n");

    while (num_ratings < MAX_RATINGS) {
        printf("Enter the title of the movie: ");
        fgets(user_input, 50, stdin);
        user_input[strcspn(user_input, "\n")] = 0;

        if (strcmp(user_input, "EXIT") == 0) {
            break;
        }

        strcpy(movies[num_ratings].title, user_input);

        printf("Enter the genre of the movie: ");
        fgets(user_input, 50, stdin);
        user_input[strcspn(user_input, "\n")] = 0;
        strcpy(movies[num_ratings].genre, user_input);

        printf("Enter the rating of the movie (0.0 to 10.0): ");
        fgets(user_input, 50, stdin);
        user_input[strcspn(user_input, "\n")] = 0;
        movies[num_ratings].rating = atof(user_input);

        num_ratings++;
    }

    printf("Here are the ratings for the movies:\n");

    float total_rating = 0;
    int num_comedies = 0;
    int num_action = 0;

    for (int i = 0; i < num_ratings; i++) {
        printf("%s: %s - %.1f\n", movies[i].title, movies[i].genre, movies[i].rating);

        total_rating += movies[i].rating;

        if (strcmp(movies[i].genre, "Comedy") == 0) {
            num_comedies++;
        } else if (strcmp(movies[i].genre, "Action") == 0) {
            num_action++;
        }
    }

    float avg_rating = total_rating / num_ratings;
    printf("The average rating for all movies is %.1f.\n", avg_rating);

    if (num_comedies > num_action) {
        printf("There are more comedies than action movies.\n");
    } else {
        printf("There are more action movies than comedies.\n");
    }

    return 0;
}