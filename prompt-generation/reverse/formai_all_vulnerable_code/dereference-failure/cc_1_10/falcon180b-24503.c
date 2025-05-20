//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove leading and trailing spaces from a string
void trim(char *str) {
    int i, j;
    for (i = 0; i < strlen(str); i++) {
        if (!isspace(str[i])) {
            str[i] = tolower(str[i]);
            break;
        }
    }
    for (j = strlen(str) - 1; j >= 0; j--) {
        if (!isspace(str[j])) {
            str[j + 1] = '\0';
            break;
        }
    }
}

// Function to get the user's movie rating
int get_rating() {
    char input[100];
    int rating;
    printf("Enter your movie rating (1-5): ");
    fgets(input, sizeof(input), stdin);
    trim(input);
    rating = atoi(input);
    if (rating < 1 || rating > 5) {
        printf("Invalid rating. Please enter a number between 1 and 5.\n");
        exit(1);
    }
    return rating;
}

// Function to get the user's movie title
char *get_title() {
    char input[100];
    char *title;
    printf("Enter the movie title: ");
    fgets(input, sizeof(input), stdin);
    trim(input);
    title = strdup(input);
    return title;
}

// Function to get the user's movie genre
char *get_genre() {
    char input[100];
    char *genre;
    printf("Enter the movie genre: ");
    fgets(input, sizeof(input), stdin);
    trim(input);
    genre = strdup(input);
    return genre;
}

// Function to get the user's movie review
char *get_review() {
    char input[1000];
    char *review;
    printf("Enter your movie review: ");
    fgets(input, sizeof(input), stdin);
    trim(input);
    review = strdup(input);
    return review;
}

// Function to print the user's movie information
void print_movie_info(char *title, char *genre, int rating, char *review) {
    printf("Movie Title: %s\n", title);
    printf("Movie Genre: %s\n", genre);
    printf("Movie Rating: %d\n", rating);
    printf("Movie Review: %s\n", review);
}

// Function to save the user's movie information to a file
void save_movie_info(char *title, char *genre, int rating, char *review) {
    FILE *fp;
    fp = fopen("movies.txt", "a+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fprintf(fp, "Title: %s\nGenre: %s\nRating: %d\nReview: %s\n", title, genre, rating, review);
    fclose(fp);
}

// Main function
int main() {
    char *title, *genre;
    int rating;
    char *review;
    title = get_title();
    genre = get_genre();
    rating = get_rating();
    review = get_review();
    print_movie_info(title, genre, rating, review);
    save_movie_info(title, genre, rating, review);
    printf("Movie information saved successfully!\n");
    return 0;
}