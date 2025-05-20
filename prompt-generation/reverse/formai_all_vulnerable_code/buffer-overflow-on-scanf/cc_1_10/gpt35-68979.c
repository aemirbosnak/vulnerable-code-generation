//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function Declarations
char *convert_to_binary(unsigned int decimal);
char *get_hash(char *input);

//Encapsulation
int main()
{
    char input[100];
    char *hash;

    printf("Enter a string to hash: ");
    scanf("%s", input);

    //get hash and print it out
    hash = get_hash(input);
    printf("Hash of \"%s\" is %s\n", input, hash);

    return 0;
}

//Hash Function Definition
char *get_hash(char *input)
{
    unsigned int hash = 0;
    unsigned int byte;
    int i;

    //Calculate hash by XOR'ing each byte of input converted to binary
    for (i = 0; i < strlen(input); i++)
    {
        byte = (unsigned int)input[i];
        hash = hash ^ byte;

        //Shift hash
        hash = (hash >> 1) | (hash << (sizeof(unsigned int) * 8 - 1));
    }

    //Convert hash to binary and return it
    return convert_to_binary(hash);
}

//Convert Decimal to Binary
char *convert_to_binary(unsigned int decimal)
{
    int i;
    char *binary = (char*)malloc(sizeof(char) * 33);

    //Set all elements to 0
    memset(binary, 0, sizeof(char) * 33);

    for (i = 0; i < 32; i++)
    {
        if (decimal & (1 << i))
            binary[31 - i] = '1';
        else
            binary[31 - i] = '0';
    }

    return binary;
}