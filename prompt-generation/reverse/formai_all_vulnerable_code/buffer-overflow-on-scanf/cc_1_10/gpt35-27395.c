//FormAI DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    printf("Enter a sentence: ");
    char sentence[100];
    scanf("%[^\n]", sentence); // Read input until new line character is encountered
    
    int len = strlen(sentence);
    char reversed[len+1];
    int i, j;
    for (i = 0, j = len-1; i < len; i++, j--) {
        reversed[i] = sentence[j];
    }
    reversed[len] = '\0'; // Terminate the reversed string with null character
    
    printf("Reversed sentence: %s\n", reversed);
    
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int num_vowels = 5;
    int vowel_count = 0;
    for (i = 0; i < len; i++) {
        char curr_char = sentence[i];
        for (j = 0; j < num_vowels; j++) {
            if (curr_char == vowels[j]) {
                vowel_count++;
                break;
            }
        }
    }
    
    printf("Number of vowels in sentence: %d\n", vowel_count);
    
    char vowels_removed[len];
    int index = 0;
    for (i = 0; i < len; i++) {
        char curr_char = sentence[i];
        int is_vowel = 0;
        for (j = 0; j < num_vowels; j++) {
            if (curr_char == vowels[j]) {
                is_vowel = 1;
                break;
            }
        }
        if (!is_vowel) {
            vowels_removed[index++] = curr_char;
        }
    }
    vowels_removed[index] = '\0';
    
    printf("Sentence with vowels removed: %s\n", vowels_removed);
    
    return 0;
}