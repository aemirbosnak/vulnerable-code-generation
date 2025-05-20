//FormAI DATASET v1.0 Category: String manipulation ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {
    char str1[25]; // array to store first string
    char str2[25]; // array to store second string

    printf("Welcome to the String Manipulation Program!\n\n");

    printf("Please enter the first string (maximum 25 characters): ");
    scanf("%s", str1);

    printf("Please enter the second string (maximum 25 characters): ");
    scanf("%s", str2);

    // Concatenate the two strings
    strcat(str1, str2);

    printf("\n\nThe concatenated string is: %s\n\n", str1);

    // Get the length of the concatenated string
    int length = strlen(str1);

    printf("The length of the concatenated string is: %d\n\n", length);

    // Reverse the concatenated string
    char reverse[length];

    int index = 0;
    for(int i=length-1; i>=0; i--) {
        reverse[index] = str1[i];
        index++;
    }

    reverse[index] = '\0';

    printf("The reversed string is: %s\n\n", reverse);

    // Change all lowercase letters in the reversed string to uppercase
    char uppercase[length];

    for(int i=0; i<length; i++) {
        if(reverse[i] >= 'a' && reverse[i] <= 'z') {
            uppercase[i] = reverse[i] - 32;
        }
        else {
            uppercase[i] = reverse[i];
        }
    }

    uppercase[index] = '\0';

    printf("The reversed string in uppercase is: %s\n\n", uppercase);

    printf("Thank you for using the String Manipulation Program!");

    return 0;
}