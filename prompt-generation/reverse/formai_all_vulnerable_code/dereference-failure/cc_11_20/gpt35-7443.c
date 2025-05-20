//FormAI DATASET v1.0 Category: String manipulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[] = "SHERLOCK";
    int str_len = strlen(str);
    printf("Original String: %s\n", str);

    // Convert all characters to lowercase
    for(int i=0; i<str_len; i++){
        str[i] = tolower(str[i]);
    }
    printf("Lowercase String: %s\n", str);

    // Calculate the frequency of each character
    int freq[26] = {0};
    for(int i=0; i<str_len; i++){
        int index = str[i] - 'a';
        freq[index]++;
    }

    // Print the frequency of each character
    for(int i=0; i<26; i++){
        if(freq[i] > 0){
            char c = i + 'a';
            printf("%c: %d occurrences\n", c, freq[i]);
        }
    }

    // Count the number of vowels
    int vowel_count = 0;
    for(int i=0; i<str_len; i++){
        char c = str[i];
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            vowel_count++;
        }
    }
    printf("Number of vowels: %d\n", vowel_count);

    // Reverse the string
    char* reversed_str = (char*) malloc(str_len * sizeof(char));
    for(int i=0; i<str_len; i++){
        reversed_str[i] = str[str_len-i-1];
    }
    printf("Reversed String: %s\n", reversed_str);

    free(reversed_str);
    return 0;
}