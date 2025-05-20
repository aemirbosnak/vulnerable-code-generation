//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: energetic
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_SIZE 1000

//Function to remove all white spaces from a string
void remove_spaces(char* str){
    int i = 0, j = 0;
    while(str[i]!= '\0'){
        if(!isspace(str[i])){
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

//Function to reverse a string
void reverse_string(char* str){
    int i = 0, j = strlen(str) - 1;
    while(i < j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

//Function to check if two strings are anagrams
int is_anagram(char* str1, char* str2){
    int len1 = strlen(str1), len2 = strlen(str2);
    if(len1!= len2)
        return 0;

    char* sorted_str1 = (char*)malloc(len1*sizeof(char));
    char* sorted_str2 = (char*)malloc(len2*sizeof(char));

    strcpy(sorted_str1, str1);
    strcpy(sorted_str2, str2);

    remove_spaces(sorted_str1);
    remove_spaces(sorted_str2);

    reverse_string(sorted_str1);
    reverse_string(sorted_str2);

    if(strcmp(sorted_str1, sorted_str2) == 0)
        return 1;
    else
        return 0;
}

int main(){
    char str1[MAX_SIZE], str2[MAX_SIZE];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    if(is_anagram(str1, str2))
        printf("%s and %s are anagrams.\n", str1, str2);
    else
        printf("%s and %s are not anagrams.\n", str1, str2);

    return 0;
}