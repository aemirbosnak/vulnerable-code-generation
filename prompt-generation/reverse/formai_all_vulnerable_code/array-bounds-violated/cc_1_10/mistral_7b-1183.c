//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void reverseString(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    printf("Original String: %s\n", str);

    reverseString(str);

    printf("Reversed String: %s\n", str);

    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            printf("String is not palindrome.\n");
            return 0;
        }
    }

    printf("String is a palindrome.\n");

    int pos = 0;
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == 'a') {
            pos = i;
            count++;
        }
    }

    if (count > 1) {
        for (int i = pos - 1; i >= 0 && str[i] != 'a'; i--) {
            str[i + 1] = str[i];
        }

        str[pos - 1] = 'e';
    }

    printf("String after processing: %s\n", str);

    int index = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == 'e') {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index + 1; i < len; i++) {
            if (str[i] != 'a') {
                str[i - 1] = str[i];
            }
        }

        str[len - 1] = '\0';
        reverseString(&str[0]);
        reverseString(&str[index]);

        printf("Final String: %s\n", str);
    }

    return 0;
}