//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

/* Function to reverse a string */
void reverse(char str[]) {
    int i = 0, j = strlen(str) - 1;
    char temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

/* Function to check if a string is a palindrome */
int isPalindrome(char str[]) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        if (tolower(str[i])!= tolower(str[j])) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

/* Function to remove all vowels from a string */
void removeVowels(char str[]) {
    int i = 0, j = 0;
    while (str[i]) {
        if (!isalpha(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

/* Function to count the number of words in a string */
int countWords(char str[]) {
    int i = 0, j = 0, count = 0;
    while (str[i]) {
        if (isspace(str[i])) {
            count++;
        }
        i++;
    }
    return count;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    /* Remove leading/trailing spaces */
    int i = 0;
    while (isspace(input[i])) {
        i++;
    }
    int j = strlen(input) - 1;
    while (isspace(input[j])) {
        input[j] = '\0';
        j--;
    }

    /* Reverse the string */
    reverse(input);

    /* Check if the string is a palindrome */
    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    /* Remove all vowels from the string */
    removeVowels(input);
    printf("The string without vowels: %s\n", input);

    /* Count the number of words in the string */
    int wordCount = countWords(input);
    printf("The number of words in the string: %d\n", wordCount);

    return 0;
}