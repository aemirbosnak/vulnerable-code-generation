//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void print_menu();
int get_rating();
void display_movie_info(char* title, int rating);

int main() {
    char title[50];
    int rating;

    printf("Welcome to the Medieval Movie Rating System!\n");
    printf("Please enter the title of the movie you would like to rate:\n");
    scanf("%s", title);

    rating = get_rating();

    display_movie_info(title, rating);

    return 0;
}

void print_menu() {
    printf("Choose your rating:\n");
    printf("1 - Poor\n");
    printf("2 - Fair\n");
    printf("3 - Good\n");
    printf("4 - Excellent\n");
    printf("5 - Masterpiece\n");
}

int get_rating() {
    int choice;

    printf("\n");
    print_menu();
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 5) {
        printf("Invalid choice! Please try again.\n");
        return get_rating();
    }

    return choice;
}

void display_movie_info(char* title, int rating) {
    printf("\n");
    printf("Movie Title: %s\n", title);
    printf("Rating: ");

    switch (rating) {
        case 1:
            printf("Poor\n");
            break;
        case 2:
            printf("Fair\n");
            break;
        case 3:
            printf("Good\n");
            break;
        case 4:
            printf("Excellent\n");
            break;
        case 5:
            printf("Masterpiece\n");
            break;
    }
}