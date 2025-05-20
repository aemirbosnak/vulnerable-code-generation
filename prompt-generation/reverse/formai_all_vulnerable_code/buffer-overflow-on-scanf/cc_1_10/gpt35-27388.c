//FormAI DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct to store movie information */
struct movie {
    int id;
    char title[100];
    char director[50];
    int year;
    float rating;
};

/* Declare function prototypes */
void add_movie(struct movie *movies, int num_movies);
void view_movies(struct movie *movies, int num_movies);
void search_movies(struct movie *movies, int num_movies);
void delete_movie(struct movie *movies, int num_movies);

int main() {

    int choice, num_movies = 0;

    /* Declare a dynamic array of structs */
    struct movie *movies = malloc(sizeof(struct movie));

    if (movies == NULL) {
        printf("Error: Memory allocation failed.");
        exit(1);
    }

    /* Display menu and get user choice */
    do {
        printf("\nMovie Rating System\n");
        printf("1. Add movie\n");
        printf("2. View movies\n");
        printf("3. Search movies\n");
        printf("4. Delete movie\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_movie(movies, num_movies);
                num_movies++;
                /* Reallocate memory to fit new movie */
                movies = realloc(movies, (num_movies+1)*sizeof(struct movie));
                break;
            case 2:
                view_movies(movies, num_movies);
                break;
            case 3:
                search_movies(movies, num_movies);
                break;
            case 4:
                delete_movie(movies, num_movies);
                num_movies--;
                /* Reallocate memory to fit remaining movies */
                movies = realloc(movies, num_movies*sizeof(struct movie));
                break;
            case 5:
                /* Free dynamically allocated memory */
                free(movies);
                printf("\nExiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while(choice != 5);

    return 0;
}

/* Function to add a new movie to the database */
void add_movie(struct movie *movies, int num_movies) {
    printf("\nEnter movie details:");
    printf("\nTitle: ");
    scanf(" %[^\n]%*c", movies[num_movies].title);
    printf("Director: ");
    scanf(" %[^\n]%*c", movies[num_movies].director);
    printf("Year: ");
    scanf("%d", &movies[num_movies].year);
    printf("Rating: ");
    scanf("%f", &movies[num_movies].rating);
    /* Assign an ID to the new movie */
    movies[num_movies].id = num_movies+1;
    printf("\nMovie added successfully!\n");
}

/* Function to view all movies in the database */
void view_movies(struct movie *movies, int num_movies) {
    if (num_movies == 0) {
        printf("\nNo movies found.\n");
        return;
    }
    printf("\nID\tTitle\t\tDirector\tYear\tRating\n");
    for (int i=0; i<num_movies; i++) {
        printf("%d\t%s\t%s\t\t%d\t%.2f\n", movies[i].id, movies[i].title,
            movies[i].director, movies[i].year, movies[i].rating);
    }
}

/* Function to search for a movie in the database */
void search_movies(struct movie *movies, int num_movies) {
    if (num_movies == 0) {
        printf("\nNo movies found.\n");
        return;
    }
    char keyword[50];
    int found = 0;
    printf("\nEnter search keyword: ");
    scanf(" %[^\n]%*c", keyword);
    printf("\nID\tTitle\t\tDirector\tYear\tRating\n");
    for (int i=0; i<num_movies; i++) {
        if (strstr(movies[i].title, keyword) != NULL ||
            strstr(movies[i].director, keyword) != NULL) {
            printf("%d\t%s\t%s\t\t%d\t%.2f\n", movies[i].id, movies[i].title,
                movies[i].director, movies[i].year, movies[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("\nNo matching movies found.\n");
    }
}

/* Function to delete a movie from the database */
void delete_movie(struct movie *movies, int num_movies) {
    if (num_movies == 0) {
        printf("\nNo movies found.\n");
        return;
    }
    int id, found = 0;
    printf("\nEnter ID of movie to delete: ");
    scanf("%d", &id);
    for (int i=0; i<num_movies; i++) {
        if (movies[i].id == id) {
            /* Shift remaining movies in array to fill gap */
            for (int j=i; j<num_movies-1; j++) {
                strcpy(movies[j].title, movies[j+1].title);
                strcpy(movies[j].director, movies[j+1].director);
                movies[j].year = movies[j+1].year;
                movies[j].rating = movies[j+1].rating;
                movies[j].id = movies[j+1].id;
            }
            found = 1;
            printf("\nMovie deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("\nMovie not found.\n");
    }
}