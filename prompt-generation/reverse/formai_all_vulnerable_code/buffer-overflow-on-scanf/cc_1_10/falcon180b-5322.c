//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MOVIES 100
#define MAX_RATERS 1000
#define MAX_RATING 10
#define MIN_RATING 1
#define MAX_RATING 10

int main()
{
    int num_movies, num_raters, num_ratings;
    char movies[MAX_MOVIES][100];
    int ratings[MAX_RATERS][MAX_MOVIES];
    float avg_rating[MAX_MOVIES];
    int total_ratings[MAX_MOVIES];
    int i, j;

    printf("Happy Movie Rating System\n\n");

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    for(i=0; i<num_movies; i++)
    {
        printf("Enter the name of movie %d: ", i+1);
        scanf("%s", movies[i]);
    }

    printf("\nEnter the number of raters: ");
    scanf("%d", &num_raters);

    for(i=0; i<num_raters; i++)
    {
        printf("Enter the name of rater %d: ", i+1);
        scanf("%s", movies[i]);
    }

    for(i=0; i<num_movies; i++)
    {
        total_ratings[i] = 0;
        for(j=0; j<num_raters; j++)
        {
            printf("Enter the rating for movie %s by rater %s (1 to 10): ", movies[i], movies[j]);
            scanf("%d", &ratings[j][i]);
            total_ratings[i]++;
        }
    }

    for(i=0; i<num_movies; i++)
    {
        avg_rating[i] = 0;
        for(j=0; j<num_raters; j++)
        {
            avg_rating[i] += ratings[j][i];
        }
        avg_rating[i] /= total_ratings[i];
    }

    printf("\nMovie Ratings:\n");
    for(i=0; i<num_movies; i++)
    {
        printf("Movie: %s\n", movies[i]);
        printf("Average Rating: %.2f\n", avg_rating[i]);
        printf("\n");
    }

    return 0;
}