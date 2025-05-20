//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: mind-bending
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//function to check palindrome
int is_palindrome(char *str, int n){
    int flag = 0;
    for(int i=0; i<n; i++){
        if(str[i]!=str[n-i-1]){
            flag = 1;
            break;
        }
    }
    return flag;
}

int main(){

    printf("Welcome to the Palindrome Checker!");
    printf("\nEnter a string to check if it's palindrome: ");

    //user input
    char *str = (char*)malloc(30*sizeof(char));
    scanf("%[^\n]", str);

    //removing spaces and converting to lowercase
    int len = strlen(str);
    for(int i=0; i<len; i++){
        if(str[i] == ' '){
            for(int j=i; j<len; j++){
                str[j] = str[j+1];
            }
            i--;
            len--;
        }
        str[i] = tolower(str[i]);
    }

    //checking if it's a palindrome
    int flag = is_palindrome(str, strlen(str));

    //displaying the result
    if(flag == 0)
        printf("\n%s is a palindrome!", str);
    else
        printf("\n%s is not a palindrome.", str);
        
    free(str); //deallocating memory

    return 0;
}