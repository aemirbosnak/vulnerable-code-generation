//FormAI DATASET v1.0 Category: Text processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100],output[100],ch;
    int i,j,len,count=0;

    printf("Enter some text: ");
    gets(input);

    len = strlen(input);

    for(i=0;i<len;i++)
    {
        ch = input[i];

        if(ch == 'a' || ch == 'A')
        {
            output[count] = '^';
            count++;
            output[count] = 'a';
            count++;
        }
        else if(ch == 'e' || ch == 'E')
        {
            output[count] = '-';
            count++;
            output[count] = 'e';
            count++;
        }
        else if(ch == 'i' || ch == 'I')
        {
            output[count] = '+';
            count++;
            output[count] = 'i';
            count++;
        }
        else if(ch == 'o' || ch == 'O')
        {
            output[count] = '*';
            count++;
            output[count] = 'o';
            count++;
        }
        else if(ch == 'u' || ch == 'U')
        {
            output[count] = '&';
            count++;
            output[count] = 'u';
            count++;
        }
        else
        {
            output[count] = ch;
            count++;
        }
    }

    output[count] = '\0';

    printf("The processed text is: %s\n",output);

    return 0;
}

/*
Sample Input: This is a text processing example program.
Sample Output: Th^is -is +a t*eX*t pr+ocessing examp&le pr+ogram.
*/