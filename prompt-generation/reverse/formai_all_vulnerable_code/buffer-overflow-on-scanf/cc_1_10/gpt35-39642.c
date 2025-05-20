//FormAI DATASET v1.0 Category: Movie Rating System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to hold movie information
struct movie{
    char name[30];
    char director[30];
    int releaseYear;
    float rating;
};

//Function to get the user input for the movie details
void getMovieDetails(struct movie *m){
    printf("Enter movie name: ");
    scanf("%[^\n]%*c", m->name);
    printf("Enter director name: ");
    scanf("%[^\n]%*c", m->director);
    printf("Enter release year: ");
    scanf("%d", &m->releaseYear);
    printf("Enter movie rating: ");
    scanf("%f", &m->rating);
}

//Function to display the movie details
void showMovieDetails(struct movie *m){
    printf("\nName: %s\n", m->name);
    printf("Director: %s\n", m->director);
    printf("Release year: %d\n", m->releaseYear);
    printf("Rating: %.1f\n", m->rating);
}

//Function to rate the movie
void rateMovie(struct movie *m){
    float rating;
    printf("\nEnter new rating for the movie: ");
    scanf("%f", &rating);
    m->rating = rating;
}

int main(){
    int i, n, choice, index;
    float totalRating = 0, avgRating;
    printf("Enter the number of movies: ");
    scanf("%d", &n);
    struct movie *movies = (struct movie*) malloc(n * sizeof(struct movie));
    for(i=0; i<n; i++){
        printf("\nEnter details of movie %d:\n", i+1);
        getMovieDetails(&movies[i]);
        totalRating += movies[i].rating;
    }
    avgRating = totalRating/n;
    printf("\nAverage rating of all the movies: %.1f", avgRating);

    do{
        printf("\n\nSelect an option:\n1. Display movie details\n2. Rate a movie\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter movie index to display details: ");
                scanf("%d", &index);
                if(index>=1 && index<=n){
                    showMovieDetails(&movies[index-1]);
                }
                else{
                    printf("\nInvalid index. Please choose an index between 1 and %d.", n);
                }
                break;
            case 2:
                printf("\nEnter movie index to rate: ");
                scanf("%d", &index);
                if(index>=1 && index<=n){
                    rateMovie(&movies[index-1]);
                    totalRating = 0;
                    for(i=0; i<n; i++){
                        totalRating += movies[i].rating;
                    }
                    avgRating = totalRating/n;
                    printf("\nAverage rating of all the movies after rating: %.1f", avgRating);
                }
                else{
                    printf("\nInvalid index. Please choose an index between 1 and %d.", n);
                }
                break;
            case 3:
                printf("\nThank you for using this movie rating system!");
                break;
            default:
                printf("\nInvalid choice. Please select again.");
        }
    }while(choice!=3);

    free(movies); //Free the allocated memory
    return 0;
}