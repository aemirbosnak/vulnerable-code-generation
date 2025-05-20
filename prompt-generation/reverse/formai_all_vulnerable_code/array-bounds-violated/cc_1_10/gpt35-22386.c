//FormAI DATASET v1.0 Category: Compression algorithms ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

int main()
{
    char input[MAX], unique[MAX];
    int frequency[MAX], count = 0;

    printf("Enter a string to compress: ");
    fgets(input, MAX, stdin);

    int len = strlen(input);
    input[len - 1] = '\0';  //To remove the newline character from the input string

    //Finding unique characters and their frequencies in the input string
    for(int i=0; i<len; i++)
    {
        int flag = 0;
        char ch = input[i];

        for(int j=0; j<count; j++)
        {
            if(ch == unique[j])
            {
                frequency[j]++;
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            unique[count] = ch;
            frequency[count] = 1;
            count++;
        }
    }

    //Printing the unique characters and their frequencies
    printf("Unique characters and their frequencies:\n\n");
    for(int i=0; i<count; i++)
    {
        printf("%c : %d\n", unique[i], frequency[i]);
    }

    //Compressing the input string
    char compressed[MAX];
    int com_count = 0;

    for(int i=0; i<len; i++)
    {
        char ch = input[i];
        int index;

        for(int j=0; j<count; j++)
        {
            if(ch == unique[j])
            {
                index = j;
                break;
            }
        }

        for(int j=0; j<frequency[index]; j++)
        {
            compressed[com_count++] = unique[index];
        }
    }

    compressed[com_count] = '\0';

    //Printing the compressed string
    printf("\nOriginal string: %s\n", input);
    printf("Compressed string: %s\n", compressed);

    return 0;
}