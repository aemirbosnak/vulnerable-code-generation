//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000

typedef struct {
    char title[MAX_SIZE];
    char director[MAX_SIZE];
    char actors[MAX_SIZE];
    char genre[MAX_SIZE];
    float rating;
} Movie;

int main() {
    int n;
    char filename[MAX_SIZE];
    Movie movies[MAX_SIZE];
    FILE *fp;
    int i;
    char ch;

    printf("Enter the name of the file containing movie ratings: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    n = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            movies[n].title[strcspn(movies[n].title, "\n")] = '\0';
            movies[n].director[strcspn(movies[n].director, "\n")] = '\0';
            movies[n].actors[strcspn(movies[n].actors, "\n")] = '\0';
            movies[n].genre[strcspn(movies[n].genre, "\n")] = '\0';
            movies[n].rating = atof(movies[n].title);
            n++;
        } else {
            strcat(movies[n].title, &ch);
            strcat(movies[n].director, &ch);
            strcat(movies[n].actors, &ch);
            strcat(movies[n].genre, &ch);
        }
    }

    fclose(fp);

    printf("Enter the name of the movie you want to search: ");
    scanf("%s", filename);

    for (i = 0; i < n; i++) {
        if (strcmp(movies[i].title, filename) == 0) {
            printf("Title: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Actors: %s\n", movies[i].actors);
            printf("Genre: %s\n", movies[i].genre);
            printf("Rating: %.2f\n", movies[i].rating);
            break;
        }
    }

    return 0;
}