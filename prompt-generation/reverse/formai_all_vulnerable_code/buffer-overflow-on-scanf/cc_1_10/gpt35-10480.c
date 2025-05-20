//FormAI DATASET v1.0 Category: String manipulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

// Function to reverse a given string
void reverse_string(char* str) {
    int len = strlen(str);
    int i, j;
    char temp;

    for(i=0, j=len-1; i<(len/2); i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to count the number of vowels in a given string
int count_vowels(char* str) {
    int len = strlen(str);
    int count = 0, i;

    for(i=0; i<len; i++) {
        char c = *(str+i);
        switch(c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                count++;
                break;
            default:
                break;
        }
    }

    return count;
}

// Function to check if a given string is a palindrome
int is_palindrome(char* str) {
    int len = strlen(str);
    int i, j;

    for(i=0, j=len-1; i<j; i++, j--) {
        if(str[i] != str[j]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[100];

    // Take input from the user
    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    // Reverse the input string
    reverse_string(str);
    printf("Reversed string: %s\n", str);

    // Count the number of vowels in the input string
    int vowel_count = count_vowels(str);
    printf("Number of vowels: %d\n", vowel_count);

    // Check if the input string is a palindrome
    int is_pal = is_palindrome(str);
    if(is_pal) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    return 0;
}