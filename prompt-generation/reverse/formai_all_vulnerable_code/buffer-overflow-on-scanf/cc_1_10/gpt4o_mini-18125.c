//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: medieval
#include <stdio.h>
#include <string.h>

// Structure to hold movie data
struct Movie {
    char title[50];
    int totalRatings;
    int numberOfRatings;
};

// Function prototypes
void rateMovie(struct Movie *movies, int *movieCount);
void viewRatings(struct Movie *movies, int movieCount);
float calculateAverageRating(struct Movie movie);

int main() {
    struct Movie movies[100];
    int movieCount = 0;
    int choice;

    do {
        printf("Welcome to the Kingdom of Ratings!\n");
        printf("1. Rate a Movie\n");
        printf("2. View All Ratings\n");
        printf("3. Leave the Kingdom\n");
        printf("Choose thy action (1-3): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                rateMovie(movies, &movieCount);
                break;
            case 2:
                viewRatings(movies, movieCount);
                break;
            case 3:
                printf("Farewell, noble patron!\n");
                break;
            default:
                printf("Alas! That be not a valid choice. Try again!\n");
                break;
        }
    } while(choice != 3);

    return 0;
}

void rateMovie(struct Movie *movies, int *movieCount) {
    char title[50];
    int rating;

    printf("Enter the title of the movie thou wishest to rate: ");
    scanf(" %[^\n]", title); // Read string with spaces

    // Find if movie already exists
    int found = -1;
    for (int i = 0; i < *movieCount; ++i) {
        if (strcmp(movies[i].title, title) == 0) {
            found = i;
            break;
        }
    }

    // If movie not found, add it
    if (found == -1) {
        found = *movieCount;
        strcpy(movies[found].title, title);
        movies[found].totalRatings = 0;
        movies[found].numberOfRatings = 0;
        (*movieCount)++;
    }

    printf("Rate the movie (0 to 5): ");
    scanf("%d", &rating);

    // Ensure valid rating
    if (rating < 0 || rating > 5) {
        printf("An invalid rating! Ratings must be between 0 and 5.\n");
        return;
    }

    movies[found].totalRatings += rating;
    movies[found].numberOfRatings++;

    printf("Thy rating hath been recorded! A noble deed indeed!\n");
}

void viewRatings(struct Movie *movies, int movieCount) {
    printf("Behold the Ratings of Movies in the Kingdom:\n");
    
    if (movieCount == 0) {
        printf("There are no movies rated as of yet.\n");
        return;
    }

    for (int i = 0; i < movieCount; ++i) {
        printf("Movie: %s\n", movies[i].title);
        printf("Total Ratings: %d\n", movies[i].totalRatings);
        printf("Number of Ratings: %d\n", movies[i].numberOfRatings);
        float average = calculateAverageRating(movies[i]);
        printf("Average Rating: %.2f\n", average);
        printf("-----------------------------------\n");
    }
}

float calculateAverageRating(struct Movie movie) {
    if (movie.numberOfRatings == 0) {
        return 0;
    }
    return (float)movie.totalRatings / movie.numberOfRatings;
}