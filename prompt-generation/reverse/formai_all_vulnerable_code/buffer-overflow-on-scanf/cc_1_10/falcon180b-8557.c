//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_WORDS_IN_MSG 50
#define MIN_MSG_LENGTH 10

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    char *word;
    int isSpam;
} SpamWord;

int isSpam(char *msg) {
    int i, j, k, numSpamWords = 0;
    char *word, **spamWords = malloc(sizeof(char *) * 10);
    spamWords[0] = strdup("free");
    spamWords[1] = strdup("make money fast");
    spamWords[2] = strdup("earn cash");
    spamWords[3] = strdup("work from home");
    spamWords[4] = strdup("get rich quick");
    spamWords[5] = strdup("earn money");
    spamWords[6] = strdup("make money");
    spamWords[7] = strdup("fast cash");
    spamWords[8] = strdup("quick cash");
    spamWords[9] = strdup("easy money");

    char *tokens[MAX_WORDS_IN_MSG];
    int numWords = 0;

    if (strlen(msg) < MIN_MSG_LENGTH) {
        return FALSE;
    }

    word = strtok(msg, " \t\n\r\f\v.,!?;:");
    while (word!= NULL) {
        if (numWords >= MAX_WORDS_IN_MSG) {
            break;
        }
        tokens[numWords] = word;
        numWords++;
        word = strtok(NULL, " \t\n\r\f\v.,!?;:");
    }

    for (i = 0; i < numWords; i++) {
        for (j = 0; j < 10; j++) {
            if (strcmp(tokens[i], spamWords[j]) == 0) {
                numSpamWords++;
                break;
            }
        }
    }

    if (numSpamWords >= 3) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int main() {
    char msg[100];

    printf("Enter message: ");
    scanf("%s", msg);

    if (isSpam(msg)) {
        printf("Message is spam.\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}