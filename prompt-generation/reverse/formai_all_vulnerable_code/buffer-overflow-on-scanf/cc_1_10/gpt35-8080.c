//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_MESSAGES 50
#define MAX_LENGTH 140
#define MAX_SPAM_COUNT 5

int spam_counts[MAX_MESSAGES] = {0};

void check_spam(char *message) {
    int i, j, length, count;

    length = strlen(message);

    for(i=0; i < length; i++) {
        count = 0;

        for(j=i+1; j < length; j++) {

            if(message[i] != message[j]) {
                break;
            }

            count++;
        }

        if(count >= 2) {
            spam_counts[i]++;
        }
    }
}

int main() {
    char messages[MAX_MESSAGES][MAX_LENGTH];
    int i, j, num_messages, spam_count, total_spam_count = 0;

    printf("Welcome to the Multiplayer Spam Detection System!\n");

    printf("How many messages do you want to check? ");
    scanf("%d", &num_messages);

    printf("Enter the %d messages to check:\n", num_messages);

    for(i=0; i < num_messages; i++) {
        scanf("%s", messages[i]);

        check_spam(messages[i]);

        if(spam_counts[i] >= MAX_SPAM_COUNT) {
            printf("Message %d is identified as spam.\n", i+1);
            total_spam_count++;
        }
    }

    if(total_spam_count > 0) {
        printf("\nTotal spam messages found: %d\n", total_spam_count);
    } else {
        printf("\nNo spam messages found!\n");
    }

    return 0;
}