//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie {
    char title[50];
    int rating;
    struct movie *next;
};

struct movie *start;

void addMovie(struct movie *movie) {
    if (start == NULL) {
        start = movie;
    } else {
        struct movie *current = start;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = movie;
    }
}

void printRatings(struct movie *movie) {
    while (movie!= NULL) {
        printf("%s - %d stars\n", movie->title, movie->rating);
        movie = movie->next;
    }
}

int main() {
    struct movie *movie;
    char title[50];
    int rating;
    
    printf("Enter the title of the movie:\n");
    scanf("%s", title);
    printf("Enter the rating of the movie (1-5):\n");
    scanf("%d", &rating);
    
    movie = malloc(sizeof(struct movie));
    strcpy(movie->title, title);
    movie->rating = rating;
    movie->next = NULL;
    
    addMovie(movie);
    
    printf("Your rating history:\n");
    printRatings(start);
    
    free(movie);
    return 0;
}