//FormAI DATASET v1.0 Category: Movie Rating System ; Style: minimalist
#include<stdio.h>

// Structure to store the movie details
struct movie{
    char title[50];
    int year;
    float rating;
};

int main(){

    // Declaration of variables
    int choice, count=0, i;
    float total_rating=0;
    float avg_rating=0;
    struct movie movies[10];

    while(1){
        // Displaying menu
        printf("\n************ Movie Rating System ************\n");
        printf("1. Add a movie\n2. Display all movies\n3. Calculate average rating\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                // Adding a movie
                printf("\nEnter the details of the movie\n");
                printf("Title: ");
                scanf("%s", movies[count].title);
                printf("Year: ");
                scanf("%d", &movies[count].year);
                printf("Rating: ");
                scanf("%f", &movies[count].rating);
                count++;
                break;
            }
            case 2:{
                // Displaying all movies
                if(count == 0){
                    printf("\nNo movies added yet!\n");
                }else{
                    printf("\n************ All Movies ************\n");
                    for(i=0; i<count; i++){
                        printf("Title: %s\n", movies[i].title);
                        printf("Year: %d\n", movies[i].year);
                        printf("Rating: %.1f\n\n", movies[i].rating);
                    }
                }
                break;
            }
            case 3:{
                // Calculating average rating
                if(count == 0){
                    printf("\nNo movies added yet!\n");
                }else{
                    for(i=0; i<count; i++){
                        total_rating += movies[i].rating;
                    }
                    avg_rating = total_rating / count;
                    printf("\nAverage Rating: %.2f\n", avg_rating);
                }
                break;
            }
            case 4:{
                // Exiting the program
                printf("\n************ Exiting Movie Rating System ************\n");
                exit(0);
            }
            default:{
                // Handling invalid choice
                printf("\nInvalid choice! Please select a valid choice.\n");
                break;
            }
        }
    }

    return 0;
}