//FormAI DATASET v1.0 Category: Movie Rating System ; Style: retro
#include<stdio.h>
#include<string.h>

const int MAX_RATINGS = 1000;

struct Movie{
    char title[50];
    char genre[20];
    int year;
    int ratingCount;
    double ratingTotal;
};

void addRating(struct Movie movies[], int index){
    int newRating;
    printf("Enter rating (0-10): ");
    scanf("%d", &newRating);
    if(newRating<0 || newRating > 10){
        printf("\nInvalid rating entered!\n");
    }
    else{
        movies[index].ratingCount++;
        movies[index].ratingTotal += newRating;
        printf("\nRating successfully added!\n");
    }
}

void displayMovies(struct Movie movies[], int count){
    printf("\n%-30s%-20s%-10s%-10s%-10s\n\n", "Title", "Genre", "Year", "Ratings", "Avg. Rating");
    for(int i=0; i<count; i++){
        double avgRating = 0.0;
        if(movies[i].ratingCount!=0){
            avgRating = movies[i].ratingTotal/movies[i].ratingCount;
        }
        printf("%-30s%-20s%-10d%-10d%.2f\n", movies[i].title, movies[i].genre, movies[i].year, movies[i].ratingCount, avgRating);
    }
}

void displayMenu(){
    printf("\n\n** Retro Movie Rating System **\n\n");
    printf("1. Enter rating for a movie\n");
    printf("2. View movie list with ratings\n");
    printf("3. Exit\n");
}

int main(){
    struct Movie movies[MAX_RATINGS];
    int count = 0;
    int choice;
    do{
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: {
                char title[50], genre[20];
                int year;
                printf("\nEnter movie title: ");
                scanf(" %[^\n]s", title);
                printf("\nEnter movie genre: ");
                scanf(" %[^\n]s", genre);
                printf("\nEnter movie year: ");
                scanf("%d", &year);
                strcpy(movies[count].title, title);
                strcpy(movies[count].genre, genre);
                movies[count].year = year;
                movies[count].ratingCount = 0;
                movies[count].ratingTotal = 0;
                addRating(movies, count);
                count++;
                break;
            }
            case 2: {
                displayMovies(movies, count);
                break;
            }
            case 3: {
                printf("\n\nGoodbye!\n");
                break;
            }
            default: {
                printf("\n\nInvalid choice entered!\n");
                break;
            }
        }
    }while(choice!=3);
    return 0;
}