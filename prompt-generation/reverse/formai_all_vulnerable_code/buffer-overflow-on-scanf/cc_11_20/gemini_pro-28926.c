//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include <stdio.h>

// Define the rating categories
#define EXCELLENT 5
#define GOOD 4
#define AVERAGE 3
#define BELOW_AVERAGE 2
#define POOR 1

// Define the movie genres
#define ACTION 1
#define COMEDY 2
#define DRAMA 3
#define HORROR 4
#define ROMANCE 5
#define SCI_FI 6

// Define the age ratings
#define G 1
#define PG 2
#define PG_13 3
#define R 4
#define NC_17 5

// Get the user's input
int main() {
    int rating;
    int genre;
    int age_rating;

    printf("Enter the rating (1-5): ");
    scanf("%d", &rating);

    printf("Enter the genre (1-6): ");
    scanf("%d", &genre);

    printf("Enter the age rating (1-5): ");
    scanf("%d", &age_rating);

    // Print the movie rating
    switch (rating) {
        case EXCELLENT:
            printf("Excellent movie!\n");
            break;
        case GOOD:
            printf("Good movie.\n");
            break;
        case AVERAGE:
            printf("Average movie.\n");
            break;
        case BELOW_AVERAGE:
            printf("Below average movie.\n");
            break;
        case POOR:
            printf("Poor movie.\n");
            break;
        default:
            printf("Invalid rating.\n");
    }

    // Print the movie genre
    switch (genre) {
        case ACTION:
            printf("Action movie.\n");
            break;
        case COMEDY:
            printf("Comedy movie.\n");
            break;
        case DRAMA:
            printf("Drama movie.\n");
            break;
        case HORROR:
            printf("Horror movie.\n");
            break;
        case ROMANCE:
            printf("Romance movie.\n");
            break;
        case SCI_FI:
            printf("Sci-fi movie.\n");
            break;
        default:
            printf("Invalid genre.\n");
    }

    // Print the movie age rating
    switch (age_rating) {
        case G:
            printf("G-rated movie.\n");
            break;
        case PG:
            printf("PG-rated movie.\n");
            break;
        case PG_13:
            printf("PG-13-rated movie.\n");
            break;
        case R:
            printf("R-rated movie.\n");
            break;
        case NC_17:
            printf("NC-17-rated movie.\n");
            break;
        default:
            printf("Invalid age rating.\n");
    }

    return 0;
}