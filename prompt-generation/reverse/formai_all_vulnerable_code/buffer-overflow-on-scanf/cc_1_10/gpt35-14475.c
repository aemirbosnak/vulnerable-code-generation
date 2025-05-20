//FormAI DATASET v1.0 Category: Text processing ; Style: visionary
#include <stdio.h>
#include <string.h>

// Function to check if a given string is a palindrome or not
int isPalindrome(char *str) {
    int i, j;
    for(i=0, j=strlen(str)-1; i<j; i++, j--) {
        if(str[i] != str[j]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

int main() {    
    char str[100];
    int option;

    printf("Welcome to the Visionary Text Processor!\n\n");

    while(1) {
        printf("Please select an option:\n");
        printf("1. Check if a string is a palindrome\n");
        printf("2. Count the number of words in a string\n");
        printf("3. Capitalize the first letter of each word in a string\n");
        printf("4. Exit\n");

        scanf("%d", &option); // Getting user input

        switch(option) {
            case 1: // Palindrome check
                printf("Please enter the string: ");
                scanf("%s", str);
                if(isPalindrome(str)) {
                    printf("The string is a palindrome!\n\n");
                }
                else {
                    printf("The string is not a palindrome.\n\n");
                }
                break;

            case 2: // Word count
                printf("Please enter the string: ");
                scanf("\n%[^\n]", str);
                int count = 0, i;
                for(i=0; str[i]!='\0'; i++) {
                    if(str[i] == ' ' && str[i+1] != ' ') { 
                        count++;
                    }
                }
                count++; // Adding one for the last word
                printf("The number of words in the string is: %d\n\n", count);
                break;

            case 3: // Capitalizing first letter of each word
                printf("Please enter the string: ");
                scanf("\n%[^\n]", str);
                str[0] = toupper(str[0]); // Capitalizing first letter
                for(i=1; str[i]!='\0'; i++) {
                    if(str[i] == ' ' && str[i+1] != ' ') {
                        str[i+1] = toupper(str[i+1]); // Capitalizing next letter
                    }
                }
                printf("The modified string is: %s\n\n", str);
                break;

            case 4: // Exit
                printf("Thank you for using the Visionary Text Processor!\n");
                return 0;

            default:
                printf("Invalid option.\n\n");
        }
    }
}