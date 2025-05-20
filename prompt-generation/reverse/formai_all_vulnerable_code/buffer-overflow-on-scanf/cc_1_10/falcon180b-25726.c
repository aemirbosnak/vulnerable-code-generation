//Falcon-180B DATASET v1.0 Category: Text processing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove all punctuation marks from a given string
void removePunctuations(char* str) {
    int i = 0;
    while (str[i]) {
        if (!isalnum(str[i])) { // Check if the character is not alphanumeric
            str[i] = '\0';
        }
        i++;
    }
}

// Function to reverse a given string
void reverseString(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to check if two strings are anagrams of each other
int areAnagrams(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1!= len2) { // Check if the lengths of the strings are not equal
        return 0;
    }
    removePunctuations(str1);
    removePunctuations(str2);
    reverseString(str1);
    reverseString(str2);
    if (strcmp(str1, str2) == 0) { // Compare the modified strings
        return 1;
    }
    return 0;
}

int main() {
    char input1[100];
    char input2[100];
    printf("Enter the first string: ");
    scanf("%s", input1);
    printf("Enter the second string: ");
    scanf("%s", input2);
    if (areAnagrams(input1, input2)) {
        printf("The strings are anagrams of each other.\n");
    }
    else {
        printf("The strings are not anagrams of each other.\n");
    }
    return 0;
}