//FormAI DATASET v1.0 Category: Movie Rating System ; Style: real-life
#include<stdio.h>
#include<string.h>

//function to read movie details
void readDetails(int i, char title[50], char genre[20], char director[20], int year, float rating) {
    printf("\n Enter details of movie %d", i+1);
    printf("\n Title of the movie: ");
    scanf("%s", title);
    printf("Genre of the movie: ");
    scanf("%s", genre);
    printf("Director of the movie: ");
    scanf("%s", director);
    printf("Release year of the movie: ");
    scanf("%d", &year);
    printf("Rating of the movie (out of 10): ");
    scanf("%f", &rating);
}

//function to display movie details
void displayDetails(int i, char title[50], char genre[20], char director[20], int year, float rating) {
    printf("\n Details of movie %d", i+1);
    printf("\n Title: %s", title);
    printf("\n Genre: %s", genre);
    printf("\n Director: %s", director);
    printf("\n Release Year: %d", year);
    printf("\n Rating: %.1f\n", rating);
}

int main() {
    int choice, n, year;
    float rating;
    char title[50], genre[20], director[20];
    
    printf("****** Welcome to Movie Rating System ******\n\n");
    printf("How many movies do you want to rate? ");
    scanf("%d", &n);
    
    //creating array to store details of n movies
    char titles[n][50], genres[n][20], directors[n][20];
    int years[n];
    float ratings[n];
    
    //loop to read and store movie details
    for(int i=0; i<n; i++) {
        readDetails(i, title, genre, director, year, rating);
        strcpy(titles[i], title);
        strcpy(genres[i], genre);
        strcpy(directors[i], director);
        years[i] = year;
        ratings[i] = rating;
    }
    
    do {
        //displaying options
        printf("\n\nWhat do you want to do?\n");
        printf("1. Display all movie details\n");
        printf("2. Display movie details by genre\n");
        printf("3. Display top-rated movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: //displaying details of all movies
            printf("\n********** DETAILS OF ALL MOVIES **********\n");
            for(int i=0; i<n; i++) {
                displayDetails(i, titles[i], genres[i], directors[i], years[i], ratings[i]);
            }
            break;
            
            case 2: //displaying details of movies for particular genre
            printf("\nEnter genre of the movie: ");
            scanf("%s", genre);
            printf("\n********** DETAILS OF MOVIES WITH GENRE '%s' **********\n", genre);
            for(int i=0; i<n; i++) {
                if(strcmp(genres[i], genre) == 0) {
                    displayDetails(i, titles[i], genres[i], directors[i], years[i], ratings[i]);
                }
            }
            break;
            
            case 3: //displaying top-rated movies
            printf("\n********** TOP RATED MOVIES **********\n");
            int topIndex, flag;
            for(int k=1; k<=n; k++) {
                topIndex = -1; //initialize topIndex to -1
                flag = 0; //initialize flag to 0
                rating = -1; //initialize rating to -1
                
                for(int i=0; i<n; i++) {
                    if(ratings[i] > rating) {
                        //check if the movie has already been displayed as top-rated
                        for(int j=0; j<k; j++) {
                            if(i == topIndex) {
                                flag = 1;
                                break;
                            }
                        }
                        if(flag == 0) {
                            rating = ratings[i];
                            topIndex = i;
                        }
                    }
                }
                displayDetails(topIndex, titles[topIndex], genres[topIndex], 
                               directors[topIndex], years[topIndex], ratings[topIndex]);
            }
            break;
            
            case 4: //exiting the program
            printf("\nThank you for using Movie Rating System. Goodbye!\n");
            break;
            
            default: //handling invalid choice
            printf("\nInvalid choice! Please enter a valid choice.\n");
        }
    } while(choice != 4); //continue the loop until user chooses to exit
    
    return 0;
}