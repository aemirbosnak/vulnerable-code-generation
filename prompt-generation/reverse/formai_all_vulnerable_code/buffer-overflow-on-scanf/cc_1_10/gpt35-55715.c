//FormAI DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {

    char str1[50], str2[50], temp[50];
    int choice;
    
    printf("Welcome! Let's play with some C Strings.\n\n");
    printf("Enter your first string: ");
    scanf("%[^\n]", str1);
    getchar();
    printf("\nEnter your second string: ");
    scanf("%[^\n]", str2);
    getchar();
    printf("\nWhat would you like to do with your strings?\n");
    printf("1. Concatenate them\n2. Compare them\n3. Reverse them\n");
    printf("\nEnter your choice (1,2,3): ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1:
            printf("\nConcatenating strings...");
            strcat(str1, str2);
            printf("\nNew string: %s", str1);
            break;
        case 2:
            printf("\nComparing strings...");
            if(strcmp(str1, str2) == 0){
                printf("\n%s and %s are equal.", str1, str2);
            } else {
                printf("\n%s and %s are not equal.", str1, str2);
            }
            break;
        case 3:
            printf("\nReversing strings...");
            strcpy(temp, str1);
            strncpy(str1, str2, 50);
            strncpy(str2, temp, 50);
            printf("\nNew first string: %s", str1);
            printf("\nNew second string: %s", str2);
            break;
        default:
            printf("\nInvalid choice! Please choose 1, 2, or 3.");
            break;
    }

    printf("\n\nThank you for playing!");
    return 0;
}