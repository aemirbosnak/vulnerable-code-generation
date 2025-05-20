#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[1001];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    
    int attempt = 0;
    while (attempt < 2) {
        if (isPalindrome(input)) {
            printf("The string is a palindrome.\n");
            return 0;
        } else {
            printf("The string is not a palindrome. Try again: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
            attempt++;
        }
    }
    printf("Failed after two attempts.\n");
    return 0;
}
