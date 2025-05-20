//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_MESSAGE_LENGTH 100
#define NUM_FILTERS 5

struct Filter {
    char keyword[10];
    int threshold;
};

bool is_spam(const char* message, const struct Filter filters[NUM_FILTERS]) {
    for (int i = 0; i < NUM_FILTERS; i++) {
        int keyword_length = strlen(filters[i].keyword);
        int message_length = strlen(message);

        for (int j = 0; j < message_length - keyword_length + 1; j++) {
            int k;
            bool match = true;

            for (k = 0; k < keyword_length; k++) {
                if (tolower(message[j + k]) != tolower(filters[i].keyword[k])) {
                    match = false;
                    break;
                }
            }

            if (match) {
                int count = 0;
                for (int l = j; l < j + keyword_length; l++) {
                    if (isdigit(message[l])) {
                        count++;
                    }
                }

                if (count > filters[i].threshold) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    struct Filter filters[NUM_FILTERS] = {{"Nuke", 3}, {"Survive", 2}, {"SOS", 1}, {"Radiation", 3}, {"Help", 1}};
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    if (message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }

    if (is_spam(message, filters)) {
        printf("SPAM DETECTED!\n");
    } else {
        printf("Message is clean.\n");
    }

    return 0;
}