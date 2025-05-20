//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Dennis Ritchie
/* 
 * A Simple Compression Algorithm
 * By [Your Name]
 * 
 * This program reads a string of uppercase letters, compresses it by counting
 * the consecutive occurrences of each character and outputting the counts
 * followed by the characters. For example, the input string "JJJKKKK" would
 * be compressed as "3J4K".
 *
 * Note that this implementation assumes that the input string contains only
 * uppercase letters.
 */

#include <stdio.h>

#define MAX_LENGTH 1000 // Maximum length of input string

int main() {
    char str[MAX_LENGTH];
    int count[MAX_LENGTH];
    int len = 0;
    
    // Read input string
    printf("Enter a string of uppercase letters: ");
    scanf("%s", str);
    
    // Compress the string
    int i = 0;
    while (str[i] != '\0') {
        char curr_char = str[i];
        int curr_count = 1;
        i++;
        while (str[i] == curr_char && curr_count < 9) {
            curr_count++;
            i++;
        }
        count[len] = curr_count;
        len++;
        count[len] = curr_char;
        len++;
    }
    
    // Output the compressed string
    printf("Compressed string: ");
    for (int j = 0; j < len; j++) {
        if ((j+1) % 2 == 1) {
            printf("%d", count[j]);
        } else {
            printf("%c", count[j]);
        }
    }
    printf("\n");
    
    return 0;
}