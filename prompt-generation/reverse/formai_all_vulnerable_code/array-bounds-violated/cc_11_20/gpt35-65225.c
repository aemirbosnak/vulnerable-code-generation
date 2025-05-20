//FormAI DATASET v1.0 Category: String manipulation ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], new_str[100];
    int i, j, len;

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    len = strlen(str);

    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        // Reversing the string
        new_str[j] = str[i];
    }
    new_str[j] = '\0';

    printf("\nOriginal String: %s", str);
    printf("\nReversed String: %s", new_str);

    // Finding the length of the string
    len = strlen(new_str);
    printf("\nLength of the Reversed String: %d", len);

    // Finding the number of vowels in the string
    int vowels = 0;
    for(i = 0; i < len; i++) {
        if(new_str[i] == 'a' || new_str[i] == 'e' || new_str[i] == 'i' || new_str[i] == 'o' || new_str[i] == 'u' || new_str[i] == 'A' || new_str[i] == 'E' || new_str[i] == 'I' || new_str[i] == 'O' || new_str[i] == 'U') {
            vowels++;
        }
    }
    printf("\nNumber of Vowels in the Reversed String: %d", vowels);

    // Appending a string to the end
    char append_str[100];
    printf("\nEnter a string to be appended to the reversed string: ");
    fgets(append_str, 100, stdin);

    // Removing the newline character from the end of the input
    len = strlen(append_str);
    if (append_str[len-1] == '\n') {
        append_str[len-1] = '\0';
    }

    strcat(new_str, append_str);
    printf("\nAppended String: %s", new_str);

    return 0;
}