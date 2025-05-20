//FormAI DATASET v1.0 Category: Smart home automation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // Initialize smart home devices
    bool smart_Lights = true;
    bool smart_AC = false;
    bool smart_TV = true;
    bool smart_Doorlock = true;
    
    // Welcome message
    printf("Welcome to your smart home!\n");
    printf("What would you like to do? Choose from the following options:\n");
    printf("1. Turn on/off Smart Lights\n");
    printf("2. Turn on/off Smart AC\n");
    printf("3. Turn on/off Smart TV\n");
    printf("4. Lock/Unlock Smart Doorlock\n");

    // Handle user input
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            if(smart_Lights) {
                printf("Turning off Smart Lights.\n");
                smart_Lights = false;
            }
            else {
                printf("Turning on Smart Lights.\n");                
                smart_Lights = true;
            }
            break;
            
        case 2:
            if(smart_AC) {
                printf("Turning off Smart AC.\n");
                smart_AC = false;
            }
            else {
                printf("Turning on Smart AC.\n");                
                smart_AC = true;
            }
            break;
            
        case 3:
            if(smart_TV) {
                printf("Turning off Smart TV.\n");
                smart_TV = false;
            }
            else {
                printf("Turning on Smart TV.\n");                
                smart_TV = true;
            }
            break;
            
        case 4:
            if(smart_Doorlock) {
                printf("Locking Smart Doorlock.\n");
                smart_Doorlock = false;
            }
            else {
                printf("Unlocking Smart Doorlock.\n");                
                smart_Doorlock = true;
            }
            break;
            
        default:
            printf("Oops, invalid choice. Try again!\n");
            break;
    }
    
    return 0;
}