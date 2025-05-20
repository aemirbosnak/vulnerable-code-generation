//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include<stdio.h>
#include<string.h>

struct movie {
    char title[50];
    char genre[20];
    int rating;
};

int main() {
    struct movie films[3];
    int i, flag = 0;
    char search[20];

    // Input movie data
    for(i=0; i<3; i++) {
        printf("Enter title of movie %d: ", i+1);
        scanf("%s", &films[i].title);
        printf("Enter genre of movie %d: ", i+1);
        scanf("%s", &films[i].genre);
        printf("Enter rating of movie %d (1-10): ", i+1);
        scanf("%d", &films[i].rating);
    }

    // Print movie data
    printf("\nMovie List:\n");
    printf("Title\tGenre\tRating\n");
    for(i=0; i<3; i++) {
        printf("%s\t%s\t%d\n", films[i].title, films[i].genre, films[i].rating);
    }

    // Search for movie by genre
    printf("\nEnter a genre to search for: ");
    scanf("%s", &search);
    printf("\nSearch results:\n");
    printf("Title\tGenre\tRating\n");
    for(i=0; i<3; i++) {
        if (strcmp(search, films[i].genre) == 0) {
            printf("%s\t%s\t%d\n", films[i].title, films[i].genre, films[i].rating);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("No movies found in that genre.\n");
    }

    // Calculate average rating of movies
    float avg = 0;
    for(i=0; i<3; i++) {
        avg += films[i].rating;
    }
    avg /= 3;
    printf("\nAverage rating of movies: %.2f\n", avg);

    // Rate a movie
    printf("\nEnter a movie title to rate: ");
    scanf("%s", &search);
    for(i=0; i<3; i++) {
        if (strcmp(search, films[i].title) == 0) {
            printf("Enter a new rating for %s (1-10): ", search);
            scanf("%d", &films[i].rating);
            printf("New rating for %s is %d.\n", search, films[i].rating);
            break;
        }
    }

    return 0;
}