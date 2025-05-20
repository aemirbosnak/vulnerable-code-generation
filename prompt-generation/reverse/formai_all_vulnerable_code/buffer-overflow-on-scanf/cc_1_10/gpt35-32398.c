//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants definitions
#define MAX_SSID_LENGTH 32
#define MAX_SIGNAL_STRENGTH 100
#define NUM_CHANNELS 11

// Function prototypes
void printHeader();
int calcWifiScore(int signalStrength, int channel);
void printWifiScoreTable();
int promptForSignalStrength();
int promptForChannel();

int main() {
    // Declare variables
    char ssid[MAX_SSID_LENGTH];
    int signalStrength, channel, wifiScore;

    // Print program header
    printHeader();

    // Prompt user for SSID
    printf("Enter SSID: ");
    scanf("%s", ssid);

    // Prompt user for signal strength
    signalStrength = promptForSignalStrength();

    // Prompt user for channel
    channel = promptForChannel();

    // Calculate Wi-Fi score based on signal strength and channel
    wifiScore = calcWifiScore(signalStrength, channel);

    // Print Wi-Fi score table
    printWifiScoreTable();

    // Output results
    printf("\nResults:\n");
    printf("SSID: %s\n", ssid);
    printf("Signal strength: %d dBm\n", signalStrength);
    printf("Channel: %d\n", channel);
    printf("Wi-Fi score: %d\n", wifiScore);

    // Exit program
    return 0;
}

/*
 * Print program header
 */
void printHeader() {
    printf("=============================\n");
    printf("= Wi-Fi Signal Strength Analyzer =\n");
    printf("=============================\n");
}

/*
 * Calculate Wi-Fi score based on signal strength and channel
 */
int calcWifiScore(int signalStrength, int channel) {
    // Score decreases with decreasing signal strength
    int score = MAX_SIGNAL_STRENGTH - signalStrength;

    // Score decreases significantly for channels 1, 6, and 11, which are overlapping channels
    if (channel == 1 || channel == 6 || channel == 11) {
        score -= (MAX_SIGNAL_STRENGTH / 2);
    }

    // Score decreases for channels that are not in the 2.4 GHz range
    if (channel < 1 || channel > 11) {
        score -= (MAX_SIGNAL_STRENGTH / 4);
    }

    return score;
}

/*
 * Print Wi-Fi score table
 */
void printWifiScoreTable() {
    printf("\nWi-Fi Score Table:\n");
    printf("|----------|------------|\n");
    printf("| Wi-Fi Score | Performance |\n");
    printf("|----------|------------|\n");
    printf("| 100 | Excellent |\n");
    printf("| 75-99 | Good |\n");
    printf("| 50-74 | Fair |\n");
    printf("| 0-49 | Poor |\n");
    printf("|----------|------------|\n");
}

/*
 * Prompt user for signal strength
 */
int promptForSignalStrength() {
    int signalStrength;

    // Loop until user enters valid signal strength
    do {
        printf("Enter signal strength (in dBm, between -100 and 0): ");
        scanf("%d", &signalStrength);
    } while (signalStrength < -100 || signalStrength > 0);

    return signalStrength;
}

/*
 * Prompt user for channel
 */
int promptForChannel() {
    int channel;

    // Loop until user enters valid channel
    do {
        printf("Enter channel (between 1 and 11): ");
        scanf("%d", &channel);
    } while (channel < 1 || channel > 11);

    return channel;
}