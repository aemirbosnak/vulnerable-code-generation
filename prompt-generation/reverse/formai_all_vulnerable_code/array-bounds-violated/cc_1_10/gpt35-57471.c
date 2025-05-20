//FormAI DATASET v1.0 Category: String manipulation ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to reverse a string
char* reverse_string(char* str){
    int length = strlen(str);
    char* rev_str = (char*)malloc(sizeof(char) * (length+1));
    for(int i=0;i<length;i++){
        rev_str[i] = str[length-i-1];
    }
    rev_str[length] = '\0';
    return rev_str;
}

//Function to compare two strings
int compare_strings(char* str1, char* str2){
    if(strcmp(str1,str2)==0){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to convert string to upper case
char* to_upper_case(char* str){
    int length = strlen(str);
    char* upper_str = (char*)malloc(sizeof(char) * (length+1));
    for(int i=0;i<length;i++){
        if(str[i]>='a' && str[i]<='z'){
            upper_str[i] = str[i] - 32;
        }
        else{
            upper_str[i] = str[i];
        }
    }
    upper_str[length] = '\0';
    return upper_str;
}

//Function to concatenate two strings
char* concatenate_strings(char* str1,char* str2){
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    char* cat_str = (char*)malloc(sizeof(char)*(length1+length2+1));
    int i;
    for(i=0;i<length1;i++){
        cat_str[i] = str1[i];
    }
    for(int j=0;j<length2;j++){
        cat_str[i+j] = str2[j];
    }
    cat_str[length1+length2] = '\0';
    return cat_str;
}

int main(){
    char str1[50];
    char str2[50];
    printf("Enter first string: ");
    fgets(str1,50,stdin);
    printf("Enter second string: ");
    fgets(str2,50,stdin);
    //Remove \n from string
    str1[strlen(str1)-1] = '\0';
    str2[strlen(str2)-1] = '\0';
    printf("Reverse of first string: %s\n",reverse_string(str1));
    printf("Reverse of second string: %s\n",reverse_string(str2));
    if(compare_strings(str1,str2)){
        printf("Strings are same.\n");
    }
    else{
        printf("Strings are different.\n");
    }
    printf("Upper case of first string: %s\n",to_upper_case(str1));
    printf("Concatenated string: %s\n",concatenate_strings(str1,str2));
    return 0;
}