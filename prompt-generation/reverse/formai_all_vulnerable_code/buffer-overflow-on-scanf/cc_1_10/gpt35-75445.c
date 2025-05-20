//FormAI DATASET v1.0 Category: String manipulation ; Style: rigorous
#include <stdio.h>
#include <string.h>

// Function to reverse a string "in-place"
void reverseString(char *str) {
    int len = strlen(str);
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to sort a string in ascending order using bubble sort
void sortString(char *str) {
    int len = strlen(str);
    int i, j;
    for (i = 0; i < len-1; i++) {
        for (j = 0; j < len-i-1; j++) {
            if (str[j] > str[j+1]) {
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}

int main() {
    // Declare a string
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string and print
    reverseString(str);
    printf("Reversed string: %s\n", str);

    // Sort the string and print
    sortString(str);
    printf("Sorted string: %s\n", str);

    // Find the number of occurrences of a character in the string
    char c;
    int count = 0;
    printf("Enter a character to count: ");
    scanf(" %c", &c);

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    printf("Number of occurrences of '%c': %d\n", c, count);

    // Replace all occurrences of a character with a different character
    char a, b;
    printf("Enter the character to replace: ");
    scanf(" %c", &a);
    printf("Enter the replacement character: ");
    scanf(" %c", &b);

    for (int i = 0; i < len; i++) {
        if (str[i] == a) {
            str[i] = b;
        }
    }
    printf("String with all '%c' replaced with '%c': %s\n", a, b, str);

    return 0;
}