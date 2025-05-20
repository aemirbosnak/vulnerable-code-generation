//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: authentic
#include <stdio.h>
#include <string.h>

// Initialize the sentiment dictionary
char *sentiment_dict[] = {
    "positive", "happy", "good", "excellent", "awesome",
    "negative", "sad", "bad", "terrible", "horrible"
};

// Count the occurrences of each sentiment in a given string
int count_sentiments(char *str) {
    int sentiment_counts[2] = {0, 0}; // [0] = positive, [1] = negative

    // Convert the string to lowercase for easier comparison
    char *lower_str = strdup(str);
    for (int i = 0; i < strlen(lower_str); i++) {
        lower_str[i] = tolower(lower_str[i]);
    }

    // Iterate over the dictionary and count the occurrences of each sentiment
    for (int i = 0; i < sizeof(sentiment_dict) / sizeof(sentiment_dict[0]); i++) {
        char *sentiment = sentiment_dict[i];
        int count = 0;

        // Check if the sentiment occurs in the string
        char *pos = strstr(lower_str, sentiment);
        while (pos != NULL) {
            count++;
            pos = strstr(pos + strlen(sentiment), sentiment);
        }

        sentiment_counts[i / 2] += count; // Increment the count for positive or negative
    }

    free(lower_str); // Free the allocated memory

    // Return the total sentiment counts
    return sentiment_counts;
}

int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Count the sentiments in the string
    int *sentiment_counts = count_sentiments(str);

    // Print the sentiment analysis results
    printf("Sentiment analysis:\n");
    printf("Positive: %d\n", sentiment_counts[0]);
    printf("Negative: %d\n", sentiment_counts[1]);

    free(sentiment_counts); // Free the allocated memory

    return 0;
}