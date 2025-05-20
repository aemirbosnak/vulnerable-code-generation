//FormAI DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

// define the struct for the movie rating system
struct movie {
    char title[50];
    int year;
    float rating;
};

// declare global variables
int num_movies = 0;
int average_rating = 0;

// function to add movie
void add_movie(struct movie *movies) {
    printf("Enter the title of the movie: ");
    scanf("%s", movies[num_movies].title);
    printf("Enter the year the movie was released: ");
    scanf("%d", &movies[num_movies].year);
    printf("Enter the rating of the movie (out of 10): ");
    scanf("%f", &movies[num_movies].rating);
    
    // update the global variables
    num_movies++;
    average_rating += movies[num_movies-1].rating;
}

// function to view all movies
void view_movies(struct movie *movies) {
    if(num_movies == 0) {
        printf("No movies found.\n");
    } else {
        printf("\nTitle\tYear\tRating\n");
        for(int i=0; i<num_movies; i++) {
            printf("%s\t%d\t%.1f\n", movies[i].title, movies[i].year, movies[i].rating);
        }
        printf("\n");
    }
}

// function to search for a movie
void search_movie(struct movie *movies) {
    if(num_movies == 0) {
        printf("No movies found.\n");
    } else {
        char search_title[50];
        printf("Enter the title of the movie to search: ");
        scanf("%s", search_title);
        int found = 0;
        for(int i=0; i<num_movies; i++) {
            if(strcmp(search_title, movies[i].title) == 0) {
                printf("\nTitle\tYear\tRating\n");
                printf("%s\t%d\t%.1f\n", movies[i].title, movies[i].year, movies[i].rating);
                found = 1;
                break;
            }
        }
        if(found == 0) {
            printf("Movie not found.\n");
        }
    }
}

// function to calculate average rating
void calculate_average_rating() {
    if(num_movies == 0) {
        printf("No movies found.\n");
    } else {
        float average = (float)average_rating / (float)num_movies;
        printf("Average movie rating: %.1f\n", average);
    }
}

// main function
int main() {
    // declare variables
    int choice = 0;
    struct movie *movies = malloc(100 * sizeof(struct movie));
    
    // loop until user chooses to exit
    while(choice != 5) {
        printf("\nMenu:\n");
        printf("1. Add movie\n");
        printf("2. View all movies\n");
        printf("3. Search for a movie\n");
        printf("4. Calculate average rating\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        // switch case based on user choice
        switch(choice) {
            case 1:
                add_movie(movies);
                break;
            case 2:
                view_movies(movies);
                break;
            case 3:
                search_movie(movies);
                break;
            case 4:
                calculate_average_rating();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    // free the memory allocated for the array
    free(movies);
    
    return 0;
}