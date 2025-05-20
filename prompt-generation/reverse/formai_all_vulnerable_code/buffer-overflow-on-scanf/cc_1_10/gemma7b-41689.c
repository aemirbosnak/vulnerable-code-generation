//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int main()
{
    char message[MAX_LEN], cover[MAX_LEN], key[MAX_LEN];
    int i, j, k, flag = 0, hidden_pos = 0;

    printf("Enter the secret message: ");
    scanf("%s", message);

    printf("Enter the cover image: ");
    scanf("%s", cover);

    printf("Enter the key: ");
    scanf("%s", key);

    k = strlen(key);

    for (i = 0; i < strlen(message); i++)
    {
        for (j = 0; j < strlen(cover); j++)
        {
            if (flag == 0)
            {
                if (message[i] == key[j])
                {
                    hidden_pos = j;
                    flag = 1;
                }
            }
            else
            {
                if (hidden_pos == j)
                {
                    cover[j] = message[i];
                }
            }
        }
    }

    FILE *fp = fopen(cover, "w");
    fprintf(fp, "%s", cover);
    fclose(fp);

    printf("Secret message hidden successfully!\n");

    return 0;
}