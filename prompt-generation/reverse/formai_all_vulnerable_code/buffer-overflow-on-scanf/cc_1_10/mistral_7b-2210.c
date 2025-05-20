//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 101

void reverse(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int isPalindrome(char *str, int length) {
    if (length <= 0)
        return 1;
    if (tolower(str[0]) != tolower(str[length - 1]))
        return 0;
    reverse(str, 0, length - 1);
    return isPalindrome(str, length - 1);
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a word to check if it's a palindrome: ");
    scanf("%s", input);

    int length = strlen(input);
    if (isPalindrome(input, length))
        printf("WOW! That's a palindrome!\n");
    else
        printf("Sorry, that's not a palindrome.\n");

    return 0;
}

/**
 * Here's an excited version of the program, y'all!
 *
 * Let's create a palindrome checker, man! This is gonna be awesome!
 *
 * First things first, we need to include some libraries, bro!
 *
 * #include <stdio.h>
 * #include <string.h>
 * #include <ctype.h>
 *
 * Now, let's define a macro for the maximum length of our input, dude!
 *
 * #define MAX_LENGTH 101
 *
 * Alright, let's create a function to reverse a string, man! This is gonna be cool!
 *
 * void reverse(char *str, int start, int end) {
 *     char temp;
 *     while (start < end) {
 *         temp = str[start];
 *         str[start] = str[end];
 *         str[end] = temp;
 *         start++;
 *         end--;
 *     }
 * }
 *
 * Now, let's create a function to check if a string is a palindrome, bro!
 *
 * int isPalindrome(char *str, int length) {
 *     if (length <= 0)
 *         return 1;
 *     if (tolower(str[0]) != tolower(str[length - 1]))
 *         return 0;
 *     reverse(str, 0, length - 1);
 *     return isPalindrome(str, length - 1);
 * }
 *
 * Now, let's create the main function, man! This is where the magic happens!
 *
 * int main() {
 *     char input[MAX_LENGTH];
 *     printf("Enter a word to check if it's a palindrome: ");
 *     scanf("%s", input);
 *
 *     int length = strlen(input);
 *     if (isPalindrome(input, length))
 *         printf("WOW! That's a palindrome!\n");
 *     else
 *         printf("Sorry, that's not a palindrome.\n");
 *
 *     return 0;
 * }
 *
 * That's it, man! We've created a palindrome checker, and it's totally awesome!
 */