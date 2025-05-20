//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: paranoid
// **Paranoid GPS Navigation Simulator**

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Obfuscated encryption key
#define KEY 0x55aa55aa

// Encrypts the GPS data.
void encrypt(char *data, size_t len)
{
    for (int i = 0; i < len; i++)
        data[i] ^= KEY;
}

// Decrypts the GPS data.
void decrypt(char *data, size_t len)
{
    encrypt(data, len);
}

// Simulates GPS data.
void simulate_gps_data(char *data, size_t len)
{
    // Generate random data.
    srand(time(NULL));
    for (int i = 0; i < len; i++)
        data[i] = rand() % 256;

    // Encrypt the data.
    encrypt(data, len);
}

// Parses the encrypted GPS data.
void parse_gps_data(char *data, size_t len)
{
    // Decrypt the data.
    decrypt(data, len);

    // Parse the data into individual fields.
    char latitude[20], longitude[20], altitude[20], speed[20], heading[20];
    sscanf(data, "%s %s %s %s %s", latitude, longitude, altitude, speed, heading);

    // Print the parsed data.
    printf("Latitude: %s\n", latitude);
    printf("Longitude: %s\n", longitude);
    printf("Altitude: %s\n", altitude);
    printf("Speed: %s\n", speed);
    printf("Heading: %s\n", heading);
}

// Main function.
int main()
{
    // Create a buffer for the GPS data.
    char data[256];

    // Simulate GPS data.
    simulate_gps_data(data, sizeof(data));

    // Parse the GPS data.
    parse_gps_data(data, sizeof(data));

    return 0;
}