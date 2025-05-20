//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SYMBOLS_NUM 26

typedef struct {
    int count;
    int symbol[SYMBOLS_NUM];
} message;

void encodeMessage(char *input, message *messageToEncode) {
    memset(messageToEncode->symbol, 0, SYMBOLS_NUM * sizeof(int));

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            messageToEncode->symbol[input[i] - 'a']++;
        }
    }
}

bool isPalindrome(char *input) {
    message message1, message2;

    encodeMessage(input, &message1);
    encodeMessage(input, &message2);

    for (int i = 0; i < SYMBOLS_NUM; i++) {
        if (message1.symbol[i] && message2.symbol[SYMBOLS_NUM - i - 1] && message1.symbol[i] != message2.symbol[SYMBOLS_NUM - i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}