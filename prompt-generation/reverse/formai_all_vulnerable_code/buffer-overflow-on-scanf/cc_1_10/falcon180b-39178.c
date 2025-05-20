//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

int main()
{
    FILE *file;
    char filename[50], ch;
    int key, i, j, k, n, count = 0, flag = 0;

    printf("Enter the name of the file to encrypt: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error! File not found.\n");
        exit(0);
    }

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    printf("Enter the number of rounds for encryption: ");
    scanf("%d", &n);

    rewind(file);

    while ((ch = fgetc(file))!= EOF)
    {
        if (isalpha(ch))
        {
            if (isupper(ch))
            {
                ch = ch + key - 65;
                if (ch > 90)
                {
                    ch = ch - 26;
                }
            }
            else
            {
                ch = ch + key - 97;
                if (ch > 122)
                {
                    ch = ch - 26;
                }
            }
        }
        else
        {
            ch = ch;
        }

        fprintf(stdout, "%c", ch);
    }

    fclose(file);

    return 0;
}