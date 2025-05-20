//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 101

void reverse(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int is_palindrome(char *str) {
    int length = strlen(str);
    if (length <= 1) {
        return 1;
    }

    for (int i = 0; i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0;
        }
    }

    // Surprisingly, we still have to reverse the second half of the string!
    reverse(str, length / 2, length - 1);

    for (int i = length / 2; i < length; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[MAX_LENGTH];

    printf("I can't believe it! Enter a string and I'll tell you if it's a palindrome!\n");
    scanf("%s", input);

    if (is_palindrome(input)) {
        printf("Wow, '%s' is a palindrome! I'm amazed!\n", input);
    } else {
        printf("I can't believe it's not a palindrome! Oh well, try another one.\n");
    }

    return 0;
}