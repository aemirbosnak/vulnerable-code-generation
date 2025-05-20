//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 10

typedef struct {
    char title[50];
    int rating; // 1-5, with 5 being the best and 1 being "I need my time back!"
} Movie;

// Function to display instructions
void displayInstructions() {
    printf("Welcome to the **CINEMATIC CIRCUS** Movie Rating System!\n");
    printf("Please enter your movie ratings with caution, as they may incur unexpected laughter!\n");
    printf("You can rate each movie between 1 (Horrible, please alert the director) to 5 (I would watch this while sipping hot cocoa). \n");
    printf("Type 'exit' to end the fun and return to reality.\n\n");
}

// Function to get a rating from the user
int getRating() {
    int rating;
    printf("Rate the movie (1-5): ");
    while (1) {
        if (scanf("%d", &rating) != 1 || rating < 1 || rating > 5) {
            printf("Invalid input! Please enter a number between 1 and 5: ");
            while(getchar() != '\n'); // clear input buffer
        } else {
            break;
        }
    }
    return rating;
}

// Function to display ratings and funny messages
void displayMovies(Movie movies[], int count) {
    printf("\nHere are your movie ratings:\n");

    for (int i = 0; i < count; i++) {
        printf("Movie: %s | Rating: %d ", movies[i].title, movies[i].rating);
        switch (movies[i].rating) {
            case 1:
                printf("😱 Never again!\n");
                break;
            case 2:
                printf("🤮 I need a refund!\n");
                break;
            case 3:
                printf("😐 It was... fine? Like apple pie with no sugar.\n");
                break;
            case 4:
                printf("😁 Not bad! I might even recommend it to my neighbor (who I don't really like).\n");
                break;
            case 5:
                printf("🤩 Absolutely fantastic! I’d pay to watch this again! (Where's my popcorn?)\n");
                break;
        }
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;

    displayInstructions();

    while (count < MAX_MOVIES) {
        char input[50];

        printf("Enter the movie title (or type 'exit' to finish): ");
        scanf(" %[^\n]", input); // Read a line of input including spaces

        if (strcmp(input, "exit") == 0) {
            break; // Exit the loop if the user types 'exit'
        } 

        strcpy(movies[count].title, input);
        movies[count].rating = getRating();
        count++;
        printf("Thank you for your rating of '%s'! 🎉\n", movies[count - 1].title);
    }

    displayMovies(movies, count);

    printf("Thank you for using the **CINEMATIC CIRCUS** Movie Rating System!\n");
    printf("Remember: Life is too short for bad movies. Go watch something you love!\n");

    return 0;
}