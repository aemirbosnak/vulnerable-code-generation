//FormAI DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

//Function to reverse a string
void reverse(char *str, int len) 
{ 
    int i, j; 
    char temp;
    
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = *(str+i);
        *(str+i) = *(str+j);
        *(str+j) = temp;
    }
} 

//Function to remove whitespace from a string
void remove_whitespace(char *str) 
{
    char *new_str = str;
    do {
        while(*new_str == ' ') {
            ++new_str;
        }
    } while(*str++ = *new_str++);
}

//Function to convert a string to uppercase
void uppercase(char *str)
{
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

//Function to convert a string to lowercase
void lowercase(char *str)
{
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

int main() 
{ 
    char str[100]; 
    int choice, len;
    
    printf("Enter a string: "); 
    fgets(str, sizeof(str), stdin);
    len = strlen(str);
    
    printf("Enter your choice:\n1. Reverse the string\n2. Remove whitespace from the string\n3. Convert the string to uppercase\n4. Convert the string to lowercase\n"); 
    scanf("%d", &choice); 
    
    switch (choice) {
        case 1: 
            reverse(str, len); 
            printf("The reversed string is: %s\n", str); 
            break;
            
        case 2:
            remove_whitespace(str); 
            printf("The string without whitespace is: %s\n", str); 
            break;
            
        case 3: 
            uppercase(str); 
            printf("The uppercase string is: %s\n", str); 
            break;
            
        case 4:
            lowercase(str); 
            printf("The lowercase string is: %s\n", str); 
            break;
            
        default: 
            printf("Invalid choice.\n");
    }
    
    return 0; 
}