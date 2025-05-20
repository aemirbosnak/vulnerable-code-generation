//FormAI DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <string.h>

int main()
{
    //Get input strings from user
    char s1[50], s2[50];
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);
    
    //Print original strings
    printf("Original strings:\n");
    printf("String 1: %s\n", s1);
    printf("String 2: %s\n", s2);

    //Combine strings into a new string with alternating characters
    char newString[100];
    int i = 0, j = 0, k = 0;
    while (s1[i] != '\0' && s2[j] != '\0') {
        newString[k++] = s1[i++];
        newString[k++] = s2[j++];
    }
    while (s1[i] != '\0') {
        newString[k++] = s1[i++];
    }
    while (s2[j] != '\0') {
        newString[k++] = s2[j++];
    }
    newString[k] = '\0';

    //Print new string
    printf("New string with alternating characters: %s\n", newString);

    // Count the number of vowels in the new string
    int countVowels = 0;
    for (i = 0; i < strlen(newString); i++) {
        if (newString[i] == 'a' || newString[i] == 'e' || newString[i] == 'i' || newString[i] == 'o' || newString[i] == 'u') {
            countVowels++;
        }
    }

    //Print number of vowels in new string
    printf("Number of vowels in new string: %d\n", countVowels);

    //Check if new string is a palindrome
    int isPalindrome = 1;
    k = strlen(newString) - 1;
    for (i = 0; i < strlen(newString) / 2; i++) {
        if (newString[i] != newString[k--]) {
            isPalindrome = 0;
            break;
        }
    }

    //Print whether new string is a palindrome or not
    if (isPalindrome == 1) {
        printf("The new string is a palindrome.\n");
    }
    else {
        printf("The new string is not a palindrome.\n");
    }

    return 0;
}