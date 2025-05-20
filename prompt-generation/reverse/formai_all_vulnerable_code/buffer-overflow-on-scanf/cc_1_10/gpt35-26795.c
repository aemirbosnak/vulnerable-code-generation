//FormAI DATASET v1.0 Category: Movie Rating System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of the movie
struct movie {
    char title[100];
    char director[100];
    int year;
    float rating;
};

// Define the function to add a new movie to the database
void add_movie(struct movie *db, int *num_movies) {
    struct movie new_movie;
    printf("Enter movie title: ");
    scanf("%s", new_movie.title);
    printf("Enter movie director: ");
    scanf("%s", new_movie.director);
    printf("Enter movie release year: ");
    scanf("%d", &new_movie.year);
    printf("Enter movie rating (out of 10): ");
    scanf("%f", &new_movie.rating);
    db[*num_movies] = new_movie;
    (*num_movies)++;
    printf("Movie added successfully!\n");
}

// Define the function to remove a movie from the database
void remove_movie(struct movie *db, int *num_movies) {
    char title[100];
    printf("Enter movie title: ");
    scanf("%s", title);
    int i;
    for (i = 0; i < *num_movies; i++) {
        if (strcmp(title, db[i].title) == 0) {
            int j;
            for (j = i; j < (*num_movies) - 1; j++) {
                db[j] = db[j+1];
            }
            (*num_movies)--;
            printf("Movie removed successfully!\n");
            return;
        }
    }
    printf("Movie not found!\n");
}

// Define the function to print the database
void print_database(struct movie *db, int num_movies) {
    printf("Movie Database:\n");
    int i;
    for (i = 0; i < num_movies; i++) {
        printf("%d. %s (dir. %s, %d) - %.1f/10\n", i+1, db[i].title, db[i].director, db[i].year, db[i].rating);
    }
}

// Define the main function
int main() {

    struct movie database[100];
    int num_movies = 0;

    // Print the menu
    printf("C Movie Rating System\n");
    printf("1. Add Movie\n");
    printf("2. Remove Movie\n");
    printf("3. Print Database\n");
    printf("4. Exit\n");

    // Loop until the user exits
    while (1) {
        int choice;
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_movie(database, &num_movies);
                break;
            case 2:
                remove_movie(database, &num_movies);
                break;
            case 3:
                print_database(database, num_movies);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}