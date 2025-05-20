//FormAI DATASET v1.0 Category: Movie Rating System ; Style: scientific
#include <stdio.h>
#include <string.h>

// Struct for storing movie data
typedef struct {
    char title[50];
    char director[50];
    int year;
    float rating;
} Movie;

// Function to get a rating between 1-10 from user
float get_rating() {
    float rating;
    printf("Please enter a rating from 1 to 10: ");
    scanf("%f", &rating);
    while (rating < 1 || rating > 10) {
        printf("Invalid rating, please enter a value between 1 and 10: ");
        scanf("%f", &rating);
    }
    return rating;
}

// Function to add a new movie to the database
void add_movie(Movie *database, int *num_movies) {
    printf("Adding a new movie...\n");
    printf("Please enter the movie title: ");
    scanf("%s", database[*num_movies].title);
    printf("Please enter the movie director: ");
    scanf("%s", database[*num_movies].director);
    printf("Please enter the year the movie was released: ");
    scanf("%d", &database[*num_movies].year);
    database[*num_movies].rating = get_rating();
    (*num_movies)++;
    printf("Movie added successfully!\n\n");
}

// Function to print all movies in the database
void print_movies(Movie *database, int num_movies) {
    printf("\nMovies in the Database:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%d. %s, directed by %s, released in %d, rated %.2f\n", i+1, database[i].title, database[i].director,
                database[i].year, database[i].rating);
    }
}

// Function to calculate the average rating of all movies in the database
float calculate_average_rating(Movie *database, int num_movies) {
    float total_rating = 0;
    for (int i = 0; i < num_movies; i++) {
        total_rating += database[i].rating;
    }
    return total_rating / num_movies;
}

int main() {
    Movie database[50];
    int num_movies = 0;
    char choice;
    
    // Program loop
    while (1) {
        printf("Welcome to the Movie Database!\n");
        printf("Please select an option:\n");
        printf("A. Add a new movie\n");
        printf("V. View all movies\n");
        printf("R. View the average rating of all movies\n");
        printf("Q. Quit\n");
        
        scanf(" %c", &choice);
        switch (choice) {
            case 'A': add_movie(database, &num_movies); break;
            case 'V': print_movies(database, num_movies); break;
            case 'R': printf("The average rating of all movies in the database is %.2f\n\n", calculate_average_rating(database, num_movies)); break;
            case 'Q': return 0;
            default: printf("Invalid choice, please enter A, V, R, or Q\n\n");
        }
    }
}