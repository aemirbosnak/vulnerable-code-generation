//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RATINGS 100
#define MAX_RATING_LENGTH 100
#define MAX_USER_LENGTH 50

struct rating {
    char user[MAX_USER_LENGTH];
    char movie[MAX_RATING_LENGTH];
    int rating;
};

int main() {
    struct rating ratings[MAX_RATINGS];
    int num_ratings = 0;
    char input[100];

    printf("Welcome to the Movie Rating System!\n\n");

    // Load ratings from file
    FILE *file = fopen("ratings.txt", "r");
    if (file == NULL) {
        printf("No ratings found. Please rate some movies.\n\n");
    } else {
        while (fgets(input, sizeof(input), file)!= NULL) {
            char user[MAX_USER_LENGTH];
            char movie[MAX_RATING_LENGTH];
            int rating;

            sscanf(input, "%s %s %d", user, movie, &rating);

            strcpy(ratings[num_ratings].user, user);
            strcpy(ratings[num_ratings].movie, movie);
            ratings[num_ratings].rating = rating;

            num_ratings++;
        }
        fclose(file);
    }

    // Main loop
    while (1) {
        printf("\nOptions:\n1. Rate a movie\n2. View ratings\n3. Exit\n");
        scanf("%d", &num_ratings);

        switch (num_ratings) {
        case 1:
            printf("Enter your name: ");
            scanf("%s", ratings[num_ratings].user);

            printf("Enter the movie name: ");
            scanf("%s", ratings[num_ratings].movie);

            printf("Enter the rating (1-5): ");
            scanf("%d", &ratings[num_ratings].rating);

            num_ratings++;
            break;

        case 2:
            printf("\nRatings:\n");
            for (int i = 0; i < num_ratings; i++) {
                printf("%s rated %s %d stars.\n", ratings[i].user, ratings[i].movie, ratings[i].rating);
            }
            break;

        case 3:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}