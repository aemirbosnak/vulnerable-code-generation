//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MOVIE_SIZE 100

struct Movie {
    char title[MOVIE_SIZE];
    int rating;
};

struct Movie movies[MAX_MOVIES];
int currentMovieIndex = 0;

int main() {
    char title[MOVIE_SIZE];
    int rating;

    while (1) {
        printf("Enter movie title (up to %d characters): ", MOVIE_SIZE);
        scanf("%s", title);

        if (strlen(title) >= MOVIE_SIZE) {
            printf("Title too long.\n");
            continue;
        }

        strcpy(movies[currentMovieIndex].title, title);

        printf("Enter movie rating (1-10): ");
        scanf("%d", &rating);

        if (rating < 1 || rating > 10) {
            printf("Invalid rating. Please enter a number between 1 and 10.\n");
            continue;
        }

        movies[currentMovieIndex].rating = rating;
        currentMovieIndex++;

        // Save the movie data to the executable file
        FILE *fp = fopen((char*)&movies, "ab");
        if (fp == NULL) {
            printf("Error: Could not save movie data to executable file.\n");
            exit(1);
        }

        fwrite(&movies[currentMovieIndex], sizeof(struct Movie), 1, fp);
        fclose(fp);

        printf("Movie saved successfully.\n");

        printf("Do you want to add another movie? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice != 'y') {
            break;
        }
    }

    printf("Exiting...\n");

    // Load movie data from the executable file
    currentMovieIndex = 0;
    while (currentMovieIndex < MAX_MOVIES) {
        FILE *fp = fopen((char*)&movies, "rb");

        if (fp == NULL) {
            printf("Error: Could not load movie data from executable file.\n");
            break;
        }

        fread(&movies[currentMovieIndex], sizeof(struct Movie), 1, fp);
        fclose(fp);

        if (movies[currentMovieIndex].rating == 0) {
            break;
        }

        printf("Title: %s\n", movies[currentMovieIndex].title);
        printf("Rating: %d\n", movies[currentMovieIndex].rating);
        currentMovieIndex++;
    }

    return 0;
}