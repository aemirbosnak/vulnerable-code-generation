//FormAI DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define MAX_STRING_LENGTH 1000

char string1[MAX_STRING_LENGTH], string2[MAX_STRING_LENGTH];
char reversed[MAX_STRING_LENGTH];
int length = 0, choice = 0;

void reverseString() {
    int i;
    for(i = 0; i < length; i++) {
        reversed[i] = string1[length - i - 1];
    }
    reversed[length] = '\0';
}

void compareStrings() {
    if(strcmp(string1, string2) == 0) {
        printf("\n%s and %s are same\n", string1, string2);
    }
    else {
        printf("\n%s and %s are different\n", string1, string2);
    }
}

void findLength() {
    length = strlen(string1);
    printf("\nLength of %s = %d\n", string1, length);
}

void toUpperCase() {
    int i;
    for(i = 0; string1[i] != '\0'; i++) {
        if(string1[i] >= 'a' && string1[i] <= 'z') {
            string1[i] = string1[i] - 32;
        }
    }
}

void toLowerCase() {
    int i;
    for(i = 0; string1[i] != '\0'; i++) {
        if(string1[i] >= 'A' && string1[i] <= 'Z') {
            string1[i] = string1[i] + 32;
        }
    }
}

void removeSpaces() {
    int i, j;
    for(i = 0; string1[i] != '\0'; i++) {
        if(string1[i] != ' ') {
            string1[j++] = string1[i];
        }
    }
    string1[j] = '\0';
}

void countOccurrence() {
    char character;
    int count = 0, i;
    printf("Enter a character: ");
    scanf("%c", &character);
    for(i = 0; i < length; i++) {
        if(character == string1[i]) {
            count++;
        }
    }
    printf("\n%c occurs %d times in %s\n", character, count, string1);
}

void menu() {
    printf("\n\nMENU\n----\n");
    printf("1. Reverse a string\n");
    printf("2. Compare two strings\n");
    printf("3. Find length of a string\n");
    printf("4. Convert a string to upper case\n");
    printf("5. Convert a string to lower case\n");
    printf("6. Remove spaces from a string\n");
    printf("7. Count occurrence of a character in a string\n");
    printf("8. Quit\n\n");
    printf("Enter your choice (1-8): ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            reverseString();
            printf("\nReversed string: %s\n", reversed);
            break;
        case 2:
            printf("\nEnter string1: ");
            scanf(" %[^\n]s", string1);
            printf("Enter string2: ");
            scanf(" %[^\n]s", string2);
            compareStrings();
            break;
        case 3:
            printf("\nEnter a string: ");
            scanf(" %[^\n]s", string1);
            findLength();
            break;
        case 4:
            printf("\nEnter a string: ");
            scanf(" %[^\n]s", string1);
            toUpperCase();
            printf("\nUpper case of the given string: %s\n", string1);
            break;
        case 5:
            printf("\nEnter a string: ");
            scanf(" %[^\n]s", string1);
            toLowerCase();
            printf("\nLower case of the given string: %s\n", string1);
            break;
        case 6:
            printf("\nEnter a string with spaces: ");
            scanf(" %[^\n]s", string1);
            removeSpaces();
            printf("\nString after removing spaces: %s\n", string1);
            break;
        case 7:
            printf("\nEnter a string: ");
            scanf(" %[^\n]s", string1);
            findLength();
            countOccurrence();
            break;
        case 8:
            printf("\nThanks for using this program!\n");
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.\n");
    }
}

int main() {
    while(true) {
        menu();
        sleep(2);
    }
    return 0;
}