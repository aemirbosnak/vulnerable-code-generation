//FormAI DATASET v1.0 Category: Movie Rating System ; Style: modular
#include<stdio.h>
#include<string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 50

// Define a structure for storing movie related info
typedef struct {
    char title[MAX_TITLE_LENGTH];
    int rating;
} Movie;

// Define global variables
int num_movies = 0;
Movie movies[MAX_MOVIES];

// Function prototypes
void addMovie();
void viewMovies();
void rateMovie();

int main()
{
    int choice;

    do {
        printf("\nMovie Rating System\n");
        printf("1. Add a movie\n");
        printf("2. View all movies\n");
        printf("3. Rate a movie\n");
        printf("4. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMovie();
                break;
            case 2:
                viewMovies();
                break;
            case 3:
                rateMovie();
                break;
            case 4:
                printf("Thank you for using the Movie Rating System\n");
                break;
            default:
                printf("Invalid choice. Try again!\n");
        }
    } while(choice != 4);

    return 0;
}

void addMovie()
{
    if(num_movies >= MAX_MOVIES) {
        printf("Maximum movies reached. Cannot add more!\n");
        return;
    }

    Movie movie;
    printf("Enter the movie title: ");
    scanf(" %[^\n]s", movie.title);

    // First check if the movie already exists
    for(int i = 0; i < num_movies; i++) {
        if(strcmp(movies[i].title, movie.title) == 0) {
            printf("This movie already exists in the system\n");
            return;
        }
    }

    printf("Enter the movie rating (out of 10): ");
    scanf("%d", &movie.rating);

    movies[num_movies++] = movie;
    printf("Movie added successfully!\n");
}

void viewMovies()
{
    if(num_movies == 0) {
        printf("No movies found in the system!\n");
        return;
    }

    printf("\nTitle\t\tRating\n");
    printf("-----\t\t------\n");
    for(int i = 0; i < num_movies; i++) {
        printf("%s\t\t%d\n", movies[i].title, movies[i].rating);
    }
}

void rateMovie()
{
    if(num_movies == 0) {
        printf("No movies found in the system!\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    int rating;

    printf("Enter the title of the movie to rate: ");
    scanf(" %[^\n]s", title);

    for(int i = 0; i < num_movies; i++) {
        if(strcmp(movies[i].title, title) == 0) {
            printf("Enter the new rating (out of 10): ");
            scanf("%d", &rating);
            movies[i].rating = rating;
            printf("Movie rating updated successfully\n");
            return;
        }
    }

    printf("Movie not found in the system!\n");
}