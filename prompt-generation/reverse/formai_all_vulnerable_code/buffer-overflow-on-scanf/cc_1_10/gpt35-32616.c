//FormAI DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <ctype.h>

/*
** A function that takes two string arguments as input, and returns an integer value.
** The function iterates over both strings and compares the corresponding characters. 
** The strings are considered "equal" up to the length of the shortest string if there are 
** no differences between corresponding characters. This function checks for spelling mistakes
** by looking for mismatches between characters in the two input strings. 
*/

int spell_check(char *input, char *dictionary) {
    int i = 0, j = 0;
    int mistake_count = 0;
    while (tolower(input[i]) != '\0' && tolower(dictionary[j]) != '\0') {
        if (tolower(input[i]) != tolower(dictionary[j])) {
            mistake_count++;
        }
        i++;
        j++;
    }
    if (mistake_count > 0 || (tolower(input[i]) != '\0' && tolower(dictionary[j]) == '\0')) {
        return 1; // spelling mistake detected
    } else {
        return 0; // no spelling mistakes detected
    }
}

int main() {
    char input[100], dictionary[1000], buffer[100];
    char file_name[100];
    int cursor = 0;
    FILE *fp;
    
    printf("Enter a file name for the dictionary: ");
    scanf("%s", file_name);
    
    //Open the file in read mode
    fp = fopen(file_name, "r");
    
    // If the file doesn't exist in the same directory or not readable
    if (fp == NULL){
        perror("Error while opening dictionary..");
        return 0;
    }
    
    // Read the file one word at a time
    while(fscanf(fp, "%s", buffer) == 1){
        int i = 0;
        while (buffer[i]) {
            dictionary[cursor++] = buffer[i++];
        }
        dictionary[cursor++] = '\n'; // distinct separator for each word in the dictionary
    }
    dictionary[cursor] = '\0'; // null terminator
    
    fclose(fp);
    
    printf("Enter a string to spellcheck: ");
    scanf("%s", input);
    
    // Iterate over the string to spellcheck
    char *token = strtok(input, " ");
    
    while (token != NULL) {
        int mistake = 0;
        
        // Iterate over the dictionary and check every word
        char *delim = "\n";
        char *found;
        char *dictionary_words = dictionary;
        while ((found = strtok_r(dictionary_words, delim, &dictionary_words))) {
            if (spell_check(token, found) == 0) {
                mistake = 1; // no spelling mistake detected in this word
                break;
            }
        }
        
        if (mistake == 1) {
            printf("%s is misspelled.\n", token);
        } else {
            printf("%s is spelled correctly.\n", token);
        }
        
        token = strtok(NULL, " ");
    }

    return 0;
}