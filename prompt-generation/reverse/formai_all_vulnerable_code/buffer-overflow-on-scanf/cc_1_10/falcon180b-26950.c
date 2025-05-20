//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RATINGS 10
#define MAX_RATING_LENGTH 100
#define MAX_RATING_STRING 200

struct rating {
    char *username;
    char *comment;
    int rating;
};

struct rating ratings[MAX_RATINGS];
int num_ratings;

void add_rating(char *username, char *comment, int rating) {
    if (num_ratings >= MAX_RATINGS) {
        printf("Error: Maximum ratings limit reached.\n");
        return;
    }
    ratings[num_ratings].username = (char *) malloc(strlen(username) + 1);
    strcpy(ratings[num_ratings].username, username);
    ratings[num_ratings].comment = (char *) malloc(strlen(comment) + 1);
    strcpy(ratings[num_ratings].comment, comment);
    ratings[num_ratings].rating = rating;
    num_ratings++;
}

void print_ratings() {
    printf("Movie Ratings:\n");
    for (int i = 0; i < num_ratings; i++) {
        printf("Username: %s\n", ratings[i].username);
        printf("Comment: %s\n", ratings[i].comment);
        printf("Rating: %d\n\n", ratings[i].rating);
    }
}

int main() {
    char username[MAX_RATING_LENGTH];
    char comment[MAX_RATING_LENGTH];
    int rating;
    char choice;

    do {
        printf("Movie Rating System\n");
        printf("1. Add a rating\n");
        printf("2. Print ratings\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter your username: ");
            scanf("%s", username);
            printf("Enter your comment: ");
            scanf("%s", comment);
            printf("Enter your rating (1-10): ");
            scanf("%d", &rating);
            add_rating(username, comment, rating);
            break;
        case '2':
            print_ratings();
            break;
        case '3':
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '3');

    return 0;
}