//FormAI DATASET v1.0 Category: String manipulation ; Style: realistic
#include<stdio.h>
#include<string.h>

int main() {
    char str1[100], str2[100];
    int i, j, len1 = 0, len2 = 0;
    
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);
    
    // Find length of first string
    for(i=0; str1[i]!='\0'; i++) {
        len1++;
    }
    
    // Find length of second string
    for(i=0; str2[i]!='\0'; i++) {
        len2++;
    }
    
    printf("\nLength of first string is: %d", len1);
    printf("\nLength of second string is: %d", len2);
    
    // Concatenating the two strings
    for(i=0; i<len2; i++) {
        str1[len1 + i] = str2[i];
    }
    str1[len1 + len2] = '\0';
    
    printf("\nConcatenated string is: %s", str1);
    
    // Reversing the first string
    for(i=0, j=len1-1; i<j; i++, j--) {
        char temp = str1[i];
        str1[i] = str1[j];
        str1[j] = temp;
    }
    
    printf("\nReversed string is: %s", str1);
    
    // Converting the first string to uppercase
    for(i=0; i<len1; i++) {
        if(str1[i]>='a' && str1[i]<='z') {
            str1[i] = str1[i] - 32;
        }
    }
    
    printf("\nUppercase string is: %s", str1);
    
    // Finding the first occurrence of a character in the first string
    char c;
    printf("\nEnter character to search for: ");
    scanf("%c", &c);
    for(i=0; i<len1; i++) {
        if(str1[i]==c) {
            printf("\nCharacter found at position: %d", i+1);
            break;
        }
    }
    if(i==len1) {
        printf("\nCharacter not found in string.");
    }
    return 0;
}