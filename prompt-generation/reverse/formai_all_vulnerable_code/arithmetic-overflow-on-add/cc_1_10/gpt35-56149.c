//FormAI DATASET v1.0 Category: Movie Rating System ; Style: introspective
#include<stdio.h>
#include<string.h>

// Function to calculate the rating based on user input
int calculateRating(int acting, int storyline, int direction, int music){
    return acting + storyline + direction + music;
}

// Function to display the movie rating based on the rating number
void displayRating(int rating){
    if(rating >= 90){
        printf("The movie rating is: A+\n");
    }else if(rating >= 80 && rating < 90){
        printf("The movie rating is: A\n");
    }else if(rating >= 70 && rating < 80){
        printf("The movie rating is: B+\n");
    }else if(rating >= 60 && rating < 70){
        printf("The movie rating is: B\n");
    }else if(rating >= 50 && rating < 60){
        printf("The movie rating is: C+\n");
    }else{
        printf("The movie rating is: C\n");
    }
}

int main(){

    int acting, storyline, direction, music;

    printf("Welcome to the Unique C Movie Rating System!\n\n");

    printf("Please rate the acting of the movie (0-10): ");
    scanf("%d", &acting);

    printf("Please rate the storyline of the movie (0-10): ");
    scanf("%d", &storyline);

    printf("Please rate the direction of the movie (0-10): ");
    scanf("%d", &direction);

    printf("Please rate the music and sound of the movie (0-10): ");
    scanf("%d", &music);

    int rating = calculateRating(acting, storyline, direction, music);
    displayRating(rating);

    printf("\nThank you for using the Unique C Movie Rating System!");

    return 0;
}