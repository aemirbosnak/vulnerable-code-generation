//FormAI DATASET v1.0 Category: String manipulation ; Style: energetic
#include<stdio.h>

int main(){

    printf("Welcome to C String Manipulation!\n");

    char str[1000];
    int choice;

    printf("\nEnter a string: ");
    gets(str);

    printf("\nChoose an operation: \n");
    printf("1. Count number of characters.\n");
    printf("2. Reverse the string.\n");
    printf("3. Convert to uppercase characters.\n");
    printf("4. Convert to lowercase characters.\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("\nNumber of characters in string: %d\n", strlen(str));
            break;
        case 2:
            printf("\nReversed string: ");
            for(int i=strlen(str)-1; i>=0; i--){
                printf("%c", str[i]);
            }
            printf("\n");
            break;
        case 3:
            printf("\nUppercase string: ");
            for(int i=0; i<strlen(str); i++){
                printf("%c", toupper(str[i]));
            }
            printf("\n");
            break;
        case 4:
            printf("\nLowercase string: ");
            for(int i=0; i<strlen(str); i++){
                printf("%c", tolower(str[i]));
            }
            printf("\n");
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }

    printf("\nThanks for using C String Manipulation!\n");

    return 0;
}