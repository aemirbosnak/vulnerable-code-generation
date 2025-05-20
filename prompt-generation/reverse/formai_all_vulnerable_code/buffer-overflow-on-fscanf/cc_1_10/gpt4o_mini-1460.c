//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    float rating;
    int year;
} Movie;

void add_movie(Movie movies[], int *count);
void display_movies(Movie movies[], int count);
void save_movies(Movie movies[], int count);
void load_movies(Movie movies[], int *count);
void sort_movies(Movie movies[], int count);
int compare(const void *a, const void *b);

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    load_movies(movies, &count);

    do {
        printf("\n*** Movie Rating System ***\n");
        printf("1. Add a Movie\n");
        printf("2. Display Movie List\n");
        printf("3. Save Movies to File\n");
        printf("4. Load Movies from File\n");
        printf("5. Sort Movies by Rating\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                add_movie(movies, &count);
                break;
            case 2:
                display_movies(movies, count);
                break;
            case 3:
                save_movies(movies, count);
                break;
            case 4:
                load_movies(movies, &count);
                break;
            case 5:
                sort_movies(movies, count);
                printf("Movies sorted by rating.\n");
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void add_movie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Cannot add more movies. Maximum limit reached!\n");
        return;
    }

    printf("Enter movie title: ");
    fgets(movies[*count].title, TITLE_LENGTH, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove trailing newline

    printf("Enter movie rating (0.0 - 10.0): ");
    scanf("%f", &movies[*count].rating);
    
    printf("Enter release year: ");
    scanf("%d", &movies[*count].year);
    getchar(); // consume newline

    (*count)++;
    printf("Movie added successfully!\n");
}

void display_movies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\nMovie List:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Rating: %.1f, Year: %d\n", movies[i].title, movies[i].rating, movies[i].year);
    }
}

void save_movies(Movie movies[], int count) {
    FILE *file = fopen("movies.txt", "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%.1f\n%d\n", movies[i].title, movies[i].rating, movies[i].year);
    }

    fclose(file);
    printf("Movies saved to file successfully!\n");
}

void load_movies(Movie movies[], int *count) {
    FILE *file = fopen("movies.txt", "r");
    if (!file) {
        printf("No saved movies found or error opening file!\n");
        return;
    }

    while (fgets(movies[*count].title, TITLE_LENGTH, file) && *count < MAX_MOVIES) {
        movies[*count].title[strcspn(movies[*count].title, "\n")] = 0; // Remove trailing newline
        fscanf(file, "%f\n", &movies[*count].rating);
        fscanf(file, "%d\n", &movies[*count].year);
        (*count)++;
    }

    fclose(file);
    printf("Movies loaded from file successfully!\n");
}

void sort_movies(Movie movies[], int count) {
    qsort(movies, count, sizeof(Movie), compare);
}

int compare(const void *a, const void *b) {
    Movie *movieA = (Movie *)a;
    Movie *movieB = (Movie *)b;
    return (movieB->rating - movieA->rating) * 10; // Sort in descending order
}