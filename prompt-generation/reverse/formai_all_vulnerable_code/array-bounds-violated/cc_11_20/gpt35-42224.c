//FormAI DATASET v1.0 Category: Spam Detection System ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LENGTH 1000 // Maximum length of a message
#define SPAM_THRESHOLD 0.5 // Threshold to classify a message as spam

int main() {
    char msg[MAX_MSG_LENGTH];
    int num_words = 0, num_spam_words = 0, i, j;
    
    // Get message input from user
    printf("Enter the message: ");
    fgets(msg, MAX_MSG_LENGTH, stdin);
    
    // Count the number of words in the message
    for (i = 0; i < strlen(msg); i++) {
        if (msg[i] == ' ' || msg[i] == '\n') {
            num_words++;
        }
    }
    
    // Check each word for spam words
    char spam_words[5][20] = {"buy", "enhancement", "click", "money", "offer"};
    
    for (i = 0; i < num_words; i++) {
        char word[20];
        int start = -1, end = -1;
        // Get the start and end position of a word
        for (j = 0; j < strlen(msg); j++) {
            if (msg[j] != ' ' && msg[j] != '\n' && start == -1) {
                start = j;
            } else if ((msg[j] == ' ' || msg[j] == '\n') && start != -1) {
                end = j-1;
                break;
            }
        }
        if (start != -1 && end == -1) {
            end = strlen(msg)-1;
        }
        // Copy word into a separate string
        int k = 0;
        for (j = start; j <= end; j++) {
            word[k] = msg[j];
            k++;
        }
        word[k] = '\0';
        // Check if word is a spam word
        for (j = 0; j < 5; j++) {
            if (strcmp(spam_words[j], word) == 0) {
                num_spam_words++;
                break;
            }
        }
        // Move on to the next word
        if (end == strlen(msg)-1) {
            break;
        } else {
            i++;
        }
    }
    
    // Classify message as spam or not
    float spam_ratio = (float) num_spam_words / num_words;
    if (spam_ratio > SPAM_THRESHOLD) {
        printf("This message is classified as spam.\n");
    } else {
        printf("This message is not classified as spam.\n");
    }
    
    return 0;
}