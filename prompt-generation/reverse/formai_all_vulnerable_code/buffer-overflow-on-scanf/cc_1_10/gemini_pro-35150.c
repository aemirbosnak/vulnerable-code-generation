//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the random number generator
void init_random() {
    srand(time(NULL));
}

// Generate a random integer between 0 and 9
int get_random_number() {
    return rand() % 10;
}

// Get the user's input
int get_user_input() {
    int rating;
    printf("Enter your rating (0-9): ");
    scanf("%d", &rating);
    return rating;
}

// Display the movie rating
void display_rating(int rating) {
    switch (rating) {
        case 0:
            printf("Awful! 👎");
            break;
        case 1:
            printf("Very bad! 👎");
            break;
        case 2:
            printf("Bad! 👎");
            break;
        case 3:
            printf("OK! 😐");
            break;
        case 4:
            printf("Good! 👍");
            break;
        case 5:
            printf("Very good! 👍");
            break;
        case 6:
            printf("Excellent! 🌟");
            break;
        case 7:
            printf("Amazing! 🌟🌟");
            break;
        case 8:
            printf("Incredible! 🌟🌟🌟");
            break;
        case 9:
            printf("Masterpiece! 🌟🌟🌟🌟");
            break;
        default:
            printf("Invalid rating! 🤔");
            break;
    }
}

// Main function
int main() {
    // Initialize the random number generator
    init_random();

    // Get the user's input
    int user_rating = get_user_input();

    // Display the movie rating
    printf("Your rating: ");
    display_rating(user_rating);

    // Generate a random rating
    int random_rating = get_random_number();

    // Display the random rating
    printf("\nRandom rating: ");
    display_rating(random_rating);

    return 0;
}