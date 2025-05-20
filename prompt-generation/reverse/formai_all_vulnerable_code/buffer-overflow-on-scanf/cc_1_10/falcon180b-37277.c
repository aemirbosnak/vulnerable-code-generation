//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the average of an array of integers
int average(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Function to prompt the user for a rating and return it as an integer
int getRating() {
    int rating = 0;
    while (rating < 1 || rating > 5) {
        printf("Enter a rating (1-5): ");
        scanf("%d", &rating);
    }
    return rating;
}

// Function to print a movie rating based on the average rating of all reviews
void printRating(int rating) {
    if (rating < 2) {
        printf("Terrible\n");
    } else if (rating < 3) {
        printf("Poor\n");
    } else if (rating < 4) {
        printf("Average\n");
    } else if (rating < 5) {
        printf("Good\n");
    } else {
        printf("Excellent\n");
    }
}

// Function to print a list of movie ratings
void printRatings(int ratings[], int n) {
    for (int i = 0; i < n; i++) {
        printRating(ratings[i]);
    }
}

// Function to prompt the user for a list of movie ratings
void getRatings(int ratings[], int n) {
    for (int i = 0; i < n; i++) {
        ratings[i] = getRating();
    }
}

int main() {
    int n;
    printf("Enter the number of movies: ");
    scanf("%d", &n);
    int ratings[n];
    getRatings(ratings, n);
    printRatings(ratings, n);
    return 0;
}