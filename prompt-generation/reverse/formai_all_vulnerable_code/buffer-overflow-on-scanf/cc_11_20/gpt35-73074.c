//FormAI DATASET v1.0 Category: String manipulation ; Style: enthusiastic
//Welcome to the world of String Manipulation!
//This program is going to take you on an exciting ride
//Buckle up tight and let's get started!

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int choice = 0;
    printf("Welcome to String Manipulation!\n");
    printf("Enter a string (less than 100 characters): ");
    scanf("%s", str);
    while (1) {
        printf("\nWhat do you want to do with the string?\n");
        printf("1) Count the number of characters\n");
        printf("2) Reverse the string\n");
        printf("3) Convert the string to uppercase\n");
        printf("4) Convert the string to lowercase\n");
        printf("5) Check if the string is a palindrome\n");
        printf("6) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Number of characters: %d", strlen(str));
                break;
            case 2: {
                int len = strlen(str);
                printf("Reversed string: ");
                for (int i = len - 1; i >= 0; i--)
                    printf("%c", str[i]);
                break;
            }
            case 3: {
                int len = strlen(str);
                printf("Uppercased string: ");
                for (int i = 0; i < len; i++)
                    printf("%c", toupper(str[i]));
                break;
            }
            case 4: {
                int len = strlen(str);
                printf("Lowercased string: ");
                for (int i = 0; i < len; i++)
                    printf("%c", tolower(str[i]));
                break;
            }
            case 5: {
                int len = strlen(str), flag = 1;
                for (int i = 0, j = len - 1; i < len / 2; i++, j--)
                    if (str[i] != str[j])
                        flag = 0;
                if (flag)
                    printf("Palindrome!");
                else
                    printf("Not a palindrome!");
                break;
            }
            case 6:
                printf("Goodbye!");
                return 0;
            default:
                printf("Invalid choice");
        }
    }
}