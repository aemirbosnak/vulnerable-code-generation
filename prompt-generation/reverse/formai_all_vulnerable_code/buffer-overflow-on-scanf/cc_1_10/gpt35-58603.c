//FormAI DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20], str2[20], str3[40];
    
    printf("\nHey there, let's play with some strings!\n");
    
    // getting input from user for string 1 and string 2
    printf("Enter String 1 : ");
    gets(str1);
    printf("Enter String 2 : ");
    gets(str2);
    
    // copying contents of string 1 to string 3
    strcpy(str3, str1);
    
    printf("\nCharcter count of String 1 : %d", strlen(str1));
    printf("\nCharcter count of String 2 : %d", strlen(str2));
    
    // concatenating string 2 to string 1
    strcat(str1, str2);
    printf("\n\nAfter concatenation");
    printf("\nString 1 : %s", str1);
    
    // finding the index of a character in string 3
    char ch;
    printf("\n\nEnter a character to find it's index in String 3 : ");
    scanf("%c", &ch);
    int index = strchr(str3, ch) - str3;
    printf("Index of %c in String 3 : %d", ch, index);
    
    // converting string 1 to uppercase
    printf("\n\nConverting String 1 to UPPERCASE");
    for(int i=0; str1[i]; i++) 
        putchar(toupper(str1[i]));
    
    // converting string 2 to lowercase
    printf("\n\nConverting String 2 to lowercase");
    for(int i=0; str2[i]; i++) 
        putchar(tolower(str2[i]));
    
    // checking for palindrome
    printf("\n\nChecking if String 3 is a palindrome");
    int len = strlen(str3);
    int flag = 0;
    for(int i=0; i<len/2; i++) {
        if(str3[i] != str3[len-i-1]) {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        printf("%s is a Palindrome", str3);
    else
        printf("%s is not a Palindrome", str3);
    
    printf("\n\nI hope you enjoyed playing with strings! Goodbye!");
    
    return 0;
}