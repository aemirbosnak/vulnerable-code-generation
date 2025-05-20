//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: high level of detail
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

int isPalindrome(char *str) {
    int i, j;
    char temp;
    
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (!isalnum(str[i])) {
            i++;
        }
        if (!isalnum(str[j])) {
            j--;
        }
        if (tolower(str[i])!= tolower(str[j])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_LENGTH];
    int length;
    
    printf("Enter a string to check if it is a palindrome: ");
    fgets(input, MAX_LENGTH, stdin);
    length = strlen(input);
    
    // Remove leading/trailing spaces
    while (isspace(input[0])) {
        strcpy(input, input + 1);
        length--;
    }
    while (isspace(input[length - 1])) {
        input[length - 1] = '\0';
        length--;
    }
    
    // Convert to lowercase
    for (int i = 0; i < length; i++) {
        input[i] = tolower(input[i]);
    }
    
    if (isPalindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }
    
    return 0;
}