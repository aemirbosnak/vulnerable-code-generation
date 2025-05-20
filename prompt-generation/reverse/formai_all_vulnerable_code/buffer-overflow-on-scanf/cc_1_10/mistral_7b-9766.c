//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 50
#define MAX_RATING_LENGTH 3

struct Movie {
    char name[MAX_NAME_LENGTH];
    char rating[MAX_RATING_LENGTH];
    int points;
};

void clean_string(char *str) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i]) && str[i] != ' ') {
            for (j = i; str[j] != '\0'; j++) {
                str[j] = str[j + 1];
            }
            i--;
        }
    }
    str[MAX_NAME_LENGTH - 1] = '\0';
}

int get_rating(char *rating) {
    int points = 0;
    for (int i = 0; rating[i] != '\0'; i++) {
        if (isdigit(rating[i])) {
            points = points * 10 + (rating[i] - '0');
        }
    }
    return points;
}

void add_movie(struct Movie movies[] , char *movie_name, char *movie_rating) {
    for (int i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].points == 0) {
            strcpy(movies[i].name, movie_name);
            strcpy(movies[i].rating, movie_rating);
            movies[i].points = get_rating(movie_rating);
            break;
        }
    }
}

void print_movies(struct Movie movies[]) {
    printf("\n======== The Honorable Cinema Hall ========\n");
    printf("| Title                         | Rating |\n");
    printf("|---------------------------------|-------|\n");
    for (int i = 0; i < MAX_MOVIES; i++) {
        if (movies[i].points != 0) {
            printf("| %-50s   | %-3s | %2d points |\n", movies[i].name, movies[i].rating, movies[i].points);
        }
    }
}

int main() {
    struct Movie movies[MAX_MOVIES];
    char movie_name[MAX_NAME_LENGTH], movie_rating[MAX_RATING_LENGTH];

    while (1) {
        printf("\n======== Welcome to the Cinema Hall ========\n");
        printf("Enter a movie name: ");
        scanf("%s", movie_name);
        clean_string(movie_name);

        printf("Enter a movie rating: ");
        scanf("%s", movie_rating);
        clean_string(movie_rating);

        add_movie(movies, movie_name, movie_rating);

        printf("Another movie? y/n\n");
        char answer;
        scanf("%c", &answer);
        if (answer != 'y') {
            break;
        }
    }

    print_movies(movies);

    return 0;
}