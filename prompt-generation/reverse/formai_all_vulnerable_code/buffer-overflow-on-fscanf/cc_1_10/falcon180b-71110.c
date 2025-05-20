//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILMS 100
#define MAX_TITLE_LENGTH 80
#define MAX_DIRECTOR_LENGTH 40
#define MAX_ACTORS_LENGTH 200
#define MAX_GENRES_LENGTH 20
#define MAX_RATING 5
#define MAX_SYNOPSIS_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char genres[MAX_GENRES_LENGTH];
    int rating;
    char synopsis[MAX_SYNOPSIS_LENGTH];
} Film;

void read_films(Film films[], int num_films) {
    FILE *fp = fopen("films.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open films file.\n");
        exit(1);
    }

    int i = 0;
    while (i < num_films && fscanf(fp, "%s %s %s %s %d %s\n", films[i].title, films[i].director, films[i].actors, films[i].genres, &films[i].rating, films[i].synopsis)!= EOF) {
        i++;
    }

    fclose(fp);
}

void print_films(Film films[], int num_films) {
    for (int i = 0; i < num_films; i++) {
        printf("%s\n", films[i].title);
        printf("Director: %s\n", films[i].director);
        printf("Actors: %s\n", films[i].actors);
        printf("Genres: %s\n", films[i].genres);
        printf("Rating: %d\n", films[i].rating);
        printf("Synopsis: %s\n\n", films[i].synopsis);
    }
}

int main() {
    Film films[MAX_FILMS];
    int num_films = 0;

    read_films(films, MAX_FILMS);
    num_films = MAX_FILMS;

    char choice;
    while (1) {
        printf("\nMovie Rating System\n");
        printf("1. List all films\n");
        printf("2. Search for a film\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            print_films(films, num_films);
            break;
        case '2':
            printf("Enter the title of the film: ");
            char title[MAX_TITLE_LENGTH];
            scanf("%s", title);

            int index = -1;
            for (int i = 0; i < num_films; i++) {
                if (strcmp(films[i].title, title) == 0) {
                    index = i;
                    break;
                }
            }

            if (index!= -1) {
                printf("Film found:\n");
                print_films(&films[index], 1);
            } else {
                printf("Film not found.\n");
            }
            break;
        case '3':
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}