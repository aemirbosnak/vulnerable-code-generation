//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len+1);
    for(int i = len-1; i >= 0; i--) {
        reversed[i] = str[len-1-i];
    }
    reversed[len] = '\0';
    printf("%s\n", reversed);
    free(reversed);
}

// Function to count the number of vowels in a string
int countVowels(char* str) {
    int count = 0;
    char vowels[] = "aeiouAEIOU";
    char* p = strtok(str, " ");
    while(p!= NULL) {
        int i = 0;
        while(vowels[i]!= '\0') {
            if(strchr(p, vowels[i])!= NULL) {
                count++;
                break;
            }
            i++;
        }
        p = strtok(NULL, " ");
    }
    return count;
}

int main() {
    char input[1000];
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    // Reverse the input string
    reverseString(input);

    // Count the number of vowels in the reversed string
    int vowelCount = countVowels(input);

    // Print the result
    printf("The reversed string has %d vowels.\n", vowelCount);

    return 0;
}