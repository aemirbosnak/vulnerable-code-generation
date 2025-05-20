//Falcon-180B DATASET v1.0 Category: Recursive ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to reverse a string */
void reverse(char* str, int start, int end) {
    char temp;
    while (start < end) {
        temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
        start++;
        end--;
    }
}

/* Function to check if a string is a palindrome */
int isPalindrome(char* str, int start, int end) {
    while (start < end) {
        if (*(str+start)!= *(str+end)) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

/* Function to generate all possible substrings of a given string */
void generateSubstrings(char* str, int start, int end, int n) {
    if (start == end) {
        printf("%s\n", str);
        return;
    }
    for (int i = start; i <= end; i++) {
        str[i] = '\0';
        generateSubstrings(str, start, i-1, n);
        str[i] = str[end];
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int n = strlen(str);
    printf("Enter the number of characters to consider (1-%d): ", n);
    int k;
    scanf("%d", &k);
    generateSubstrings(str, 0, n-1, k);
    return 0;
}