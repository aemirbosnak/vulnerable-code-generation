//FormAI DATASET v1.0 Category: Movie Rating System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for movie
struct movie {
    char title[100];
    char director[50];
    int year;
    float rating;
};

// function prototypes
void addMovie();
void deleteMovie();
void displayMovie();
void searchMovie();
void rateMovie();

// global variables
int movieCount = 0;
struct movie movies[10];

int main() {
    int choice;
    do {
        printf("\nWelcome to the C Movie Rating System!");
        printf("\n1. Add a movie");
        printf("\n2. Delete a movie");
        printf("\n3. Display all movies");
        printf("\n4. Search for a movie");
        printf("\n5. Rate a movie");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMovie();
                break;
            case 2:
                deleteMovie();
                break;
            case 3:
                displayMovie();
                break;
            case 4:
                searchMovie();
                break;
            case 5:
                rateMovie();
                break;
            case 6:
                printf("\nThank you! Have a nice day.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    } while(choice != 6);
    return 0;
}

// function to add a movie
void addMovie() {
    if(movieCount < 10) {
        printf("\nEnter details of movie %d:\n", movieCount+1);
        printf("Title: ");
        scanf("%s", movies[movieCount].title);
        printf("Director: ");
        scanf("%s", movies[movieCount].director);
        printf("Year: ");
        scanf("%d", &movies[movieCount].year);
        printf("Rating: ");
        scanf("%f", &movies[movieCount].rating);
        movieCount++;
        printf("\nMovie added successfully!\n");
    }
    else {
        printf("\nMaximum limit of movies reached.\n");
    }
}

// function to delete a movie
void deleteMovie() {
    if(movieCount == 0) {
        printf("\nNo movies added yet.\n");
    }
    else {
        int index;
        char title[100];
        printf("\nEnter the title of the movie to be deleted: ");
        scanf("%s", title);
        for(int i=0; i<movieCount; i++) {
            if(strcmp(movies[i].title, title) == 0) {
                index = i;
                break;
            }
        }
        for(int i=index; i<movieCount-1; i++) {
            movies[i] = movies[i+1];
        }
        movieCount--;
        printf("\nMovie deleted successfully!\n");
    }
}

// function to display all movies
void displayMovie() {
    if(movieCount == 0) {
        printf("\nNo movies added yet.\n");
    }
    else {
        printf("\nList of movies:\n");
        printf("-----------------------------------------------------\n");
        printf("Title\t\t\tDirector\tYear\tRating\n");
        printf("-----------------------------------------------------\n");
        for(int i=0; i<movieCount; i++) {
            printf("%-30s %-15s %d\t%.1f\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
        }
        printf("-----------------------------------------------------\n");
    }
}

// function to search for a movie
void searchMovie() {
    if(movieCount == 0) {
        printf("\nNo movies added yet.\n");
    }
    else {
        char title[100];
        int flag = 0;
        printf("\nEnter the title of the movie to search: ");
        scanf("%s", title);
        for(int i=0; i<movieCount; i++) {
            if(strcmp(movies[i].title, title) == 0) {
                printf("\nMovie found!\n");
                printf("Title\t\t\tDirector\tYear\tRating\n");
                printf("-----------------------------------------------------\n");
                printf("%-30s %-15s %d\t%.1f\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
                printf("-----------------------------------------------------\n");
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            printf("\nMovie not found.\n");
        }
    }
}

// function to rate a movie
void rateMovie() {
    if(movieCount == 0) {
        printf("\nNo movies added yet.\n");
    }
    else {
        char title[100];
        int flag = 0;
        float rating;
        printf("\nEnter the title of the movie to rate: ");
        scanf("%s", title);
        for(int i=0; i<movieCount; i++) {
            if(strcmp(movies[i].title, title) == 0) {
                printf("\nEnter the rating for the movie (0-10): ");
                scanf("%f", &rating);
                if(rating >= 0 && rating <= 10) {
                    movies[i].rating = rating;
                    printf("\nMovie rated successfully!\n");
                }
                else {
                    printf("\nInvalid rating. Please enter a rating between 0 and 10.\n");
                }
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            printf("\nMovie not found.\n");
        }
    }
}