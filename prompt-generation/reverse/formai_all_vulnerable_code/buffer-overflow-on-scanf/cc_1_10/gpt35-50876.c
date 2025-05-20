//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include<stdio.h>
#include<ctype.h>
#include<string.h>

// Romeo and Juliet inspired C Movie Rating System

void display_menu(){
    printf("\n ******* C Movie Rating System ******* \n\n");
    printf("1. Rate a movie \n");
    printf("2. View movies by rating \n");
    printf("3. Exit system \n\n");
}

void rate_movie(char movies[][50], int ratings[], int *count){
    char title[50];
    int rating;
    int found = 0;
    
    printf("Enter movie title: ");
    scanf(" %s", title);
    
    for(int i=0; i<*count; i++){
        if(strcmp(movies[i], title) == 0){
            printf("\nYou have already rated this movie!\n");
            found = 1;
            break;
        }
    }
    
    if(found == 0){
        printf("Enter your rating (1-10): ");
        scanf("%d", &rating);
        
        while(rating < 1 || rating > 10){
            printf("Invalid rating! Please enter a rating between 1-10: ");
            scanf("%d", &rating);
        }
        
        int i = *count;
        ratings[i] = rating;
        strcpy(movies[i], title);
        *count += 1;
        
        printf("\nThank you for rating %s!\n", title);
    }
}

void view_movies(char movies[][50], int ratings[], int count){
    if(count == 0){
        printf("\nNo movies rated yet!\n");
        return;
    }
    
    int sorted[count];
    int temp_ratings[count];
    char temp_movies[count][50];
    
    for(int i=0; i<count; i++){
        sorted[i] = i;
        temp_ratings[i] = ratings[i];
        strcpy(temp_movies[i], movies[i]);
    }
    
    for(int i=0; i<count-1; i++){
        for(int j=i+1; j<count; j++){
            if(temp_ratings[i] < temp_ratings[j]){
                int temp = temp_ratings[i];
                temp_ratings[i] = temp_ratings[j];
                temp_ratings[j] = temp;
                
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }
    
    printf("\n***** Movies by Rating *****\n\n");
    for(int i=0; i<count; i++){
        printf("%d. %s (%d)\n", i+1, temp_movies[sorted[i]], temp_ratings[i]);
    }
}

int main(){
    char movies[100][50];
    int ratings[100];
    int count = 0;
    int choice;
    
    printf("Welcome to the C Movie Rating System!\n");
    
    do{
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                rate_movie(movies, ratings, &count);
                break;
            case 2:
                view_movies(movies, ratings, count);
                break;
            case 3:
                printf("\nThank you for using the C Movie Rating System!");
                break;
            default:
                printf("\nInvalid choice! Please choose again.\n");
        }
    }while(choice != 3);
    
    return 0;
}