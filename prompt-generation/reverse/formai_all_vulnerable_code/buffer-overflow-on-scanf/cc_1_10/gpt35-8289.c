//FormAI DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>

// constants
#define MAX_MOVIES 10

// structures
struct movie {
    char title[50];
    char director[50];
    int release_year;
    float rating;
};

// function prototypes
void addMovie(struct movie movies[], int *count);
void displayMovies(struct movie movies[], int count);
void rateMovie(struct movie movies[], int count);

int main() {
    struct movie movies[MAX_MOVIES];
    int count = 0;
    char choice;
    
    do {
        printf("\n\n===== C MOVIE RATING SYSTEM =====\n");
        printf("1. Add Movie\n2. Display Movies\n3. Rate Movie\n4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1':
                addMovie(movies, &count);
                break;
            case '2':
                displayMovies(movies, count);
                break;
            case '3':
                rateMovie(movies, count);
                break;
            case '4':
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid choice! Try again...\n");
        }
    } while(choice != '4');
    
    return 0;
}

void addMovie(struct movie movies[], int *count) {
    if(*count == MAX_MOVIES) {
        printf("Maximum number of movies exceeded!\n");
        return;
    }
    
    printf("\nEnter details of movie %d:\n", *count + 1);
    
    printf("Title: ");
    scanf(" %[^\n]", movies[*count].title);
    
    printf("Director: ");
    scanf(" %[^\n]", movies[*count].director);
    
    printf("Release Year: ");
    scanf(" %d", &movies[*count].release_year);
    
    printf("Rating: ");
    scanf(" %f", &movies[*count].rating);
    
    printf("Movie Added Successfully!\n");
    (*count)++;
}

void displayMovies(struct movie movies[], int count) {
    if(count == 0) {
        printf("No movies found!\n");
        return;
    }
    
    printf("\n===== MOVIES =====\n");
    for(int i=0; i<count; i++) {
        printf("%d. %s (%s), %d, Rating: %.2f\n", i+1, movies[i].title, movies[i].director, movies[i].release_year, movies[i].rating);
    }
}

void rateMovie(struct movie movies[], int count) {
    if(count == 0) {
        printf("No movies found!\n");
        return;
    }
    
    int movieIndex;
    float rating;
    
    printf("\nEnter movie index (1-%d): ", count);
    scanf(" %d", &movieIndex);
    
    if(movieIndex <= 0 || movieIndex > count) {
        printf("Invalid movie index! Try again...\n");
        return;
    }
    
    printf("Enter new rating for %s: ", movies[movieIndex-1].title);
    scanf(" %f", &rating);
    
    movies[movieIndex-1].rating = rating;
    
    printf("Movie rating updated Successfully!\n");
}