//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int is_palindrome(char *word);
int is_palindrome_ignore_case(char *word);
int is_palindrome_ignore_spaces(char *word);
int is_palindrome_ignore_spaces_and_case(char *word);

int main() {
    char word[MAX_WORD_LENGTH];
    int choice;
    int result;

    printf("Welcome to the Palindrome Checker!\n");
    printf("Enter a word or phrase to check if it is a palindrome:\n");
    scanf("%s", word);

    printf("\nSelect a checking option:\n");
    printf("1. Check for palindrome (case sensitive)\n");
    printf("2. Check for palindrome (ignore case)\n");
    printf("3. Check for palindrome (ignore spaces)\n");
    printf("4. Check for palindrome (ignore spaces and case)\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            result = is_palindrome(word);
            break;
        case 2:
            result = is_palindrome_ignore_case(word);
            break;
        case 3:
            result = is_palindrome_ignore_spaces(word);
            break;
        case 4:
            result = is_palindrome_ignore_spaces_and_case(word);
            break;
        default:
            printf("Invalid option selected.\n");
            return 1;
    }

    if(result == 1) {
        printf("%s is a palindrome.\n", word);
    } else {
        printf("%s is not a palindrome.\n", word);
    }

    return 0;
}

int is_palindrome(char *word) {
    int length = strlen(word);
    int i;

    for(i = 0; i < length/2; i++) {
        if(word[i]!= word[length-i-1]) {
            return 0;
        }
    }

    return 1;
}

int is_palindrome_ignore_case(char *word) {
    int length = strlen(word);
    int i;

    for(i = 0; i < length/2; i++) {
        if(tolower(word[i])!= tolower(word[length-i-1])) {
            return 0;
        }
    }

    return 1;
}

int is_palindrome_ignore_spaces(char *word) {
    int length = strlen(word);
    int i;

    for(i = 0; i < length/2; i++) {
        while(isspace(word[i])) {
            i++;
        }
        while(isspace(word[length-i-1])) {
            length--;
        }
        if(tolower(word[i])!= tolower(word[length-i-1])) {
            return 0;
        }
    }

    return 1;
}

int is_palindrome_ignore_spaces_and_case(char *word) {
    int length = strlen(word);
    int i;

    for(i = 0; i < length/2; i++) {
        while(isspace(word[i])) {
            i++;
        }
        while(isspace(word[length-i-1])) {
            length--;
        }
        if(tolower(word[i])!= tolower(word[length-i-1])) {
            return 0;
        }
    }

    return 1;
}