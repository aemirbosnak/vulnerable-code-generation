//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: genious
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

int isPalindrome(char* str) {
    int length = strlen(str);
    char reversed[MAX_LENGTH];
    int i = 0, j = length - 1;

    while (i < j) {
        if (!isalnum(str[i])) {
            i++;
            continue;
        }
        if (!isalnum(str[j])) {
            j--;
            continue;
        }
        if (tolower(str[i])!= tolower(str[j])) {
            return 0;
        }
        reversed[i] = str[j];
        reversed[j] = str[i];
        i++;
        j--;
    }

    if (i >= j) {
        return 1;
    }

    return 0;
}

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string: ");
    scanf("%s", input);

    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}