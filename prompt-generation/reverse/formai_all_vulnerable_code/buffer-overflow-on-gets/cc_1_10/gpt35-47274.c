//FormAI DATASET v1.0 Category: Spam Detection System ; Style: calm
#include <stdio.h>
#include <string.h>

#define SPAM_KEYWORDS_COUNT 5
#define SPAM_SCORE_THRESHOLD 5

// List of potential spam keywords
char *SPAM_KEYWORDS[] = {"money", "free", "limited", "offer", "urgent"};

/**
 * Calculate the spam score of a message
 */
int calculate_spam_score(char *message)
{
    int i, score = 0;

    // Check for each spam keyword in the message
    for (i = 0; i < SPAM_KEYWORDS_COUNT; i++)
    {
        if (strstr(message, SPAM_KEYWORDS[i]) != NULL)
        {
            score++;
        }
    }

    return score;
}

/**
 * Check if a message is a spam or not
 */
int is_spam(char *message)
{
    int score = calculate_spam_score(message);

    if (score >= SPAM_SCORE_THRESHOLD)
    {
        return 1;
    }

    return 0;
}

int main()
{
    char message[1000];
    printf("Enter a message: ");
    gets(message);

    if (is_spam(message))
    {
        printf("This message is a spam.");
    }
    else
    {
        printf("This message is not a spam.");
    }

    return 0;
}