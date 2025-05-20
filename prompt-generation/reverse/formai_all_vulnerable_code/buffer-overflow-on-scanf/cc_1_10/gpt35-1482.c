//FormAI DATASET v1.0 Category: Movie Rating System ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_MOVIES 100

typedef struct {
    char movieName[50];
    char director[50];
    float rating;
}Movie;

Movie movies[MAX_MOVIES];
int numberOfMovies = 0;

void addMovie(){
    Movie newMovie;
    printf("Enter the movie name: ");
    scanf("%s", newMovie.movieName);
    printf("Enter the movie director: ");
    scanf("%s", newMovie.director);
    printf("Enter the movie rating (out of 10): ");
    scanf("%f", &newMovie.rating);
    if(numberOfMovies < MAX_MOVIES){
        movies[numberOfMovies++] = newMovie;
        printf("Movie added successfully!\n");
    }else{
        printf("Sorry, maximum number of movies reached!\n");
    }
}

void displayMovies(){
    if(numberOfMovies == 0){
        printf("No movies added yet!\n");
    }else{
        printf("Movies List\n");
        printf("---------------------------------------------------------------------------------\n");
        printf("S.no     Name                  Director                      Rating(out of 10)\n");
        printf("---------------------------------------------------------------------------------\n");
        for(int i=0; i<numberOfMovies; i++){
            printf("%-10d%-22s%-30s%.2f\n", i+1, movies[i].movieName, movies[i].director, movies[i].rating);
        }
    }
}

void searchMovieByName(){
    char searchName[50];
    printf("Enter the name of the movie you want to search: ");
    scanf("%s", searchName);
    int flag = 0;
    for(int i=0; i<numberOfMovies; i++){
        if(strcmp(searchName, movies[i].movieName) == 0){
            printf("Movie found!\n");
            printf("Name: %s\nDirector: %s\nRating: %.2f\n", movies[i].movieName, movies[i].director, movies[i].rating);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Movie not found!\n");
    }
}

void searchMovieByRating(){
    float searchRating;
    printf("Enter the rating of the movie you want to search: ");
    scanf("%f", &searchRating);
    int flag = 0;
    for(int i=0; i<numberOfMovies; i++){
        if(searchRating == movies[i].rating){
            printf("Movie found!\n");
            printf("Name: %s\nDirector: %s\nRating: %.2f\n", movies[i].movieName, movies[i].director, movies[i].rating);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("No movie found with this rating!\n");
    }
}

void deleteMovie(){
    int sNo;
    printf("Enter the serial number of the movie you want to delete: ");
    scanf("%d", &sNo);
    if(sNo <= numberOfMovies && sNo > 0){
        numberOfMovies--;
        for(int i=sNo-1; i<numberOfMovies; i++){
            movies[i] = movies[i+1];
        }
        printf("Movie deleted successfully!\n");
    }else{
        printf("Invalid serial number!\n");
    }
}

void editMovie(){
    int sNo;
    printf("Enter the serial number of the movie you want to edit: ");
    scanf("%d", &sNo);
    if(sNo <= numberOfMovies && sNo > 0){
        printf("Enter the new movie name: ");
        scanf("%s", movies[sNo-1].movieName);
        printf("Enter the new director name: ");
        scanf("%s", movies[sNo-1].director);
        printf("Enter the new rating (out of 10): ");
        scanf("%f", &movies[sNo-1].rating);
        printf("Movie edited successfully!\n");
    }else{
        printf("Invalid serial number!\n");
    }
}

int main(){
    int choice;
    while(1){
        printf("\nMovie Rating System\n");
        printf("---------------------\n");
        printf("1. Add movie\n");
        printf("2. Display all movies\n");
        printf("3. Search movie by name\n");
        printf("4. Search movie by rating\n");
        printf("5. Delete movie\n");
        printf("6. Edit movie\n");
        printf("7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: addMovie();
                    break;
            case 2: displayMovies();
                    break;
            case 3: searchMovieByName();
                    break;
            case 4: searchMovieByRating();
                    break;
            case 5: deleteMovie();
                    break;
            case 6: editMovie();
                    break;
            case 7: exit(0);
            default: printf("\nInvalid choice. Please try again...");
        }
    }
    return 0;
}