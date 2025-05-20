//FormAI DATASET v1.0 Category: String manipulation ; Style: random
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], temp[100];
    int i, j, choice;

    printf("Welcome to C String Manipulation program!\n\n");

    printf("Enter your first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter your second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    printf("\nWhat do you want to do with your strings?\n");
    printf("1. Concatenate the strings.\n");
    printf("2. Find the length of the strings.\n");
    printf("3. Compare the strings.\n");
    printf("4. Reverse the strings.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            strcat(str1, str2);
            printf("\nConcatenated string: %s\n", str1);
            break;
        case 2:
            printf("\nLength of first string: %d\n", strlen(str1));
            printf("Length of second string: %d\n", strlen(str2));
            break;
        case 3:
            if(strcmp(str1, str2) == 0)
                printf("\n%s and %s are equal strings\n", str1, str2);
            else
                printf("\n%s and %s are not equal strings\n", str1, str2);
            break;
        case 4:
            for(i = 0, j = strlen(str1) - 1; i < j; i++, j--) {
                temp[i] = str1[j];
                str1[j] = str1[i];
                str1[i] = temp[i];
            }
            for(i = 0, j = strlen(str2) - 1; i < j; i++, j--) {
                temp[i] = str2[j];
                str2[j] = str2[i];
                str2[i] = temp[i];
            }
            printf("\nReversed first string: %s\n", str1);
            printf("Reversed second string: %s\n", str2);
            break;
        default:
            printf("\nInvalid choice\n");
    }

    return 0;
}