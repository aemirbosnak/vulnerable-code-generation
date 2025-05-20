//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    int rating;
} Movie;

int main() {
    Movie movies[100];
    int numMovies = 0;
    FILE *fp;

    if ((fp = fopen("movies.txt", "r")) == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %d", movies[numMovies].title, &movies[numMovies].rating) == 2) {
        numMovies++;
    }

    fclose(fp);

    int numSeen;
    int numSearched;
    char searchTitle[50];
    int searchResult;

    printf("Enter the number of movies you've seen: ");
    scanf("%d", &numSeen);

    printf("Enter a movie title to search for: ");
    scanf("%s", searchTitle);

    searchResult = 0;

    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].title, searchTitle) == 0) {
            searchResult = i;
            break;
        }
    }

    if (searchResult == 0) {
        printf("Movie not found.\n");
    } else {
        printf("Movie found!\n");
        printf("Title: %s\n", movies[searchResult].title);
        printf("Rating: %d\n", movies[searchResult].rating);
    }

    return 0;
}