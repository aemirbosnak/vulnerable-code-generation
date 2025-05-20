//FormAI DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>

struct movie {
    char name[50];
    char genre[20];
    int year;
    int rating;
};

struct movie allMovies[5]; // An array of structures containing movie data

int main() {
    int i, choice;
    
    printf("Welcome to the Movie Rating System!\n");
    
    // Prompt user to enter movie details for 5 movies
    for (i = 0; i < 5; i++) {
        printf("\nEnter details for Movie %d:\n", i+1);
        printf("Name: ");
        scanf("%[^\n]%*c", allMovies[i].name);
        printf("Genre: ");
        scanf("%[^\n]%*c", allMovies[i].genre);
        printf("Year: ");
        scanf("%d", &allMovies[i].year);
        printf("Rating (out of 10): ");
        scanf("%d", &allMovies[i].rating);
    }
    
    // Display menu and prompt user to choose an option
    printf("\n\nWhat would you like to do?\n");
    printf("1. View all movies and their ratings\n");
    printf("2. View top rated movies\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: 
            // Display all movies and their ratings
            printf("\n\nAll Movies:\n");
            printf("%-3s %-30s %-20s %-10s\n", "No.", "Name", "Genre", "Rating");
            for (i = 0; i < 5; i++) {
                printf("%-3d %-30s %-20s %-10d\n", i+1, allMovies[i].name, allMovies[i].genre, allMovies[i].rating);
            }
            break;
        case 2:
            // Display top rated movies
            printf("\n\nTop Rated Movies:\n");
            printf("%-3s %-30s %-20s %-10s\n", "No.", "Name", "Genre", "Rating");
            for (i = 0; i < 5; i++) {
                if (allMovies[i].rating >= 8) {
                    printf("%-3d %-30s %-20s %-10d\n", i+1, allMovies[i].name, allMovies[i].genre, allMovies[i].rating);
                }
            }
            break;
        case 3:
            // Exit program
            printf("\n\nGoodbye!");
            break;
        default:
            // Display error and ask user to retry
            printf("\n\nInvalid choice. Please try again.\n");
            break;
    }
    
    return 0;
}