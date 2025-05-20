//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 50
#define MAX_NAME_LEN 50
#define MAX_RATING_LEN 3

struct Movie {
    char name[MAX_NAME_LEN];
    int rating;
};

void readMovies(struct Movie movies[], FILE *file);
void writeMovies(struct Movie movies[], FILE *file);
void printMenu();
void printMovie(struct Movie movie);

int main() {
    FILE *file;
    struct Movie movies[MAX_MOVIES];
    int choice, i;

    file = fopen("movies.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    readMovies(movies, file);
    fclose(file);

    printMenu();

    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                for (i = 0; i < 50; i++) {
                    printMovie(movies[i]);
                    printf("Enter rating (1-10): ");
                    scanf("%d", &movies[i].rating);
                }
                writeMovies(movies, fopen("movies.txt", "w"));
                break;
            case 2:
                printMenu();
                for (i = 0; i < 50; i++) {
                    printMovie(movies[i]);
                    printf("Average rating: %.1f\n", (float)movies[i].rating / 10.0);
                }
                break;
            case 3:
                exit(0);
        }
    }

    return 0;
}

void readMovies(struct Movie movies[], FILE *file) {
    int i = 0;
    char line[MAX_NAME_LEN + MAX_RATING_LEN + 2];

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%s %d", movies[i].name, &movies[i].rating);
        i++;
    }
}

void writeMovies(struct Movie movies[], FILE *file) {
    int i;

    for (i = 0; i < 50; i++) {
        fprintf(file, "%s %d\n", movies[i].name, movies[i].rating);
    }
}

void printMenu() {
    printf("\nMovie Rating System Menu\n");
    printf("--------------------------\n");
    printf("1. Rate a movie\n");
    printf("2. View average ratings\n");
    printf("3. Exit\n");
}

void printMovie(struct Movie movie) {
    printf("\n%s\n", movie.name);
}