//FormAI DATASET v1.0 Category: Movie Rating System ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

int main(){
    //Welcome message
    printf("Welcome to the Unique C Movie Rating System!\n\n");

    //Variable declaration
    char movieName[50];
    float rating;
    int age, numOfViewers;

    //Ask for user input
    printf("Enter the movie name: ");
    fgets(movieName, 50, stdin); //fgets() is used to input string with spaces
    printf("Enter the age limit of the movie: ");
    scanf("%d", &age);
    printf("Enter the number of viewers who watched the movie: ");
    scanf("%d", &numOfViewers);

    //Calculate the average rating
    float totalRating = 0;
    for(int i=1; i<=numOfViewers; i++){
        printf("Enter the rating (out of 10) given by viewer %d: ", i);
        scanf("%f", &rating);
        totalRating += rating;
    }
    float avgRating = totalRating / numOfViewers;

    //Display the movie's information and rating
    printf("\n\n********** Movie Information **********\n\n");
    printf("Name: %s", movieName);
    printf("Age Limit: %d+\n", age);
    printf("Number of Viewers: %d\n", numOfViewers);
    printf("Average Rating: %.2f\n\n", avgRating);

    //Assign a rating based on the average rating
    char finalRating[10];
    if(avgRating >= 8){
        strcpy(finalRating, "Excellent");
    }
    else if(avgRating >= 6.5 && avgRating < 8){
        strcpy(finalRating, "Good");
    }
    else if(avgRating >= 5 && avgRating < 6.5){
        strcpy(finalRating, "Average");
    }
    else{
        strcpy(finalRating, "Poor");
    }

    //Display the final rating
    printf("********** Final Rating **********\n\n");
    printf("The final rating of the movie %s is %s\n", movieName, finalRating);

    return 0;
}