//FormAI DATASET v1.0 Category: Firewall ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the input is valid
bool isValidInput(char input[])
{
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] < 48 || input[i] > 57)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char firewallInput[10];
    bool isValid = false;
    int firewallValue;

    // Get the Firewall Value from the user
    printf("Please enter a valid Firewall value: ");
    while (!isValid)
    {
        scanf("%s", &firewallInput);
        isValid = isValidInput(firewallInput);
        if (!isValid)
        {
            printf("Invalid Input! Please enter a valid Firewall value: ");
        }
    }
    firewallValue = atoi(firewallInput);

    // Check if the input is divisible by 3
    for (int i = 1; i <= firewallValue; i++)
    {
        if (i % 3 == 0)
        {
            printf("Firewall Bypassed at value %d\n", i);
        }
        else if (i % 5 == 0)
        {
            printf("Firewall Bypassed at value %d\n", i);
        }
        else if (i % 7 == 0)
        {
            printf("Firewall Bypassed at value %d\n", i);
        }
        else
        {
            printf("Firewall Value at %d\n", i);
        }
    }
    return 0;
}