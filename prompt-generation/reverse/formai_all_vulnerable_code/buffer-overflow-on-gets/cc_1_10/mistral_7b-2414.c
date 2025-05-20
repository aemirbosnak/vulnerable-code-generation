//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: mind-bending
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void reverse(char *str, int start, int end) {
    char temp;
    if (start >= end)
        return;

    reverse(str, start + 1, end - 1);
    temp = str[start];
    str[start] = str[end];
    str[end] = temp;
}

int main() {
    char str[MAX_SIZE];
    int i, checksum = 0;

    printf("Enter a string: ");
    gets(str);

    // Reverse the string
    reverse(str, 0, strlen(str) - 1);

    // Concatenate the reversed string with the original string
    char concatenated_str[MAX_SIZE * 2] = {0};
    strcat(concatenated_str, str);
    strcat(concatenated_str, str);

    // Print the concatenated string
    printf("Concatenated String: %s\n", concatenated_str);

    // Store ASCII codes in a character array
    char ascii_codes[strlen(concatenated_str)];
    for (i = 0; i < strlen(concatenated_str); i++) {
        ascii_codes[i] = concatenated_str[i];
    }

    // Calculate checksum using XOR operation
    for (i = 0; i < strlen(concatenated_str); i++) {
        checksum ^= ascii_codes[i];
    }

    // Print the checksum
    printf("Checksum: %d\n", checksum);

    return 0;
}