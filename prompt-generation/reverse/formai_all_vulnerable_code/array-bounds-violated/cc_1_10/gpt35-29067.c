//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000 // Maximum length of input string

char* compress(char* input){
    int length = strlen(input);
    char* result = malloc(sizeof(char) * (length + 1)); // Allocate memory for output string
    int i = 0, count = 1, index = 0;
    char current;

    while (i < length){
        current = input[i];

        while (input[i] == input[i+1]){ // Count number of repeated characters
            count++;
            i++;
        }

        if (count > 1){ // If there are repeated characters, add count to output string
            result[index] = count + '0';
            index++;

            while (count > 0){ // Add the actual character to the output string 'count' number of times
                result[index] = current;
                index++;
                count--;
            }
        } else { // If there are no repeated characters, simply add the current character to the output string
            result[index] = current;
            index++;
        }

        count = 1;
        i++;
    }

    result[index] = '\0'; // Add null character at the end of the output string
    return result;
}

int main(){
    char input[MAX_LENGTH], *output;
    printf("Enter string to compress: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    if (input[strlen(input)-1] == '\n'){
        input[strlen(input)-1] = '\0';
    }

    output = compress(input);
    printf("Compressed string: %s\n", output);

    free(output); // Free memory allocated for output string
    return 0;
}