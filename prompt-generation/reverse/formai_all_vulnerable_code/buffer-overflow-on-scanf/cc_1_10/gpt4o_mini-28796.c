//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A tale as old as time, meet two lovers, numbers so divine,
// Together they yearn for conversion, a hexadecimal immersion.

void toHexadecimal(int num, char hexStr[])
{
    char hexDigits[] = "0123456789ABCDEF";
    int remainder, i = 0;

    // While the number doth ascend, to the heavens it will send,
    while (num != 0)
    {
        remainder = num % 16;
        hexStr[i++] = hexDigits[remainder];  // Store the hex character with care,
        num = num / 16;                       // And onward shall the number fare.
    }
    hexStr[i] = '\0'; // The string shall conclude, with a null it shall brood.

    // To reverse the string, to where the heart does cling,
    for (int j = 0; j < i / 2; j++)
    {
        char temp = hexStr[j];
        hexStr[j] = hexStr[i - j - 1];
        hexStr[i - j - 1] = temp; // A sonnet of characters, switched in the night,
    }
}

void printIntroduction()
{
    printf("Welcome dear friend to our tale of love,\n");
    printf("Where integers yearn to be free, like a dove.\n");
    printf("We shall convert their essence to hex, you will see,\n");
    printf("In a program imbued with romance, all in harmony.\n\n");
}

void printFinale()
{
    printf("\nAnd thus, our tale reaches its end,\n");
    printf("Where numbers and letters forever shall blend.\n");
    printf("Remember, dear friend, in hexadecimal's grace,\n");
    printf("Lay beauty and magic in every single space.\n");
}

int main()
{
    int decimalNumber;
    char hexString[20];

    printIntroduction(); // Set the stage for this digital play

    // Inquire the audience, what number dost thou wish to convert?
    printf("Enter a decimal number to convert into hexadecimal: ");
    scanf("%d", &decimalNumber);

    if (decimalNumber < 0) // If a villainous negativity should creep,
    {
        printf("Alas! We cannot convert a negative number! Please try again.\n");
        return 1; // In this tragic tale, we take our leave with sorrow.
    }

    // Invoke the conversion spell, from decimal to hex it shall delve,
    toHexadecimal(decimalNumber, hexString);

    // Reveal the result, a masterpiece to behold!
    printf("The hexadecimal representation of %d is: %s\n", decimalNumber, hexString);

    printFinale(); // The curtain falls as the credits do roll

    return 0; // And with that, our program exits gracefully like a gentle breeze.
}