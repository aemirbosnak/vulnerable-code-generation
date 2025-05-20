//FormAI DATASET v1.0 Category: Firewall ; Style: genious
#include<stdio.h>
#include<string.h>

// Function to check if the IP address is valid or not
int isValidIpAddress(char* ipAddress)
{
    int num, dots = 0;
    char* ptr;
    
    if(ipAddress == NULL)
        return 0;
    
    ptr = strtok(ipAddress, "."); // Tokenize the IP and break it into four components separated by dots
    
    if(ptr == NULL)
        return 0;
    
    while(ptr)
    {
        if(!isdigit(*ptr)) // Check if the component is a digit or not
            return 0;
        
        num = atoi(ptr);
        
        if(num < 0 || num > 255) // Check if the component is within the valid range of 0-255
            return 0;
        
        ptr = strtok(NULL, "."); // Move onto the next component
        
        if(ptr != NULL)
            dots++;
    }
    
    if(dots != 3) // Check if there are exactly three dots separating the four components
        return 0;
    
    return 1;
}

int main()
{
    char ipAddress[16];
    int port;
    printf("Enter the IP address to block: ");
    scanf("%s", ipAddress);
    
    if(!isValidIpAddress(ipAddress))
    {
        printf("Invalid IP address!\n");
        return 1;
    }
    
    printf("Enter the port number to block: ");
    scanf("%d", &port);
    
    if(port < 1 || port > 65535)
    {
        printf("Invalid port number!\n");
        return 1;
    }
    
    // Open the firewall configuration file for writing
    FILE* fp = fopen("firewall.cfg", "a");
    
    if(fp == NULL)
    {
        printf("Failed to open firewall configuration file for writing!\n");
        return 1;
    }
    
    // Write the IP address and port number to block to the configuration file
    fprintf(fp, "%s:%d\n", ipAddress, port);
    
    fclose(fp);
    
    printf("Firewall rule added successfully!\n");
    
    return 0;
}