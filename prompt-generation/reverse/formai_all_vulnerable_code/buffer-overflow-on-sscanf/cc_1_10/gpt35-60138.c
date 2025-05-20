//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define NUM_CHANNELS 14      // Total number of Wi-Fi channels
#define BUFFER_SIZE 1024     // Size of buffer for reading input files

void print_channel(int channel, double power, float min, float max) {
    char indicator;
    if (power >= max) {
        indicator = '+';
    } else if (power <= min) {
        indicator = '-';
    } else {
        indicator = ' ';
    }
    printf("Channel %2d [%c] Signal Strength: %5.2f dBm\n", channel, indicator, power);
}

void analyze_file(char *filename, float *min, float *max) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    int channel;
    double power;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        if (sscanf(buffer, "Channel %d : %lf dBm", &channel, &power) == 2) {
            if (channel >= 1 && channel <= NUM_CHANNELS) {
                if (power < *min) {
                    *min = power;
                }
                if (power > *max) {
                    *max = power;
                }
                print_channel(channel, power, *min, *max);
            }
        }
    }

    fclose(fp);
}

void print_intro() {
    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("==============================\n");
    printf("This program will analyze a set of Wi-Fi signal strength measurements.\n");
    printf("You can provide the measurements in a file or enter them manually.\n");
}

int is_valid_channel(char *input) {
    if (strlen(input) != 2) {
        return 0;
    }
    if (!isdigit(input[0]) || !isdigit(input[1])) {
        return 0;
    }
    int channel = (input[0] - '0') * 10 + (input[1] - '0');
    if (channel < 1 || channel > NUM_CHANNELS) {
        return 0;
    }
    return 1;
}

void manual_input(float *min, float *max) {
    char input[5];
    int channel;
    double power;
    while (1) {
        printf("Enter Wi-Fi channel and signal strength measurement (e.g. '01 -75.00' for channel 1 and -75.00 dBm): ");
        fgets(input, 5, stdin);
        if (strcasecmp(input, "quit") == 0) {
            break;
        }
        if (is_valid_channel(input)) {
            printf("Enter signal strength measurement for channel %d: ", channel);
            fgets(input, 5, stdin);
            power = atof(input);
            if (power < *min) {
                *min = power;
            }
            if (power > *max) {
                *max = power;
            }
            print_channel(channel, power, *min, *max);
        } else {
            printf("Invalid channel number. Please enter a number between 01 and %02d.\n", NUM_CHANNELS);
        }
    }
}

void input_mode(float *min, float *max) {
    char input[10];
    while (1) {
        printf("Enter 'file' to read measurements from a file or 'manual' to enter them manually: ");
        fgets(input, 10, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character
        if (strcasecmp(input, "file") == 0) {
            printf("Enter file name: ");
            fgets(input, 1024, stdin);
            input[strcspn(input, "\n")] = 0; // Remove newline character
            analyze_file(input, min, max);
            break;
        } else if (strcasecmp(input, "manual") == 0) {
            printf("Enter measurements manually (type 'quit' to exit).\n");
            manual_input(min, max);
            break;
        } else {
            printf("Invalid input. Please enter either 'file' or 'manual'.\n");
        }
    }
}

int main() {
    float min = INFINITY;
    float max = -INFINITY;
    print_intro();
    input_mode(&min, &max);
    printf("Minimum signal strength: %5.2f dBm\n", min);
    printf("Maximum signal strength: %5.2f dBm\n", max);
    return 0;
}