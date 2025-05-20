//FormAI DATASET v1.0 Category: String manipulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];
    int option, length;

    printf("Welcome to the String Manipulation Program!\n\n");

    do {
        printf("Please select an option:\n");
        printf("1. Concatenate two strings.\n");
        printf("2. Find the length of a string.\n");
        printf("3. Convert a string to uppercase.\n");
        printf("4. Convert a string to lowercase.\n");
        printf("5. Reverse a string.\n");
        printf("6. Exit the program.\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Please enter the first string:\n");
                scanf("%s", str1);
                printf("Please enter the second string:\n");
                scanf("%s", str2);
                strcat(str1, str2);
                printf("The concatenated string is: %s\n\n", str1);
                break;

            case 2:
                printf("Please enter a string:\n");
                scanf("%s", str1);
                length = strlen(str1);
                printf("The length of the string is: %d\n\n", length);
                break;

            case 3:
                printf("Please enter a string:\n");
                scanf("%s", str1);
                length = strlen(str1);
                for (int i = 0; i < length; i++) {
                    if (str1[i] >= 'a' && str1[i] <= 'z') {
                        str1[i] = str1[i] - 32;
                    }
                }
                printf("The uppercase string is: %s\n\n", str1);
                break;

            case 4:
                printf("Please enter a string:\n");
                scanf("%s", str1);
                length = strlen(str1);
                for (int i = 0; i < length; i++) {
                    if (str1[i] >= 'A' && str1[i] <= 'Z') {
                        str1[i] = str1[i] + 32;
                    }
                }
                printf("The lowercase string is: %s\n\n", str1);
                break;

            case 5:
                printf("Please enter a string:\n");
                scanf("%s", str1);
                length = strlen(str1);
                char temp;
                for (int i = 0; i < length/2; i++) {
                    temp = str1[i];
                    str1[i] = str1[length-i-1];
                    str1[length-i-1] = temp;
                }
                printf("The reversed string is: %s\n\n", str1);
                break;

            case 6:
                printf("Exiting the program. Thanks for using it!\n\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n\n");
        }
    } while (option != 6);

    return 0;
}