//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_TOKENS 100
#define MIN_WORD_LENGTH 3
#define MIN_CHAR_LENGTH 2

int main() {
    char* email = (char*) malloc(MAX_LENGTH * sizeof(char));
    char* message = (char*) malloc(MAX_LENGTH * sizeof(char));
    
    printf("Enter the email address: ");
    scanf("%s", email);
    
    printf("Enter the message: ");
    scanf("%s", message);
    
    char tokens[MAX_TOKENS][MAX_LENGTH];
    int num_tokens = 0;
    
    int i = 0;
    while (i < strlen(message)) {
        if (isalpha(message[i])) {
            int j = 0;
            while (j < strlen(message) && isalnum(message[j])) {
                tokens[num_tokens][j] = message[j];
                j++;
            }
            tokens[num_tokens][j] = '\0';
            num_tokens++;
        }
        i++;
    }
    
    int num_emails = 0;
    int num_spams = 0;
    
    for (int k = 0; k < num_tokens; k++) {
        int len = strlen(tokens[k]);
        if (len < MIN_WORD_LENGTH) {
            continue;
        }
        
        int chars[len];
        int j = 0;
        while (j < len) {
            chars[j] = tolower(tokens[k][j]);
            j++;
        }
        
        int num_same_chars = 0;
        for (int l = 0; l < len; l++) {
            int count = 0;
            for (int m = l + 1; m < len; m++) {
                if (chars[l] == chars[m]) {
                    count++;
                }
            }
            if (count > 1) {
                num_same_chars++;
            }
        }
        
        if (num_same_chars > MIN_CHAR_LENGTH) {
            num_spams++;
        }
    }
    
    if (num_spams > num_emails) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }
    
    free(email);
    free(message);
    
    return 0;
}