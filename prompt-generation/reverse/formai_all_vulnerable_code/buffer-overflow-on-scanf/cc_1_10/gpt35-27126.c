//FormAI DATASET v1.0 Category: Movie Rating System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store movie details
struct Movie {
    char title[100];
    char director[50];
    char genre[20];
    int year;
    float rating;
};

// Function prototypes
void add_movie();
void view_movies();
void search_movie();
void rate_movie();
void delete_movie();
void exit_program();

// Global variables
struct Movie movies[100];
int num_movies = 0;

int main() {
    // Welcome message
    printf("Welcome to the C Movie Rating System\n");
    
    // Display menu options
    printf("\n1. Add Movie\n");
    printf("2. View Movies\n");
    printf("3. Search Movie\n");
    printf("4. Rate Movie\n");
    printf("5. Delete Movie\n");
    printf("6. Exit Program\n");
    
    // Get menu choice from user
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    // Process user choice
    switch(choice) {
        case 1:
            add_movie();
            break;
        case 2:
            view_movies();
            break;
        case 3:
            search_movie();
            break;
        case 4:
            rate_movie();
            break;
        case 5:
            delete_movie();
            break;
        case 6:
            exit_program();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            main(); // Return to main menu
    }
    
    return 0;
}

void add_movie() {
    // Get movie details from user
    printf("\nEnter movie title: ");
    scanf("%s", movies[num_movies].title);
    printf("Enter director: ");
    scanf("%s", movies[num_movies].director);
    printf("Enter genre: ");
    scanf("%s", movies[num_movies].genre);
    printf("Enter year: ");
    scanf("%d", &movies[num_movies].year);
    printf("Enter rating (out of 10): ");
    scanf("%f", &movies[num_movies].rating);
    num_movies++; // Increase movie count
    
    printf("\nMovie added successfully!\n");
    main(); // Return to main menu
}

void view_movies() {
    // Check if any movies have been added
    if (num_movies == 0) {
        printf("\nNo movies found.\n");
        main(); // Return to main menu
    }
    
    printf("\n");
    
    // Display all movies
    for (int i = 0; i < num_movies; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Genre: %s\n", movies[i].genre);
        printf("Year: %d\n", movies[i].year);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("\n");
    }
    
    main(); // Return to main menu
}

void search_movie() {
    // Get search query from user
    char query[100];
    printf("\nEnter title or director: ");
    scanf("%s", query);
    
    // Search for movies containing query in title or director
    int count = 0;
    for (int i = 0; i < num_movies; i++) {
        if (strstr(movies[i].title, query) != NULL || strstr(movies[i].director, query) != NULL) {
            printf("\nTitle: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Genre: %s\n", movies[i].genre);
            printf("Year: %d\n", movies[i].year);
            printf("Rating: %.1f\n", movies[i].rating);
            printf("\n");
            count++;
        }
    }
    
    // Display message if no movies found
    if (count == 0) {
        printf("\nNo movies found.\n");
    }
    
    main(); // Return to main menu
}

void rate_movie() {
    // Get movie title from user
    char title[100];
    printf("\nEnter movie title: ");
    scanf("%s", title);
    
    // Search for movie with title
    int index = -1;
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            index = i;
            break;
        }
    }
    
    // Display message if movie not found
    if (index == -1) {
        printf("\nMovie not found.\n");
        main(); // Return to main menu
    }
    
    // Get new rating from user
    printf("\nEnter new rating (out of 10): ");
    scanf("%f", &movies[index].rating);
    
    printf("\nRating updated successfully!\n");
    main(); // Return to main menu
}

void delete_movie() {
    // Get movie title from user
    char title[100];
    printf("\nEnter movie title: ");
    scanf("%s", title);
    
    // Search for movie with title
    int index = -1;
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            index = i;
            break;
        }
    }
    
    // Display message if movie not found
    if (index == -1) {
        printf("\nMovie not found.\n");
        main(); // Return to main menu
    }
    
    // Remove movie from array
    for (int i = index; i < num_movies - 1; i++) {
        movies[i] = movies[i+1];
    }
    num_movies--; // Decrease movie count
    
    printf("\nMovie deleted successfully!\n");
    main(); // Return to main menu
}

void exit_program() {
    printf("\nThank you for using the C Movie Rating System. Goodbye!\n");
    exit(0); // Exit program
}