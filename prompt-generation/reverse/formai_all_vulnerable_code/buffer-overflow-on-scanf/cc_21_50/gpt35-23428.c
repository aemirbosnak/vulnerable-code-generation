//FormAI DATASET v1.0 Category: String manipulation ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50];
    int option, length, count = 0;

    printf("Enter a string:\n");
    scanf("%s", str1);

    printf("\nChoose an option:\n");
    printf("1. Reverse the string\n");
    printf("2. Count the number of vowels\n");
    printf("3. Check if the string is a palindrome\n");
    printf("4. Find the length of string\n");
    printf("5. Compare two strings\n");
    printf("Option: ");
    scanf("%d", &option);

    switch (option) {
        case 1: // reverse the string
            length = strlen(str1);
            for (int i = length - 1; i >= 0; i--) {
                printf("%c", str1[i]);
            }
            break;
        case 2: // count the number of vowels
            length = strlen(str1);
            for (int i = 0; i < length; i++) {
                if (str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u' ||
                    str1[i] == 'A' || str1[i] == 'E' || str1[i] == 'I' || str1[i] == 'O' || str1[i] == 'U') {
                    count++;
                }
            }
            printf("\nNumber of vowels: %d", count);
            break;
        case 3: // check if the string is a palindrome
            length = strlen(str1);
            for (int i = 0; i < length; i++) {
                str2[i] = str1[length - i - 1];
            }
            str2[length] = '\0';
            if (strcmp(str1, str2) == 0) {
                printf("\nThe string is a palindrome");
            } else {
                printf("\nThe string is not a palindrome");
            }
            break;
        case 4: // find the length of the string
            length = strlen(str1);
            printf("\nThe length of the string is %d", length);
            break;
        case 5: // compare two strings
            printf("\nEnter another string:\n");
            scanf("%s", str2);
            if (strcmp(str1, str2) == 0) {
                printf("\nThe two strings are equal");
            } else {
                printf("\nThe two strings are not equal");
            }
            break;
        default:
            printf("\nInvalid option!");
    }

    return 0;
}