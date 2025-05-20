//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    printf("Welcome to the User Input Sanitizer program!\n\n");
    
    char input[100];
    printf("Please enter your input:\n");
    fgets(input, sizeof(input), stdin);
    
    int len = strlen(input);
    
    // remove newline character if exists
    if (input[len-1] == '\n') {
        input[len-1] = '\0';
        len--;
    }
    
    // check for invalid characters
    int i = 0;
    while (i < len) {
        if (!(isalpha(input[i]) || isdigit(input[i]))) {
            printf("Error: Input contains invalid characters.\n");
            exit(1);
        }
        i++;
    }
    
    // convert input to lowercase
    for (i = 0; i < len; i++) {
        input[i] = tolower(input[i]);
    }
    
    // remove any spaces
    char sanitized_input[len];
    int j = 0;
    for (i = 0; i < len; i++) {
        if (input[i] != ' ') {
            sanitized_input[j] = input[i];
            j++;
        }
    }
    sanitized_input[j] = '\0';
    
    // check if input is a palindrome
    int palindrome = 1;
    len = strlen(sanitized_input);
    for (i = 0; i < len/2; i++) {
        if (sanitized_input[i] != sanitized_input[len-i-1]) {
            palindrome = 0;
            break;
        }
    }
    
    // print sanitized input and tell if it is a palindrome
    printf("Sanitized input: %s\n", sanitized_input);
    if (palindrome) {
        printf("Wow, your input is a palindrome!\n");
    } else {
        printf("Your input is not a palindrome, but that's okay. Keep trying!\n");
    }
    
    return 0;
}