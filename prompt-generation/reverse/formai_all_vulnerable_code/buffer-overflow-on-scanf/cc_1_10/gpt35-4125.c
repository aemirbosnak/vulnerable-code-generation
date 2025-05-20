//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// define our struct to represent a word and its palindrome status
typedef struct {
    char* str;
    int is_palindrome;
} Word;

// function to check if a word is a palindrome
int is_palindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-1-i]) {
            return 0;
        }
    }
    return 1;
}

// function to create a new Word struct
Word create_word(char* str) {
    Word word;
    word.str = str;
    word.is_palindrome = is_palindrome(str);
    return word;
}

int main() {

    // create an array of Word structs to hold our words and their palindrome status
    Word words[10];

    // prompt the user to input 10 words
    printf("Enter 10 words: \n");
    for (int i = 0; i < 10; i++) {
        char str[101];
        scanf("%s", str);
        words[i] = create_word(str);
    }

    // print out the results
    printf("\nResults:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s ", words[i].str);
        if (words[i].is_palindrome) {
            printf("is a palindrome.\n");
        } else {
            printf("is not a palindrome.\n");
        }
    }

    return 0;
}