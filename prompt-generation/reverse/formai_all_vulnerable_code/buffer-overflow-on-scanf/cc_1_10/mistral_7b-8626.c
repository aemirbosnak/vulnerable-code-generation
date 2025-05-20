//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

void reverse_string(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int is_alphanumeric(char c) {
    return (isalnum(c) || isspace(c) || c == '_');
}

int check_palindrome(char *str) {
    int size = strlen(str);
    if (size <= 1) {
        return 1;
    }

    for (int i = 0; i < size / 2; i++) {
        if (is_alphanumeric(str[i]) && is_alphanumeric(str[size - i - 1])) {
            if (tolower(str[i]) != tolower(str[size - i - 1])) {
                return 0;
            }
        } else if (!is_alphanumeric(str[i]) && !is_alphanumeric(str[size - i - 1])) {
            continue;
        } else {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char **argv) {
    char input[MAX_SIZE];

    printf("Welcome to Palindr0m3_Ch3ck3r_v3.0.c, the ultimate palindrome decipherer.\n");
    printf("Type your word or phrase, or enter 0 to exit: ");
    scanf("%s", input);

    if (strcmp(input, "0") == 0) {
        printf("Exiting Palindr0m3_Ch3ck3r_v3.0.c...\n");
        return 0;
    }

    reverse_string(input, 0, strlen(input) - 1);

    if (check_palindrome(input)) {
        printf("Palindrome detected! The word or phrase '%s' is a palindrome.\n", input);
    } else {
        printf("Palindrome not detected. The word or phrase '%s' is not a palindrome.\n", input);
    }

    reverse_string(input, 0, strlen(input) - 1);
    printf("Your word or phrase is now back in its original form.\n");

    return 0;
}