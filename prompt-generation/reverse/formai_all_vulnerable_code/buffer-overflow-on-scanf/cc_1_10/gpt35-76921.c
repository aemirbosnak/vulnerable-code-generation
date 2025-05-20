//FormAI DATASET v1.0 Category: Movie Rating System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

// Function to calculate the rating based on the reviews.
float calculateRating(int* reviews, int totalReviews){
    float rating = 0;
    for(int i=0; i<totalReviews; i++){
        rating += reviews[i];
    }
    rating /= totalReviews;
    return rating;
}

int main(){
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please enter the number of movies you want to rate: ");
    int numMovies;
    scanf("%d", &numMovies);

    int** reviews = (int**)malloc(numMovies * sizeof(int*)); // 2D array to store the reviews
    if(reviews == NULL){
        printf("Memory allocation failed!\n");
        return 0;
    }

    int* totalReviews = (int*)calloc(numMovies, sizeof(int)); // Array to store the total number of reviews per movie
    if(totalReviews == NULL){
        printf("Memory allocation failed!\n");
        free(reviews);
        return 0;
    }

    for(int i=0; i<numMovies; i++){
        printf("\nEnter the number of reviews for movie %d: ", i+1);
        scanf("%d", &totalReviews[i]);

        reviews[i] = (int*)calloc(totalReviews[i], sizeof(int)); // Allocating memory for reviews of the current movie
        if(reviews[i] == NULL){
            printf("Memory allocation failed!\n");
            for(int j=0; j<i; j++){
                free(reviews[j]); // Freeing the memory allocated before returning
            }
            free(reviews);
            free(totalReviews);
            return 0;
        }

        printf("\nEnter the individual ratings for movie %d:\n", i+1);
        for(int j=0; j<totalReviews[i]; j++){
            scanf("%d", &reviews[i][j]);
        }
    }

    printf("\n\n");

    float* ratings = (float*)malloc(numMovies * sizeof(float)); // Array to store the calculated ratings
    if(ratings == NULL){
        printf("Memory allocation failed!\n");
        for(int i=0; i<numMovies; i++){
            free(reviews[i]);
        }
        free(reviews);
        free(totalReviews);
        return 0;
    }

    for(int i=0; i<numMovies; i++){
        ratings[i] = calculateRating(reviews[i], totalReviews[i]); // Calculating the rating of the current movie
        printf("The rating of movie %d is %f\n", i+1, ratings[i]);
    }

    free(ratings);
    for(int i=0; i<numMovies; i++){
        free(reviews[i]);
    }
    free(reviews);
    free(totalReviews);

    printf("\nThank you for using the Unique C Movie Rating System!\n");
    return 0;
}