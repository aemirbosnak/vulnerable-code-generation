//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a message
#define MAX_MESSAGE_LENGTH 1024

// Define the maximum number of keywords
#define MAX_KEYWORDS 100

// Define the maximum number of messages
#define MAX_MESSAGES 1000

// Define the structure of a keyword
typedef struct {
    char *keyword;
    int weight;
} Keyword;

// Define the structure of a message
typedef struct {
    char *message;
    int score;
} Message;

// Create an array of keywords
Keyword keywords[MAX_KEYWORDS];

// Create an array of messages
Message messages[MAX_MESSAGES];

// Initialize the spam detection system
void initialize_spam_detection_system() {
    // Load the keywords from a file
    FILE *keywords_file = fopen("keywords.txt", "r");
    if (keywords_file == NULL) {
        perror("Error opening keywords file");
        exit(1);
    }

    int i = 0;
    char line[MAX_MESSAGE_LENGTH];
    while (fgets(line, MAX_MESSAGE_LENGTH, keywords_file) != NULL) {
        // Remove the newline character from the line
        line[strlen(line) - 1] = '\0';

        // Allocate memory for the keyword
        keywords[i].keyword = malloc(strlen(line) + 1);

        // Copy the keyword into the array
        strcpy(keywords[i].keyword, line);

        // Set the weight of the keyword
        keywords[i].weight = 1;

        i++;
    }

    fclose(keywords_file);

    // Load the messages from a file
    FILE *messages_file = fopen("messages.txt", "r");
    if (messages_file == NULL) {
        perror("Error opening messages file");
        exit(1);
    }

    i = 0;
    while (fgets(line, MAX_MESSAGE_LENGTH, messages_file) != NULL) {
        // Remove the newline character from the line
        line[strlen(line) - 1] = '\0';

        // Allocate memory for the message
        messages[i].message = malloc(strlen(line) + 1);

        // Copy the message into the array
        strcpy(messages[i].message, line);

        // Set the score of the message to 0
        messages[i].score = 0;

        i++;
    }

    fclose(messages_file);
}

// Calculate the spam score of a message
int calculate_spam_score(char *message) {
    int score = 0;

    // Loop through the keywords
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        // Check if the keyword is contained in the message
        if (strstr(message, keywords[i].keyword) != NULL) {
            // Increment the score of the message
            score += keywords[i].weight;
        }
    }

    return score;
}

// Classify a message as spam or not spam
int classify_message(char *message) {
    int score = calculate_spam_score(message);

    // If the score is greater than 0, the message is classified as spam
    if (score > 0) {
        return 1;
    }

    // Otherwise, the message is classified as not spam
    else {
        return 0;
    }
}

// Print the results of the spam detection system
void print_results() {
    // Loop through the messages
    for (int i = 0; i < MAX_MESSAGES; i++) {
        // Print the message
        printf("Message %d: %s\n", i + 1, messages[i].message);

        // Print the score of the message
        printf("Score: %d\n", messages[i].score);

        // Print the classification of the message
        if (classify_message(messages[i].message)) {
            printf("Classification: Spam\n\n");
        } else {
            printf("Classification: Not spam\n\n");
        }
    }
}

// Main function
int main() {
    // Initialize the spam detection system
    initialize_spam_detection_system();

    // Calculate the spam score of each message
    for (int i = 0; i < MAX_MESSAGES; i++) {
        messages[i].score = calculate_spam_score(messages[i].message);
    }

    // Print the results of the spam detection system
    print_results();

    return 0;
}