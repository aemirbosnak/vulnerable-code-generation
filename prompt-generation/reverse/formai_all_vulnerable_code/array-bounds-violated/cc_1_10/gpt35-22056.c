//FormAI DATASET v1.0 Category: Compression algorithms ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char input[1000], output[1000];
    int frequency[256] = {0}, i, j;
    int len, index = 0;

    printf("Enter the input string: ");
    scanf("%[^\n]%*c", input);

    len = strlen(input);

    //Count frequency of each character
    for (i = 0; i < len; i++)
    {
        frequency[(int)input[i]]++;
    }

    //Encode the string
    for (i = 0; i < len; i++)
    {
        if (frequency[(int)input[i]] > 0)
        {
            //Add the character to output string
            output[index++] = input[i];

            //Add frequency of the character to output string
            sprintf(output + index, "%d", frequency[(int)input[i]]);
            index += 1 + strlen(output + index);
 
            //Set the frequency of the character to zero to avoid repetition
            frequency[(int)input[i]] = 0;
        }
    }

    //Printing the encoded string
    printf("Encoded string: %s\n", output);

    //Decode the string
    index = 0;
    len = strlen(output);
    while (index < len)
    {
        //Extract the character
        char character = output[index++];

        //Extract the frequency of the character
        char freq[10];
        for (i = 0; output[index] != '\0' && output[index] != character; i++, index++)
        {
            freq[i] = output[index];
        }

        freq[i] = '\0';
        int frequency = atoi(freq);

        //Add the character to the output string
        for (j = 0; j < frequency; j++)
        {
            printf("%c", character);
        }
    }

    return 0;
}