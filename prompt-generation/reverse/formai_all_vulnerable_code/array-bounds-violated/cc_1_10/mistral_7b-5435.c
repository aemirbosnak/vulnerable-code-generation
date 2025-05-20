//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 1000

void reverse_string(char *str, int length) {
    int start = 0, end = length - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int check_palindrome(char *str, int length) {
    int i;

    reverse_string(str, length);

    for (i = 0; str[i] != '\0' && i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[MAX_STR_LEN];
    int length, result;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    length = strlen(str);
    str[length - 1] = '\0'; // Remove the newline character from fgets

    result = check_palindrome(str, length);

    if (result == 1) {
        printf("Palindrome\n");
    } else {
        printf("Not a Palindrome\n");
    }

    return 0;
}