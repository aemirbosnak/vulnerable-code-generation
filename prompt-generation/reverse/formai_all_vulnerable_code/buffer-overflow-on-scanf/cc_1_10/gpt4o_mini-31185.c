//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_menu() {
    printf("\n----- C String Manipulation Menu -----\n");
    printf("1. Concatenate Strings\n");
    printf("2. Reverse a String\n");
    printf("3. Check Palindrome\n");
    printf("4. Calculate Length of a String\n");
    printf("5. Convert to Uppercase\n");
    printf("6. Convert to Lowercase\n");
    printf("7. Exit\n");
    printf("--------------------------------------\n");
    printf("Choose an option: ");
}

void concatenate_strings() {
    char str1[100], str2[100], result[200];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    strcpy(result, str1);
    strcat(result, str2);
    printf("Concatenated Result: %s\n", result);
}

void reverse_string() {
    char str[100];
    printf("Enter a string to reverse: ");
    scanf("%s", str);
    int len = strlen(str);
    char reversed[100];
    for(int i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0'; // Null-terminate the string
    printf("Reversed String: %s\n", reversed);
}

void check_palindrome() {
    char str[100];
    printf("Enter a string to check for palindrome: ");
    scanf("%s", str);
    int len = strlen(str);
    int is_palindrome = 1;
    
    for(int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }
}

void calculate_length() {
    char str[100];
    printf("Enter a string to find its length: ");
    scanf("%s", str);
    int length = strlen(str);
    printf("Length of the string \"%s\" is: %d\n", str, length);
}

void convert_to_uppercase() {
    char str[100];
    printf("Enter a string to convert to uppercase: ");
    scanf("%s", str);
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
    printf("Uppercase String: %s\n", str);
}

void convert_to_lowercase() {
    char str[100];
    printf("Enter a string to convert to lowercase: ");
    scanf("%s", str);
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
    printf("Lowercase String: %s\n", str);
}

int main() {
    while (1) {
        display_menu();
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                concatenate_strings();
                break;
            case 2:
                reverse_string();
                break;
            case 3:
                check_palindrome();
                break;
            case 4:
                calculate_length();
                break;
            case 5:
                convert_to_uppercase();
                break;
            case 6:
                convert_to_lowercase();
                break;
            case 7:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}