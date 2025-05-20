//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

// Function prototypes
void generate_random_string(char *str, int len);
int is_palindrome(char *str);
int count_vowels(char *str);
void reverse_string(char *str);

int main()
{
    char input_string[100];
    int len, i, j, count;

    printf("Enter a string: ");
    scanf("%s", input_string);
    len = strlen(input_string);

    // Remove whitespace and make lowercase
    for (i = 0; i < len; i++) {
        if (isspace(input_string[i])) {
            input_string[i] = '\0';
        } else {
            input_string[i] = tolower(input_string[i]);
        }
    }

    // Count vowels
    count = count_vowels(input_string);
    printf("Number of vowels: %d\n", count);

    // Check if palindrome
    if (is_palindrome(input_string)) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    // Generate random string
    generate_random_string(input_string, len);
    printf("Random string: %s\n", input_string);

    // Reverse string
    reverse_string(input_string);
    printf("Reversed string: %s\n", input_string);

    return 0;
}

// Function to generate a random string of given length
void generate_random_string(char *str, int len)
{
    int i;
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for (i = 0; i < len; i++) {
        str[i] = charset[rand() % strlen(charset)];
    }
    str[len] = '\0';
}

// Function to check if a string is a palindrome
int is_palindrome(char *str)
{
    int len, i;

    len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        if (str[i]!= str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to count the number of vowels in a string
int count_vowels(char *str)
{
    int len, count;

    len = strlen(str);
    count = 0;
    for (int i = 0; i < len; i++) {
        if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u') {
            count++;
        }
    }
    return count;
}

// Function to reverse a string
void reverse_string(char *str)
{
    int len, i;

    len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}