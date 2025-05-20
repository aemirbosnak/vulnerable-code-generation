//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
    // Welcome message!
    printf("Welcome to the Happy Sentiment Analysis Tool!\n\n");
    
    // Ask the user for input
    char user_input[100];
    printf("Enter your sentence: ");
    fgets(user_input, 100, stdin);

    // Regex patterns for happy words
    char *good_words[] = {"happy", "joy", "delight", "great", "fun", "love", "excited", "awesome", "wonderful", 
    "fantastic", "amazing", "pleasure", "smile", "laugh", "beautiful", "vibrant", "glad", "celebrate", "enjoy"};

    // Regex patterns for negative words
    char *bad_words[] = {"sad", "hate", "angry", "dislike", "pain", "hurt", "fear", "anxiety", "depressed", "agony", 
    "gloomy", "unhappy", "terrible", "awful", "painful", "emotional", "disgusting", "disappoint", "sorrow", "tear",
    "cry", "broken"};

    // Splitting user input into individual words
    char *token = strtok(user_input, " ");
    int good_count = 0;
    int bad_count = 0;

    while(token != NULL) {
        // Check if word matches any of the happy words
        for(int i = 0; i < 20; i++) {
            if(strncmp(token, good_words[i], strlen(good_words[i])) == 0) {
                good_count += 1;
            }
        }
        // Check if word matches any of the negative words
        for(int i = 0; i < 21; i++) {
            if(strncmp(token, bad_words[i], strlen(bad_words[i])) == 0) {
                bad_count += 1;
            }
        }
        token = strtok(NULL, " ");
    }

    // Generate sentiment result
    printf("\nAnalysis Result:\n\n");
    if(good_count > bad_count) {
        printf("Congratulations! Your sentence has a positive sentiment.\n");
    } else if(bad_count > good_count) {
        printf("Unfortunately, Your sentence has a negative sentiment.\n");
    } else {
        printf("Neutral sentiment detected.\n");
    }
    return 0;
}