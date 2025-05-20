//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char ssid[100], signal[10], choice;
    int strength, num_devices = 0;
    
    printf("\nWelcome to the Wi-Fi Signal Strength Analyzer!\n\n");
    
    printf("Enter the SSID of the Wi-Fi network: ");
    scanf("%s", ssid);
    
    printf("\nScanning for nearby Wi-Fi signals...\n\n");
    sleep(2);
    
    // Simulating the scanning process and finding signals
    printf("Found 5 Wi-Fi signals within range of %s:\n\n", ssid);
    printf("1. Signal: \"HomeWifi\" | Strength: -40 dBm\n");
    printf("2. Signal: \"StarbucksWifi\" | Strength: -56 dBm\n");
    printf("3. Signal: \"LibraryWifi\" | Strength: -67 dBm\n");
    printf("4. Signal: \"FreeWifi\" | Strength: -72 dBm\n");
    printf("5. Signal: \"McDonaldsWifi\" | Strength: -84 dBm\n\n");
    
    // Prompt the user to choose which signal to analyze
    printf("Which signal would you like to analyze? (Enter 1-5): ");
    scanf(" %c", &choice);
    
    // Depending on the user's choice, display the signal strength and number of devices connected
    switch(choice) {
        case '1':
            strength = -40;
            num_devices = 12;
            strcpy(signal, "HomeWifi");
            break;
        case '2':
            strength = -56;
            num_devices = 6;
            strcpy(signal, "StarbucksWifi");
            break;
        case '3':
            strength = -67;
            num_devices = 4;
            strcpy(signal, "LibraryWifi");
            break;
        case '4':
            strength = -72;
            num_devices = 3;
            strcpy(signal, "FreeWifi");
            break;
        case '5':
            strength = -84;
            num_devices = 1;
            strcpy(signal, "McDonaldsWifi");
            break;
        default:
            printf("Invalid choice. Exiting program.\n");
            return 1;
    }
    
    printf("\nAnalyzing signal \"%s\"...\n\n", signal);
    sleep(2);
    
    printf("Signal strength: %d dBm\n", strength);
    printf("Number of devices connected: %d\n\n", num_devices);
    
    printf("Thank you for using the Wi-Fi Signal Strength Analyzer! Goodbye.\n");
    
    return 0;
}