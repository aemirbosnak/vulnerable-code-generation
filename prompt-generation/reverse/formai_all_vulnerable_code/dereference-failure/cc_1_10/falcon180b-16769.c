//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining structure for a movie
struct Movie{
    char title[50];
    char director[30];
    char cast[100];
    int year;
    int rating;
};

//Function to add a movie to the list
void addMovie(struct Movie movies[], int n, char title[], char director[], char cast[], int year, int rating){
    strcpy(movies[n].title, title);
    strcpy(movies[n].director, director);
    strcpy(movies[n].cast, cast);
    movies[n].year = year;
    movies[n].rating = rating;
}

//Function to display the list of movies
void displayMovies(struct Movie movies[], int n){
    printf("List of Movies:\n");
    for(int i=0; i<n; i++){
        printf("%d. %s (%d) - Directed by %s, starring %s\n", i+1, movies[i].title, movies[i].year, movies[i].director, movies[i].cast);
    }
}

//Function to search for a movie by title
int searchMovie(struct Movie movies[], int n, char title[]){
    for(int i=0; i<n; i++){
        if(strcmp(movies[i].title, title) == 0){
            return i;
        }
    }
    return -1;
}

//Function to rate a movie
void rateMovie(struct Movie movies[], int n, char title[], int rating){
    int index = searchMovie(movies, n, title);
    if(index!= -1){
        movies[index].rating += rating;
        printf("Rating updated for %s\n", title);
    }
    else{
        printf("Movie not found\n");
    }
}

//Function to sort the list of movies by rating
void sortMovies(struct Movie movies[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(movies[i].rating < movies[j].rating){
                struct Movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
}

//Main function
int main(){
    int n;
    printf("Enter the number of movies: ");
    scanf("%d", &n);

    struct Movie movies[n];

    //Adding movies to the list
    addMovie(movies, 0, "The Godfather", "Francis Ford Coppola", "Marlon Brando, Al Pacino", 1972, 9);
    addMovie(movies, 1, "The Shawshank Redemption", "Frank Darabont", "Tim Robbins, Morgan Freeman", 1994, 9);
    addMovie(movies, 2, "The Dark Knight", "Christopher Nolan", "Christian Bale, Heath Ledger", 2008, 9);

    //Displaying the list of movies
    displayMovies(movies, n);

    //Sorting the list of movies by rating
    sortMovies(movies, n);

    //Displaying the sorted list of movies
    printf("\nSorted list of movies by rating:\n");
    displayMovies(movies, n);

    return 0;
}