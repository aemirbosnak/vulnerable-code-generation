//FormAI DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <string.h>

int main() 
{
    char message[1000], c;
    int i, spam_count = 0;

    printf("Enter a message: ");
    gets(message);

    for(i=0; i<strlen(message); i++) 
    {
        c = message[i];

        if (c == 'a') 
        {
            if (message[i+1] == 'd' && message[i+2] == 'v' && message[i+3] == 'e' && message[i+4] == 'r' && message[i+5] == 't' && message[i+6] == 'i' && message[i+7] == 's' && message[i+8] == 'i' && message[i+9] == 'n' && message[i+10] == 'g') 
            {
                spam_count++;
            }
        } 
        else if (c == 'w') 
        {
            if (message[i+1] == 'i' && message[i+2] == 'n' && message[i+3] == 'n' && message[i+4] == 'i' && message[i+5] == 'n' && message[i+6] == 'g') 
            {
                spam_count++;
            } 
            else if (message[i+1] == 'a' && message[i+2] == 't' && message[i+3] == 'c' && message[i+4] == 'h' && message[i+5] == 'e' && message[i+6] == 's') 
            {
                spam_count++;
            }
        } 
        else if (c == 'f') 
        {
            if (message[i+1] == 'r' && message[i+2] == 'e' && message[i+3] == 'e')
            {
                spam_count++;
            }
        } 
    }

    if (spam_count > 0) 
    {
        printf("\nWarning! This message contains %d spam keywords.", spam_count);
    } 
    else 
    {
        printf("\nThis message appears to be safe.");
    }

    return 0;
}