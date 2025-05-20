//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: active
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 

// Returns true if input is a valid integer 
bool is_integer(const char *input) 
{ 
    for(int i=0; i<strlen(input); i++) 
    { 
        if(input[i] < '0' || input[i] > '9') 
            return false; 
    } 
    return true; 
} 

int main() 
{ 
    char command[20], interface[10], buffer[256], *value; 
    FILE *fp; 
    int signal_strength; 

    printf("Wi-Fi Signal Strength Analyzer\n\n"); 

    while(true) 
    { 
        printf("Enter the network interface to analyze (e.g. wlan0): "); 
        scanf("%s", interface); 

        // Check if interface name is valid 
        sprintf(buffer, "ifconfig %s > /dev/null", interface); 
        if(system(buffer) != 0) 
        { 
            printf("Invalid network interface.\n"); 
            continue; 
        } 

        // Get current signal strength 
        sprintf(buffer, "iwconfig %s | grep Signal | awk '{print $4}'", interface); 
        fp = popen(buffer, "r"); 
        fgets(buffer, 256, fp); 
        signal_strength = atoi(buffer); 
        pclose(fp); 

        printf("Current signal strength: %d dBm\n", signal_strength); 

        while(true) 
        { 
            printf("Enter a threshold value or Q to quit: "); 
            scanf("%s", command); 

            if(strcasecmp(command, "Q") == 0) 
            { 
                printf("Goodbye!\n"); 
                return 0; 
            } 

            if(!is_integer(command) || atoi(command) < 0) 
            { 
                printf("Invalid input.\n"); 
                continue; 
            } 

            // Compare signal strength to threshold value 
            if(signal_strength < atoi(command)) 
            { 
                printf("Signal strength is below threshold.\n"); 
            } 
            else 
            { 
                printf("Signal strength is above or equal to threshold.\n"); 
            } 
        } 
    } 

    return 0; 
}