//FormAI DATASET v1.0 Category: Bitwise operations ; Style: funny
#include<stdio.h>
#include<string.h>

int main()
{
    char bit1[9], bit2[9]; //two char arrays to store two binary numbers of maximum 8 bits each
    int decimal1, decimal2, ans; //three integers for decimal value of first number, decimal value of second number and the answer after bitwise operation
    char op[4]; //char array to store the operator

    printf("Howdy there! I am the Bitwise Bot. Let's perform some funny bitwise operations.\n");

    printf("\nEnter the first binary number (up to 8 bits): ");
    scanf("%s", bit1);

    printf("Enter the second binary number (up to 8 bits): ");
    scanf("%s", bit2);

    printf("\nChoose the operator you want to apply ('AND', 'OR', 'XOR' or 'NOT'): ");
    scanf("%s", op);
    
    if(strlen(bit1)>8 || strlen(bit2)>8) //if length of either binary number exceeds 8 bits
    {
        printf("\nError: Bits exceeded the limit of 8 bits. I cannot proceed with this relationship.\n"); //pun intended
        return 0;
    }

    decimal1 = (int) strtol(bit1, NULL, 2); //converting first binary number to decimal value
    decimal2 = (int) strtol(bit2, NULL, 2); //converting second binary number to decimal value

    if(strcmp(op, "AND") == 0) //if AND operator is chosen
    {
        ans = decimal1 & decimal2; //bitwise AND operation
        printf("\nThis is where the magic happens: %s & %s = %d\n", bit1, bit2, ans);
    }
    else if(strcmp(op, "OR") == 0) //if OR operator is chosen
    {
        ans = decimal1 | decimal2; //bitwise OR operation
        printf("\nDon't tell your ex but: %s | %s = %d\n", bit1, bit2, ans);
    }
    else if(strcmp(op, "XOR") == 0) //if XOR operator is chosen
    {
        ans = decimal1 ^ decimal2; //bitwise XOR operation
        printf("\nThis one's a little risky: %s ^ %s = %d\n", bit1, bit2, ans);
    }
    else if(strcmp(op, "NOT") == 0) //if NOT operator is chosen
    {
        ans = ~decimal1; //bitwise NOT operation on first binary number
        printf("\nYou can't say this to your new crush but: NOT %s = %d\n", bit1, ans);
    }
    else //if none of the valid operators are chosen
    {
        printf("\nError: Invalid operator chosen. I cannot proceed with this relationship.\n"); //pun intended again
    }

    printf("\nBye bye for now!\n");

    return 0;
}