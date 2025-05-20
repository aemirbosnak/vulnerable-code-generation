//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

struct movie {
    char title[MAX_WORD_LEN];
    int year;
    char rating[MAX_WORD_LEN];
};

struct movie movies[MAX_WORDS];
int num_movies = 0;

void add_movie() {
    printf("Enter movie title: ");
    scanf("%s", movies[num_movies].title);

    printf("Enter movie year: ");
    scanf("%d", &movies[num_movies].year);

    printf("Enter movie rating: ");
    scanf("%s", movies[num_movies].rating);

    num_movies++;
}

void display_movies() {
    printf("Movie List:\n");
    printf("------------------------\n");
    printf("Title\tYear\tRating\n");
    printf("------------------------\n");

    for (int i = 0; i < num_movies; i++) {
        printf("%s\t%d\t%s\n", movies[i].title, movies[i].year, movies[i].rating);
    }
}

int main() {
    printf("Welcome to the C Movie Rating System!\n");

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add movie\n2. Display movies\n3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_movie();
            break;

        case 2:
            display_movies();
            break;

        case 3:
            printf("Thanks for using the C Movie Rating System! Goodbye!\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}