//FormAI DATASET v1.0 Category: Firewall ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main()
{
    char packet[100];
    int flag = 1;

    while (flag == 1)
    {
        printf("Enter packet:\n");
        scanf("%s", packet);

        if (strstr(packet, "malware") != NULL)
        {
            printf("Firewall : Block malware packet\n");
            flag = 0;
        }
        else if (strstr(packet, "spoof") != NULL)
        {
            printf("Firewall: Block spoof packet\n");
            flag = 0;
        }
        else if (strstr(packet, "phishing") != NULL)
        {
            printf("Firewall : Block phishing packet\n");
            flag = 0;
        }
        else if(strstr(packet, "exploit") != NULL)
        {
            printf("Firewall : Block exploit packet\n");
            flag = 0;
        }
        else if(strstr(packet, "worm") != NULL)
        {
            printf("Firewall : Block worm packet\n");
            flag = 0;
        }
        else if(strstr(packet, "DDoS") != NULL)
        {
            printf("Firewall : Block DDoS packet\n");
            flag = 0;
        }
        else
        {
            printf("Firewall : Allow packet\n");
        }
    }

    return 0;
}