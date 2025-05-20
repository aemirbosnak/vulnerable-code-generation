//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 1024
#define SPAM_THRESHOLD 3

// Structure to hold a message
typedef struct {
    char content[MAX_LENGTH];
    int spamScore;
} Message;

// Function declarations
void toLowerCase(char *str);
int calculateSpamScore(const char *message);
bool isSpam(Message *msg);

int main() {
    int n;
    printf("Enter number of messages to evaluate: ");
    scanf("%d", &n);
    getchar(); // Consume newline character
    
    Message *messages = malloc(n * sizeof(Message));
    if (!messages) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter message %d: ", i + 1);
        fgets(messages[i].content, MAX_LENGTH, stdin);
        messages[i].content[strcspn(messages[i].content, "\n")] = 0; // Remove newline
        messages[i].spamScore = calculateSpamScore(messages[i].content);
    }

    printf("\nSpam Evaluation Results:\n");
    for (int i = 0; i < n; i++) {
        printf("Message %d: %s\n", i + 1, messages[i].content);
        printf("Spam Score: %d -> %s\n", messages[i].spamScore, isSpam(&messages[i]) ? "SPAM" : "NOT SPAM");
    }

    free(messages);
    return EXIT_SUCCESS;
}

void toLowerCase(char *str) {
    for (; *str; ++str) {
        *str = tolower(*str);
    }
}

int calculateSpamScore(const char *message) {
    int score = 0;
    const char *spamWords[] = {
        "free", "winner", "credit", "buy", "prize", 
        "urgent", "offer", "discount", "cash", "quarantine"
    };
    char tempMessage[MAX_LENGTH];
    strncpy(tempMessage, message, MAX_LENGTH);
    toLowerCase(tempMessage); // Change to lower case

    for (int i = 0; i < sizeof(spamWords) / sizeof(spamWords[0]); i++) {
        if (strstr(tempMessage, spamWords[i]) != NULL) {
            score++;
        }
    }
    
    return score;
}

bool isSpam(Message *msg) {
    return msg->spamScore >= SPAM_THRESHOLD;
}