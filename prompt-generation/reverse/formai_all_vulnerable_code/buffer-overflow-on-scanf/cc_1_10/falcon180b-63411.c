//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int is_palindrome(char* str) {
    // Convert the input string to lowercase
    for(int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
    
    // Remove non-alphanumeric characters from the string
    char* cleaned_str = strdup(str);
    for(int i = 0; i < strlen(cleaned_str); i++) {
        if(!isalnum(cleaned_str[i])) {
            cleaned_str[i] = '\0';
        }
    }
    
    // Reverse the cleaned string
    char reversed_str[MAX_LENGTH];
    int j = 0;
    for(int i = strlen(cleaned_str) - 1; i >= 0; i--) {
        reversed_str[j] = cleaned_str[i];
        j++;
    }
    
    // Compare the reversed string with the original string
    for(int i = 0; i < strlen(str); i++) {
        if(reversed_str[i]!= str[i]) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input);
    
    // Check if the input string is a palindrome
    if(is_palindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }
    
    return 0;
}