//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_MESSAGES 100
#define MESSAGE_LENGTH 256
#define SPAM_WORDS 5

const char *spam_words[SPAM_WORDS] = {
    "win", "free", "guarantee", "click", "buy"
};

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_spam(const char *message) {
    for (int i = 0; i < SPAM_WORDS; i++) {
        if (strstr(message, spam_words[i]) != NULL) {
            return 1; // Spam detected!
        }
    }
    return 0; // No spam found!
}

void print_menu() {
    printf("========================================\n");
    printf("       Welcome to Spam Detector!      \n");
    printf("========================================\n");
    printf("1. Analyze a message\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char messages[MAX_MESSAGES][MESSAGE_LENGTH];
    int count = 0, choice;

    printf("Spam Detection System Initialized!\n");

    while (1) {
        print_menu();
        scanf("%d", &choice);
        getchar(); // To consume the newline

        if (choice == 1) {
            if (count >= MAX_MESSAGES) {
                printf("Message limit reached! Please reset.\n");
                continue;
            }

            printf("Enter your message: ");
            fgets(messages[count], MESSAGE_LENGTH, stdin);
            messages[count][strcspn(messages[count], "\n")] = 0; // Remove newline

            to_lower_case(messages[count]);

            if (is_spam(messages[count])) {
                printf("🚫 Spam Alert! The message contains spam phrases.\n");
            } else {
                printf("✅ No Spam Detected! Your message is safe.\n");
            }

            count++;
        } else if (choice == 2) {
            printf("Thank you for using the Spam Detection System! Goodbye! 🎉\n");
            break;
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}