//FormAI DATASET v1.0 Category: Movie Rating System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

struct movie{
    char title[50];
    char genre[20];
    int year;
    float rating[MAX_RATINGS];
    int num_ratings;
    float avg_rating;
};

struct movie movies[MAX_MOVIES];
int num_movies = 0;

// Function to add a new movie
void add_movie(){
    struct movie new_movie;
    printf("\nEnter movie title: ");
    scanf("%s", new_movie.title);
    printf("Enter movie genre: ");
    scanf("%s", new_movie.genre);
    printf("Enter movie year: ");
    scanf("%d", &new_movie.year);
    new_movie.avg_rating = 0.0;
    new_movie.num_ratings = 0;
    movies[num_movies] = new_movie;
    num_movies++;
}

// Function to add a rating to a movie
void rate_movie(){
    char movie_title[50];
    printf("\nEnter movie title: ");
    scanf("%s", movie_title);
    for(int i=0; i<num_movies; i++){
        if(strcmp(movies[i].title, movie_title) == 0){
            if(movies[i].num_ratings >= MAX_RATINGS){
                printf("Max number of ratings reached for this movie.\n");
                return;
            }
            printf("Enter rating (0-10): ");
            scanf("%f", &movies[i].rating[movies[i].num_ratings]);
            movies[i].num_ratings++;
            float sum_ratings = 0.0;
            for(int j=0; j<movies[i].num_ratings; j++){
                sum_ratings += movies[i].rating[j];
            }
            movies[i].avg_rating = sum_ratings / movies[i].num_ratings;
            printf("Rating added successfully!\n");
            return;
        }
    }
    printf("Movie not found. Please add the movie first.\n");
}

// Function to display all movies
void display_movies(){
    printf("\n");
    for(int i=0; i<num_movies; i++){
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Year: %d\n", movies[i].year);
        printf("Number of ratings: %d\n", movies[i].num_ratings);
        printf("Average rating: %.2f\n\n", movies[i].avg_rating);
    }
}

// Function to display top rated movies
void top_rated(){
    printf("\n");
    struct movie top_rated_movies[MAX_MOVIES];
    int num_top_rated = 0;
    float max_rating = 0.0;
    for(int i=0; i<num_movies; i++){
        if(movies[i].avg_rating > max_rating){
            max_rating = movies[i].avg_rating;
            memcpy(top_rated_movies, &movies[i], sizeof(struct movie));
            num_top_rated = 1;
        }
        else if(movies[i].avg_rating == max_rating){
            memcpy(&top_rated_movies[num_top_rated], &movies[i], sizeof(struct movie));
            num_top_rated++;
        }
    }
    if(num_top_rated == 0){
        printf("No movies found.\n");
    }
    else{
        printf("Top rated movies:\n");
        for(int i=0; i<num_top_rated; i++){
            printf("%d) Title: %s\n", i+1, top_rated_movies[i].title);
            printf("Genre: %s\n", top_rated_movies[i].genre);
            printf("Year: %d\n", top_rated_movies[i].year);
            printf("Average rating: %.2f\n\n", top_rated_movies[i].avg_rating);
        }
    }
}

// Main function
int main(){
    int choice;
    do{
        printf("-----------------------\n");
        printf("C Movie Rating System\n");
        printf("-----------------------\n");
        printf("1. Add movie\n");
        printf("2. Rate movie\n");
        printf("3. Display movies\n");
        printf("4. Top rated movies\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_movie();
                break;
            case 2:
                rate_movie();
                break;
            case 3:
                display_movies();
                break;
            case 4:
                top_rated();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }while(choice != 0);
    return 0;
}