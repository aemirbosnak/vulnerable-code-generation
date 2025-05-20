//FormAI DATASET v1.0 Category: Firewall ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    // Declare a string to store input IP address 
    char ip[30];
    int allowed = 1;
    
    // Prompt the user to input IP address
    printf("Enter IP address: ");
    scanf("%s", ip);

    // Split the IP address into four integers
    int ip1, ip2, ip3, ip4;
    sscanf(ip, "%d.%d.%d.%d", &ip1, &ip2, &ip3, &ip4);
    
    // Check the validity of each IP segment
    if(ip1 < 0 || ip1 > 255 || 
       ip2 < 0 || ip2 > 255 || 
       ip3 < 0 || ip3 > 255 || 
       ip4 < 0 || ip4 > 255) 
    {
        printf("Invalid IP address!");
        allowed = 0;
    }
    
    // Check if the IP address is in the banned list
    if(strcmp(ip, "192.168.1.1") == 0 || 
       strcmp(ip, "10.0.0.1") == 0 ||
       strcmp(ip, "172.16.0.1") == 0)
    {
        printf("This IP address is banned!");
        allowed = 0;
    }
    
    // Check if the IP address belongs to a certain range
    if(ip1 == 192 && ip2 == 168 && ip3 == 0 && ip4 <= 100) 
    {
        printf("This IP range is not allowed!");
        allowed = 0;
    }
    
    // Check if the IP address belongs to a certain subnet
    if(ip1 == 10 && ip2 == 0 && ip3 == 0 && ip4 >= 0 && ip4 <= 255) 
    {
        printf("This IP subnet is not allowed!");
        allowed = 0;
    }
    
    // Allow or deny access based on the above checks
    if(allowed == 1)
    {
        printf("Access granted!");
    }
    else
    {
        printf("Access denied!");
    }
    
    return 0;
}