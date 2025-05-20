//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000
#define TRUE 1
#define FALSE 0

int is_palindrome(char* str) {
    int i, j;
    char clean_str[MAX_LENGTH];
    strcpy(clean_str, str);
    for (i = 0, j = strlen(clean_str)-1; i < j; i++, j--) {
        if (tolower(clean_str[i])!= tolower(clean_str[j])) {
            return FALSE;
        }
    }
    return TRUE;
}

void reverse_string(char* str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str)-1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char input[MAX_LENGTH];
    int choice, length;
    printf("Welcome to the String Manipulation Program!\n");
    while (TRUE) {
        printf("\nPlease choose an option:\n");
        printf("1. Reverse a string\n");
        printf("2. Check if a string is a palindrome\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a string: ");
                scanf("%s", input);
                reverse_string(input);
                printf("Reversed string: %s\n", input);
                break;
            case 2:
                printf("Enter a string: ");
                scanf("%s", input);
                if (is_palindrome(input)) {
                    printf("%s is a palindrome!\n", input);
                } else {
                    printf("%s is not a palindrome.\n", input);
                }
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}