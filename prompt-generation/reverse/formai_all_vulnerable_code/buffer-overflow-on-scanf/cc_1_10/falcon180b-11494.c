//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int is_numeric(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int is_palindrome(char *str) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            return 0;
        }
    }
    return 1;
}

int is_pangram(char *str) {
    int i;
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    for (i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            str[i] = tolower(str[i]);
            if (strchr(alphabet, str[i]) == NULL) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char str[MAX_LEN];
    printf("Enter a string: ");
    scanf("%s", str);

    if (is_numeric(str)) {
        printf("The string is numeric.\n");
    } else if (is_palindrome(str)) {
        printf("The string is a palindrome.\n");
    } else if (is_pangram(str)) {
        printf("The string is a pangram.\n");
    } else {
        printf("The string is none of the above.\n");
    }

    return 0;
}