//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "temperature_log.txt"
#define MAX_READINGS 100
#define MAX_LINE_LENGTH 256

// Function declarations
void log_temperature(float temperature);
float generate_temperature();
void display_readings();
void simulate_temperature_monitoring(float lower_limit, float upper_limit);

int main() {
    float lower_limit, upper_limit;

    // Get temperature monitoring limits from the user
    printf("Enter lower temperature limit: ");
    scanf("%f", &lower_limit);
    
    printf("Enter upper temperature limit: ");
    scanf("%f", &upper_limit);

    // Start the simulation
    simulate_temperature_monitoring(lower_limit, upper_limit);

    return 0;
}

// Function to log temperature readings to a file
void log_temperature(float temperature) {
    FILE *fp = fopen(FILENAME, "a");
    if (fp == NULL) {
        fprintf(stderr, "Error opening log file!\n");
        return;
    }
    // Get the current time
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline character
    
    // Log temperature with timestamp
    fprintf(fp, "[%s] Temperature: %.2f°C\n", timestamp, temperature);
    fclose(fp);
}

// Function to generate random temperature values
float generate_temperature() {
    return ((float)rand() / (float)(RAND_MAX)) * 100.0; // Random temperature between 0 to 100°C
}

// Function to display current readings
void display_readings() {
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening log file!\n");
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    printf("\n--- Temperature Readings ---\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);
}

// Function to simulate temperature monitoring
void simulate_temperature_monitoring(float lower_limit, float upper_limit) {
    srand(time(NULL)); // Seed random number generator
    for (int i = 0; i < MAX_READINGS; i++) {
        float temperature = generate_temperature();
        
        // Log the temperature
        log_temperature(temperature);
        
        // Display the readings
        printf("Current Temperature: %.2f°C\n", temperature);
        
        // Check thresholds
        if (temperature < lower_limit) {
            printf("Warning: Temperature below lower limit!\n");
        } else if (temperature > upper_limit) {
            printf("Warning: Temperature above upper limit!\n");
        }

        // Sleep for 1 second before the next reading
        sleep(1);
        
        // Display previous readings every 5 cycles
        if (i % 5 == 4) {
            display_readings();
        }
    }
    
    printf("\nMonitoring completed. Check %s for logs.\n", FILENAME);
}