//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// A tale of love, that spark ignites,
// As we convert numbers in binary lights.
void intToBinary(int num, char *binary)
{
    if (num > 1)
        intToBinary(num >> 1, binary);

    strcat(binary, (num & 1) ? "1" : "0");
}

// In fair Verona, where we set our scene,
// The function to print the binary will glean.
void printBinaryRepresentation(int num)
{
    char binary[33];
    memset(binary, 0, sizeof(binary)); // Initialize the binary array
    
    intToBinary(num, binary);

    printf("Lo! The binary representation of %d is: %s\n", num, binary);
}

// An affair of the heart hidden, buried in code,
// For each lover's number, love's journey bestowed.
int main()
{
    int num;

    // Oh, what light through yonder window breaks,
    // A prompt for users, their choice to take.
    printf("Enter a number, forsooth, to convert to binary:\n");
    
    // To read the number with care, we must,
    // The lovers of logic, in conversion we trust.
    if (scanf("%d", &num) != 1) {
        fprintf(stderr, "Alas! A misstep in the input, do try once more!\n");
        return 1; // Exit with dismay, for fate strewn upon the floor.
    }

    // The numbers we embrace, whether joyful or grim,
    // We shall reveal their binary, let no light be dim.
    printBinaryRepresentation(num);

    // And when the conversion is spoken like sweet verse,
    // The binary shall flourish, the universe diverse.
    return 0; // As all good tales must reach their end,
}