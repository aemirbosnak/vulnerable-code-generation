//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
    printf("Welcome to the C Movie Rating System!\n");
    printf("Please rate the following movies from 0-10\n");
    
    // Movie ratings
    float matrix_rating, fight_club_rating, pulp_fiction_rating, inception_rating, godfather_rating, shawshank_rating, star_wars_rating, jurassic_park_rating;
    
    // Get movie ratings from user
    printf("The Matrix: ");
    scanf("%f", &matrix_rating);
    
    printf("Fight Club: ");
    scanf("%f", &fight_club_rating);
    
    printf("Pulp Fiction: ");
    scanf("%f", &pulp_fiction_rating);
    
    printf("Inception: ");
    scanf("%f", &inception_rating);
    
    printf("The Godfather: ");
    scanf("%f", &godfather_rating);
    
    printf("The Shawshank Redemption: ");
    scanf("%f", &shawshank_rating);
    
    printf("Star Wars: ");
    scanf("%f", &star_wars_rating);
    
    printf("Jurassic Park: ");
    scanf("%f", &jurassic_park_rating);
    
    // Calculate average rating
    float average_rating = (matrix_rating + fight_club_rating + pulp_fiction_rating + inception_rating + godfather_rating + shawshank_rating + star_wars_rating + jurassic_park_rating) / 8.0;
    
    // Display rating results
    printf("\nThe average movie rating is: %f\n", average_rating);
    
    if (average_rating >= 8.0) {
        printf("Wow, great movies!");
    } else if (average_rating >= 6.0) {
        printf("Some decent movies in there.");
    } else {
        printf("Maybe you need to watch more movies.");
    }
    
    return 0;
}