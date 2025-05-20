//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Ada Lovelace
/* Ada Lovelace's Unique C Alien Language Translator Program */

#include <stdio.h>
#include <string.h>

// Defining the unique symbols of C Alien Language
#define _o "** "
#define _OO "* "
#define _oo "  "

// Function to translate a string from English to C Alien Language
void translateToCAlienLanguage(char *str){
    int len = strlen(str);
    for(int i=0;i<len;i++){
        switch(str[i]){
            case 'a':
                printf(_oo);
                break;
            case 'b':
                printf(_OO);
                break;
            case 'c':
                printf(_o _OO);
                break;
            case 'd':
                printf(_o _o);
                break;
            case 'e':
                printf(_oo);
                break;
            // Add cases for the rest of the alphabets in a similar fashion
            default:
                printf("%c", str[i]);
                break;
        }
    }
    printf("\n");
}

// Function to translate a string from C Alien Language to English
void translateToEnglish(char *str){
    int len = strlen(str);
    for(int i=0;i<len;i++){
        if(str[i] == ' '){ continue; }
        if(str[i+1] == ' '){ // Check next character to see if it is a space
            if(str[i+2] == '*'){ // Check next next character to see if it is an asterisk
                printf("a");
                i += 2; // Skip the next two characters since we already translated them
            }
            else{
                printf("b");
                i += 1; // Skip the next character since we already translated it
            }
        }
        else if(str[i+2] == '*'){ // Check next next character to see if it is an asterisk
            if(str[i] == '*' && str[i+1] == '*'){
                printf("c");
            }
            else{
                printf("d");
            }
            i += 2; // Skip the next two characters since we already translated them
        }
        else{
            printf("e");
        }
    }
    printf("\n");
}

int main(){
    printf("Welcome to Ada Lovelace's Unique C Alien Language Translator Program!\n\n");
    
    int choice;
    do{
        printf("Please choose an option:\n");
        printf("1. Translate from English to C Alien Language\n");
        printf("2. Translate from C Alien Language to English\n");
        printf("3. Exit program\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice){
            case 1:
                printf("\nEnter the string you want to translate to C Alien Language:\n");
                char engStr[1000];
                fgets(engStr, 1000, stdin);
                translateToCAlienLanguage(engStr);
                break;
            case 2:
                printf("\nEnter the string you want to translate to English from C Alien Language:\n");
                char alienStr[1000];
                fgets(alienStr, 1000, stdin);
                translateToEnglish(alienStr);
                break;
            case 3:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }while(choice != 3);
    
    return 0;
}