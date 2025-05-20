//FormAI DATASET v1.0 Category: Movie Rating System ; Style: high level of detail
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Declare a struct to encapsulate movie information
struct Movie {
    char title[50];
    char director[50];
    int year;
    float rating;
};

//Function to add a new movie to the database
void addMovie(struct Movie movies[], int numMovies) {
    printf("\nEnter the Title of the Movie: ");
    scanf("%s", movies[numMovies].title);
    printf("Enter the Name of the Director: ");
    scanf("%s", movies[numMovies].director);
    printf("Enter the Year of Release: ");
    scanf("%d", &movies[numMovies].year);
    printf("Enter the Rating (Out of 10): ");
    scanf("%f", &movies[numMovies].rating);
    printf("\nMovie Added Successfully!\n\n");
}

//Function to display all the movies in the database
void displayMovies(struct Movie movies[], int numMovies) {
    printf("\n");
    if(numMovies == 0) {
        printf("No Movies Found!\n\n");
        return;
    }
    printf("Title\t\t\tDirector\t\t\tYear\tRating\n\n");
    for(int i = 0; i < numMovies; i++) {
        printf("%s\t\t\t%s\t\t\t%d\t%.1f\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
    }
    printf("\n");
}

//Function to search for a movie based on its title
void searchMovie(struct Movie movies[], int numMovies) {
    char query[50];
    printf("\nEnter the Title of the Movie you want to search for: ");
    scanf("%s", query);
    for(int i = 0; i < numMovies; i++) {
        if(strcmp(movies[i].title, query) == 0) {
            printf("\nMovie Found!\n\nTitle: %s\nDirector: %s\nYear: %d\nRating: %.1f\n\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
            return;
        }
    }
    printf("\nMovie Not Found!\n\n");
}

//Function to rate a movie
void rateMovie(struct Movie movies[], int numMovies) {
    char query[50];
    printf("\nEnter the Title of the Movie which you want to rate: ");
    scanf("%s", query);
    for(int i = 0; i < numMovies; i++) {
        if(strcmp(movies[i].title, query) == 0) {
            printf("\nEnter the new Rating of the Movie (Out of 10): ");
            scanf("%f", &movies[i].rating);
            printf("\nRating Updated Successfully!\n\n");
            return;
        }
    }
    printf("\nMovie Not Found!\n\n");
}

//Function to sort movies by rating in descending order
void sortMovies(struct Movie movies[], int numMovies) {
    struct Movie temp;
    for(int i = 0; i < numMovies; i++) {
        for(int j = i+1; j < numMovies; j++) {
            if(movies[i].rating < movies[j].rating) {
                temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
    printf("\nMovies Sorted by Rating (Descending Order) Successfully!\n");
    displayMovies(movies, numMovies);
}

int main() {
    struct Movie movies[100]; //Initialize Movie Database
    int numMovies = 0; //Initialize Number of Movies
    int choice; //Initialize User Choice
    printf("\t\tC Movie Rating System\n\n");
    while(1) { //Infinite Loop to Display Menu
        printf("1.Add a New Movie\n2.Display All Movies\n3.Search for a Movie\n4.Rate a Movie\n5.Sort Movies by Rating\n6.Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addMovie(movies, numMovies); numMovies++; break;
            case 2: displayMovies(movies, numMovies); break;
            case 3: searchMovie(movies, numMovies); break;
            case 4: rateMovie(movies, numMovies); break;
            case 5: sortMovies(movies, numMovies); break;
            case 6: printf("\nThank you for using C Movie Rating System!\n\n"); exit(0); break;
            default: printf("\nInvalid Choice! Please try again...\n\n"); break;
        }
    }
    return 0;
}