//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define alien language dictionary
char *alienDictionary[4][2] = {
    {"~@", "a"},
    {"!*#", "b"},
    {"#$%", "c"},
    {"^&$", "d"}
};

// function to translate alien language to English
char *alienToEnglish(char *alienString) {
    int i, j, k;
    int flag = 0;
    char *englishString = malloc(256 * sizeof(char)); // allocate space for English string
    
    // iterate through each character of the alienString
    for (i = 0; i < strlen(alienString); i+=3) {
        char *alienSubstr = malloc(4 * sizeof(char)); // allocate space for substring
        strncpy(alienSubstr, alienString + i, 3); // copy substring
        
        // iterate through the dictionary to find matching value
        for (j = 0; j < 4; j++) {
            if (strcmp(alienDictionary[j][0], alienSubstr) == 0) {
                flag = 1;
                strcat(englishString, alienDictionary[j][1]); // append to English string
                break;
            }
        }
        
        if (flag == 0) {
            printf("Code not Found!");
            exit(0);
        } else {
            flag = 0;
        }
        free(alienSubstr); // free memory
    }
    return englishString;
}

int main() {
    char alienString[256];
    printf("Enter Alien Language String: ");
    scanf("%s", &alienString); // get input from user
    
    char *englishString;
    englishString = alienToEnglish(alienString); // call alienToEnglish function
    
    printf("\nThe English Translation of '%s' is '%s'", alienString, englishString);
    free(englishString); // free memory
    
    return 0;
}