//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
    char phrase[100];
    printf("Enter a phrase: ");
    fgets(phrase, sizeof(phrase), stdin);
    
    // removes new line character at the end of the phrase
    phrase[strcspn(phrase, "\n")] = 0;
    
    int phrase_len = strlen(phrase);
    
    // counts the number of vowels and consonants in the phrase
    int vowels = 0, consonants = 0;
    for(int i = 0; i < phrase_len; i++) {
        char c = phrase[i];
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
           || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowels++;
        }
        else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            consonants++;
        }
    }
    
    printf("Number of vowels in the phrase: %d\n", vowels);
    printf("Number of consonants in the phrase: %d\n", consonants);
    
    // reverses the phrase
    char reversed_phrase[100];
    for(int i = 0; i < phrase_len; i++) {
        reversed_phrase[i] = phrase[phrase_len-1-i];
    }
    reversed_phrase[phrase_len] = 0;
    
    printf("Phrase in reverse order: %s\n", reversed_phrase);
    
    // capitalizes the first letter of each word in the phrase
    char capitalized_phrase[100];
    int is_word_start = 1;
    for(int i = 0; i < phrase_len; i++) {
        char c = phrase[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if(is_word_start) {
                c = toupper(c);
            }
            else {
                c = tolower(c);
            }
            is_word_start = 0;
        }
        else {
            is_word_start = 1;
        }
        capitalized_phrase[i] = c;
    }
    capitalized_phrase[phrase_len] = 0;
    
    printf("Phrase with capitalized words: %s\n", capitalized_phrase);
    
    // replaces all occurrences of a substring in the phrase
    char search_substring[100];
    char replace_substring[100];
    printf("Enter a substring to search for: ");
    scanf("%s", search_substring);
    printf("Enter a substring to replace with: ");
    scanf("%s", replace_substring);
    
    char replaced_phrase[100];
    int search_substring_len = strlen(search_substring);
    int replace_substring_len = strlen(replace_substring);
    
    int j = 0;
    for(int i = 0; i < phrase_len; i++) {
        if(strncmp(&phrase[i], search_substring, search_substring_len) == 0) {
            // copy replace_substring instead of the search_substring
            for(int k = 0; k < replace_substring_len; k++, j++) {
                replaced_phrase[j] = replace_substring[k];
            }
            i += search_substring_len - 1; // skip past the search_substring
        }
        else {
            replaced_phrase[j] = phrase[i];
            j++;
        }
    }
    replaced_phrase[j] = 0;
    
    printf("Phrase with replaced substring: %s\n", replaced_phrase);
    
    return 0;
}