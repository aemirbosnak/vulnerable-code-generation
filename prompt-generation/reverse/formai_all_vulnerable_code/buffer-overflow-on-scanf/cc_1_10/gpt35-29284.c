//FormAI DATASET v1.0 Category: Movie Rating System ; Style: authentic
#include<stdio.h>
#include<string.h>

//structure to hold movie details
typedef struct{
    char title[50];
    char director[50];
    char cast[100];
    int year;
    int rating;
} Movie;

//function prototypes
void addMovie(Movie movies[], int num_movies);
void displayMovies(Movie movies[], int num_movies);
void searchMovies(Movie movies[], int num_movies);

int main(){

    int num_movies = 0, choice;
    Movie movies[20];

    printf("Welcome to Unique C Movie Rating System\n");

    do{
        printf("\nPlease choose an option:\n");
        printf("1. Add movie\n");
        printf("2. Display movies\n");
        printf("3. Search movies\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addMovie(movies, num_movies);
                num_movies++;
                printf("Movie added successfully!");
                break;
            case 2:
                displayMovies(movies, num_movies);
                break;
            case 3:
                searchMovies(movies, num_movies);
                break;
            case 4:
                printf("Thank you for using Unique C Movie Rating System\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }while(choice != 4);

    return 0;
}

//function to add a new movie
void addMovie(Movie movies[], int num_movies){

    printf("\nEnter the movie details:\n");
    printf("Title: ");
    scanf("%s", movies[num_movies].title);
    printf("Director: ");
    scanf("%s", movies[num_movies].director);
    printf("Cast: ");
    scanf("%s", movies[num_movies].cast);
    printf("Year: ");
    scanf("%d", &movies[num_movies].year);
    printf("Rating (out of 10): ");
    scanf("%d", &movies[num_movies].rating);
}

//function to display all movies
void displayMovies(Movie movies[], int num_movies){

    if(num_movies == 0){
        printf("\nNo movies to display.\n");
        return;
    }

    printf("\n%-30s %-20s %-40s %-10s %-10s\n", "Title", "Director", "Cast", "Year", "Rating");
    for(int i=0; i<num_movies; i++){
        printf("%-30s %-20s %-40s %-10d %-10d\n", movies[i].title, 
            movies[i].director, movies[i].cast, movies[i].year, movies[i].rating);
    }
}

//function to search for a movie
void searchMovies(Movie movies[], int num_movies){

    if(num_movies == 0){
        printf("\nNo movies to search.\n");
        return;
    }

    char search_title[50];
    printf("\nEnter the title of the movie you want to search: ");
    scanf("%s", search_title);

    int found_flag = 0;
    for(int i=0; i<num_movies; i++){
        if(strcmp(search_title, movies[i].title) == 0){
            printf("\n%-30s %-20s %-40s %-10s %-10s\n", "Title", "Director", "Cast", "Year", "Rating");
            printf("%-30s %-20s %-40s %-10d %-10d\n", movies[i].title, 
                movies[i].director, movies[i].cast, movies[i].year, movies[i].rating);
            found_flag = 1;
        }
    }

    if(found_flag == 0){
        printf("\nMovie not found.\n");
    }
}