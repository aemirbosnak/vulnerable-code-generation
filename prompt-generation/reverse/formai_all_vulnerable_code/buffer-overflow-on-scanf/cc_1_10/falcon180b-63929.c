//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RATINGS 10
#define MAX_NAME_LEN 50
#define MAX_TITLE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int num_ratings;
    int ratings[MAX_RATINGS];
    char movie_title[MAX_TITLE_LEN];
} Movie;

void initialize_movie(Movie* movie) {
    strcpy(movie->name, "");
    movie->num_ratings = 0;
    for (int i = 0; i < MAX_RATINGS; i++) {
        movie->ratings[i] = 0;
    }
    strcpy(movie->movie_title, "");
}

void print_movie(Movie* movie) {
    printf("Name: %s\n", movie->name);
    printf("Number of ratings: %d\n", movie->num_ratings);
    printf("Ratings: ");
    for (int i = 0; i < MAX_RATINGS; i++) {
        if (movie->ratings[i] > 0) {
            printf("%d ", movie->ratings[i]);
        }
    }
    printf("\nMovie title: %s\n", movie->movie_title);
}

int get_rating(char* rating_str) {
    int rating = 0;
    if (strcmp(rating_str, "1") == 0) {
        rating = 1;
    } else if (strcmp(rating_str, "2") == 0) {
        rating = 2;
    } else if (strcmp(rating_str, "3") == 0) {
        rating = 3;
    } else if (strcmp(rating_str, "4") == 0) {
        rating = 4;
    } else if (strcmp(rating_str, "5") == 0) {
        rating = 5;
    }
    return rating;
}

void add_rating(Movie* movie) {
    char rating_str[10];
    printf("Enter rating (1-5): ");
    scanf("%s", rating_str);
    int rating = get_rating(rating_str);
    if (movie->num_ratings < MAX_RATINGS) {
        movie->ratings[movie->num_ratings] = rating;
        movie->num_ratings++;
    } else {
        printf("Maximum number of ratings reached.\n");
    }
}

void add_movie(Movie* movie) {
    printf("Enter movie title: ");
    scanf("%s", movie->movie_title);
}

int main() {
    Movie movie;
    initialize_movie(&movie);
    char choice;
    while (1) {
        printf("1. Add rating\n2. Add movie\n3. Print movie\n4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                add_rating(&movie);
                break;
            case '2':
                add_movie(&movie);
                break;
            case '3':
                print_movie(&movie);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}