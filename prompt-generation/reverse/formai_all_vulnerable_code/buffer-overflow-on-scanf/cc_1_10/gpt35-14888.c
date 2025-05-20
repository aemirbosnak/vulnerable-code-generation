//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[1000];
    int i, j, len, count=0;
    char c;

    printf("Enter message: ");
    scanf("%[^\n]", message);

    len = strlen(message);

    for(i=0; i<len; i++)
    {
        c = message[i];

        if(c == 'c' || c == 'C')
        {
            j = i+1;

            while(message[j] == ' ' || message[j] == '\t')
            {
                j++;
            }

            if(message[j] == 'p' || message[j] == 'P')
            {
                count++;

                if(count >= 3)
                {
                    printf("Possible spam detected!\n");
                    printf("Message: %s\n", message);
                    printf("Count: %d\n", count);
                    return 1;
                }
            }
            else
            {
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    printf("No spam detected.\n");
    return 0;
}