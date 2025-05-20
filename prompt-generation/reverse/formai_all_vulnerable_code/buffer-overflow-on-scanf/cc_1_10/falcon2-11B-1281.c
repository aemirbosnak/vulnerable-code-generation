//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

int main() {
    // Read the input email text
    char email_text[10000];
    scanf("%[^\n]s", email_text);
    
    // Convert the text to lowercase for case-insensitive comparison
    for (int i = 0; i < strlen(email_text); i++) {
        email_text[i] = tolower(email_text[i]);
    }
    
    // Split the text into words
    char **words = (char **)malloc(strlen(email_text) + 1 * sizeof(char *));
    int num_words = 0;
    for (int i = 0; i < strlen(email_text); i++) {
        if (isalnum(email_text[i])) {
            words[num_words] = (char *)malloc((i - num_words) * sizeof(char));
            for (int j = num_words; j <= i; j++) {
                words[num_words][j - num_words] = email_text[j];
            }
            num_words++;
        }
    }
    words[num_words] = NULL;
    
    // Define the spam words
    char *spam_words[] = {"free", "offer", "discount", "limited", "time", "now", "act", "today"};
    
    // Count the number of spam words in the email
    int num_spam_words = 0;
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < sizeof(spam_words) / sizeof(spam_words[0]); j++) {
            if (strcmp(spam_words[j], words[i]) == 0) {
                num_spam_words++;
                break;
            }
        }
    }
    
    // Output the result
    if (num_spam_words > 0) {
        printf("This email is spam.\n");
    } else {
        printf("This email is not spam.\n");
    }
    
    // Free memory
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
    
    return 0;
}