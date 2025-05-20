//FormAI DATASET v1.0 Category: Movie Rating System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

void addMovie(char movies[][50], int *numMovies);
void rateMovie(char movies[][50], int ratings[][MAX_RATINGS], int numMovies);
void displayRatings(char movies[][50], int ratings[][MAX_RATINGS], int numMovies);

int main()
{
    srand(time(NULL));
    char movies[MAX_MOVIES][50];
    int ratings[MAX_MOVIES][MAX_RATINGS] = {0};
    int numMovies = 0;
    char choice = ' ';
    
    printf("Welcome to the C Movie Rating System\n");
    
    do {
        printf("\nEnter 'A' to add a movie\n");
        printf("Enter 'R' to rate a movie\n");
        printf("Enter 'D' to display all ratings\n");
        printf("Enter 'Q' to quit\n");
        printf("Choice: ");
        
        scanf(" %c", &choice);
        
        switch (choice) {
            case 'A':
                addMovie(movies, &numMovies);
                break;
            case 'R':
                rateMovie(movies, ratings, numMovies);
                break;
            case 'D':
                displayRatings(movies, ratings, numMovies);
                break;
            case 'Q':
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 'Q');
    
    return 0;
}

void addMovie(char movies[][50], int *numMovies)
{
    char name[50];
    
    printf("\nEnter the name of the movie: ");
    scanf(" %[^\n]", name);
    
    strcpy(movies[*numMovies], name);
    (*numMovies)++;
    
    printf("%s added to movie list\n", name);
}

void rateMovie(char movies[][50], int ratings[][MAX_RATINGS], int numMovies)
{
    int movieIndex, rating;
    
    if (numMovies == 0) {
        printf("\nNo movies found in the system\n");
        return;
    }
    
    // Randomly select a movie to rate
    movieIndex = rand() % numMovies;
    
    printf("\nRate the movie '%s' from 0 to 9: ", movies[movieIndex]);
    scanf("%d", &rating);
    
    if (rating < 0 || rating > 9) {
        printf("Invalid rating\n");
        return;
    }
    
    for (int i = 0; i < MAX_RATINGS; i++) {
        if (ratings[movieIndex][i] == 0) {
            ratings[movieIndex][i] = rating;
            break;
        }
    }
    
    printf("Rating of %d added for '%s'\n", rating, movies[movieIndex]);
}

void displayRatings(char movies[][50], int ratings[][MAX_RATINGS], int numMovies)
{
    if (numMovies == 0) {
        printf("\nNo movies found in the system\n");
        return;
    }
    
    for (int i = 0; i < numMovies; i++) {
        printf("\n%s:\n", movies[i]);
        
        if (ratings[i][0] == 0) {
            printf("No ratings yet\n");
            continue;
        }
        
        float total = 0;
        int count = 0;
        
        for (int j = 0; j < MAX_RATINGS; j++) {
            if (ratings[i][j] != 0) {
                printf("%d ", ratings[i][j]);
                total += ratings[i][j];
                count++;
            }
        }
        
        float average = total / count;
        printf("(average rating: %.1f)\n", average);
    }
}