//FormAI DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE], str3[MAX_SIZE];
    int choice, length, i, j;

    printf("Enter first string: ");
    fgets(str1, MAX_SIZE, stdin);
    length = strlen(str1);

    // Remove trailing newline character
    if(str1[length-1] == '\n') {
        str1[length-1] = '\0';
        length--;
    }

    printf("\nWhat do you want to do with the string %s?\n", str1);
    printf("1. Convert it to all uppercase characters\n");
    printf("2. Convert it to all lowercase characters\n");
    printf("3. Reverse the string\n");
    printf("4. Remove all numbers\n");
    printf("5. Replace all spaces with hyphens (-)\n");
    printf("6. Remove all vowels\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    getchar(); // Consume newline character left in buffer by scanf

    switch(choice) {
        case 1:
            // Convert to uppercase
            for(i=0; str1[i]!='\0'; i++) {
                str2[i] = toupper(str1[i]);
            }
            str2[i] = '\0';
            printf("\nString in uppercase: %s\n", str2);
            break;
        case 2:
            // Convert to lowercase
            for(i=0; str1[i]!='\0'; i++) {
                str2[i] = tolower(str1[i]);
            }
            str2[i] = '\0';
            printf("\nString in lowercase: %s\n", str2);
            break;
        case 3:
            // Reverse the string
            for(i=0, j=length-1; j>=0; i++, j--) {
                str2[i] = str1[j];
            }
            str2[i] = '\0';
            printf("\nReversed string: %s\n", str2);
            break;
        case 4:
            // Remove all numbers
            for(i=0, j=0; str1[i]!='\0'; i++) {
                if(str1[i] < '0' || str1[i] > '9') {
                    str2[j++] = str1[i];
                }
            }
            str2[j] = '\0';
            printf("\nString with all numbers removed: %s\n", str2);
            break;
        case 5:
            // Replace all spaces with hyphens
            for(i=0, j=0; str1[i]!='\0'; i++) {
                if(str1[i] == ' ') {
                    str2[j++] = '-';
                }
                else {
                    str2[j++] = str1[i];
                }
            }
            str2[j] = '\0';
            printf("\nString with all spaces replaced by hyphens: %s\n", str2);
            break;
        case 6:
            // Remove all vowels
            for(i=0, j=0; str1[i]!='\0'; i++) {
                if(tolower(str1[i]) != 'a' && tolower(str1[i]) != 'e' && tolower(str1[i]) != 'i' && tolower(str1[i]) != 'o' && tolower(str1[i]) != 'u') {
                    str2[j++] = str1[i];
                }
            }
            str2[j] = '\0';
            printf("\nString with all vowels removed: %s\n", str2);
            break;
        default:
            printf("Invalid choice entered!\n");
    }

    // Compare the original and modified strings
    if(strcmp(str1, str2) == 0) {
        printf("\nThe original string %s and the modified string %s are the same.\n", str1, str2);
    }
    else {
        printf("\nThe original string %s and the modified string %s are different.\n", str1, str2);
    }

    // Copy the modified string to another string and append it to the original string
    strcpy(str3, str2);
    strcat(str3, str1);
    printf("\nNew string after appending the modified string %s to the original string %s: %s\n", str2, str1, str3);

    return 0;
}