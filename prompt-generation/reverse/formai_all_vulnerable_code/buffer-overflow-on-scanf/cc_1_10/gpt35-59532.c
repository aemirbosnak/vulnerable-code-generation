//FormAI DATASET v1.0 Category: Movie Rating System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// struct to store movie details
typedef struct {
    char name[50];
    char director[50];
    int year;
    float rating;
} movie;

// function to get user input for a movie
void add_movie(movie* m) {
    printf("Enter movie name: ");
    fgets(m->name, 50, stdin);
    
    printf("Enter movie director: ");
    fgets(m->director, 50, stdin);
    
    printf("Enter year of release: ");
    scanf("%d", &(m->year));
    
    printf("Enter movie rating (out of 10): ");
    scanf("%f", &(m->rating));
    getchar(); // clear newline character from input
}

// function to display movie details
void print_movie(movie m) {
    printf("Movie Name: %s", m.name);
    printf("Director: %s", m.director);
    printf("Year of release: %d\n", m.year);
    printf("Rating: %.1f\n", m.rating);
}

// main function
int main() {
    // declare variables and arrays
    int choice = 0;
    int num_movies = 0;
    movie* movie_list = NULL;
    
    printf("Welcome to the Movie Rating System!\n");
    
    // loop until user chooses to exit
    while(choice != 4) {
        // display menu
        printf("\nEnter a choice:\n");
        printf("1. Add a movie\n");
        printf("2. View all movies\n");
        printf("3. View top rated movies\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        getchar(); // clear newline character from input
        
        switch(choice) {
            case 1: // add a movie
                num_movies++;
                movie_list = (movie*) realloc(movie_list, num_movies * sizeof(movie));
                add_movie(&(movie_list[num_movies-1]));
                break;
                
            case 2: // view all movies
                if(num_movies == 0) {
                    printf("No movies found.\n");
                } else {
                    printf("All movies:\n");
                    for(int i=0; i<num_movies; i++) {
                        print_movie(movie_list[i]);
                    }
                }
                break;
                
            case 3: // view top rated movies
                if(num_movies == 0) {
                    printf("No movies found.\n");
                } else {
                    float max_rating = -1;
                    int max_rating_index = -1;
                    printf("Top rated movies:\n");
                    for(int i=0; i<num_movies; i++) {
                        if(movie_list[i].rating > max_rating) {
                            max_rating = movie_list[i].rating;
                            max_rating_index = i;
                        }
                    }
                    if(max_rating_index == -1) {
                        printf("No top rated movies found.\n");
                    } else {
                        print_movie(movie_list[max_rating_index]);
                    }
                }
                break;
                
            case 4: // exit
                printf("Exiting Movie Rating System...\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    // free allocated memory and exit
    free(movie_list);
    return 0;
}