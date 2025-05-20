//FormAI DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str1[50], str2[50];
    int choice, len1, len2, i;

    printf("\nEnter first string: ");
    fgets(str1, 50, stdin);
    len1 = strlen(str1);

    printf("Enter second string: ");
    fgets(str2, 50, stdin);
    len2 = strlen(str2);

    while(1) {
        printf("\nChoose an operation:\n");
        printf("1: Concatenate both strings\n");
        printf("2: Compare both strings\n");
        printf("3: Copy second string to first string\n");
        printf("4: Exit program\n");

        scanf("%d", &choice);
        getchar();  // Used to clear the input buffer

        switch(choice) {
            case 1:
                for(i=0; i<len2; i++) {
                    str1[len1+i-1] = str2[i];
                }
                printf("\nConcatenated string: %s", str1);
                break;

            case 2:
                if (strcmp(str1, str2) == 0)
                    printf("\nBoth strings are equal");
                else
                    printf("\nBoth strings are not equal");
                break;

            case 3:
                strcpy(str1, str2);
                printf("\nSecond string copied to first string: %s", str1);
                break;

            case 4:
                printf("\nExiting program...");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.");
                break;
        }
    }
}