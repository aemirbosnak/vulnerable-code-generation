//FormAI DATASET v1.0 Category: String manipulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int len;

    // Read the input string
    printf("Enter a string: ");
    fgets(str1, 100, stdin);

    // Remove the new line character from the end
    len = strlen(str1);
    if (len > 0 && str1[len-1] == '\n') {
        str1[len-1] = '\0';
    }

    // Copy the input string to another string
    strcpy(str2, str1);
    printf("Original String: %s\n", str1);

    // Reverse the string
    int i, j;
    char temp;
    for (i=0, j=len-1; i<j; i++, j--) {
        temp = str1[i];
        str1[i] = str1[j];
        str1[j] = temp;
    }
    printf("Reversed String: %s\n", str1);

    // Check if the string is a palindrome or not
    int isPalindrome = 1;
    for(i=0; i<len/2; i++) {
        if(str1[i] != str1[len-i-1]) {
            isPalindrome = 0;
            break;
        }
    }
    if(isPalindrome) {
        printf("The string is a palindrome\n");
    }
    else {
        printf("The string is not a palindrome\n");
    }

    // Convert the string to uppercase and lowercase
    int option;
    printf("Choose option:\n1) Convert to Uppercase\n2) Convert to Lowercase\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            for(i=0; i<len; i++) {
                str2[i] = toupper(str2[i]);
            }
            printf("Uppercase String: %s\n", str2);
            break;
        case 2:
            for(i=0; i<len; i++) {
                str2[i] = tolower(str2[i]);
            }
            printf("Lowercase String: %s\n", str2);
            break;
        default:
            printf("Invalid option selected\n");
    }

    return 0;
}