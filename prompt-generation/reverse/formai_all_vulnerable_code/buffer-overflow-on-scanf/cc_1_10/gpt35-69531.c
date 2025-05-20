//FormAI DATASET v1.0 Category: Movie Rating System ; Style: expert-level
#include <stdio.h>

/* Rating struct to store movie rating details */
typedef struct {
    char title[50];
    char genre[20];
    float rating;
} Rating;

/* Function to display movie ratings */
void displayRatings(Rating ratings[], int numRatings) {
    printf("\nMovie Ratings:\n");
    printf("Title \t\t Genre \t\t Rating\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < numRatings; i++) {
        printf("%s \t\t %s \t\t %.1f\n", ratings[i].title, ratings[i].genre, ratings[i].rating);
    }
    printf("---------------------------------------\n");
}

/* Function to add new movie rating */
void addRating(Rating ratings[], int numRatings) {
    printf("\nEnter details for new movie rating:\n");
    printf("Title: ");
    scanf("%s", ratings[numRatings].title);
    printf("Genre: ");
    scanf("%s", ratings[numRatings].genre);
    printf("Rating (out of 10): ");
    scanf("%f", &ratings[numRatings].rating);
}

/* Function to update movie rating */
void updateRating(Rating ratings[], int numRatings) {
    char title[50];
    printf("\nEnter title of movie to update: ");
    scanf("%s", title);
    for (int i = 0; i < numRatings; i++) {
        if (strcmp(ratings[i].title, title) == 0) {
            printf("Enter new rating (out of 10): ");
            scanf("%f", &ratings[i].rating);
            printf("Rating for %s has been updated!\n", title);
            return;
        }
    }
    printf("Movie rating for %s not found.\n", title);
}

/* Main function */
int main() {
    int choice, numRatings = 0;
    Rating ratings[100];

    /* Continuous loop until user chooses to exit */
    while (1) {
        printf("\nMovie Rating System\n");
        printf("1. Display all ratings\n");
        printf("2. Add new rating\n");
        printf("3. Update rating\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numRatings == 0) {
                    printf("\nNo movie ratings found!\n");
                } else {
                    displayRatings(ratings, numRatings);
                }
                break;
            case 2:
                addRating(ratings, numRatings);
                numRatings++;
                break;
            case 3:
                if (numRatings == 0) {
                    printf("\nNo movie ratings found!\n");
                } else {
                    updateRating(ratings, numRatings);
                }
                break;
            case 4:
                printf("\nExiting Movie Rating System...\n");
                return 0;
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}