//FormAI DATASET v1.0 Category: Firewall ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int verifyIP(char *);
int verifyPort(char *);

int main()
{
    // Greet the user
    printf("Welcome to the Firewall Program!\n\n");

    // Define user input variables
    char ip[20];
    char port[5];

    // Prompt user for IP address
    printf("Please enter the IP address you would like to block: ");
    scanf("%s", ip);

    // Verify user input
    if (verifyIP(ip))
    {
        printf("IP address %s is valid. \n", ip);
    }
    else
    {
        printf("IP address %s is invalid. Please try again. \n", ip);
        exit(0);
    }

    // Prompt user for port number
    printf("Please enter the port number you would like to block: ");
    scanf("%s", port);

    // Verify user input
    if (verifyPort(port))
    {
        printf("Port %s is valid. \n", port);
    }
    else
    {
        printf("Port %s is invalid. Please try again. \n", port);
        exit(0);
    }

    // Create firewall rule
    printf("\nCreating firewall rule to block ip %s on port %s... \n", ip, port);
    printf("Firewall rule created successfully! \n");

    // Exit program
    printf("\nThank you for using the Firewall Program! Goodbye. \n");
    exit(0);
}

// Function to verify IP address
int verifyIP(char *ip)
{
    int num, dots = 0;
    char *ptr;

    if (ip == NULL)
    {
        return 0;
    }
    ptr = strtok(ip, ".");
    if (ptr == NULL)
    {
        return 0;
    }

    while (ptr)
    {
        if (!isdigit(*ptr))
        {
            return 0;
        }

        num = atoi(ptr);
        if (num >= 0 && num <= 255)
        {
            ptr = strtok(NULL, ".");
            if (ptr != NULL)
                dots++;
        }
        else
        {
            return 0;
        }
    }

    if (dots != 3)
    {
        return 0;
    }

    return 1;
}

// Function to verify port number
int verifyPort(char *port)
{
    int num;
    char *ptr;

    if (port == NULL)
    {
        return 0;
    }
    ptr = strtok(port, ".");
    if (ptr == NULL)
    {
        return 0;
    }

    num = atoi(ptr);
    if (num >= 1 && num <= 65535)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}