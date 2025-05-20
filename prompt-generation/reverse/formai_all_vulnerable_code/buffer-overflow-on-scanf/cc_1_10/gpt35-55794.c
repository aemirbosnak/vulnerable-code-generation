//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: shape shifting
#include <stdio.h>

// A simple function to create public key for given private key
int createPublicKey(int privateKey, int base, int mod)
{
    int publicKey = 1;

    for(int i = 0; i < privateKey; i++)
    {
        publicKey = (publicKey * base) % mod;
    }

    return publicKey;
}

int main()
{
    // User inputs the private key, base and mod values
    int privateKey, base, mod;
    printf("Enter the private key, base and mod values:\n");
    scanf("%d%d%d", &privateKey, &base, &mod);

    // Generate the public key using the above function
    int publicKey = createPublicKey(privateKey, base, mod);

    // Print the results
    printf("Private Key: %d\n", privateKey);
    printf("Base: %d\n", base);
    printf("Mod: %d\n", mod);
    printf("Public Key: %d\n", publicKey);
    
    // Shape shifting begins
    printf("\n\nWelcome to the Shape Shifting Arena!\n");

    // Creating a square shape using asterisk
    printf("\nSquare Shape:\n");
    int size = 8; // Size of square shape
    for(int i = 0; i < size; i++)
    {
        // Print a row of asterisks
        for(int j = 0; j < size; j++)
        {
            printf("* ");
        }

        // Go to next row
        printf("\n");
    }

    // Creating a right-angled triangle shape using numbers
    printf("\nRight-Angled Triangle Shape:\n");
    int height = 6; // Height of triangle shape
    for(int i = 1; i <= height; i++)
    {
        // Print the numbers in the current row
        for(int j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }

        // Go to next row
        printf("\n");
    }

    // Creating a diamond shape using letters
    printf("\nDiamond Shape:\n");
    int diamondSize = 7; // Length of diamond shape
    int spaces = diamondSize / 2;

    // Print the upper half of diamond
    for(int i = 0; i < diamondSize; i++)
    {
        // Print leading spaces
        for(int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        // Print the letters in current row
        for(int j = 0; j < diamondSize - 2 * spaces; j++)
        {
            printf("%c", 'A' + i);
        }

        // Print trailing spaces
        for(int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        // Go to next row
        printf("\n");

        // Decrease spaces for next row in upper half
        if(i < diamondSize / 2)
        {
            spaces--;
        }
        // Increase spaces for next row in lower half
        else
        {
            spaces++;
        }
    }

    // End of shape shifting
    printf("\nThanks for visiting the Shape Shifting Arena!\n");

    return 0;
}