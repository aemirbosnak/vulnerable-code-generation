//FormAI DATASET v1.0 Category: String manipulation ; Style: introspective
#include <stdio.h>
#include <string.h>

/*
This program demonstrates the usage of C string manipulation functions.
It provides the user with a menu of different operations that can be performed on a given string.
The user can choose to perform any or all of the following operations:
1. Remove all occurrences of a given character from the string.
2. Replace all occurrences of a given character with another character.
3. Reverse the string.
4. Convert the string to uppercase.
5. Convert the string to lowercase.
*/

int main() {
    char str[1000], choice, charToRemove, charToReplace, newChar;
    int i;

    printf("Enter a string: ");
    fgets(str, 1000, stdin); // read input string from user

    do {
        printf("\n\nWhat would you like to do with this string?\n");
        printf("1. Remove all occurrences of a character.\n");
        printf("2. Replace all occurrences of a character with another character.\n");
        printf("3. Reverse the string.\n");
        printf("4. Convert the string to uppercase.\n");
        printf("5. Convert the string to lowercase.\n");
        printf("Enter your choice (1/2/3/4/5): ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                printf("\nEnter the character you want to remove: ");
                scanf(" %c", &charToRemove);
                for(i=0;i<strlen(str);i++) { // loop through string
                    if(str[i] == charToRemove) { // if the current character matches the char to be removed
                        for(int j=i;j<strlen(str);j++) { // shift all characters to the left by 1
                            str[j] = str[j+1];
                        }
                        i--;
                    }
                }
                printf("\nString after removing all occurrences of '%c': %s",charToRemove,str);
                break;
            case '2':
                printf("\nEnter the character you want to replace: ");
                scanf(" %c", &charToRemove);
                printf("\nEnter the new character: ");
                scanf(" %c", &newChar);
                for(i=0;i<strlen(str);i++) { // loop through string
                    if(str[i] == charToRemove) { // if the current character matches the char to be replaced
                        str[i] = newChar; // replace with new character
                    }
                }
                printf("\nString after replacing all occurrences of '%c' with '%c': %s",charToRemove,newChar,str);
                break;
            case '3':
                for(i=0;i<strlen(str)/2;i++) { // loop through half the string
                    // swap the characters at position i and length-i-1
                    char temp = str[i];
                    str[i] = str[strlen(str)-i-1];
                    str[strlen(str)-i-1] = temp;
                }
                printf("\nString after reversal: %s",str);
                break;
            case '4':
                for(i=0;i<strlen(str);i++) { // loop through string
                    str[i] = toupper(str[i]); // convert each character to uppercase
                }
                printf("\nString in uppercase: %s",str);
                break;
            case '5':
                for(i=0;i<strlen(str);i++) { // loop through string
                    str[i] = tolower(str[i]); // convert each character to lowercase
                }
                printf("\nString in lowercase: %s",str);
                break;
            default:
                printf("\nInvalid choice entered. Please try again.");
        }
    } while(choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5');

    return 0;
}