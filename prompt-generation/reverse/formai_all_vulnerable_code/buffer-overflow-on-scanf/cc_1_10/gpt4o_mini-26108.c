//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MOVIES 100
#define TITLE_LENGTH 100
#define REVIEW_LENGTH 500

typedef struct {
    char title[TITLE_LENGTH];
    char reviewerName[TITLE_LENGTH];
    int rating; // Scale of 1 to 10
    char review[REVIEW_LENGTH];
    time_t timestamp;
} MovieReview;

void addReview(MovieReview *reviews, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Review limit reached. Cannot add more reviews.\n");
        return;
    }

    MovieReview newReview;
    printf("Enter movie title: ");
    getchar(); // Clear newline character
    fgets(newReview.title, TITLE_LENGTH, stdin);
    newReview.title[strcspn(newReview.title, "\n")] = 0; // Remove newline

    printf("Enter your name: ");
    fgets(newReview.reviewerName, TITLE_LENGTH, stdin);
    newReview.reviewerName[strcspn(newReview.reviewerName, "\n")] = 0; // Remove newline

    printf("Enter your rating (1-10): ");
    scanf("%d", &newReview.rating);
    
    while (newReview.rating < 1 || newReview.rating > 10) {
        printf("Rating must be between 1 and 10. Please enter again: ");
        scanf("%d", &newReview.rating);
    }

    printf("Write your review (max %d characters): ", REVIEW_LENGTH);
    getchar(); // Clear newline character
    fgets(newReview.review, REVIEW_LENGTH, stdin);
    newReview.review[strcspn(newReview.review, "\n")] = 0; // Remove newline

    newReview.timestamp = time(NULL);
    reviews[*count] = newReview;
    (*count)++;

    printf("Review added successfully!\n");
}

void displayReviews(const MovieReview *reviews, int count) {
    if (count == 0) {
        printf("No reviews available.\n");
        return;
    }

    printf("\n*** Movie Reviews ***\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", reviews[i].title);
        printf("Reviewer: %s\n", reviews[i].reviewerName);
        printf("Rating: %d/10\n", reviews[i].rating);
        printf("Review: %s\n", reviews[i].review);
        char *timeStr = ctime(&reviews[i].timestamp);
        printf("Submitted on: %s", timeStr);
        printf("-------------------------\n");
    }
}

void searchReviews(const MovieReview *reviews, int count) {
    if (count == 0) {
        printf("No reviews to search through.\n");
        return;
    }

    char searchTerm[TITLE_LENGTH];
    printf("Enter movie title to search for: ");
    getchar(); // Clear newline character
    fgets(searchTerm, TITLE_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline

    int found = 0;
    printf("\n*** Search Results for '%s' ***\n", searchTerm);
    for (int i = 0; i < count; i++) {
        if (strstr(reviews[i].title, searchTerm) != NULL) {
            printf("Title: %s\n", reviews[i].title);
            printf("Reviewer: %s\n", reviews[i].reviewerName);
            printf("Rating: %d/10\n", reviews[i].rating);
            printf("Review: %s\n", reviews[i].review);
            char *timeStr = ctime(&reviews[i].timestamp);
            printf("Submitted on: %s", timeStr);
            printf("-------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No reviews found for '%s'.\n", searchTerm);
    }
}

int main() {
    MovieReview reviews[MAX_MOVIES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n*** Futuristic Movie Rating System ***\n");
        printf("1. Add New Review\n");
        printf("2. Display All Reviews\n");
        printf("3. Search Reviews by Movie Title\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addReview(reviews, &count);
                break;
            case 2:
                displayReviews(reviews, count);
                break;
            case 3:
                searchReviews(reviews, count);
                break;
            case 0:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    }

    return 0;
}