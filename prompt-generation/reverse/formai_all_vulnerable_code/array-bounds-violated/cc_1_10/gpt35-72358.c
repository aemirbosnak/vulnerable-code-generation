//FormAI DATASET v1.0 Category: Compression algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 // maximum length of string to be compressed

char compressed[MAX_LEN]; // compressed string

// function to compress the given string and return its length
int compress(char* str, int len){
    if(len == 0) // empty string case
        return 0;

    int count = 1; // initialize count of characters
    char curr_char = str[0]; // initialize current character

    int index = 0; // initialize index of compressed string

    // loop through the string and compress it
    for(int i = 1; i < len; i++){
        if(str[i] == curr_char){ // if the current character is same as previous
            count++; // increase count
        }
        else{ // current character is different from previous
            if(count > 1){ // if previous character has occurred more than once
                compressed[index++] = curr_char; // add character to compressed string
                char* count_str = (char*) malloc(sizeof(char) * 10); // allocate memory for count string
                sprintf(count_str, "%d", count); // convert count int to string
                int count_len = strlen(count_str); // get length of count string
                memcpy(&compressed[index], count_str, count_len); // add count string to compressed string
                index += count_len; // increase index by length of count string
                free(count_str); // free count string memory
            }
            else{ // previous character has occurred only once
                compressed[index++] = curr_char; // add character to compressed string
            }
            curr_char = str[i]; // update current character
            count = 1; // reset count
        }
    }

    // handle the last character occurrence
    if(count > 1){ // if the last character has occurred more than once
        compressed[index++] = curr_char; // add character to compressed string
        char* count_str = (char*) malloc(sizeof(char) * 10); // allocate memory for count string
        sprintf(count_str, "%d", count); // convert count int to string
        int count_len = strlen(count_str); // get length of count string
        memcpy(&compressed[index], count_str, count_len); // add count string to compressed string
        index += count_len; // increase index by length of count string
        free(count_str); // free count string memory
    }
    else{ // if the last character has occurred only once
        compressed[index++] = curr_char; // add character to compressed string
    }

    compressed[index] = '\0'; // terminate compressed string

    return index; // return length of compressed string
}

int main(){
    char str[MAX_LEN];
    printf("Enter the string to compress: ");
    fgets(str, MAX_LEN, stdin);
    str[strlen(str)-1] = '\0'; // remove newline character from string

    int len = strlen(str); // length of input string

    int compressed_len = compress(str, len); // compress string and get its length

    printf("Compressed string: %s\n", compressed); // print compressed string
    printf("Length of compressed string: %d\n", compressed_len); // print length of compressed string

    return 0;
}