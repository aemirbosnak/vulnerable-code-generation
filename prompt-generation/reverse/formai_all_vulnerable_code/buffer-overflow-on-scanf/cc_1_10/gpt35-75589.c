//FormAI DATASET v1.0 Category: Movie Rating System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

/* Defining the movie structure */
struct movie{
    char title[100];
    char genre[50];
    int year;
    float rating;
};

/* Global variables */
int numMovies = 0;
struct movie *movies;

/* Function to add a new movie */
void addMovie(){
    numMovies++;
    movies = (struct movie*) realloc(movies, numMovies * sizeof(struct movie));
    
    printf("\nEnter the title of the movie: ");
    scanf("%s", movies[numMovies - 1].title);
    
    printf("Enter the genre of the movie: ");
    scanf("%s", movies[numMovies - 1].genre);
    
    printf("Enter the year of the movie: ");
    scanf("%d", &movies[numMovies - 1].year);
    
    printf("Enter the rating of the movie (out of 10): ");
    scanf("%f", &movies[numMovies - 1].rating);
    
    printf("\nMovie added successfully!\n");
}

/* Function to display all movies */
void displayMovies(){
    if(numMovies == 0){
        printf("\nNo movies found!\n");
        return;
    }
    
    printf("\nHere's a list of all the movies:\n");
    printf("Title\t\t\tGenre\t\tYear\tRating\n");
    printf("-----------------------------------------------------------------------------\n");
    
    for(int i=0; i<numMovies; i++){
        printf("%-20s\t%-20s\t%d\t%.1f\n", movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
    }
}

/* Function to find a movie by title */
void findMovie(){
    if(numMovies == 0){
        printf("\nNo movies found!\n");
        return;
    }
    
    char title[100];
    printf("\nEnter the title of the movie you want to find: ");
    scanf("%s", title);
    
    for(int i=0; i<numMovies; i++){
        if(strcmp(movies[i].title, title) == 0){
            printf("\nMovie found!\n");
            printf("Title\t\t\tGenre\t\tYear\tRating\n");
            printf("-----------------------------------------------------------------------------\n");
            printf("%-20s\t%-20s\t%d\t%.1f\n", movies[i].title, movies[i].genre, movies[i].year, movies[i].rating);
            return;
        }
    }
    
    printf("\nMovie not found!\n");
}

/* Function to rate a movie */
void rateMovie(){
    if(numMovies == 0){
        printf("\nNo movies found!\n");
        return;
    }
    
    char title[100];
    printf("\nEnter the title of the movie you want to rate: ");
    scanf("%s", title);
    
    for(int i=0; i<numMovies; i++){
        if(strcmp(movies[i].title, title) == 0){
            printf("\nEnter your rating for the movie (out of 10): ");
            scanf("%f", &movies[i].rating);
            printf("\nYour rating for the movie '%s' has been submitted successfully! Thank you!\n", movies[i].title);
            return;
        }
    }
    
    printf("\nMovie not found!\n");
}

/* Function to display the menu */
void displayMenu(){
    printf("--------------------------\n");
    printf("Welcome to the movie rating system!\n");
    printf("--------------------------\n");
    printf("1. Add a new movie\n");
    printf("2. Display all movies\n");
    printf("3. Find a movie\n");
    printf("4. Rate a movie\n");
    printf("5. Exit\n");
    printf("--------------------------\n");
    printf("Enter your choice: ");
}

int main(){
    int choice;
    
    /* Allocating memory for the movies array */
    movies = (struct movie*) malloc(numMovies * sizeof(struct movie));
    
    do{
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice){
            case 1: addMovie();
                    break;
            case 2: displayMovies();
                    break;
            case 3: findMovie();
                    break;
            case 4: rateMovie();
                    break;
            case 5: printf("\nThank you for using the movie rating system!\n");
                    break;
            default: printf("\nInvalid choice! Please try again.\n");
        }
        
    }while(choice != 5);
    
    return 0;
}