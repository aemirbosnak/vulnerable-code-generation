//FormAI DATASET v1.0 Category: String manipulation ; Style: brave
#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    char temp;
    for(int i=0; i<len/2; i++) {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

int main() {
    char str1[100], str2[100];
    int choice, len1, len2;

    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    len1 = strlen(str1);
    str1[len1-1] = '\0'; // Removing the newline character from the input string

    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    len2 = strlen(str2);
    str2[len2-1] = '\0'; // Removing the newline character from the input string

    printf("\nWhat would you like to do with these strings?\n");
    printf("1. Concatenate the strings\n");
    printf("2. Reverse the strings\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcat(str1, str2); // Concatenating the two strings
            printf("Concatenated string: %s\n", str1);
            break;
        case 2:
            printf("Reversing the first string: ");
            reverseString(str1); // Reversing the first string
            printf("%s\n", str1);

            printf("Reversing the second string: ");
            reverseString(str2); // Reversing the second string
            printf("%s\n", str2);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}