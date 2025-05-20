//Falcon-180B DATASET v1.0 Category: Error handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

/* Function to reverse a string */
void reverse_string(char *str) {
    int len = strlen(str);
    char *rev_str = malloc(len + 1);
    if (rev_str == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    int j = 0;
    for (int i = len - 1; i >= 0; i--) {
        rev_str[j] = str[i];
        j++;
    }
    rev_str[j] = '\0';
    printf("Reversed string: %s\n", rev_str);
    free(rev_str);
}

/* Function to check if a string is a palindrome */
int is_palindrome(char *str) {
    int len = strlen(str);
    char *rev_str = malloc(len + 1);
    if (rev_str == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    int j = 0;
    for (int i = len - 1; i >= 0; i--) {
        rev_str[j] = str[i];
        j++;
    }
    rev_str[j] = '\0';
    if (strcmp(str, rev_str) == 0) {
        printf("String is a palindrome\n");
        free(rev_str);
        return 1;
    } else {
        printf("String is not a palindrome\n");
        free(rev_str);
        return 0;
    }
}

int main() {
    char str[MAX_LEN];
    printf("Enter a string: ");
    scanf("%s", str);
    is_palindrome(str);
    return 0;
}