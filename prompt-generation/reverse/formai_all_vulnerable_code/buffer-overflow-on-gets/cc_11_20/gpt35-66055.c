//FormAI DATASET v1.0 Category: Text processing ; Style: creative
#include<stdio.h>
#include<string.h>

int main(){

    // Taking input string
    char input_string[100];
    printf("Enter a string: ");
    gets(input_string);
    
    // Converting each character to uppercase
    char uppercase_string[100];
    for(int i=0; i<strlen(input_string); i++){
        uppercase_string[i] = toupper(input_string[i]);
    }
    printf("Uppercase string: %s\n", uppercase_string);
    
    // Counting vowels and consonants
    int vowel_count = 0;
    int consonant_count = 0;
    for(int i=0; i<strlen(input_string); i++){
        switch(uppercase_string[i]){
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowel_count++;
                break;
            default:
                consonant_count++;
                break;
        }
    }
    printf("Vowels: %d\n", vowel_count);
    printf("Consonants: %d\n", consonant_count);
    
    // Reversing the string
    char reversed_string[100];
    int j = 0;
    for(int i=strlen(input_string)-1; i>=0; i--){
        reversed_string[j] = input_string[i];
        j++;
    }
    printf("Reversed string: %s\n", reversed_string);
    
    // Removing all vowels
    char consonant_string[100];
    int k = 0;
    for(int i=0; i<strlen(input_string); i++){
        switch(uppercase_string[i]){
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                break;
            default:
                consonant_string[k] = input_string[i];
                k++;
                break;
        }
    }
    printf("String without vowels: %s\n", consonant_string);
    
    return 0;
}