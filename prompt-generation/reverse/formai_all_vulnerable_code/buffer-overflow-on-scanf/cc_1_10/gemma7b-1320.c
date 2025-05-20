//Gemma-7B DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    int fd, i, j, k, l, n, x, y;
    char str[1024], key[1024], iv[1024], buf[1024];

    printf("Hey, wanna encrypt some stuff? Sure, let's do that!\n");

    printf("First, give me a secret key (at least 16 characters): ");
    scanf("%s", key);

    printf("Next, tell me what you want to encrypt: ");
    scanf("%s", str);

    n = strlen(str);
    x = strlen(key);

    if (x < 16)
    {
        printf("Error: Key is too short. Please use at least 16 characters.\n");
        return 1;
    }

    iv[0] = key[0] ^ key[x - 1];
    for (i = 1; i < x - 1; i++)
    {
        iv[i] = key[i] ^ key[i - 1];
    }

    for (i = 0; i < n; i++)
    {
        buf[i] = str[i] ^ iv[i];
    }

    printf("Here's your encrypted message: ");
    for (i = 0; i < n; i++)
    {
        printf("%c", buf[i]);
    }

    printf("\n");

    return 0;
}