//FormAI DATASET v1.0 Category: Spam Detection System ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 50
#define MAX_SPAM_LENGTH 20

char spam_words[MAX_SPAM_WORDS][MAX_SPAM_LENGTH];
int num_spam_words = 0;

int is_spam(char* message) {
    char* word = strtok(message, " ");
    while (word != NULL) {
        for (int i = 0; i < num_spam_words; i++) {
            if (strcmp(word, spam_words[i]) == 0) {
                return 1;
            }
        }
        word = strtok(NULL, " ");
    }
    return 0;
}

void add_spam_word(char* word) {
    // Check if word already exists
    for (int i = 0; i < num_spam_words; i++) {
        if (strcmp(word, spam_words[i]) == 0) {
            printf("%s already exists in spam word list.\n", word);
            return;
        }
    }
    if (num_spam_words == MAX_SPAM_WORDS) {
        printf("Cannot add %s to spam word list, maximum number of words reached.\n", word);
        return;
    }
    strcpy(spam_words[num_spam_words], word);
    num_spam_words++;
    printf("Added %s to spam word list.\n", word);
}

void remove_spam_word(char* word) {
    int removed = 0;
    for (int i = 0; i < num_spam_words; i++) {
        if (strcmp(word, spam_words[i]) == 0) {
            // Shift remaining elements left
            for (int j = i; j < num_spam_words - 1; j++) {
                strcpy(spam_words[j], spam_words[j+1]);
            }
            num_spam_words--;
            removed = 1;
            printf("Removed %s from spam word list.\n", word);
            break;
        }
    }
    if (!removed) {
        printf("%s was not found in spam word list.\n", word);
    }
}

void print_spam_words() {
    printf("Spam words:\n");
    for (int i = 0; i < num_spam_words; i++) {
        printf("%d. %s\n", i+1, spam_words[i]);
    }
}

int main() {
    char message[100];
    int choice;

    while (1) {
        printf("Choose an option:\n");
        printf("1. Add spam word\n");
        printf("2. Remove spam word\n");
        printf("3. View spam word list\n");
        printf("4. Test message for spam\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a new spam word: ");
                scanf("%s", message);
                add_spam_word(message);
                break;
            case 2:
                printf("Enter the word to remove: ");
                scanf("%s", message);
                remove_spam_word(message);
                break;
            case 3:
                print_spam_words();
                break;
            case 4:
                printf("Enter message to test: ");
                fgets(message, 100, stdin);
                if (is_spam(message)) {
                    printf("The message contains spam.\n");
                } else {
                    printf("The message is not spam.\n");
                }
                break;
            case 5:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
                break;
        }
    }
}