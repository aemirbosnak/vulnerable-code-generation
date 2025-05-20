//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: secure
#include<stdio.h>
#include<string.h>

// function to check if character is alphanumeric
int is_alnum(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
        return 1;
    }
    return 0;
}

// function to remove special characters and convert to lowercase
void remove_special_chars_and_tolower(char *str, int n){
    int i, j;
    for(i=0; i<n; i++){
        if(!is_alnum(str[i])){
            for(j=i; j<n-1; j++){
                str[j] = str[j+1];
            }
            str[n-1] = '\0';
            n--;
            i--;
        }
        else{
            str[i] = tolower(str[i]);
        }
    }
}

// function to check if given string is palindrome or not
int is_palindrome(char *str, int n){
    int i;
    for(i=0; i<n/2; i++){
        if(str[i] != str[n-i-1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    // remove newline character from end of input string
    if(str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }

    // remove special characters and convert to lowercase
    remove_special_chars_and_tolower(str, strlen(str));

    // check if palindrome or not
    if(is_palindrome(str, strlen(str))){
        printf("%s is a palindrome\n", str);
    }
    else{
        printf("%s is not a palindrome\n", str);
    }

    return 0;
}