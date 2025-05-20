//FormAI DATASET v1.0 Category: Movie Rating System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie {
    char title[50];
    char director[50];
    float rating;
};

int main() {
    struct movie m;
    float user_rating;
    char option[10];

    printf("Welcome to the Unique C Movie Rating System!\n");

    printf("Enter the title of the movie: ");
    fgets(m.title, 50, stdin);

    printf("Enter the name of the director of the movie: ");
    fgets(m.director, 50, stdin);

    printf("Enter your rating for the movie (out of 10): ");
    scanf("%f", &user_rating);
    
    //Check if the user_rating is within bounds
    while (user_rating > 10 || user_rating < 0){
        printf("Invalid rating. Please enter a rating between 0 and 10: ");
        scanf("%f", &user_rating);
    }

    m.rating = user_rating;
    printf("\nThank you for rating %s directed by %s with a rating of %.2f/10.\n", m.title, m.director, m.rating);

    //Ask if user wants to see current rating or update it
    printf("Enter 's' to see the current rating or 'u' to update the rating: ");
    fgets(option, 10, stdin);

    while (strcmp(option, "s\n") != 0 && strcmp(option, "u\n") != 0 ){
        printf("Invalid option. Please enter 's' to see the current rating or 'u' to update the rating: ");
        fgets(option, 10, stdin);
    }

    if (strcmp(option, "s\n") == 0){
        printf("\nThe current rating for %s directed by %s is %.2f/10.\n", m.title, m.director, m.rating);
    }else{
        printf("\nEnter new rating for the movie %s directed by %s: ", m.title, m.director);
        scanf("%f", &user_rating);
        
        while (user_rating > 10 || user_rating < 0){
            printf("Invalid rating. Please enter a rating between 0 and 10: ");
            scanf("%f", &user_rating);
        }

        m.rating = user_rating;
        printf("\nThe updated rating for %s directed by %s is %.2f/10.\n", m.title, m.director, m.rating);
    }

    return 0;
}