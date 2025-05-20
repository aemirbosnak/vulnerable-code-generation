//FormAI DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    int choice, length;

    printf("Enter a string: ");
    scanf("%s", str);

    length = strlen(str);

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Convert all lowercase letters to uppercase letters\n");
        printf("2. Convert all uppercase letters to lowercase letters\n");
        printf("3. Reverse the string\n");
        printf("4. Check if string is a palindrome\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < length; i++) {
                    if (str[i] >= 'a' && str[i] <= 'z') {
                        str[i] -= 32;
                    }
                }
                printf("The uppercase string is: %s\n", str);
                break;
            case 2:
                for (int i = 0; i < length; i++) {
                    if (str[i] >= 'A' && str[i] <= 'Z') {
                        str[i] += 32;
                    }
                }
                printf("The lowercase string is: %s\n", str);
                break;
            case 3:
                for (int i = 0; i < length / 2; i++) {
                    char temp = str[i];
                    str[i] = str[length - i - 1];
                    str[length - i - 1] = temp;
                }
                printf("The reversed string is: %s\n", str);
                break;
            case 4:
                for (int i = 0; i < length / 2; i++) {
                    if (str[i] != str[length - i - 1]) {
                        printf("The string is not a palindrome\n");
                        break;
                    }
                }
                printf("The string is a palindrome\n");
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}