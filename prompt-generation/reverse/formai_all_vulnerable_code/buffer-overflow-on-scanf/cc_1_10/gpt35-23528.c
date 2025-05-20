//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if string is a valid C Cat Language
bool isValidCCatLanguage(char* str){
    if(str == NULL)
        return false;
    int len = strlen(str);
    
    // Check if first character is C
    if(str[0] != 'C')
        return false;
    
    // Check if last character is t
    if(str[len-1] != 't')
        return false;
    
    // Check if second character is a vowel
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    bool secondCharVowel = false;
    int i;
    for(i=0; i<5; i++){
        if(str[1] == vowels[i]){
            secondCharVowel = true;
            break;
        }
    }

    if(!secondCharVowel)
        return false;
    
    // Check if last two characters are "at"
    if(len >= 3 && str[len-2] != 'a' && str[len-1] != 't')
        return false;
    
    return true;
}

// Function to convert C Cat Language to English
char* convertCCToEnglish(char* str){
    char subStr[256];
    strcpy(subStr, str+2); // Copy substring after "C<first vowel>"
    subStr[strlen(subStr)-2] = '\0'; // Remove "at" from end of string

    char* newStr = (char*)calloc(256, sizeof(char)); // Allocate memory for new string
    strcat(newStr, "Cat");
    strcat(newStr, subStr);
    strcat(newStr, "Dog");
    return newStr;
}

// Driver program
int main(){
    char cCatString[256];
    printf("Enter a C Cat Language string: ");
    scanf("%s", cCatString);
    
    if(isValidCCatLanguage(cCatString)){
        char* englishString = convertCCToEnglish(cCatString);
        printf("English equivalent: %s\n", englishString);
        free(englishString);
    }
    else{
        printf("Invalid C Cat Language string.\n");
    }
    
    return 0;
}