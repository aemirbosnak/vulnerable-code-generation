//FormAI DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char input[10000];
int length;

void compress(char * data)
{
    int i, j, k, count;
    int freq[256];

    for (i = 0; i < 256; i++)
        freq[i] = 0;

    for (i = 0; i < length; i++)
        freq[(int)data[i]]++;

    for (i = j = 0; i < length; j++)
    {
        int ch = (int)data[i];
        count = 0;

        while (i < length && ch == (int)data[i])
        {
            i++;
            count++;
        }

        input[j++] = ch;
        input[j] = count + '0';
    }

    input[j] = '\0';

    printf("\nCompressed data:\n%s", input);
}

void decompress(char * data)
{
    int i, j, k, count;
    int freq[256];

    for (i = 0; i < 256; i++)
        freq[i] = 0;

    for (i = 0; i < length; i++)
        freq[(int)data[i]]++;

    for (i = j = 0; i < length;)
    {
        int ch = (int)data[i];
        count = 0;

        while (data[i + 1] >= '0' && data[i + 1] <= '9')
        {
            count = count * 10 + data[i + 1] - '0';
            i++;
        }

        i++;
        while (count--)
        {
            input[j++] = ch;
        }
    }

    input[j] = '\0';

    printf("\nDecompressed data:\n%s", input);
}

int main()
{
    printf("Enter the string to be compressed: ");
    scanf("%s", input);
    length = strlen(input);

    printf("\nOriginal data:\n%s\n", input);

    compress(input);

    decompress(input);

    return 0;
}