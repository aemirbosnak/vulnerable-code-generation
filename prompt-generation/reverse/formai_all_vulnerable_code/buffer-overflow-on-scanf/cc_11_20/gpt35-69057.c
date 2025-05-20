//FormAI DATASET v1.0 Category: Smart home automation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    //Initialize variables
    int light = 0;
    int temperature = 25;
    int humidity = 60;
    int security = 0;
    
    //Welcome message
    printf("Welcome to Smart Home Automation System\n");
    printf("--------------------------------------\n");
    
    //Main menu
    printf("\nMain Menu\n");
    printf("1. Control Lights\n");
    printf("2. Control Temperature\n");
    printf("3. Control Humidity\n");
    printf("4. Control Security\n");
    printf("5. Exit\n");
    
    //User input
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    //Main program switch statement
    switch(choice) {
        
        //Control Lights
        case 1: {
            printf("\nLight Control\n");
            printf("1. Turn on\n");
            printf("2. Turn off\n");
            printf("3. Exit\n");
            int lightChoice;
            printf("\nEnter your choice: ");
            scanf("%d", &lightChoice);
            switch(lightChoice) {
                case 1: {
                    //Turn on lights
                    light = 1;
                    printf("Lights turned on\n");
                    break;
                }
                case 2: {
                    //Turn off lights
                    light = 0;
                    printf("Lights turned off\n");
                    break;
                }
                case 3: {
                    //Exit light control
                    break;
                }
                default: {
                    printf("Invalid choice\n");
                    break;
                }
            }
            break;
        }
        
        //Control Temperature
        case 2: {
            printf("\nTemperature Control\n");
            printf("1. Increase temperature\n");
            printf("2. Decrease temperature\n");
            printf("3. Exit\n");
            int temperatureChoice;
            printf("\nEnter your choice: ");
            scanf("%d", &temperatureChoice);
            switch(temperatureChoice) {
                case 1: {
                    //Increase temperature
                    temperature++;
                    printf("Temperature increased to %d degrees Celsius\n", temperature);
                    break;
                }
                case 2: {
                    //Decrease temperature
                    temperature--;
                    printf("Temperature decreased to %d degrees Celsius\n", temperature);
                    break;
                }
                case 3: {
                    //Exit temperature control
                    break;
                }
                default: {
                    printf("Invalid choice\n");
                    break;
                }
            }
            break;
        }
        
        //Control Humidity
        case 3: {
            printf("\nHumidity Control\n");
            printf("1. Increase humidity\n");
            printf("2. Decrease humidity\n");
            printf("3. Exit\n");
            int humidityChoice;
            printf("\nEnter your choice: ");
            scanf("%d", &humidityChoice);
            switch(humidityChoice) {
                case 1: {
                    //Increase humidity
                    humidity++;
                    printf("Humidity increased to %d percent\n", humidity);
                    break;
                }
                case 2: {
                    //Decrease humidity
                    humidity--;
                    printf("Humidity decreased to %d percent\n", humidity);
                    break;
                }
                case 3: {
                    //Exit humidity control
                    break;
                }
                default: {
                    printf("Invalid choice\n");
                    break;
                }
            }
            break;
        }
        
        //Control Security
        case 4: {
            printf("\nSecurity Control\n");
            printf("1. Arm security system\n");
            printf("2. Disarm security system\n");
            printf("3. Exit\n");
            int securityChoice;
            printf("\nEnter your choice: ");
            scanf("%d", &securityChoice);
            switch(securityChoice) {
                case 1: {
                    //Arm security system
                    security = 1;
                    printf("Security system armed\n");
                    break;
                }
                case 2: {
                    //Disarm security system
                    security = 0;
                    printf("Security system disarmed\n");
                    break;
                }
                case 3: {
                    //Exit security control
                    break;
                }
                default: {
                    printf("Invalid choice\n");
                    break;
                }
            }
            break;
        }
        
        //Exit program
        case 5: {
            printf("\nExiting program...\n");
            exit(0);
        }
        
        //Invalid choice
        default: {
            printf("\nInvalid choice\n");
            break;
        }
    }
    
    //Program end message
    printf("\nProgram end\n");
    
    return 0;
}