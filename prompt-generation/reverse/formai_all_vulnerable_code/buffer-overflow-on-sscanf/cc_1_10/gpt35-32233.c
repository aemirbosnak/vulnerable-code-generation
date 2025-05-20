//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>

// define constants
#define MAX_MOVIES 10
#define MAX_RATINGS 5

// function to prompt user for ratings and return the average
float get_average_rating(char movie_title[]) {
    int rating_count[MAX_RATINGS] = {0}; // initialize count of each rating to 0
    int total_ratings = 0; // initialize total number of ratings to 0
    
    printf("Rate the movie \"%s\" on a scale of 1-5:\n", movie_title);
    
    // loop through input and increment count of each rating
    char input;
    while ((input = getchar()) != '\n') {
        if (input >= '1' && input <= '5') {
            rating_count[input - '1']++;
            total_ratings++;
        }
    }
    
    float sum = 0;
    for (int i = 0; i < MAX_RATINGS; i++) {
        sum += (i+1) * rating_count[i];
    }
    
    if (total_ratings > 0) {
        return sum / total_ratings;
    } else {
        return 0.0;
    }
}

int main() {
    char movie_titles[MAX_MOVIES][50];
    float movie_ratings[MAX_MOVIES] = {0};
    
    printf("Welcome to the C Movie Rating System!\n");
    printf("Please enter up to %d movie titles:\n", MAX_MOVIES);
    
    // loop through input and add each title to array
    char title[50];
    for (int i = 0; i < MAX_MOVIES; i++) {
        fgets(title, 50, stdin);
        if (title[0] == '\n') {
            break;
        }
        sscanf(title, "%[^\n]", movie_titles[i]);
    }
    
    printf("Thank you! Now let's rate some movies!\n");
    
    // loop through each movie and prompt user for ratings
    for (int i = 0; i < MAX_MOVIES; i++) {
        if (movie_titles[i][0] == '\0') {
            break;
        }
        printf("\n");
        movie_ratings[i] = get_average_rating(movie_titles[i]);
        printf("\"%s\" received an average rating of %.1f\n", movie_titles[i], movie_ratings[i]);
    }
    
    printf("\nHere are the final ratings for all %d movies:\n", MAX_MOVIES);
    
    // loop through each movie and print its title and rating
    for (int i = 0; i < MAX_MOVIES; i++) {
        if (movie_titles[i][0] == '\0') {
            break;
        }
        printf("\"%s\": %.1f\n", movie_titles[i], movie_ratings[i]);
    }
    
    return 0;
}