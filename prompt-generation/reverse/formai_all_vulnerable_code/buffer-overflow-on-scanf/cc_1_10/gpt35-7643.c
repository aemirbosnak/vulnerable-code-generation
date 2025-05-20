//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void display_menu();
void get_user_location(float *latitude, float *longitude);
void generate_random_location(float *latitude, float *longitude);
void calculate_distance(float lat1, float long1, float lat2, float long2, float *distance);
void display_map(float latitude, float longitude, float d_latitude, float d_longitude);

int main()
{
    float user_latitude, user_longitude, destination_latitude, destination_longitude;
    float distance_to_destination;
    char choice;
    bool is_random_destination = false;

    // Seed the random number generator
    srand(time(NULL));

    // Get the user's location
    get_user_location(&user_latitude, &user_longitude);

    do {
        // Display the menu
        display_menu();

        // Get the user's choice
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                // Get a random destination
                generate_random_location(&destination_latitude, &destination_longitude);
                is_random_destination = true;
                printf("Random destination set.\n");
                break;
            case '2':
                // Set a custom destination
                printf("Enter the destination's latitude and longitude:\n");
                scanf("%f %f", &destination_latitude, &destination_longitude);
                is_random_destination = false;
                break;
            case '3':
                // Calculate and display the distance to the destination
                calculate_distance(user_latitude, user_longitude, destination_latitude, destination_longitude, &distance_to_destination);
                printf("The distance to the destination is %f km.\n", distance_to_destination);
                break;
            case '4':
                // Display a map with the user's location and the destination
                if (is_random_destination) {
                    display_map(user_latitude, user_longitude, destination_latitude, destination_longitude);
                } else {
                    printf("Please set a destination first.\n");
                }
                break;
            case '5':
                // Quit the program
                printf("Goodbye!\n");
                break;
            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != '5');

    return 0;
}

/**
 * Displays the program menu.
 */
void display_menu() {
    printf("\nGPS Navigation Simulation\n");
    printf("------------------------\n");
    printf("1. Set a random destination\n");
    printf("2. Set a custom destination\n");
    printf("3. Calculate distance to destination\n");
    printf("4. View map\n");
    printf("5. Quit\n");
}

/**
 * Gets the user's current location.
 */
void get_user_location(float *latitude, float *longitude) {
    printf("Enter your current latitude and longitude:\n");
    scanf("%f %f", latitude, longitude);
}

/**
 * Generates a random destination.
 */
void generate_random_location(float *latitude, float *longitude) {
    *latitude = (float)((rand() % 180) - 90);
    *longitude = (float)((rand() % 360) - 180);
}

/**
 * Calculates the distance between two latitude/longitude points using the Haversine formula.
 */
void calculate_distance(float lat1, float long1, float lat2, float long2, float *distance) {
    const float R = 6371.0; // mean radius of Earth in km
    const float d_lat = (lat2 - lat1) * (3.14159265359 / 180.0);
    const float d_long = (long2 - long1) * (3.14159265359 / 180.0);
    const float a = sin(d_lat/2) * sin(d_lat/2) + cos(lat1 * (3.14159265359 / 180.0)) * cos(lat2 * (3.14159265359 / 180.0)) * sin(d_long/2) * sin(d_long/2);
    const float c = 2 * atan2(sqrt(a), sqrt(1-a));
    *distance = R * c;
}

/**
 * Displays a map showing the user's location and the destination.
 */
void display_map(float latitude, float longitude, float d_latitude, float d_longitude) {
    printf("Displaying map...\n");
    printf("User location: %.6f, %.6f\n", latitude, longitude);
    printf("Destination: %.6f, %.6f\n", d_latitude, d_longitude);
}