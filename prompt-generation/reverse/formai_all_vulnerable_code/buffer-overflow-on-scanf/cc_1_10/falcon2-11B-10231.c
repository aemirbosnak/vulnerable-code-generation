//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Function to compress the string
void compress(char *str)
{
    int count = 1;
    int i = 0;
    int j = 0;

    // Iterate through the string
    while (str[i]!= '\0')
    {
        if (str[i] == str[i + 1])
        {
            count++;
        }
        else
        {
            // If the count is greater than 1, store the character and its count
            if (count > 1)
            {
                printf("%c%d", str[j], count);
                j++;
            }

            // Reset the count and character pointer
            count = 1;
            i++;
        }
    }

    // If the count is greater than 1, store the character and its count
    if (count > 1)
    {
        printf("%c%d", str[j], count);
    }
}

int main()
{
    // Take input string
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Call compress function
    compress(str);

    return 0;
}