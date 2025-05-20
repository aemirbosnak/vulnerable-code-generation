//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove all vowels from a string
void remove_vowels(char* str) {
    int i, j;
    char vowels[] = "AEIOUaeiou";
    for(i=0, j=0; str[i]; i++) {
        if(strchr(vowels, toupper(str[i])) == NULL) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Function to reverse a string
void reverse_string(char* str) {
    int i, j;
    char temp;
    for(i=0, j=strlen(str)-1; i<j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int i, j;
    for(i=0, j=strlen(str)-1; i<j; i++, j--) {
        if(str[i]!= str[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    scanf("%s", str);

    // Remove all vowels from the string
    remove_vowels(str);

    // Reverse the string
    reverse_string(str);

    // Check if the modified string is a palindrome
    if(is_palindrome(str)) {
        printf("Modified string is a palindrome.\n");
    } else {
        printf("Modified string is not a palindrome.\n");
    }

    return 0;
}