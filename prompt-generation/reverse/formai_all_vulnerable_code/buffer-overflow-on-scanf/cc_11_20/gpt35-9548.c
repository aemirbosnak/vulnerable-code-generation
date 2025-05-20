//FormAI DATASET v1.0 Category: Smart home light control ; Style: active
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool isLightOn = false; // variable to track the state of the light
    int time = 0; // variable to track the time of day
    int brightness = 100; // variable to track the brightness of the light
    char input; // variable to hold user input
    
    printf("Welcome to Smart Home Light Control!\n");
    
    while(true) {
        printf("Time of day (in hours, from 0 to 23): ");
        scanf("%d", &time); // get input from user
        
        if(time < 0 || time > 23) { // input validation
            printf("Invalid time! Please enter a value from 0 to 23.\n");
            continue; // restart loop
        }
        
        if(time >= 7 && time < 21) { // day time
            if(isLightOn) { // if light is already on
                printf("The light is already on.\n");
            } else { // turn on light
                isLightOn = true;
                printf("The light is now on.\n");
            }
            printf("Would you like to adjust the brightness? (Y/N) ");
            scanf(" %c", &input); // get input from user
            
            if(input == 'Y' || input == 'y') {
                printf("Brightness (0-100): ");
                scanf("%d", &brightness); // get input from user
                
                if(brightness < 0 || brightness > 100) { // input validation
                    printf("Invalid brightness! Please enter a value from 0 to 100.\n");
                    continue; // restart loop
                }
                
                printf("The brightness is now set to %d.\n", brightness);
            } else {
                printf("Okay, the brightness will remain at 100.\n");
            }
        } else { // night time
            if(isLightOn) { // turn off light
                isLightOn = false;
                printf("The light is now off.\n");
            } else { // if light is already off
                printf("The light is already off.\n");
            }
        }
        
        printf("Would you like to exit? (Y/N) ");
        scanf(" %c", &input); // get input from user
        
        if(input == 'Y' || input == 'y') {
            break; // exit loop
        }
    }
    
    printf("Goodbye! Thanks for using Smart Home Light Control.\n");
    
    return 0;
}