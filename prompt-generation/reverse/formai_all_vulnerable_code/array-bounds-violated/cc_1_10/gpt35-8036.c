//FormAI DATASET v1.0 Category: String manipulation ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int length;

    printf("Enter the first string: ");
    fgets(str1, 100, stdin); // input from user
    printf("Enter the second string: ");
    fgets(str2, 100, stdin);

    length = strlen(str1); // using strlen function to get length of string

    // concatenating the strings
    strcat(str1, str2);

    printf("\nConcatenated string: %s \n", str1);

    // finding and replacing the character
    for(int i = 0; i < length; i++) {
        if(str1[i] == 'a') { // finding the character
            str1[i] = '*'; // replacing the character
        }
    }

    printf("Replaced string: %s \n", str1);

    // calculating the number of words
    int words = 1; // assuming there will be at least one word
    for(int i = 0; i < length; i++) {
        if(str1[i] == ' ' && str1[i-1] != ' ') { // checking for word boundary
            words++; 
        }
    }

    printf("Number of words: %d \n", words);

    // reversing the string
    char temp;
    for(int i = 0; i < length/2; i++) {
        temp = str1[i];
        str1[i] = str1[length - i - 1];
        str1[length - i - 1] = temp;
    }

    printf("Reversed string: %s \n", str1);

    return 0;
}