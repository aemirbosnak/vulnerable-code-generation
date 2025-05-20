//FormAI DATASET v1.0 Category: String manipulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    int length = strlen(name);
    char* reverse = (char*)malloc(length + 1);

    // Reverse the name using a for loop
    for (int i = 0; i < length; i++) {
        reverse[i] = name[length - 1 - i];
    }
    reverse[length] = '\0';

    printf("Your name backwards is: %s\n", reverse);
    
    // Find the first vowel in the name
    char* vowels = "aeiouAEIOU";
    char* first_vowel = strpbrk(name, vowels);

    if (first_vowel != NULL) {
        printf("The first vowel in your name is '%c'\n", *first_vowel);
        
        // Replace all occurrences of the first vowel with an asterisk
        char* asterisks = (char*)malloc(length + 1);
        memset(asterisks, '*', length);
        
        char* replaced = (char*)malloc(length + 1);
        char* str = name;
        while (*str != '\0') {
            if (*str == *first_vowel) {
                strcat(replaced, asterisks);
            } else {
                strncat(replaced, str, 1);
            }
            str++;
        }
        replaced[length] = '\0';
        
        printf("Your name with first vowel replaced with asterisks is: %s\n", replaced);
        
        free(asterisks);
        free(replaced);
    } else {
        printf("Your name contains no vowels.\n");
    }

    free(reverse);
    return 0;
}