//FormAI DATASET v1.0 Category: Compression algorithms ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define SIZE 256

// Function to add a character to an array in string format
void addc(char ch, char* strin)
{
    int len = strlen(strin);
    strin[len] = ch;
    strin[len + 1] = '\0';
}

// Function to add an integer to an array in string format
void addi(int num, char* strin)
{
    char temp[10];
    sprintf(temp, "%d", num);
    strcat(strin, temp);
}

// Function to apply compression algorithm to given string
char* compress(char* strin)
{
    char* strout = malloc(strlen(strin) * sizeof(char)); // Allocate memory for output string
    strout[0] = '\0'; // Initialize output string

    char last_char = '\0'; // Initialize last character to null character
    int count = 0; // Initialize character count to 0

    // Loop through input string
    for (int i = 0; i < strlen(strin); i++) {
        if (isalnum(strin[i])) { // If current character is alphanumeric
            if (strin[i] == last_char) { // If current character is equal to last character
                count++; // Increment character count
            }
            else { // If current character is not equal to last character
                if (last_char != '\0') { // If last character is not null character
                    if (count > 1) { // If last character had repeated occurrences
                        addi(count, strout); // Add character count to output string
                    }
                    addc(last_char, strout); // Add last character to output string
                }
                last_char = strin[i]; // Update last character
                count = 1; // Reset character count to 1
            }
        }
    }

    // Handle last character
    if (last_char != '\0') {
        if (count > 1) { // If last character had repeated occurrences
            addi(count, strout); // Add character count to output string
        }
        addc(last_char, strout); // Add last character to output string
    }

    return strout; // Return output string
}

// Main function
int main()
{
    char strin[SIZE], * strout;
    printf("Enter a string to compress: ");
    gets(strin);

    // Apply compression algorithm
    strout = compress(strin);

    // Display output
    printf("Compressed string: %s", strout);

    return 0;
}