//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: mind-bending
#include <stdio.h>
#include <string.h>

int isPalindrome(char *str){
    int len = strlen(str);
    for(int i=0; i<len/2; i++){
        if(str[i]!=str[len-i-1])
            return 0;
    }
    return 1;
}

void printResult(char *str, int res) {
    if (res) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is NOT a palindrome\n", str);
    }
}

int main(){
    char str[100];
    printf("Let's test for palindrome, shall we?\n");
    printf("Enter a string for testing: ");
    scanf("%s", str);

    int res = isPalindrome(str);

    printf("\nHmmm... let me think for a moment...\n");
    printf("Calculating result...\n");
    for (int i=0; i<100; i++) {
        printf("%d percent done...\n", i+1);
    }

    printf("\nRESULT:\n");
    printResult(str, res);

    printf("\nDo you want to test another string? (y/n) ");
    char option;
    scanf(" %c", &option);

    if (option == 'y' || option == 'Y') {
        printf("\nGreat! Enter the next string: ");
        scanf("%s", str);
        res = isPalindrome(str);
        printf("\nHmmm... let me think for a moment...\n");
        printf("Calculating result...\n");
        for (int i=0; i<100; i++) {
            printf("%d percent done...\n", i+1);
        }
        printf("\nRESULT:\n");
        printResult(str, res);
    } else {
        printf("\nGoodbye! Thanks for testing.\n");
    }

    return 0;
}