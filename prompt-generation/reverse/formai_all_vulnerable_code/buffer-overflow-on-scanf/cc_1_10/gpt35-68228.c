//FormAI DATASET v1.0 Category: Movie Rating System ; Style: creative
#include<stdio.h>
#include<stdlib.h>

//Function to display the menu
void displayMenu(){
    printf("---------Welcome to C Movie Rating System---------\n");
    printf("1. Add a movie to the database\n");
    printf("2. Rate a movie\n");
    printf("3. Find the highest rated movie\n");
    printf("4. Find the lowest rated movie\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

//The structure for the movie database
struct movie{
    char title[50];
    char genre[50];
    float rating;
}movies[10];

//Function to add movie details to the database
void addMovie(int movieCount){
    printf("\nEnter the movie title: ");
    scanf("%s", movies[movieCount].title);
    printf("Enter the genre: ");
    scanf("%s", movies[movieCount].genre);
    printf("Enter the rating (out of 10): ");
    scanf("%f", &movies[movieCount].rating);
    printf("\nMovie successfully added to the database!\n\n");
}

//Function to rate a movie
void rateMovie(int movieCount){
    char movieTitle[50];
    int flag=0;
    printf("\nEnter the title of the movie: ");
    scanf("%s", movieTitle);
    for(int i=0;i<movieCount;i++){
        if(strcmp(movieTitle,movies[i].title)==0){
            flag=1;
            printf("Enter your rating for the movie (out of 10): ");
            float rating;
            scanf("%f", &rating);
            rating=(rating+movies[i].rating)/2;
            movies[i].rating=rating;
            printf("\nThank you for rating the movie!\n\n");
        }
    }
    if(flag==0) printf("\nThe requested movie is not in the database!\n\n");
}

//Function to find the highest rated movie
void highestRatedMovie(int movieCount){
    float maxRating=0;
    int index;
    for(int i=0;i<movieCount;i++){
        if(movies[i].rating>maxRating){
            maxRating=movies[i].rating;
            index=i;
        }
    }
    printf("\nThe highest rated movie is: %s with a rating of %.2f.\n\n", movies[index].title, movies[index].rating);
}

//Function to find the lowest rated movie
void lowestRatedMovie(int movieCount){
    float minRating=10;
    int index;
    for(int i=0;i<movieCount;i++){
        if(movies[i].rating<minRating){
            minRating=movies[i].rating;
            index=i;
        }
    }
    printf("\nThe lowest rated movie is: %s with a rating of %.2f.\n\n", movies[index].title, movies[index].rating);
}

int main(){
    int movieCount=0, choice;
    while(1){
        displayMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(movieCount<10) addMovie(movieCount++);
                else printf("\nSorry, the database is full!\n\n");
                break;
            case 2:
                if(movieCount==0) printf("\nThe database is empty! Please add a movie.\n\n");
                else rateMovie(movieCount);
                break;
            case 3:
                if(movieCount==0) printf("\nThe database is empty! Please add a movie.\n\n");
                else highestRatedMovie(movieCount);
                break;
            case 4:
                if(movieCount==0) printf("\nThe database is empty! Please add a movie.\n\n");
                else lowestRatedMovie(movieCount);
                break;
            case 5:
                printf("\nThank you for using C Movie Rating System! Goodbye.\n\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    }
    return 0;
}