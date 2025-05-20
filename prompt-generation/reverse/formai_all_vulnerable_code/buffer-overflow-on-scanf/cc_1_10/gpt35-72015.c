//FormAI DATASET v1.0 Category: Movie Rating System ; Style: ultraprecise
#include <stdio.h>

// define the MovieRatings struct
typedef struct {
    char title[50];
    int rating;
} MovieRatings;

// function prototypes
void add_new_rating(MovieRatings ratings[], int *num_ratings);
void display_ratings(MovieRatings ratings[], int num_ratings);
void view_top_rated(MovieRatings ratings[], int num_ratings);
void view_bottom_rated(MovieRatings ratings[], int num_ratings);

int main() {
    MovieRatings ratings[50]; // maximum of 50 movies can be rated
    int num_ratings = 0;
    char choice;

    do {
        // display menu options
        printf("\nMovie Rating System\n");
        printf("1. Add a new rating\n");
        printf("2. View all ratings\n");
        printf("3. View top rated movies\n");
        printf("4. View bottom rated movies\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // read user choice from input
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_new_rating(ratings, &num_ratings);
                break;
            case '2':
                display_ratings(ratings, num_ratings);
                break;
            case '3':
                view_top_rated(ratings, num_ratings);
                break;
            case '4':
                view_bottom_rated(ratings, num_ratings);
                break;
            case '5':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '5');

    return 0;
}

void add_new_rating(MovieRatings ratings[], int *num_ratings) {
    char temp[50];

    printf("\nEnter the movie title: ");
    scanf(" %[^\n]s", temp);
    strcpy(ratings[*num_ratings].title, temp);

    printf("Enter the movie rating (1-10): ");
    scanf(" %d", &ratings[*num_ratings].rating);

    *num_ratings += 1;

    printf("New rating added successfully!\n");
}

void display_ratings(MovieRatings ratings[], int num_ratings) {
    if (num_ratings == 0) {
        printf("\nNo ratings added yet.\n");
    } else {
        printf("\nAll ratings:\n");

        for (int i = 0; i < num_ratings; i++) {
            printf("%d. %s (Rating: %d)\n", i+1, ratings[i].title, ratings[i].rating);
        }
    }
}

void view_top_rated(MovieRatings ratings[], int num_ratings) {
    if (num_ratings == 0) {
        printf("\nNo ratings added yet.\n");
    } else {
        printf("\nTop rated movies:\n");
        
        // bubble sort the ratings array in descending order
        for (int i = 0; i < num_ratings - 1; i++) {
            for (int j = 0; j < num_ratings - i - 1; j++) {
                if (ratings[j].rating < ratings[j+1].rating) {
                    // swap the ratings
                    MovieRatings temp = ratings[j];
                    ratings[j] = ratings[j+1];
                    ratings[j+1] = temp;
                }
            }
        }

        // display the top 5 rated movies (or all if less than 5)
        int count = 0;
        for (int i = 0; i < num_ratings; i++) {
            if (count == 5) {
                break; // only show top 5 rated movies
            }
            printf("%d. %s (Rating: %d)\n", i+1, ratings[i].title, ratings[i].rating);
            count++;
        }
    }
}

void view_bottom_rated(MovieRatings ratings[], int num_ratings) {
     if (num_ratings == 0) {
        printf("\nNo ratings added yet.\n");
    } else {
        printf("\nBottom rated movies:\n");
        
        // bubble sort the ratings array in ascending order
        for (int i = 0; i < num_ratings - 1; i++) {
            for (int j = 0; j < num_ratings - i - 1; j++) {
                if (ratings[j].rating > ratings[j+1].rating) {
                    // swap the ratings
                    MovieRatings temp = ratings[j];
                    ratings[j] = ratings[j+1];
                    ratings[j+1] = temp;
                }
            }
        }

        // display the bottom 5 rated movies (or all if less than 5)
        int count = 0;
        for (int i = 0; i < num_ratings; i++) {
            if (count == 5) {
                break; // only show bottom 5 rated movies
            }
            printf("%d. %s (Rating: %d)\n", i+1, ratings[i].title, ratings[i].rating);
            count++;
        }
    }
}