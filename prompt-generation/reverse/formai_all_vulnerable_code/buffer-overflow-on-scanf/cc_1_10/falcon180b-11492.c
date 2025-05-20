//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 5
#define MAX_RATING_LENGTH 20

struct rating {
    char critic[MAX_RATING_LENGTH];
    char review[MAX_RATING_LENGTH];
    int score;
};

int main() {
    struct rating ratings[MAX_RATINGS];
    int num_ratings = 0;
    char movie_name[MAX_RATING_LENGTH];
    char critic_name[MAX_RATING_LENGTH];
    int score;

    printf("Enter the name of the movie: ");
    scanf("%s", movie_name);

    while(1) {
        printf("\nEnter critic name and rating (or type 'done'): ");
        scanf("%s", critic_name);

        if(strcmp(critic_name, "done") == 0) {
            break;
        }

        printf("Enter critic's rating (out of 10): ");
        scanf("%d", &score);

        strcpy(ratings[num_ratings].critic, critic_name);
        strcpy(ratings[num_ratings].review, "");
        ratings[num_ratings].score = score;

        num_ratings++;
    }

    printf("\nMovie: %s\n", movie_name);
    printf("Ratings:\n");

    for(int i=0; i<num_ratings; i++) {
        printf("%s - %d\n", ratings[i].critic, ratings[i].score);
    }

    return 0;
}