//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void main()
{
    char key;
    char input[1024];
    int i = 0;
    int flag = 0;
    FILE *fp;

    // Open the secret file
    fp = fopen("secret.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    // Read the secret file contents
    fscanf(fp, "%s", input);
    fclose(fp);

    // Loop to read keystrokes
    while ((key = getchar()) != '\n')
    {
        // Check if the keystroke matches the secret file contents
        if (input[i] == key)
        {
            i++;
            if (i == strlen(input))
            {
                flag = 1;
            }
        }
        else
        {
            i = 0;
        }
    }

    // Check if the flag is set
    if (flag)
    {
        printf("Access granted\n");
    }
    else
    {
        printf("Access denied\n");
    }
}