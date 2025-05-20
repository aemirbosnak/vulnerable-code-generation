//FormAI DATASET v1.0 Category: Spam Detection System ; Style: creative
#include <stdio.h>
#include <string.h>

// define the maximum length of the spam message
#define MAX_MESSAGE_LENGTH 200

// define the threshold for spam detection
#define SPAM_THRESHOLD 0.8

// function to calculate the similarity index between two strings
double getSimilarityIndex(char* string1, char* string2)
{
    int matchingChars = 0;

    // compare every character of the two strings
    for(int i = 0; i < strlen(string1); i++) {
        for(int j = 0; j < strlen(string2); j++) {
            if(string1[i] == string2[j]) {
                matchingChars++;
                break;
            }
        }
    }

    // calculate the similarity index
    double similarityIndex = (double)matchingChars / (double)strlen(string1);

    return similarityIndex;
}

// function to check if a given message is a spam
int isSpam(char* message, char** spamList, int spamListSize)
{
    double similarityIndex;
    int count = 0;

    // check the message against every entry in the spam list
    for(int i = 0; i < spamListSize; i++) {
        similarityIndex = getSimilarityIndex(message, spamList[i]);

        if(similarityIndex >= SPAM_THRESHOLD) {
            count++;

            // threshold for number of matches
            if(count >= 2) {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    char* spamList[] = {"get-rich-quick", "make money fast", "work from home"};
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // remove the newline character from the end of the message
    message[strlen(message) - 1] = '\0';

    if(isSpam(message, spamList, sizeof(spamList)/sizeof(spamList[0]))) {
        printf("Spam message detected!\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}