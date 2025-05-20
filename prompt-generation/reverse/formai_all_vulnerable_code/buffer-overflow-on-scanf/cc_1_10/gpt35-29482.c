//FormAI DATASET v1.0 Category: String manipulation ; Style: systematic
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], str3[200]; //declare three character arrays
    
    //get input strings from the user
    printf("Enter String 1: \n");
    scanf("%s", str1);
    
    printf("Enter String 2: \n");
    scanf("%s", str2);
    
    //concatenate the two strings using strcat() function
    strcat(str1, str2);
    printf("Concatenated String: %s\n\n", str1);
    
    //copy the concatenated string to str3 using strcpy() function
    strcpy(str3, str1);
    printf("Copied String: %s\n\n", str3);
    
    //find length of the original string using strlen() function
    int length = strlen(str2);
    printf("Length of String 2: %d\n\n", length);
    
    //compare the two strings using strcmp() function
    int result = strcmp(str1, str2);
    if(result == 0){
        printf("Strings are equal\n\n");
    }
    else{
        printf("Strings are not equal\n\n");
    }
    
    //find the index of a character in a string using strchr() function
    char* pos = strchr(str1, 'a');
    if(pos != NULL){
        printf("Index of character 'a' in string 1: %d\n\n", pos - str1);
    }
    else{
        printf("Character 'a' not found in string 1\n\n");
    }
    
    //replace a character in the string using strcpy() and strcat() functions
    pos = strchr(str1, 'e');
    if(pos != NULL){
        int index = pos - str1;
        strcpy(str1 + index, "ello");
        strcat(str1, str2 + 1);
        printf("New String 1: %s\n", str1);
    }
    else{
        printf("Character 'e' not found in string 1\n\n");
    }
    
    return 0;
}