//FormAI DATASET v1.0 Category: Movie Rating System ; Style: retro
#include<stdio.h>

// Function to display the menu
void showMenu(){
    printf("------------MOVIE RATINGS------------\n\n");
    printf("1. Add a movie and its rating\n");
    printf("2. View ratings\n");
    printf("3. Search for a movie\n");
    printf("4. Exit\n");
}

// Function to add a movie and its rating
void addMovie(char movies[][25], int ratings[], int *count){
    char movieName[25];
    int rating;
    
    printf("Enter the name of the movie: ");
    scanf(" %[^\n]", movieName);
    
    printf("Enter the rating (1-10) for the movie: ");
    scanf("%d", &rating);
    
    // Add the movie to the list
    strcpy(movies[*count], movieName);
    ratings[*count] = rating;
    (*count)++;
    
    printf("\n%s has been added with a rating of %d.\n\n", movieName, rating);
}

// Function to view all the ratings
void viewRatings(char movies[][25], int ratings[], int count){
    printf("\n     MOVIE          RATING\n");
    printf("----------------------------\n");
    for(int i=0;i<count;i++){
        printf("%d.   %-20s%d\n", i+1, movies[i], ratings[i]);
    }
    printf("\n");
}

// Function to search for a movie
void searchMovie(char movies[][25], int ratings[], int count){
    char movieName[25];
    printf("Enter the name of the movie to search: ");
    scanf(" %[^\n]", movieName);
    
    int found = 0;
    for(int i=0;i<count;i++){
        if(strcmp(movies[i], movieName) == 0){
            found = 1;
            printf("\n%s has a rating of %d.\n\n", movieName, ratings[i]);
            break;
        }
    }
    
    if(!found){
        printf("\n%s was not found.\n\n", movieName);
    }
}

int main(){
    char movies[50][25];
    int ratings[50];
    int count=0;
    
    int choice;
    
    do{
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                addMovie(movies, ratings, &count);
                break;
            case 2:
                viewRatings(movies, ratings, count);
                break;
            case 3:
                searchMovie(movies, ratings, count);
                break;
            case 4:
                printf("\nGoodbye!\n\n");
                break;
            default:
                printf("\nInvalid choice!\n\n");
        }
    
    }while(choice != 4);
    
    return 0;
}