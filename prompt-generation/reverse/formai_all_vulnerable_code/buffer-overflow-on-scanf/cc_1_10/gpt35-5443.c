//FormAI DATASET v1.0 Category: Compression algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 50 

// Function to compress the string recursively
char* compress(char* str, char* compressed_str, int count, char current_char, int index){
    if(index == strlen(str)){
        // Adding count to the compressed string
        char count_str[MAXSIZE];
        sprintf(count_str, "%d", count);
        strcat(compressed_str, count_str);
        // Adding current_char to the compressed string
        strncat(compressed_str, &current_char, 1);
        return compressed_str;
    }
    else{
        if(str[index] == current_char){
            // If the current character matches the previous character 
            // then increment the count and continue with recursion
            return compress(str, compressed_str, count+1, current_char, index+1);
        }
        else{
            // If the current character is different from the previous character
            // then add the count and current_char to the compressed string
            char count_str[MAXSIZE];
            sprintf(count_str, "%d", count);
            strcat(compressed_str, count_str);
            strncat(compressed_str, &current_char, 1);
            // Restart the count and continue with recursion
            return compress(str, compressed_str, 1, str[index], index+1);
        }
    }
}

// Main function
int main(){
    char str[MAXSIZE], compressed_str[MAXSIZE];
    printf("Enter a string to compress: ");
    scanf("%s", str);
    // Starting with the first character of the string
    char current_char = str[0];
    // Initializing count to 1
    int count = 1;
    // First character of the compressed string is same as the first character of the original string
    char count_str[MAXSIZE];
    sprintf(count_str, "%d", count);
    strcat(compressed_str, count_str);
    strncat(compressed_str, &current_char, 1);
    // Calling the recursive function to compress the remaining string
    char* result_str = compress(str, compressed_str, count, current_char, 1);
    printf("Compressed string: %s\n", result_str);
    return 0;
}