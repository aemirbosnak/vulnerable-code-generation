//FormAI DATASET v1.0 Category: Movie Rating System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for movie
struct Movie {
    char *title;
    char *director;
    int year;
    float rating;
};

// function to add new movie
void add_new_movie(struct Movie *movies, int count) {
    // dynamic memory allocation for title and director strings
    char *title = (char *) malloc(sizeof(char) * 50);
    char *director = (char *) malloc(sizeof(char) * 50);
    int year;
    float rating;
    
    // take input from user
    printf("Enter movie title: ");
    scanf("%s", title);
    printf("Enter director name: ");
    scanf("%s", director);
    printf("Enter year of release: ");
    scanf("%d", &year);
    printf("Enter movie rating (out of 10): ");
    scanf("%f", &rating);
    
    // add data to struct
    movies[count].title = title;
    movies[count].director = director;
    movies[count].year = year;
    movies[count].rating = rating;
}

// function to rate a movie
void rate_movie(struct Movie *movies, int count) {
    // check if there are no movies
    if(count == 0) {
        printf("No movies added yet. Please add a movie first.\n");
    } else {
        // display movies
        printf("All movies:\n");
        for(int i=0; i<count; i++) {
            printf("%d. %s, %d, %.1f/10\n", i+1, movies[i].title, movies[i].year, movies[i].rating);
        }
        
        // take input from user
        printf("Enter movie number to rate (1-%d): ", count);
        int num;
        scanf("%d", &num);
    
        // check if input is valid
        if(num >= 1 && num <= count) {
            // take rating input
            float rating;
            printf("Enter rating (out of 10): ");
            scanf("%f", &rating);
            
            // update rating
            movies[num-1].rating = rating;
        } else {
            printf("Invalid input. Please enter a number from 1 to %d.\n", count);
        }
    }
}

// function to delete a movie
void delete_movie(struct Movie *movies, int count) {
    // check if there are no movies
    if(count == 0) {
        printf("No movies added yet. Please add a movie first.\n");
    } else {
        // display movies
        printf("All movies:\n");
        for(int i=0; i<count; i++) {
            printf("%d. %s, %d, %.1f/10\n", i+1, movies[i].title, movies[i].year, movies[i].rating);
        }
        
        // take input from user
        printf("Enter movie number to delete (1-%d): ", count);
        int num;
        scanf("%d", &num);
        
        // check if input is valid
        if(num >= 1 && num <= count) {
            // free memory of title and director strings
            free(movies[num-1].title);
            free(movies[num-1].director);
            
            // shift array elements to delete movie
            for(int i=num-1; i<count-1; i++) {
                movies[i] = movies[i+1];
            }
            
            // decrement count
            count--;
            
            printf("Movie deleted successfully.\n");
        } else {
            printf("Invalid input. Please enter a number from 1 to %d.\n", count);
        }
    }
}

// function to display all movies
void display_movies(struct Movie *movies, int count) {
    // check if there are no movies
    if(count == 0) {
        printf("No movies added yet. Please add a movie first.\n");
    } else {
        // display movies
        printf("All movies:\n");
        for(int i=0; i<count; i++) {
            printf("%d. %s, %d, %.1f/10\n", i+1, movies[i].title, movies[i].year, movies[i].rating);
        }
    }
}

// main function
int main() {
    // initialize array of struct with size 10
    struct Movie movies[10];
    // initialize count to 0
    int count = 0;
    // initialize choice variable
    int choice = 0;
    
    // loop until user exits
    while(choice != 5) {
        // display menu
        printf("\n--- C Movie Rating System ---\n");
        printf("1. Add new movie\n");
        printf("2. Rate a movie\n");
        printf("3. Delete a movie\n");
        printf("4. Display all movies\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        // switch case for choice
        switch(choice) {
            case 1:
                // check if array is full
                if(count == 10) {
                    printf("Sorry, cannot add more than 10 movies.\n");
                } else {
                    add_new_movie(movies, count);
                    count++;
                }
                break;
                
            case 2:
                rate_movie(movies, count);
                break;
                
            case 3:
                delete_movie(movies, count);
                break;
                
            case 4:
                display_movies(movies, count);
                break;
            
            case 5:
                printf("Thank you for using C Movie Rating System!\n");
                break;
                
            default:
                printf("Invalid input. Please enter a number from 1 to 5.\n");
                break;
        }
    }
    
    return 0;
}