//Falcon-180B DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Function to print a string in reverse order
void reverseString(char* str) {
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
}

// Recursive function to count the number of vowels in a string
int countVowels(char* str) {
    if (*str == '\0') {
        return 0;
    }
    if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' || *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U') {
        return 1 + countVowels(str + 1);
    }
    return countVowels(str + 1);
}

// Recursive function to print a pattern of asterisks
void printPattern(int n) {
    if (n == 0) {
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");
    printPattern(n - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("The string in reverse order is: ");
    reverseString(str);
    printf("\n");
    int vowelCount = countVowels(str);
    if (vowelCount == 0) {
        printf("The string does not contain any vowels.\n");
    }
    else {
        printf("The string contains %d vowels.\n", vowelCount);
    }
    int n;
    printf("Enter the number of rows for the pattern: ");
    scanf("%d", &n);
    printf("The pattern of asterisks is:\n");
    printPattern(n);
    return 0;
}