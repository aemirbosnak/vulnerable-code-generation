//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void itoa(int num, char *str, int base) {
    int i = 0;
    char *ptr = str;
    const char *digits = "0123456789ABCDEF";

    if (num == 0) {
        *ptr++ = '0';
        *ptr = '\0';
        return;
    }

    while (num) {
        *ptr++ = digits[num % base];
        num /= base;
        i++;
    }

    reverse(ptr);

    *ptr = '\0';
}

int main() {
    char str1[MAX_SIZE] = "", str2[MAX_SIZE] = "";
    int num = 12345;
    char op;

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);

    itoa(num, str1, 10);
    printf("Number in string form (decimal): %s\n", str1);

    strcpy(str2, "hello world");
    printf("Original string: %s\n", str2);

    reverse(str2);
    printf("Reversed string: %s\n", str2);

    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    if (strcmp(str1, "12345helloworld") == 0) {
        printf("Strings are identical\n");
    } else {
        printf("Strings are different\n");
    }

    return 0;
}