//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: statistical
#include<stdio.h>

void main()
{
    char text[100], ch;
    int i, j, length;
    printf("Enter Text: ");
    scanf("%[^\n]", text);
    length = strlen(text);
    printf("ASCII Art Generator Output:\n");
    for(i=0; i<length; i++)
    {
        ch = text[i];
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch - 32;
        }
        if(ch >= 'A' && ch <= 'Z')
        {
            for(j=1; j<=5; j++)
            {
                if((j == 1) || (j == 5))
                {
                    printf("  ");
                }
                else if(j == 2)
                {
                    printf("..");
                }
                else if(j == 3)
                {
                    printf(". ");
                }
                else
                {
                    printf(".%c.", ch);
                }
            }
            printf("\n");
        }
        else if(ch == ' ')
        {
            for(j=1; j<=5; j++)
            {
                printf("  ");
            }
            printf("\n");
        }
    }
}