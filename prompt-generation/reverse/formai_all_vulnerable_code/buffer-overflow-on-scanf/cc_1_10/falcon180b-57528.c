//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 1000
#define MAX_NAME_LEN 100
#define MAX_GENRE_LEN 50
#define MAX_RATING 5

typedef struct {
    char name[MAX_NAME_LEN];
    char genre[MAX_GENRE_LEN];
    int rating;
} Movie;

int main()
{
    int numMovies, i;
    char filename[MAX_NAME_LEN];
    FILE *file;
    Movie movies[MAX_MOVIES];

    printf("Enter the name of the file containing the list of movies: ");
    scanf("%s", filename);

    // Open the file and read the number of movies
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    fscanf(file, "%d", &numMovies);

    // Read the movies from the file
    for (i = 0; i < numMovies; i++) {
        fscanf(file, "%s %s %d", movies[i].name, movies[i].genre, &movies[i].rating);
    }

    // Close the file
    fclose(file);

    // Prompt the user for a search query
    printf("Enter a search query (leave blank to display all movies): ");
    char query[MAX_NAME_LEN];
    scanf("%s", query);

    // Search for movies that match the query
    int numResults = 0;
    for (i = 0; i < numMovies; i++) {
        if (strcmp(query, "") == 0 || strstr(movies[i].name, query)!= NULL || strstr(movies[i].genre, query)!= NULL) {
            printf("%s (%s) - %d stars\n", movies[i].name, movies[i].genre, movies[i].rating);
            numResults++;
        }
    }

    // Display the total number of results
    if (numResults == 0) {
        printf("No results found.\n");
    }

    return 0;
}