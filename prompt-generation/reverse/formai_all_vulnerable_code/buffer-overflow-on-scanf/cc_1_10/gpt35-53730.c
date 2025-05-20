//FormAI DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

void printMenu();
void reverseString(char[], char[]);
void removeSpaces(char[], char[]);
void lowercaseString(char[], char[]);
void uppercaseString(char[], char[]);
void replaceString(char[], char[], char[], char[]);
void countVowels(char[]);

int main() {
    char choice;
    char inputString[MAX_STRING_LENGTH], outputString[MAX_STRING_LENGTH], str1[MAX_STRING_LENGTH], str2[MAX_STRING_LENGTH];

    printf("Enter a string: ");
    fgets(inputString, MAX_STRING_LENGTH, stdin);
    inputString[strcspn(inputString, "\n")] = 0; // remove newline character from inputString

    do {
        printMenu(); // print menu options
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                printf("\nSelected option: Reverse String\n");
                reverseString(inputString, outputString);
                printf("Output String: %s\n\n", outputString);
                break;

            case '2':
                printf("\nSelected option: Remove Spaces\n");
                removeSpaces(inputString, outputString);
                printf("Output String: %s\n\n", outputString);
                break;

            case '3':
                printf("\nSelected option: Convert to Lowercase\n");
                lowercaseString(inputString, outputString);
                printf("Output String: %s\n\n", outputString);
                break;

            case '4':
                printf("\nSelected option: Convert to Uppercase\n");
                uppercaseString(inputString, outputString);
                printf("Output String: %s\n\n", outputString);
                break;

            case '5':
                printf("\nSelected option: Replace String\n");
                printf("Enter the string to replace: ");
                scanf("%s", str1);
                printf("Enter the new string: ");
                scanf("%s", str2);
                replaceString(inputString, outputString, str1, str2);
                printf("Output String: %s\n\n", outputString);
                break;

            case '6':
                printf("\nSelected option: Count Vowels\n");
                countVowels(inputString);
                break;

            case '7':
                printf("Exiting Program...");
                break;

            default:
                printf("Invalid Choice\n\n");
                break;
        }
    } while(choice != '7');

    return 0;
}

void printMenu() {
    printf("====================================\n");
    printf("Enter the number of the operation:\n");
    printf("1. Reverse String\n");
    printf("2. Remove Spaces\n");
    printf("3. Convert to Lowercase\n");
    printf("4. Convert to Uppercase\n");
    printf("5. Replace String\n");
    printf("6. Count Vowels\n");
    printf("7. Exit Program\n");
    printf("====================================\n");
    printf("Enter Choice: ");
}

void reverseString(char input[], char output[]) {
    int i, j;

    for(i=strlen(input)-1, j=0; i>=0; i--, j++) {
        output[j] = input[i];
    }
    output[j] = '\0';
}

void removeSpaces(char input[], char output[]) {
    int i, j;

    for(i=0, j=0; i<strlen(input); i++) {
        if(input[i] != ' ') {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0';
}

void lowercaseString(char input[], char output[]) {
    int i;

    for(i=0; i<strlen(input); i++) {
        output[i] = tolower(input[i]);
    }
    output[i] = '\0';
}

void uppercaseString(char input[], char output[]) {
    int i;

    for(i=0; i<strlen(input); i++) {
        output[i] = toupper(input[i]);
    }
    output[i] = '\0';
}

void replaceString(char input[], char output[], char str1[], char str2[]) {
    int i, j, k, l;
    int stringMatch;

    for(i=0, j=0; i<strlen(input); i++) {

        stringMatch = 1;

        if(input[i] == str1[0]) {
            for(k=i, l=0; k<i+strlen(str1); k++, l++) {
                if(input[k] != str1[l]) {
                    stringMatch = 0;
                    break;
                }
            }

            if(stringMatch == 1) {
                for(k=0; k<strlen(str2); k++) {
                    output[j] = str2[k];
                    j++;
                }
                i = i+strlen(str1)-1;
            }
            else {
                output[j] = input[i];
                j++;
            }
        }
        else {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0';
}

void countVowels(char input[]) {
    int i;
    int vowelCount = 0;

    for(i=0; i<strlen(input); i++) {
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' ||
           input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') {
            vowelCount++;
        }
    }
    printf("Number of vowels in string: %d\n\n", vowelCount);
}