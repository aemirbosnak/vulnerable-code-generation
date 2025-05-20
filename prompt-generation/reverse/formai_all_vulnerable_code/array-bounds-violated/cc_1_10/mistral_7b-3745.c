//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int is_palindrome(char str[], int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

void remove_whitespace(char str[], int size) {
    int i = 0, j = 0;

    while (i < size && isspace(str[i])) {
        i++;
    }

    while (i < size && j < size) {
        if (!isspace(str[i]) && !isspace(str[j])) {
            if (str[i] != str[j]) {
                str[j] = str[i];
            }
            i++;
            j++;
        } else if (!isspace(str[i])) {
            i++;
        } else {
            j++;
        }
    }

    str[j] = '\0';
}

int main() {
    char str[MAX_SIZE];
    int length, i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    remove_whitespace(str, strlen(str));

    length = strlen(str);

    if (is_palindrome(str, 0, length - 1)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    for (i = 0; i < length / 2 + 1; i++) {
        if (str[i] != str[length - i - 1]) {
            printf("The characters at indices %d and %d are not the same.\n", i, length - i - 1);
            break;
        }
    }

    if (i > length / 2) {
        printf("%s is a palindrome (manually checked).\n", str);
    }

    return 0;
}