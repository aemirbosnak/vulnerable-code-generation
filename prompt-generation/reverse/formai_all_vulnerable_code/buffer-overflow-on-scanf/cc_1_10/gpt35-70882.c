//FormAI DATASET v1.0 Category: String manipulation ; Style: excited
#include <stdio.h>
#include <string.h>

/* This is a unique C string manipulation example program! */
int main() {
    char str1[50], str2[50]; // initialize two character arrays
    int length1, length2;

    printf("Welcome to the AMAZING String Manipulator!\n");
    printf("Enter your first string: ");
    scanf("%s", str1); // get user input for first string
    printf("Enter your second string: ");
    scanf("%s", str2); // get user input for second string

    length1 = strlen(str1); // get the length of the first string
    length2 = strlen(str2); // get the length of the second string

    printf("\nNow let's have some fun!\n");
    printf("Your first string is \"%s\" and the length is %d\n", str1, length1);
    printf("Your second string is \"%s\" and the length is %d\n", str2, length2);

    printf("\nFirst string in uppercase: ");
    for(int i = 0; i < length1; i++){
        printf("%c", toupper(str1[i])); // print each character of the first string in uppercase
    }

    printf("\nSecond string in lowercase: ");
    for(int i = 0; i < length2; i++) {
        printf("%c", tolower(str2[i])); // print each character of the second string in lowercase
    }

    // combine the two strings and print the result
    printf("\nYour first string and second string combined: %s%s\n", str1, str2);

    // check if the two strings are equal or not
    if(strcmp(str1, str2) == 0) {
        printf("Wow, your strings are equal!\n");
    } else {
        printf("Your strings are not equal :(\n");
    }

    // reverse the order of characters of the first string and print the result
    printf("First string in reverse: ");
    for(int i = length1 - 1; i >= 0; i--) {
        printf("%c", str1[i]);
    }

    printf("\n\nHope you enjoyed playing around with strings using the AMAZING String Manipulator!");
    return 0;
}