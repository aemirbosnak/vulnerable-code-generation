//FormAI DATASET v1.0 Category: Movie Rating System ; Style: excited
#include <stdio.h> //inclusion of standard input/output header file
#include <stdlib.h> //inclusion of standard library header file

//Struct definition to hold movie data
struct movie {
    char title[50], director[50];
    int year, rating;
};

//Function to add a new movie and rating
void add_movie(struct movie *m) { 
    printf("\nEnter the name of the movie: ");
    scanf("%s", m->title);
    printf("Enter the name of the director: ");
    scanf("%s", m->director);
    printf("Enter the year the movie was released: ");
    scanf("%d", &m->year);
    printf("Enter the rating (out of 10) for the movie: ");
    scanf("%d", &m->rating);
    printf("\nThank you! The movie %s has been added with a rating of %d.\n", m->title, m->rating);
}

//Function to display all movies and ratings
void display_movies(struct movie *movies, int num_movies) { 
    printf("\nAll movies and their ratings:\n");
    for(int i = 0; i < num_movies; i++) {
        printf("%s (Dir. %s, %d) - %d/10\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
    }
}

//Function to find the highest rated movie
void find_highest_rated_movie(struct movie *movies, int num_movies) { 
    int highest_rating = 0, index = 0;
    for(int i = 0; i < num_movies; i++) {
        if(movies[i].rating > highest_rating) {
            highest_rating = movies[i].rating;
            index = i;
        }
    }
    printf("\nThe highest rated movie is %s (Dir. %s, %d) with a rating of %d/10.\n", movies[index].title, movies[index].director, movies[index].year, movies[index].rating);
}

//Main function
int main() {
    int choice, num_movies = 0;
    struct movie *movies = malloc(sizeof(struct movie));
    //Menu driven user interface
    printf("\n--- Welcome to the Unique C Movie Rating System! ---\n");
    printf("\n1. Add a new movie and rating.");
    printf("\n2. Display all movies and ratings.");
    printf("\n3. Find the highest rated movie.");
    printf("\n4. Exit.");
    do {
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                num_movies++;
                movies = realloc(movies, num_movies * sizeof(struct movie));
                add_movie(&movies[num_movies - 1]);
                break;
            case 2:
                if(num_movies == 0) {
                    printf("\nThere are no movies to display. Please add a movie and rating first.\n");
                }
                else {
                    display_movies(movies, num_movies);
                }
                break;
            case 3:
                if(num_movies == 0) {
                    printf("\nThere are no movies to find the highest rated movie from. Please add a movie and rating first.\n");
                }
                else {
                    find_highest_rated_movie(movies, num_movies);
                }
                break;
            case 4:
                printf("\nThank you for using the Unique C Movie Rating System! Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);
    free(movies);
    return 0;
}