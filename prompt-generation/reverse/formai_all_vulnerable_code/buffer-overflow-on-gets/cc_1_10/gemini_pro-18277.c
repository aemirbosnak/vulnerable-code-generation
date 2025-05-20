//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *str, *rev;
    int len, i;

    printf("Hello there, pal-o-meter enthusiast! Let's put your words to the palindrome test, shall we?\n");
    printf("Type in your word or phrase, and brace yourself for the truth!\n");

    //Dynamically allocate memory for the string
    str = (char *)malloc(100);
    if (str == NULL) {
        printf("Oops, we couldn't find enough memory to store your words. Try again with something smaller!\n");
        exit(1);
    }

    //Get the string from the user
    printf("Input: ");
    gets(str);

    //Find the length of the string
    len = strlen(str);

    //Dynamically allocate memory for the reversed string
    rev = (char *)malloc(len + 1);
    if (rev == NULL) {
        printf("Uh-oh, we're still short on memory. Please enter a shorter word or phrase.\n");
        exit(1);
    }

    //Reverse the string
    for (i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0';

    //Compare the original string with the reversed string
    if (strcmp(str, rev) == 0) {
        printf("\nWow, you've got a palindrome on your hands! Your word or phrase reads the same forwards and backwards – how cool!\n");
    } else {
        printf("\nSorry, but your input is not a palindrome. Maybe try a different word or phrase and see if it passes the test?\n");
    }

    //Free the allocated memory
    free(str);
    free(rev);

    return 0;
}