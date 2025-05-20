//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE];
    int length, i, j;
    char *p;
    int count = 0;
    int flag = 0;
    int num1 = 0, num2 = 0;
    int result = 0;
    int k = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", input);
    length = strlen(input);

    for (i = 0; i < length; i++) {
        if (isalpha(input[i])) {
            count++;
        }
    }

    if (count == 0) {
        printf("Error: Input string must contain at least one alphabet.\n");
        exit(1);
    }

    for (i = 0; i < length; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                input[i] = input[i] - 'A' + 'a';
            } else {
                input[i] = input[i] - 'a' + 'A';
            }
        }
    }

    for (i = 0; i < length; i++) {
        if (isalpha(input[i])) {
            num1 = input[i] - 'A' + 1;
            num2 = input[i + 1] - 'A' + 1;

            if (i == length - 1) {
                num2 = num2 - 1;
            }

            result = (num1 * num2) % 26;

            if (result == 0) {
                result = 26;
            }

            j = result - 1;

            if (j < 0) {
                j = j + 26;
            }

            input[i] = j + 'A';
            input[i + 1] = j + 'A';

            i++;
        }
    }

    printf("Encrypted string: %s\n", input);

    return 0;
}