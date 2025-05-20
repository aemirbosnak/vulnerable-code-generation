//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

// Struct for Movie
struct Movie{
    char title[100];
    int year;
    char genre[50];
    float rating;
};

// Display movie details
void displayMovie(struct Movie movie)
{
    printf("\nTitle: %s", movie.title);
    printf("\nYear: %d", movie.year);
    printf("\nGenre: %s", movie.genre);
    printf("\nRating: %.2f", movie.rating);
}

// Add new movie
void addMovie(struct Movie movie[], int *count)
{
    printf("\nEnter the movie title: ");
    scanf("%[^\n]s", movie[*count].title);
    printf("\nEnter the release year: ");
    scanf("%d", &movie[*count].year);
    printf("\nEnter the genre: ");
    scanf("%s", movie[*count].genre);
    printf("\nEnter the rating (out of 5): ");
    scanf("%f", &movie[*count].rating);
    (*count)++;
}

// List all movies
void listMovies(struct Movie movie[], int count)
{
    for(int i=0;i<count;i++){
        displayMovie(movie[i]);
        printf("\n-------------------------");
    }
}

// Filter movies based on genre
void filterMoviesByGenre(struct Movie movie[], int count, char genre[])
{
    int found=0;
    for(int i=0;i<count;i++){
        if(strcmp(movie[i].genre, genre) == 0){
            displayMovie(movie[i]);
            printf("\n-------------------------");
            found++;
        }
    }
    if(found==0){
        printf("\nNo movies found in the %s genre.",genre);
    }
}

// Rate a movie
void rateMovie(struct Movie movie[], int count, char title[])
{
    int found=0;
    for(int i=0;i<count;i++){
        if(strcmp(movie[i].title, title) == 0){
            printf("\nEnter your rating for %s (out of 5): ",title);
            scanf("%f",&movie[i].rating);
            found++;
            printf("\nThank you for rating %s!",title);
        }
    }
    if(found==0){
        printf("\nMovie not found!");
    }
}

// Main function
int main()
{
    int choice, count=0;
    struct Movie movie[100];
    char genre[50], title[100];

    do{
        // Display menu
        printf("\n-----------------------------------------------------");
        printf("\nWelcome to the C Movie Rating System");
        printf("\n-----------------------------------------------------");
        printf("\n1. Add New Movie");
        printf("\n2. List All Movies");
        printf("\n3. Filter Movies By Genre");
        printf("\n4. Rate a Movie");
        printf("\n5. Exit");
        printf("\n-----------------------------------------------------");
        printf("\nEnter your choice (1-5): ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                addMovie(movie, &count);
                break;
            case 2:
                listMovies(movie, count);
                break;
            case 3:
                printf("\nEnter the genre you want to filter: ");
                scanf("%s", genre);
                filterMoviesByGenre(movie, count, genre);
                break;
            case 4:
                printf("\nEnter the title of the movie you want to rate: ");
                scanf("%s", title);
                rateMovie(movie, count, title);
                break;
            case 5:
                printf("\nThank you for using the C Movie Rating System!");
                break;
            default:
                printf("\nInvalid choice! Please try again.");
                break;
        }
    }while(choice!=5);
    return 0;
}