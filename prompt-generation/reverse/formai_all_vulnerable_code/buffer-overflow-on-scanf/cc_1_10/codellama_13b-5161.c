//Code Llama-13B DATASET v1.0 Category: Browser Plugin ; Style: real-life
// Browser Plugin Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a string to uppercase
void to_uppercase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        i++;
    }
}

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }
}

// Function to reverse a string
void reverse(char *str) {
    int i, j, len;
    len = strlen(str);
    for (i = 0, j = len - 1; i < j; i++, j--) {
        str[i] = str[i] ^ str[j];
        str[j] = str[i] ^ str[j];
        str[i] = str[i] ^ str[j];
    }
}

// Main function
int main() {
    char input[100];
    char output[100];
    printf("Enter a string: ");
    scanf("%s", input);
    to_uppercase(input);
    printf("The uppercase string is: %s\n", input);
    to_lowercase(input);
    printf("The lowercase string is: %s\n", input);
    reverse(input);
    printf("The reversed string is: %s\n", input);
    return 0;
}