//FormAI DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold movie details
struct movie {
    char title[50];
    char genre[20];
    int length;
    int rating;
};

// Function to print a single movie's details
void printMovie(struct movie temp){
    printf("Title: %s\n", temp.title);
    printf("Genre: %s\n", temp.genre);
    printf("Length: %d minutes\n", temp.length);
    printf("Rating: %d\n\n", temp.rating);
}

// Function to add a new movie to the database
void addMovie(struct movie *arr, int *count){
    printf("Enter the title of the movie: ");
    scanf(" %[^\n]s", arr[*count].title);
    
    printf("Enter the genre of the movie: ");
    scanf(" %[^\n]s", arr[*count].genre);
    
    printf("Enter the length of the movie in minutes: ");
    scanf("%d", &arr[*count].length);
    
    printf("Enter the rating of the movie (1-10): ");
    scanf("%d", &arr[*count].rating);
    printf("Movie added successfully!\n\n");
    (*count)++;
}

// Function to search and return the index of a movie
int searchMovie(struct movie *arr, int count, char *title){
    for(int i = 0; i < count; i++){
        if(strcmp(arr[i].title, title) == 0){
            return i;
        }
    }
    return -1;
}

// Function to rate a movie
void rateMovie(struct movie *arr, int count){
    char title[50];
    printf("Enter the title of the movie to rate: ");
    scanf(" %[^\n]s", title);
    
    int index = searchMovie(arr, count, title);
    if(index == -1){
        printf("Movie not found!\n\n");
        return;
    }
    
    printf("Enter the new rating for the movie (1-10): ");
    scanf("%d", &arr[index].rating);
    printf("Rating updated successfully!\n\n");
}

// Function to delete a movie
void deleteMovie(struct movie *arr, int *count){
    char title[50];
    printf("Enter the title of the movie to delete: ");
    scanf(" %[^\n]s", title);
    
    int index = searchMovie(arr, *count, title);
    if(index == -1){
        printf("Movie not found!\n\n");
        return;
    }
    
    for(int i = index; i < *count-1; i++){
        arr[i] = arr[i+1];
    }
    printf("Movie deleted successfully!\n\n");
    (*count)--;
}

// Function to display all the movies in the database
void displayAllMovies(struct movie *arr, int count){
    if(count == 0){
        printf("No movies found in database!\n\n");
        return;
    }
    
    printf("\n%-20s %-20s %-10s %-10s\n", "Title", "Genre", "Length", "Rating");
    printf("---------------------------------------------------------\n");
    for(int i = 0; i < count; i++){
        printf("%-20s %-20s %-10d %-10d\n", arr[i].title, arr[i].genre, arr[i].length, arr[i].rating);
    }
    printf("---------------------------------------------------------\n\n");
}

int main(){
    struct movie movieArr[100];
    int count = 0;
    int choice;
    
    printf("---------------Welcome to the Movie Rating System---------------\n");
    
    while(1){
        printf("Enter your choice:\n");
        printf("1. Add a new movie\n");
        printf("2. Rate a movie\n");
        printf("3. Delete a movie\n");
        printf("4. Display all movies\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                addMovie(movieArr, &count);
                break;
            case 2:
                rateMovie(movieArr, count);
                break;
            case 3:
                deleteMovie(movieArr, &count);
                break;
            case 4:
                displayAllMovies(movieArr, count);
                break;
            case 5:
                printf("Thanks for using the Movie Rating System!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}