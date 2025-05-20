//FormAI DATASET v1.0 Category: Spam Detection System ; Style: mathematical
#include <stdio.h>

#define SPAM_THRESHOLD 0.7

double calculate_spam_score(char* message) {
    /* perform mathematical calculations to determine spam score */
    /* assume message is a null-terminated string */
    
    int num_chars = 0;
    int num_caps = 0;
    int num_digits = 0;
    int num_punct = 0;
    int num_spam_words = 0;
    
    for (int i = 0; message[i] != '\0'; i++) {
        num_chars++;
        
        if (message[i] >= 'A' && message[i] <= 'Z') {
            num_caps++;
        }
        
        if (message[i] >= '0' && message[i] <= '9') {
            num_digits++;
        }
        
        if (message[i] == '!' || message[i] == '?' || message[i] == '.') {
            num_punct++;
        }
    }
    
    /* assume spam words are "buy" and "sale" */
    char* spam_word1 = "buy";
    char* spam_word2 = "sale";
    
    char* ptr = message;
    while (ptr = strstr(ptr, spam_word1)) {
        num_spam_words++;
        ptr += strlen(spam_word1);
    }
    
    ptr = message;
    while (ptr = strstr(ptr, spam_word2)) {
        num_spam_words++;
        ptr += strlen(spam_word2);
    }
    
    double score = ((double)num_caps / num_chars * 0.4) + ((double)num_digits / num_chars * 0.2) 
                    + ((double)num_punct / num_chars * 0.1) + ((double)num_spam_words * 0.3);
    
    return score;
}

int main() {
    char message[1000];
    printf("Enter message: ");
    scanf("%[^\n]s", message);
    
    double spam_score = calculate_spam_score(message);
    
    if (spam_score >= SPAM_THRESHOLD) {
        printf("This message is likely spam.\n");
    } else {
        printf("This message is not spam.\n");
    }
    
    return 0;
}