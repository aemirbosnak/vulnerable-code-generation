//Falcon-180B DATASET v1.0 Category: Text processing ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//Function to remove all white spaces from the input string
void removeWhiteSpaces(char* str){
    int i=0,j=0;
    while(str[i]!='\0'){
        if(!isspace(str[i])){
            str[j++]=str[i];
        }
        i++;
    }
    str[j]='\0';
}

//Function to convert the input string to lowercase
void convertToLowercase(char* str){
    int i=0;
    while(str[i]!='\0'){
        str[i]=tolower(str[i]);
        i++;
    }
}

//Function to reverse the input string
void reverseString(char* str){
    int i=0,j=strlen(str)-1;
    while(i<j){
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
}

//Function to check if the input string is a palindrome
int isPalindrome(char* str){
    int i=0,j=strlen(str)-1;
    while(i<j){
        if(str[i]!=str[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

//Main function to take input from user, process it and display the result
int main(){
    char input[100];
    printf("Enter a string: ");
    scanf("%s",input);

    //Removing white spaces from the input string
    removeWhiteSpaces(input);

    //Converting the input string to lowercase
    convertToLowercase(input);

    //Reversing the input string
    reverseString(input);

    //Checking if the input string is a palindrome
    if(isPalindrome(input)){
        printf("The input string is a palindrome.\n");
    }
    else{
        printf("The input string is not a palindrome.\n");
    }

    return 0;
}