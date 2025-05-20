//FormAI DATASET v1.0 Category: Smart home light control ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    // Initialize variables
    int room_id, num_lights, i, choice;
    float max_brightness;
    time_t current_time;
    char* c_time_string;
    
    // Getting user inputs
    printf("Enter room id: ");
    scanf("%d", &room_id);
    printf("Enter number of lights: ");
    scanf("%d", &num_lights);
    printf("Enter maximum brightness (0-1): ");
    scanf("%f", &max_brightness);
    
    // Generating random seed
    srand(time(0));
    
    // Controlling lights
    while(1) {
        printf("Choose an option:\n");
        printf("1. Turn on lights\n");
        printf("2. Turn off lights\n");
        printf("3. Adjust brightness\n");
        printf("4. Quit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Turning on all lights in room %d\n", room_id);
                for(i=0; i<num_lights; i++) {
                    printf("Light %d turned on\n", i+1);
                }
                break;
            
            case 2:
                printf("Turning off all lights in room %d\n", room_id);
                for(i=0; i<num_lights; i++) {
                    printf("Light %d turned off\n", i+1);
                }
                break;
                
            case 3:
                printf("Enter new brightness: ");
                float brightness;
                scanf("%f", &brightness);
                if(brightness > max_brightness) {
                    printf("Brightness exceeds maximum brightness of %.2f\n", max_brightness);
                    brightness = max_brightness;
                }
                printf("Setting all lights in room %d to %.2f brightness\n", room_id, brightness);
                for(i=0; i<num_lights; i++) {
                    float random_brightness = brightness * (rand() % 100) / 100.0;
                    printf("Light %d brightness set to %.2f\n", i+1, random_brightness);
                }
                break;
                
            case 4:
                time(&current_time);
                c_time_string = ctime(&current_time);
                printf("Program terminated at %s\n", c_time_string);
                exit(0);
                break;
            
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }

    return 0;
}