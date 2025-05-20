//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read Wi-Fi signal strength from the user
int read_signal_strength() {
    int strength;
    printf("Enter the Wi-Fi signal strength (in dBm): ");
    scanf("%d", &strength);
    return strength;
}

// Function to determine Wi-Fi signal quality based on signal strength
char* determine_signal_quality(int strength) {
    if (strength >= -50) {
        return "Excellent";
    } else if (strength >= -60) {
        return "Good";
    } else if (strength >= -70) {
        return "Fair";
    } else if (strength >= -80) {
        return "Low";
    } else {
        return "Very Low";
    }
}

// Function to recursively print the Wi-Fi signal quality and strength
void print_signal_info(int iterations) {
    // Base case: stop after 10 iterations
    if (iterations == 10) {
        return;
    }
    
    // Read Wi-Fi signal strength from the user
    int strength = read_signal_strength();
    
    // Determine Wi-Fi signal quality based on signal strength
    char* quality = determine_signal_quality(strength);
    
    // Print Wi-Fi signal strength and quality
    printf("Wi-Fi signal strength: %d dBm\n", strength);
    printf("Wi-Fi signal quality: %s\n", quality);
    
    // Recursively call the function again
    print_signal_info(iterations + 1);
}

// Main function to start the program
int main() {
    // Welcome message
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
    
    // Print Wi-Fi signal strength and quality recursively
    print_signal_info(0);
    
    // Goodbye message
    printf("Thank you for using the Wi-Fi Signal Strength Analyzer!\n");
    
    return 0;
}