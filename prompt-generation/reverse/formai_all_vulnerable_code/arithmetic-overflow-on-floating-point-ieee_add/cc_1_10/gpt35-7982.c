//FormAI DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

//Function to calculate and return the rating of a movie
float get_rating(float, float, float, float);

int main()
{
    float plot, acting, visuals, sound;  //Variables to store user input ratings
    float rating;   //Variable to store overall rating of the movie

    //Welcome message to the user
    printf("Welcome to the Post-Apocalyptic C Movie Rating System!\n\n");

    //User Input Section
    printf("Please rate the following aspects of the movie on a scale of 1 to 10:\n");
    printf("Plot: ");
    scanf("%f", &plot);
    printf("Acting: ");
    scanf("%f", &acting);
    printf("Visuals: ");
    scanf("%f", &visuals);
    printf("Sound: ");
    scanf("%f", &sound);

    //Calculate rating using the get_rating function
    rating = get_rating(plot, acting, visuals, sound);

    //Output Section
    printf("\n\nThe overall rating for the movie is: %.2f\n\n", rating);

    //Based on the rating, provide a recommendation to the user
    if(rating >= 8)
    {
        printf("This movie is a must-watch!\n");
    }
    else if(rating >= 6.5 && rating < 8)
    {
        printf("This movie is definitely worth watching!\n");
    }
    else if(rating >= 5 && rating < 6.5)
    {
        printf("This movie is mediocre, watch at your own risk!\n");
    }
    else
    {
        printf("This movie is a disaster, stay away!\n");
    }

    return 0;
}

//Function to calculate and return the rating of a movie
float get_rating(float plot, float acting, float visuals, float sound)
{
    float rating;

    rating = ((plot * 2) + acting + visuals + (sound * 1.5)) / 5.5;

    return rating;
}