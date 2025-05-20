//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert Cat Language to English Language
char* cat_to_eng(char* cat_str) {
    int cat_len = strlen(cat_str);
    char* eng_str = (char*) malloc(cat_len * 3);  // Allocate memory for maximum possible English characters
    
    int eng_index = 0;  // Keeps track of the current index in the English string
    
    for (int i = 0; i < cat_len; i++) {
        if (cat_str[i] == 'm') {  // If the current character is 'm', replace it with 'a'
            eng_str[eng_index] = 'a';
            eng_index++;
        }
        else if (cat_str[i] == 'e') {  // If the current character is 'e', replace it with 'b'
            eng_str[eng_index] = 'b';
            eng_index++;
        }
        else if (cat_str[i] == 'o') {  // If the current character is 'o', replace it with 'c'
            eng_str[eng_index] = 'c';
            eng_index++;
        }
        else {  // If the current character is not 'm', 'e', or 'o', copy it to the English string as is
            eng_str[eng_index] = cat_str[i];
            eng_index++;
        }
    }
    
    eng_str[eng_index] = '\0';  // Add null terminator to the end of the English string
    
    return eng_str;
}

int main() {
    char cat_str[100];
    char* eng_str;
    
    printf("Enter a string in Cat Language:\n");
    gets(cat_str);
    
    eng_str = cat_to_eng(cat_str);
    
    printf("The string in English Language is:\n");
    puts(eng_str);
    
    free(eng_str);  // Free the memory allocated for the English string
    
    return 0;
}