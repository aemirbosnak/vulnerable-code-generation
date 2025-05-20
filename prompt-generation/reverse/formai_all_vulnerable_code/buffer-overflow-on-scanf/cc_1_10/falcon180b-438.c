//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: genious
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// Function to reverse a string
void reverse(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
        start++;
        end--;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int i, j, len;
    len = strlen(str);
    for (i = 0, j = len-1; i < j; i++, j--) {
        if (tolower(*(str+i))!= tolower(*(str+j))) {
            return 0;
        }
    }
    return 1;
}

// Function to translate a string to Alien language
void translate(char *str) {
    int i, len;
    len = strlen(str);
    for (i = 0; i < len; i++) {
        if (isalpha(*(str+i))) {
            *(str+i) = *(str+i) + 13;
        }
    }
}

int main() {
    char str[1000];
    int len;

    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);

    // Remove spaces and special characters
    char *p = strtok(str, ",.?!;:");
    while (p!= NULL) {
        strcat(str, p);
        p = strtok(NULL, ",.?!;:");
    }

    // Reverse the string
    reverse(str, 0, len-1);

    // Check if the reversed string is a palindrome
    if (isPalindrome(str)) {
        printf("The reversed string is a palindrome.\n");
    } else {
        printf("The reversed string is not a palindrome.\n");
    }

    // Translate the string to Alien language
    translate(str);
    printf("The translated string is: %s\n", str);

    return 0;
}