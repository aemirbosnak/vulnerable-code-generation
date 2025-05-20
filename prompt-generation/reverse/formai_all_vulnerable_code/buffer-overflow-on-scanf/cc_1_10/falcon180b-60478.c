//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

/* Function to reverse a string */
void reverseString(char* str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

/* Function to check if a string is a palindrome */
int isPalindrome(char* str) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            return 0;
        }
    }
    return 1;
}

/* Function to remove all vowels from a string */
void removeVowels(char* str) {
    int i;
    char vowels[] = "aeiouAEIOU";
    for (i = 0; str[i]!= '\0'; i++) {
        if (strchr(vowels, str[i]) == NULL) {
            str[i] = str[i + 1];
            str[i + 1] = '\0';
            i--;
        }
    }
}

/* Function to count the number of words in a string */
int countWords(char* str) {
    int i, count = 0;
    char delimiters[] = ",.?!;:";
    for (i = 0; str[i]!= '\0'; i++) {
        if (strchr(delimiters, str[i])!= NULL) {
            count++;
        }
    }
    return count;
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    /* Reverse the string */
    reverseString(str);
    printf("Reversed string: %s\n", str);

    /* Check if the string is a palindrome */
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    /* Remove all vowels from the string */
    removeVowels(str);
    printf("String without vowels: %s\n", str);

    /* Count the number of words in the string */
    int numWords = countWords(str);
    printf("Number of words in the string: %d\n", numWords);

    return 0;
}