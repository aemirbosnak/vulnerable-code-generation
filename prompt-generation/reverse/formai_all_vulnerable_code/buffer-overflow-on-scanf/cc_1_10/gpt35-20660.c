//FormAI DATASET v1.0 Category: Movie Rating System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the details of each movie
typedef struct
{
    char title[50];
    char director[50];
    int year;
    float rating;
} Movie;

// Function to display the details of a movie
void display(Movie m)
{
    printf("Title: %s\n", m.title);
    printf("Director: %s\n", m.director);
    printf("Year: %d\n", m.year);
    printf("Rating: %.1f/10\n", m.rating);
}

// Function to add a new movie to the collection
void addMovie(Movie *movies, int *count)
{
    printf("Enter the title of the movie: ");
    scanf("%s", movies[*count].title);
    
    printf("Enter the director of the movie: ");
    scanf("%s", movies[*count].director);
    
    printf("Enter the year of release: ");
    scanf("%d", &movies[*count].year);
    
    printf("Enter the rating of the movie (out of 10): ");
    scanf("%f", &movies[*count].rating);
    
    (*count)++;
    printf("Movie added successfully!\n");
}

// Function to modify the details of a movie
void modifyMovie(Movie *movies, int count)
{
    char title[50];
    int i, found = 0;
    
    printf("Enter the title of the movie to modify: ");
    scanf("%s", title);
    
    for(i=0; i<count; i++)
    {
        if(strcmp(movies[i].title, title) == 0)
        {
            found = 1;
            
            printf("Enter the new title of the movie (or press enter to keep the same): ");
            scanf("%s", movies[i].title);
            
            printf("Enter the new director of the movie (or press enter to keep the same): ");
            scanf("%s", movies[i].director);
            
            printf("Enter the new year of release (or enter 0 to keep the same): ");
            scanf("%d", &movies[i].year);
            
            printf("Enter the new rating of the movie (out of 10) (or enter 0 to keep the same): ");
            scanf("%f", &movies[i].rating);
            
            printf("Movie details modified successfully!\n");
        }
    }
    
    if(!found)
    {
        printf("No movie found with that title.\n");
    }
}

// Function to delete a movie from the collection
void deleteMovie(Movie *movies, int *count)
{
    char title[50];
    int i, j, found = 0;
    
    printf("Enter the title of the movie to delete: ");
    scanf("%s", title);
    
    for(i=0; i<*count; i++)
    {
        if(strcmp(movies[i].title, title) == 0)
        {
            found = 1;
            
            for(j=i; j<(*count)-1; j++)
            {
                movies[j] = movies[j+1];
            }
            (*count)--;
            
            printf("Movie deleted successfully!\n");
            break;
        }
    }
    
    if(!found)
    {
        printf("No movie found with that title.\n");
    }
}

// Function to display the collection of movies
void displayCollection(Movie *movies, int count)
{
    int i;
    printf("Movie Collection:\n");
    for(i=0; i<count; i++)
    {
        printf("%d. %s\n", i+1, movies[i].title);
    }
}

// Main function to run the program
int main()
{
    Movie *movies;
    int choice, count=0;
    
    // Allocate memory for 10 movies
    movies = (Movie*) malloc(10 * sizeof(Movie));

    do
    {
        printf("\n---------- Movie Rating System ----------\n");
        printf("1. Add a new movie to the collection\n");
        printf("2. Modify the details of a movie in the collection\n");
        printf("3. Delete a movie from the collection\n");
        printf("4. Display the details of a movie in the collection\n");
        printf("5. Display the collection of movies\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                modifyMovie(movies, count);
                break;
            case 3:
                deleteMovie(movies, &count);
                break;
            case 4:
                if(count == 0)
                {
                    printf("No movies in the collection.\n");
                }
                else
                {
                    char title[50];
                    int i, found = 0;
                    
                    printf("Enter the title of the movie to display: ");
                    scanf("%s", title);
                    
                    for(i=0; i<count; i++)
                    {
                        if(strcmp(movies[i].title, title) == 0)
                        {
                            found = 1;
                            display(movies[i]);
                            break;
                        }
                    }
                    
                    if(!found)
                    {
                        printf("No movie found with that title.\n");
                    }
                }
                break;
            case 5:
                if(count == 0)
                {
                    printf("No movies in the collection.\n");
                }
                else
                {
                    displayCollection(movies, count);
                }
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while(choice != 6);

    // Free the memory allocated for the movies
    free(movies);
    
    return 0;
}