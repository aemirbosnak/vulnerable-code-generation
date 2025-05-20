//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOCATIONS 10
#define MAX_NAME_LENGTH 20
#define MAX_INSTRUCTIONS 100
#define PI 3.14159265

typedef struct {
    char name[MAX_NAME_LENGTH];
    float latitude;
    float longitude;
} Location;

typedef struct {
    char instructions[MAX_INSTRUCTIONS][MAX_NAME_LENGTH];
    int count;
} InstructionSet;

Location locations[MAX_LOCATIONS];
InstructionSet instructionSet;

void initializeLocations() {
    strcpy(locations[0].name, "The Dancing Trees");
    locations[0].latitude = 12.34 + (rand() % 100) / 1000.0;
    locations[0].longitude = 45.67 + (rand() % 100) / 1000.0;

    strcpy(locations[1].name, "Whispers of Time");
    locations[1].latitude = 23.45 + (rand() % 100) / 1000.0;
    locations[1].longitude = 56.78 + (rand() % 100) / 1000.0;

    strcpy(locations[2].name, "The Floating Island");
    locations[2].latitude = 34.56 + (rand() % 100) / 1000.0;
    locations[2].longitude = 67.89 + (rand() % 100) / 1000.0;
}

void generateInstructions() {
    instructionSet.count = 0;

    snprintf(instructionSet.instructions[instructionSet.count++], MAX_NAME_LENGTH, "Navigate through the cacophony of colors.");
    snprintf(instructionSet.instructions[instructionSet.count++], MAX_NAME_LENGTH, "Turn left at the ghostly whisper of the moon.");
    snprintf(instructionSet.instructions[instructionSet.count++], MAX_NAME_LENGTH, "Continue until you smell the nostalgia in the air.");
    snprintf(instructionSet.instructions[instructionSet.count++], MAX_NAME_LENGTH, "Twirl thrice to summon the light of forgotten dreams.");
    snprintf(instructionSet.instructions[instructionSet.count++], MAX_NAME_LENGTH, "Arrive at your destination, where history and myopia meet.");
}

void displayInstructions() {
    for (int i = 0; i < instructionSet.count; i++) {
        printf("%s\n", instructionSet.instructions[i]);
    }
}

float calculateDistance(float lat1, float lon1, float lat2, float lon2) {
    // Using a simple approximation over a flat surface for this surreal world 
    float dlat = lat2 - lat1;
    float dlon = lon2 - lon1;
    return sqrt(dlat * dlat + dlon * dlon) * 100; // Scale to surreal distance units
}

void findNearestLocation(float currentLat, float currentLon) {
    float minDistance = 99999;
    Location nearestLocation;

    for (int i = 0; i < MAX_LOCATIONS; i++) {
        float distance = calculateDistance(currentLat, currentLon, locations[i].latitude, locations[i].longitude);
        if (distance < minDistance) {
            minDistance = distance;
            nearestLocation = locations[i];
        }
    }

    printf("You are closest to: %s\n", nearestLocation.name);
    printf("Coordinates: %.6f, %.6f\n", nearestLocation.latitude, nearestLocation.longitude);
}

int main() {
    srand(time(NULL));
    initializeLocations();
    generateInstructions();

    printf("Welcome to the Surreal GPS Navigation!\n");
    printf("Your Journey Awaits...\n\n");

    float currentLat, currentLon;
    printf("Enter your current coordinates (latitude longitude): ");
    scanf("%f %f", &currentLat, &currentLon);

    findNearestLocation(currentLat, currentLon);
    printf("\nInstructions for your journey:\n");
    displayInstructions();

    printf("\nAs you embark on this surreal adventure, remember: Reality is merely a canvas for your imagination.\n");
    return 0;
}