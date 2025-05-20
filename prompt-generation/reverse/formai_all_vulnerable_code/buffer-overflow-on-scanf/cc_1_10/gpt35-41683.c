//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LEN 100
#define SPAM_THRESHOLD 0.5

struct message {
    char text[MAX_MSG_LEN];
    int length;
    double spam_score;
    int is_spam;
};

// Function to calculate the spam score of a message
double calculate_spam_score(char *text, int length) {
    int i, caps_count = 0, exclamation_count = 0, dollar_count = 0;
    double caps_ratio, exclamation_ratio, dollar_ratio;
    for(i = 0; i < length; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z') {
            caps_count++;
        }
        if(text[i] == '!') {
             exclamation_count++;
        }
        if(text[i] == '$') {
            dollar_count++;
        }
    }
    caps_ratio = (double) caps_count / length;
    exclamation_ratio = (double) exclamation_count / length;
    dollar_ratio = (double) dollar_count / length;
    return 0.4 * caps_ratio + 0.5 * exclamation_ratio + 0.1 * dollar_ratio;
}

// Function to classify a message as spam or not based on its spam score
void classify_message(struct message *msg) {
    if(msg->spam_score > SPAM_THRESHOLD) {
        msg->is_spam = 1;
    } else {
        msg->is_spam = 0;
    }
}

int main() {
    int num_msgs, i;
    char text[MAX_MSG_LEN];
    struct message messages[10];
    printf("Enter the number of messages to classify:\n");
    scanf("%d", &num_msgs);
    for(i = 0; i < num_msgs; i++) {
        printf("Enter message %d:\n", i + 1);
        scanf("%s", text);
        strcpy(messages[i].text, text);
        messages[i].length = strlen(text);
        messages[i].spam_score = calculate_spam_score(text, messages[i].length);
        classify_message(&messages[i]);
        if(messages[i].is_spam) {
            printf("Message %d is spam.\n", i + 1);
        } else {
            printf("Message %d is not spam.\n", i + 1);
        }
    }
    return 0;
}