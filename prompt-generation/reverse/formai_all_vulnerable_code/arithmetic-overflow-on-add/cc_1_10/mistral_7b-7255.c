//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define HASH_SIZE 10000

typedef struct {
    char word[20];
    int hash;
} HashEntry;

void hash_word(const char *word, int *hash) {
    int sum = 0;
    for (int i = 0; word[i]; i++) {
        sum += tolower((unsigned char) word[i]);
    }
    *hash = sum % HASH_SIZE;
}

bool is_spam(const char *input) {
    static HashEntry whitelist[] = {
        {"hello", 3423}, {"world", 1234}, {"spam", 5678}, {"test", 9876}
    };
    static HashEntry spamlist[1000];
    static bool spam_init = false;

    if (!spam_init) {
        int i, j;
        FILE *spam_file = fopen("spam.txt", "r");
        if (!spam_file) {
            perror("Could not open spam file");
            exit(EXIT_FAILURE);
        }

        for (i = 0; i < HASH_SIZE; i++) {
            char line[100];
            if (fgets(line, sizeof(line), spam_file) == NULL) break;

            sscanf(line, "%s %n", spamlist[i].word, &i);
            hash_word(spamlist[i].word, &spamlist[i].hash);
        }
        fclose(spam_file);
        spam_init = true;
    }

    int input_hash;
    hash_word(input, &input_hash);
    for (int i = 0; i < sizeof(whitelist) / sizeof(HashEntry); i++) {
        if (strcmp(input, whitelist[i].word) == 0 && input_hash == whitelist[i].hash) {
            return false;
        }
    }

    for (int i = 0; i < 1000; i++) {
        if (input_hash == spamlist[i].hash) {
            return true;
        }
    }

    return false;
}

int main() {
    char input[100];
    printf("Enter your message: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (is_spam(input)) {
        printf("Your message is spam.\n");
    } else {
        printf("Your message is not spam.\n");
    }

    return 0;
}