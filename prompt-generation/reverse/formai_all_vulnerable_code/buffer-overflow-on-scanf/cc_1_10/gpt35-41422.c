//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: scalable
#include <stdio.h>
#include <string.h>

void check_palindrome(char*);

int main() {
    char word[100];

    printf("Enter a word: ");
    scanf("%s", &word);

    check_palindrome(word);
    
    return 0;
}

void check_palindrome(char* word) {
    int len = strlen(word);
    int i, j, is_palindrome=1;

    // Remove any non alpha-numeric characters
    for(i=0; i<len; i++) {
        if(!isalnum(word[i])) {
            for(j=i; j<len; j++) {
                word[j] = word[j+1];
            }
            len--;
            i--;
        }
    }

    // Convert to lowercase
    for(i=0; i<len; i++) {
        word[i] = tolower(word[i]);
    }

    // Check for palindrome
    for(i=0; i<len/2; i++) {
        if(word[i] != word[len-i-1]) {
            is_palindrome = 0;
            break;
        }
    }

    if(is_palindrome) {
        printf("%s is a palindrome.", word);
    }
    else {
        printf("%s is not a palindrome.", word);
    }
}