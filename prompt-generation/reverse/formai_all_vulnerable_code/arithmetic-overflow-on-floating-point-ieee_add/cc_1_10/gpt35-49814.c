//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of Wi-Fi Access Points to scan
#define MAX_AP 10

// Define the maximum distance in meters to scan for Wi-Fi signal strength
#define MAX_DISTANCE 100

// Define the maximum signal strength in dBm
#define MAX_SIGNAL_STRENGTH -30

// Define the minimum signal strength in dBm
#define MIN_SIGNAL_STRENGTH -90

// Define the Wi-Fi Access Point structure
struct WifiAccessPoint {
    char* ssid;
    double x;
    double y;
    double z;
    double signal_strength;
};

// Define the function to calculate the distance between two points
double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Define the main function
int main() {

    // Define the Wi-Fi Access Points
    struct WifiAccessPoint wifi_access_points[MAX_AP] = {
        {"MyNetwork", 10.0, 10.0, 2.0, -50.0},
        {"NeighborhoodNetwork", 20.0, 20.0, 2.0, -65.0},
        {"GuestNetwork", 30.0, 30.0, 2.0, -70.0}
    };
    
    // Define the current position of the Wi-Fi analyzer
    double x0 = 5.0;
    double y0 = 5.0;
    double z0 = 2.0;

    // Print the header
    printf("SSID\tSignal Strength\tDistance\n");
    
    // Loop over the Wi-Fi Access Points and calculate the distance and signal strength
    int i;
    for(i=0; i<MAX_AP; i++) {
        double d = distance(x0, y0, z0, wifi_access_points[i].x, wifi_access_points[i].y, wifi_access_points[i].z);
        double signal_strength = wifi_access_points[i].signal_strength - (20*log10(d) + 20*log10(2.4e9) - 28.0);
        if(signal_strength > MAX_SIGNAL_STRENGTH) {
            signal_strength = MAX_SIGNAL_STRENGTH;
        }
        if(signal_strength < MIN_SIGNAL_STRENGTH) {
            signal_strength = MIN_SIGNAL_STRENGTH;
        }
        printf("%s\t%.0lf dBm\t%.2lf m\n", wifi_access_points[i].ssid, signal_strength, d);
    }

    // Print the conclusion
    printf("Wi-Fi signal analysis completed successfully!\n");

    // Return success
    return 0;
}