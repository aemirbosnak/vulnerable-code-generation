//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY "mysecretkey"

void encrypt(char* text, int key_len)
{
    int i = 0;
    int j = 0;
    char key[key_len];
    strcpy(key, KEY);
    while (text[i])
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = (text[i] + ((j % key_len) - 65 + 97)) % 26 + 65;
            }
            else
            {
                text[i] = (text[i] + ((j % key_len) - 97 + 65)) % 26 + 97;
            }
        }
        i++;
        j++;
    }
}

int main()
{
    char text[1000];
    printf("Enter the file name to encrypt: ");
    scanf("%s", text);

    FILE* file = fopen(text, "r");
    if (file == NULL)
    {
        printf("File not found.\n");
        return 0;
    }

    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), file)!= NULL)
    {
        encrypt(buffer, strlen(KEY));
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}