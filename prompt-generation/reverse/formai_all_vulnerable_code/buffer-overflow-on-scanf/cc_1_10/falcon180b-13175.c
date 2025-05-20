//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int get_string_length(char *str);
void reverse_string(char *str);
int main() {
    char input[100];

    // Get input string
    printf("Enter a string: ");
    scanf("%s", input);

    // Get length of input string
    int length = get_string_length(input);

    // Reverse the input string
    reverse_string(input);

    // Print reversed string
    printf("Reversed string: %s\n", input);

    // Print length of input string
    printf("Length of input string: %d\n", length);

    return 0;
}

// Function to get length of a string
int get_string_length(char *str) {
    int length = 0;

    while (*(str + length)!= '\0') {
        length++;
    }

    return length;
}

// Function to reverse a string
void reverse_string(char *str) {
    int length = get_string_length(str);
    char temp;

    // Swap characters starting from both ends
    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}