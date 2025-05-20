//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int get_size_of_string(const char *string) {
    int size = 0;
    while (string[size] != '\0') {
        ++size; 
    }
    return size;
}

int is_palindrome(const char *string) {
    char temp1, temp2;
    int i = 0, j;
    int size = get_size_of_string(string);
    j = size - 1;

    while (i < j) {
        if (isalpha(string[i]) && isalpha(string[j])) {
            temp1 = tolower(string[i]);
            temp2 = tolower(string[j]);
            if (temp1 != temp2) {
                return 0;
            }
            ++i;
            --j;
        } else if (isalpha(string[i])) {
            --j;
        } else {
            ++i;
        }
    }
    return 1;
}

void print_output(const char *string) {
    int size = get_size_of_string(string);
    printf("\nEntered string: %s\n", string);
    
    if (is_palindrome(string)) {
        printf("Result: %s is a palindrome\n", string);
    } else {
        printf("Result: %s is not a palindrome\n", string);
    }
}

int main() {
    char string[100];
    printf("\nEnter a string to check if it is a palindrome: ");
    gets(string);
    print_output(string);
    return 0;
}