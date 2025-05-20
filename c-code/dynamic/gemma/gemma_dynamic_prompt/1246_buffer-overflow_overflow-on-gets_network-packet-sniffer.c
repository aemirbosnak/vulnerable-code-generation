#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buf[1024];
    char packet[2048];
    int i = 0;
    FILE *fp;

    fp = fopen("packet.txt", "r");
    if (fp == NULL)
    {
        return 1;
    }

    while (fgets(packet, 2048, fp) != NULL)
    {
        for (i = 0; packet[i] != '\0'; i++)
        {
            if (i >= 1024)
            {
                packet[i] = '\0';
            }
            buf[i] = packet[i];
        }
        printf("%s\n", buf);
    }

    fclose(fp);
    return 0;
}
