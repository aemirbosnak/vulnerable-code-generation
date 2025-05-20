//FormAI DATASET v1.0 Category: System administration ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to check if a given string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    for(int i = 0; i < len/2; i++) {
        if(*(str+i) != *(str+len-i-1)) {
            return 0;
        }
    }
    return 1;
}

//Function to find the largest palindrome in a given input
void find_largest_palindrome(char *input) {
    char *temp = (char*)malloc(strlen(input)+1);
    char *largest_palindrome = (char*)malloc(strlen(input)+1);
    int i, j, k, len, found = 0;
    len = strlen(input);

    for(i = 0; i < len; i++) {
        for(j = i+1; j < len; j++) {
            for(k = 0; k < (j-i+1); k++) {
                *(temp+k) = *(input+i+k);
            }
            *(temp+k) = '\0';
            if(is_palindrome(temp)) {
                found = 1;
                if(strlen(temp) > strlen(largest_palindrome)) {
                    strcpy(largest_palindrome, temp);
                }
            }
        }
    }

    if(found) {
        printf("The largest palindrome found in the input is: %s\n", largest_palindrome);
    } else {
        printf("No palindrome found in the input!\n");
    }
    free(temp);
    free(largest_palindrome);
}

//Function to reverse a given string
char* reverse_string(char *str) {
    int len = strlen(str);
    char *rev_str = (char*)malloc(len+1);
    for(int i = 0; i < len; i++) {
        *(rev_str+i) = *(str+len-i-1);
    }
    *(rev_str+len) = '\0';
    return rev_str;
}

//Function to check if a given string is a palindrome using recursion
int is_palindrome_recursive(char *str, int start, int end) {
    if(start >= end) {
        return 1;
    }
    if(*(str+start) != *(str+end)) {
        return 0;
    }
    return is_palindrome_recursive(str, start+1, end-1);
}

int main() {
    char input[100];
    printf("Enter an input string: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("1. Find the largest palindrome in the input\n");
    printf("2. Check if the input is a palindrome using recursion\n");
    printf("Choose an option (1/2): ");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            find_largest_palindrome(input);
            break;
        case 2:
            if(is_palindrome_recursive(input, 0, strlen(input)-1)) {
                printf("The input is a palindrome!\n");
            } else {
                printf("The input is not a palindrome!\n");
            }
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}