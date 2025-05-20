//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 5
#define MAX_TITLE_LEN 100
#define MAX_DESCRIPTION_LEN 1000

typedef struct {
    char title[MAX_TITLE_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int rating;
} Movie;

int main() {
    Movie movies[MAX_RATINGS];
    int num_movies = 0;

    // Prompt user to enter movie information
    printf("Enter movie information (or 0 to stop):\n");
    for (int i = 0; i < MAX_RATINGS; i++) {
        char title[MAX_TITLE_LEN];
        char description[MAX_DESCRIPTION_LEN];
        int rating;

        printf("Movie %d:\n", i + 1);
        printf("Title: ");
        scanf("%s", title);
        printf("Description: ");
        scanf("%s", description);
        printf("Rating: ");
        scanf("%d", &rating);

        // Check if input is valid
        if (strlen(title) > MAX_TITLE_LEN || strlen(description) > MAX_DESCRIPTION_LEN || rating < 0 || rating > 5) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        // Add movie to the list
        strcpy(movies[num_movies].title, title);
        strcpy(movies[num_movies].description, description);
        movies[num_movies].rating = rating;
        num_movies++;
    }

    // Display the movie list
    printf("Movie List:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%d) %s - %s (Rating: %d)\n", i + 1, movies[i].title, movies[i].description, movies[i].rating);
    }

    // Ask user to choose a movie to watch
    printf("Enter the number of the movie you want to watch:\n");
    int movie_num = 0;
    scanf("%d", &movie_num);

    // Check if input is valid
    if (movie_num < 1 || movie_num > num_movies) {
        printf("Invalid input. Try again.\n");
        return 0;
    }

    // Display the movie's information
    printf("Movie Information:\n");
    printf("Title: %s\n", movies[movie_num - 1].title);
    printf("Description: %s\n", movies[movie_num - 1].description);
    printf("Rating: %d\n", movies[movie_num - 1].rating);

    // Ask user if they want to watch the movie
    char choice;
    printf("Do you want to watch the movie? (y/n): ");
    scanf(" %c", &choice);

    // Check if input is valid
    if (choice!= 'y' && choice!= 'n') {
        printf("Invalid input. Try again.\n");
        return 0;
    }

    // Display the movie
    printf("Watching movie...\n");
    printf("Title: %s\n", movies[movie_num - 1].title);
    printf("Description: %s\n", movies[movie_num - 1].description);
    printf("Rating: %d\n", movies[movie_num - 1].rating);

    // Ask user if they want to watch another movie
    printf("Do you want to watch another movie? (y/n): ");
    scanf(" %c", &choice);

    // Check if input is valid
    if (choice!= 'y' && choice!= 'n') {
        printf("Invalid input. Try again.\n");
        return 0;
    }

    return 0;
}