//FormAI DATASET v1.0 Category: Encryption ; Style: statistical
/* This C program demonstrates how to encrypt a message using the statistical method */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY 3  // define the encryption key

int main()
{
    char plain_text[100], cipher_text[100];
    int i, j, k, m, n;
    float freq[26] = {8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 0.2, 0.8, 4.0, 2.4, 
                    6.7, 7.5, 1.9, 0.1, 6.0, 6.3, 9.0, 2.8, 1.0, 2.4, 0.2, 2.0, 0.1}; // English language frequency

    srand(time(NULL)); // Seed the random number generator

    // Prompt user for input
    printf("Enter the plain text message: ");
    fgets(plain_text, 100, stdin);

    // Remove newline character from input
    plain_text[strlen(plain_text)-1] = '\0';

    // Encryption
    for(i=0; i<strlen(plain_text); i++)
    {
        // Skip spaces and special characters
        if(plain_text[i] == ' ' || plain_text[i] == '.' || plain_text[i] == ',' || plain_text[i] == '\n')
            continue;

        // Convert uppercase to lowercase
        if(plain_text[i] >= 'A' && plain_text[i] <= 'Z')
            plain_text[i] += 32;

        // Calculate the frequency of each letter
        m = plain_text[i] - 'a';
        freq[m]++;

        // Randomly shuffle the letters
        n = rand() % 26;
        if(n != m)
        {
            k = freq[m];
            freq[m] = freq[n];
            freq[n] = k;
        }

        // Encrypt the letter
        j = plain_text[i] - 'a' + KEY;
        if(j > 25)
            j = j - 26;
        cipher_text[i] = j + 'a';

    }
    cipher_text[i] = '\0';  // Add terminating null character to string

    // Print the encrypted message
    printf("Encrypted message: %s\n", cipher_text);

    return 0;
}