//FormAI DATASET v1.0 Category: System administration ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given string is a valid IP address
int is_valid_ip_address(char *ip_address)
{
    // Check if the string is null or empty
    if (!ip_address || strlen(ip_address) == 0) {
        return 0;
    }

    int num;
    char *token, *rest = ip_address;
    int count = 0;

    // Split the string by "."
    while ((token = strtok_r(rest, ".", &rest))) {
        count++;

        // The string should have exactly 4 tokens separated by "."
        if (count > 4) {
            return 0;
        }

        // Check if the token is a valid integer between 0 and 255
        num = atoi(token);
        if (num < 0 || num > 255) {
            return 0;
        }
    }

    // The string should have exactly 4 tokens separated by "."
    if (count != 4) {
        return 0;
    }

    return 1; // The string is a valid IP address
}

int main()
{
    char ip_address[20];

    // Get the IP address from the user
    printf("Enter an IP address: ");
    scanf("%s", ip_address);

    // Check if the given IP address is valid
    if (is_valid_ip_address(ip_address)) {
        printf("Valid IP address\n");
    } else {
        printf("Invalid IP address\n");
    }

    return 0;
}