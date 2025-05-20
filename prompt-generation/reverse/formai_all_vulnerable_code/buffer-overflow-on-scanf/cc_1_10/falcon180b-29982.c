//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to reverse a string
void reverse(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;

    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

// function to check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;

    while (start < end) {
        if (tolower(*start)!= tolower(*end)) {
            return 0;
        }
        start++;
        end--;
    }

    return 1;
}

// function to remove all vowels from a string
void removeVowels(char *str) {
    char vowels[] = "aeiouAEIOU";
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;

    while (start < end) {
        if (strchr(vowels, tolower(*start))!= NULL) {
            *start = '\0';
        }
        start++;
    }
}

int main() {
    char str[1000];

    // get input string from user
    printf("Enter a string: ");
    scanf("%s", str);

    // reverse the string
    reverse(str);

    // check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    // remove all vowels from the string
    removeVowels(str);

    // print the modified string
    printf("Modified string: %s\n", str);

    return 0;
}