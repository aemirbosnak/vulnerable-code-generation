//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGES 100
#define MAX_LENGTH 256

typedef struct {
    char content[MAX_LENGTH];
    int frequency;
} Message;

// Voyeur of Words
void count_word_frequencies(Message messages[], int *count) {
    char *token;
    char temp[MAX_LENGTH];
    int i, j;
  
    for (i = 0; i < *count; i++) {
        strcpy(temp, messages[i].content);
        token = strtok(temp, " ");
        
        while (token != NULL) {
            int found = 0;
            for (j = 0; j < *count; j++) {
                if (strcmp(token, messages[j].content) == 0) {
                    messages[j].frequency++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(messages[*count].content, token);
                messages[*count].frequency = 1;
                (*count)++;
            }
            token = strtok(NULL, " ");
        }
    }
}

// Distinguished Diversity Detector
int is_spam(Message messages[], int count) {
    for (int i = 0; i < count; i++) {
        if (messages[i].frequency > 2) {  // Arbitrary threshold - A conundrum of commonality!
            return 1;
        }
    }
    return 0;
}

// The Deduction of Unveiling Messages
void display_results(Message messages[], int count) {
    printf("\nAnalysis of the Letters:\n");
    for (int i = 0; i < count; i++) {
        printf("Word: %-15s Frequency: %d\n", messages[i].content, messages[i].frequency);
    }
}

int main() {
    Message messages[MAX_MESSAGES];
    int message_count = 0;

    printf("=== SPAM DETECTION SYSTEM ===\n");

    // Enter messages
    printf("Enter the number of messages (up to %d): ", MAX_MESSAGES);
    scanf("%d", &message_count);

    if (message_count > MAX_MESSAGES || message_count < 1) {
        printf("Invalid number of messages. Please restart the program and try again.\n");
        return 1;
    }
    
    printf("Enter your messages one by one:\n");
    getchar(); // To consume the new line character after reading an int
    for (int i = 0; i < message_count; i++) {
        printf("Message %d: ", i + 1);
        fgets(messages[i].content, MAX_LENGTH, stdin);
        
        // Removing newline character
        size_t len = strlen(messages[i].content);
        if(len > 0 && messages[i].content[len-1] == '\n') {
            messages[i].content[len-1] = '\0';
        }
        messages[i].frequency = 0; // Initialize frequency to zero
    }

    count_word_frequencies(messages, &message_count);
    
    // Determine if the message contents contain spam
    if (is_spam(messages, message_count)) {
        printf("\nAlarming! The messages contain spam-like attributes.\n");
    } else {
        printf("\nThe messages appear to be genuine and devoid of spam.\n");
    }

    display_results(messages, message_count);
    
    return 0;
}