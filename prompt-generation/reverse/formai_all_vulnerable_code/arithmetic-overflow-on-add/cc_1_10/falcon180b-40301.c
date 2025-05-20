//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

// Function to calculate the signal strength in percentage
double calculate_signal_strength(int rssi) {
    double strength = 100.0 * (rssi + 100);
    return strength;
}

// Function to print the signal strength in percentage
void print_signal_strength(double strength) {
    printf("Signal strength: %.2f%%\n", strength);
}

// Function to get the Wi-Fi signal strength from the user
int get_signal_strength() {
    int rssi;
    printf("Enter the Wi-Fi signal strength (in dBm): ");
    scanf("%d", &rssi);
    return rssi;
}

// Function to get the signal strength in percentage from the user
double get_signal_strength_percentage() {
    int rssi;
    double strength;
    printf("Enter the Wi-Fi signal strength (in percentage): ");
    scanf("%d", &rssi);
    strength = calculate_signal_strength(rssi);
    return strength;
}

// Main function to analyze the Wi-Fi signal strength
int main() {
    int rssi;
    double strength;
    printf("Donald Knuth Wi-Fi Signal Strength Analyzer\n");
    printf("----------------------------------------\n");
    printf("Enter 1 to get the signal strength in dBm\n");
    printf("Enter 2 to get the signal strength in percentage\n");
    scanf("%d", &rssi);
    if (rssi == 1) {
        rssi = get_signal_strength();
        strength = calculate_signal_strength(rssi);
        print_signal_strength(strength);
    } else if (rssi == 2) {
        strength = get_signal_strength_percentage();
        print_signal_strength(strength);
    } else {
        printf("Invalid choice\n");
    }
    return 0;
}