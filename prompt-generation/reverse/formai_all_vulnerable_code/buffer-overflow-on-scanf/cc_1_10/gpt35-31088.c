//FormAI DATASET v1.0 Category: Movie Rating System ; Style: all-encompassing
#include<stdio.h> //including standard input output header file
#include<string.h> //including header file for string manipulation

//Function to get the movie name from the user
void get_movie_name(char name[])
{
    printf("\nEnter the name of the movie: ");
    scanf("%[^\n]s", name);
}

//Function to get the release year of the movie from the user
int get_release_year()
{
    int year;
    printf("\nEnter the release year of the movie: ");
    scanf("%d", &year);
    return year;
}

//Function to get the genre of the movie from the user
void get_genre(char genre[])
{
    printf("\nEnter the genre of the movie: ");
    scanf("%s", genre);
}

//Function to get the rating of the movie from the user
float get_rating()
{
    float rating;
    printf("\nEnter the rating of the movie (out of 10): ");
    scanf("%f", &rating);
    return rating;
}

//Function to display the rating of the movie based on the C Movie Rating System
void display_rating(float rating)
{
    printf("\nRating: ");
    if(rating < 5)
        printf("Flop");
    else if(rating >= 5 && rating < 7)
        printf("Average");
    else if(rating >= 7 && rating < 9)
        printf("Hit");
    else
        printf("Blockbuster");
}

int main()
{
    char movie_name[100], genre[50];
    int release_year;
    float rating;

    printf("\n***** Welcome to the C Movie Rating System *****\n");

    //Get the movie details from the user
    get_movie_name(movie_name);
    release_year = get_release_year();
    get_genre(genre);
    rating = get_rating();

    //Display the movie details entered by the user
    printf("\nMovie Name: %s\nRelease Year: %d\nGenre: %s", movie_name, release_year, genre);
    display_rating(rating);

    return 0;
}