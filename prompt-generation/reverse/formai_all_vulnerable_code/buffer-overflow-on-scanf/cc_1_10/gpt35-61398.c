//FormAI DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[50], str2[50];
    int choice, length, result;
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    length = strlen(str1);

    while(1) {
        printf("\nChoose an operation: \n");
        printf("1. Concatenate\n");
        printf("2. Reverse\n");
        printf("3. Compare\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;
            }
            case 2: {
                char reverse[50];
                for(int i=0; i<length; i++) {
                    reverse[i] = str1[length-i-1];
                }
                reverse[length] = '\0';
                printf("Reversed string: %s\n", reverse);
                break;
            }
            case 3: {
                result = strcmp(str1, str2);
                if(result == 0) {
                    printf("The two strings are the same.\n");
                } else if(result > 0) {
                    printf("The first string is greater than the second string.\n");
                } else {
                    printf("The first string is lesser than the second string.\n");
                }
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice, try again!\n");
            }
        }
    }
    return 0;
}