//Gemma-7B DATASET v1.0 Category: Firewall ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char firewall[256];
    int i, j, k, l, m, n;
    firewall[0] = '\0';

    // Building the Firewall
    printf("Enter the number of rules: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the rule number: ");
        scanf("%d", &k);

        printf("Enter the protocol: ");
        scanf("%s", firewall);

        printf("Enter the source IP address: ");
        scanf("%s", firewall);

        printf("Enter the destination IP address: ");
        scanf("%s", firewall);

        printf("Enter the port number: ");
        scanf("%d", &l);

        printf("Enter the action: ");
        scanf("%s", firewall);

        firewall[k] = '\1';
    }

    // Testing the Firewall
    printf("Enter the IP address: ");
    scanf("%s", firewall);

    printf("Enter the port number: ");
    scanf("%d", &m);

    if (firewall[m] == '\1')
    {
        printf("Access granted.\n");
    }
    else
    {
        printf("Access denied.\n");
    }

    return 0;
}