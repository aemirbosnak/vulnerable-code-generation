//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Struct to store the movie details
struct Movie {
    char title[50];
    char genre[20];
    int year;
    float rating;
};
int main() {
    int num;
    printf("Enter the number of movies to be rated: ");
    scanf("%d", &num);
    //Dynamically allocate memory for the movies
    struct Movie* ptr = (struct Movie*) malloc(num * sizeof(struct Movie));
    //Get input from user for each movie
    for(int i = 0; i < num; i++) {
        printf("\nEnter details for Movie %d:\n", i+1);
        printf("Title: ");
        scanf(" %[^\n]", ptr[i].title);
        printf("Genre: ");
        scanf(" %[^\n]", ptr[i].genre);
        printf("Year: ");
        scanf("%d", &ptr[i].year);
        printf("Rating (Out of 10): ");
        scanf("%f", &ptr[i].rating);
    }
    //Print the Movie details
    printf("\n\nMovie Details:\n\n");
    printf("Title\t\tGenre\t\tYear\t\tRating\n");
    for(int i = 0; i < num; i++) {
        printf("%s\t\t%s\t\t%d\t\t%.1f\n", ptr[i].title, ptr[i].genre, ptr[i].year, ptr[i].rating);
    }
    //Ask user for required rating threshold
    float threshold;
    printf("\n\nEnter your required rating threshold (Out of 10): ");
    scanf("%f", &threshold);
    //Print list of movies that satisfy the threshold condition
    printf("The following movies have a rating above %.1f:\n", threshold);
    printf("Title\t\tGenre\t\tYear\t\tRating\n");
    for(int i = 0; i < num; i++) {
        if(ptr[i].rating >= threshold) {
            printf("%s\t\t%s\t\t%d\t\t%.1f\n", ptr[i].title, ptr[i].genre, ptr[i].year, ptr[i].rating);
        }
    }
    //Free the dynamically allocated memory
    free(ptr);
    return 0;
}