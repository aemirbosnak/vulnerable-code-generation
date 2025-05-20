//FormAI DATASET v1.0 Category: Movie Rating System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int rating;
} Movie;

Movie movies[MAX_MOVIES];
int num_movies = 0;

void add_movie()
{
    char name[MAX_NAME_LENGTH];
    int rating;
    printf("Enter the name of the movie: ");
    scanf("%s", name);
    printf("Enter the rating of the movie (1-10): ");
    scanf("%d", &rating);
    if (num_movies < MAX_MOVIES) {
        strcpy(movies[num_movies].name, name);
        movies[num_movies].rating = rating;
        num_movies++;
        printf("Movie added successfully!\n");
    }
    else {
        printf("Maximum number of movies reached.\n");
    }
}

void print_movies()
{
    if (num_movies == 0) {
        printf("No movies to display.\n");
        return;
    }
    printf("Here are the current movies in the system:\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < num_movies; i++) {
        printf("Movie %d\n", i + 1);
        printf("Name: %s\n", movies[i].name);
        printf("Rating: %d\n\n", movies[i].rating);
    }
}

void search_movie()
{
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the movie to search for: ");
    scanf("%s", name);
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            printf("Movie found!\n");
            printf("Name: %s\n", movies[i].name);
            printf("Rating: %d\n", movies[i].rating);
            return;
        }
    }
    printf("Movie not found.\n");
}

void remove_movie()
{
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the movie to remove: ");
    scanf("%s", name);
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].name, name) == 0) {
            for (int j = i; j < num_movies - 1; j++) {
                strcpy(movies[j].name, movies[j + 1].name);
                movies[j].rating = movies[j + 1].rating;
            }
            num_movies--;
            printf("Movie removed successfully!\n");
            return;
        }
    }
    printf("Movie not found.\n");
}

int main()
{
    int choice;
    do {
        printf("\n--------C Movie Rating System--------\n");
        printf("1. Add a movie\n");
        printf("2. Print current movies\n");
        printf("3. Search for a movie\n");
        printf("4. Remove a movie\n");
        printf("5. Quit\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                print_movies();
                break;
            case 3:
                search_movie();
                break;
            case 4:
                remove_movie();
                break;
            case 5:
                printf("Thank you for using C Movie Rating System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}