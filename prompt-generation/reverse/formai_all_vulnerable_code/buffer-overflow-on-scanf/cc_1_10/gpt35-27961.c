//FormAI DATASET v1.0 Category: Firewall ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if an IP address is valid
int isValidIP(char *ip) {
    char delim[] = ".";
    char *ptr = strtok(ip, delim);
    
    // Loop through all four octets of the IP address
    int octet, count = 0;
    while (ptr != NULL) {
        // Parse and validate each octet
        octet = atoi(ptr);
        if (octet < 0 || octet > 255) {
            return 0;
        }
        ptr = strtok(NULL, delim);
        count++;
    }
    
    // Make sure we have exactly four octets
    if (count != 4) {
        return 0;
    }
    
    return 1;
}

int main() {
    char input[100];
    printf("Enter an IP address to block: ");
    scanf("%s", input);
    
    // Validate the input IP address
    if (!isValidIP(input)) {
        printf("Invalid IP address. Please try again.\n");
        return -1;
    }
    
    // Open the firewall configuration file for writing
    FILE *config_file = fopen("/etc/firewall.conf", "a");
    if (config_file == NULL) {
        printf("Error opening firewall config file.\n");
        return -1;
    }
    
    // Write the rule to block the input IP address
    fprintf(config_file, "block in from %s\n", input);
    fclose(config_file);
    
    printf("Firewall configured to block IP address %s.\n", input);
    
    return 0;
}