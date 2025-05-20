#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char message[100];
    int key;
    int i;

    printf("Enter a message: ");
    scanf("%s", message);

    printf("Enter the key: ");
    scanf("%d", &key);

    for (i = 0; message[i] != '\0'; i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
    }

    printf("Encrypted message: %s", message);

    return 0;
}
