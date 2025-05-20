//FormAI DATASET v1.0 Category: Binary Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BINARY_LENGTH 50

void reverse(char s[])
{
    int length, c;
    char *begin, *end, temp;

    length = strlen(s);

    begin = s;
    end = s;

    for (c = 0; c < length - 1; c++)
        end++;

    for (c = 0; c < length/2; c++)
    {
        temp = *end;
        *end = *begin;
        *begin = temp;

        begin++;
        end--;
    }
}

void paranoidBinaryConverter() {

    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    char binary[MAX_BINARY_LENGTH];
    int i = 0;

    while (num != 0) {
        binary[i++] = (num % 2 == 0 ? '0' : '1');
        num /= 2;
    }

    binary[i] = '\0';

    reverse(binary);

    printf("The binary representation is: %s\n", binary);

    int len = strlen(binary);
    if(len > MAX_BINARY_LENGTH - 1 || len == 0) {
        printf("Invalid binary length, exiting...\n");
        exit(1);
    }

    for(int i=0; i<len; i++) {
        if(binary[i] != '1' && binary[i] != '0') {
            printf("Error: Invalid binary detected, exiting...\n");
            exit(1);
        }
    }

    printf("Paranoid check complete.\n");
}

int main() {
    paranoidBinaryConverter();
    return 0;
}