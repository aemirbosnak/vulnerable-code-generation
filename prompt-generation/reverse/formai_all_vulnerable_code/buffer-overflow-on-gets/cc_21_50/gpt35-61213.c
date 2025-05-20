//FormAI DATASET v1.0 Category: Text processing ; Style: retro
#include <stdio.h> 

int main() 
{ 
    printf("++++++++++ RETRO TEXT PROCESSING ++++++++++\n"); 
    
    char text[100]; 
    printf("\nEnter a string: "); 
    gets(text); 

    int vowels=0, consonants=0, digits=0, spaces=0; 
    
    for(int i=0; text[i]!='\0'; ++i) 
    { 
        if(text[i]=='a' || text[i]=='e' || text[i]=='i' || text[i]=='o' || text[i]=='u' || 
            text[i]=='A' || text[i]=='E' || text[i]=='I' || text[i]=='O' || text[i]=='U') 
        { 
            ++vowels; 
        } 
        else if((text[i]>='a'&& text[i]<='z') || (text[i]>='A'&& text[i]<='Z')) 
        { 
            ++consonants; 
        } 
        else if(text[i]>='0' && text[i]<='9') 
        { 
            ++digits; 
        } 
        else if (text[i]==' ') 
        { 
            ++spaces; 
        } 
    } 
    
    printf("\nTotal Vowels: %d", vowels); 
    printf("\nTotal Consonants: %d", consonants); 
    printf("\nTotal Digits: %d", digits); 
    printf("\nTotal Spaces: %d", spaces); 

    printf("\n\n++++++++++ CONVERT TO LOWERCASE ++++++++++\n"); 

    for(int i=0; text[i]!='\0'; ++i) 
    { 
        if(text[i]>='A' && text[i]<='Z') 
        { 
            text[i] = text[i] + 32; 
        } 
    } 
    
    printf("\nLowercase String: %s", text); 

    printf("\n\n++++++++++ CONVERT TO UPPERCASE ++++++++++\n"); 

    for(int i=0; text[i]!='\0'; ++i) 
    { 
        if(text[i]>='a' && text[i]<='z') 
        { 
            text[i] = text[i] - 32; 
        } 
    } 
    
    printf("\nUppercase String: %s", text); 

    printf("\n\n++++++++++ REVERSE STRING ++++++++++\n"); 

    for(int i=0; text[i]!='\0'; ++i) 
    { 
        int len = strlen(text)-1; 
        char temp = text[len-i]; 
        text[len-i] = text[i]; 
        text[i] = temp; 
    } 
    
    printf("\nReversed String: %s", text); 

    return 0; 
}