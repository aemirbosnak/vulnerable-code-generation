//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: funny
#include <stdio.h>
#include <string.h>

// Function to get sentiment score
int getSentimentScore(char *input) {
    int score = 0;
    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        switch(input[i]) {
            case 'h':
                score += 3;
                break;
            case 'a':
                score += 2;
                break;
            case 'p':
                score += 1;
                break;
            case 'y':
                score += 1;
                break;
            case ' ': // Ignoring spaces
                break;
            default:
                score -= 1;
                break;
        }
    }

    return score;
}

int main() {
    char input[100];

    printf("Welcome to the Funny Sentiment Analysis Tool by Bot-Man!\n");

    while (1) {
        printf("Enter your text here (enter 'exit' to terminate program): ");
        fgets(input, 100, stdin);

        // Removing trailing newline character
        input[strlen(input)-1] = '\0';

        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        int score = getSentimentScore(input);

        if (score >= 6) {
            printf("WOW! You're too happy! Your sentiment score is: %d\n", score);
        } else if (score >= 2) {
            printf("Looks like you're feeling good! Your sentiment score is: %d\n", score);
        } else if (score >= -2) {
            printf("Not too happy, not too sad. Your sentiment score is: %d\n", score);
        } else if (score >= -6) {
            printf("Seems like you're not having a good day. Your sentiment score is: %d\n", score);
        } else {
            printf("Oh no! Are you okay? Your sentiment score is: %d\n", score);
        }
    }

    return 0;
}