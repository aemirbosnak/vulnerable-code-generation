//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: creative
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void print_palindrome_art(void);

bool is_palindrome(const char* str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (tolower(str[left]) != tolower(str[right])) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main(void) {
    char input[101];

    print_palindrome_art();
    printf("Enter a string: ");
    scanf("%s", input);

    if (is_palindrome(input)) {
        printf("%s is a palindrome!\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }

    print_palindrome_art();

    return 0;
}

void print_palindrome_art(void) {
    printf("\n");
    printf("                      .--.        .--. \n");
    printf("           ________  /  _  \\____  /  _  \\\n");
    printf("          /  _  __ \\|  |_|  / _ \\|  |_|  \n");
    printf("         |  |_|  | |    ||  _/ |    ||  \n");
    printf("         |  _  _| |    || |    |    ||  \n");
    printf("         |_|  |_| |____|/ |_|    |____|/ \n");
    printf("                       |__|        |__|\n");
    printf("\n");
}