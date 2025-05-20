//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Function to count the frequency of each character in the input string
int countFreq(char str[]) {
    int freq[256] = {0}; // Initializing the frequency of each character to 0
    int i;
    
    for(i=0; str[i]!='\0'; i++) {
        freq[str[i]]++; // Incrementing the frequency of each character
    }
    
    return freq[str[i-1]]; // Returning the frequency of the last character
}

// Function to encode the input string using the frequency of each character
void encode(char str[], int freq[]) {
    int i, j;
    char code[256] = {0}; // Initializing the code for each character to 0
    
    for(i=0; i<256; i++) {
        if(freq[i] > 0) {
            code[i] = (char) (i+1); // Assigning the code for each character as its ASCII value + 1
        }
    }
    
    for(i=0; str[i]!='\0'; i++) {
        printf("%c", code[str[i]]); // Printing the code for each character
    }
}

// Function to decode the encoded string using the frequency of each character
void decode(char str[], int freq[]) {
    int i, j;
    char code[256] = {0}; // Initializing the code for each character to 0
    
    for(i=0; i<256; i++) {
        if(freq[i] > 0) {
            code[i] = (char) (i+1); // Assigning the code for each character as its ASCII value + 1
        }
    }
    
    for(i=0; str[i]!='\0'; i++) {
        printf("%c", code[str[i]]); // Printing the character for each code
    }
}

// Main function to take input from the user and call the appropriate function
int main() {
    char str[100];
    int freq[256] = {0};
    
    printf("Enter the string to be compressed: ");
    scanf("%s", str);
    
    freq[str[strlen(str)-1]]++; // Incrementing the frequency of the last character
    
    printf("Compressed string: ");
    encode(str, freq);
    
    printf("\nDecompressed string: ");
    decode(str, freq);
    
    return 0;
}