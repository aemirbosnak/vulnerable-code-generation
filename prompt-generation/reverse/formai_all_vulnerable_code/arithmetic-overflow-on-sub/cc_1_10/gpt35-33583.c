//FormAI DATASET v1.0 Category: System administration ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int seconds){
    time_t start = time(NULL);
    while (time(NULL) - start < seconds){}
}

int main(){
    time_t t;
    srand((unsigned) time(&t));

    int power = 0;
    int battery_level = 100;
    int system_status = 1; //0 for off, 1 for on
    char response;

    while(system_status){

        printf("Power status: %d\n", power);
        printf("Battery level: %d\n\n", battery_level);

        if(power < 10){
            printf("ALERT: Power critically low! \n");
            delay(3);
            printf("Systems shutting down to conserve power...\n");
            system_status = 0;
        }

        printf("Enter command ('s' to scan for resources, 'c' to charge battery, 'q' to quit): ");
        scanf("%c", &response);

        switch(response){
            case 's': {
                int resource = rand() % 3 + 1;
                printf("\nScanning...\n");

                switch(resource){
                    case 1:
                        printf("Found food supplies.\n\n");
                        delay(2);
                        printf("Adding to inventory...\n\n");
                        break;
                    case 2:
                        printf("Found weapons cache.\n\n");
                        delay(2);
                        printf("Adding to inventory...\n\n");
                        break;
                    case 3:
                        printf("Found medical supplies.\n\n");
                        delay(2);
                        printf("Adding to inventory...\n\n");
                        break;

                }

                power += 5;
                printf("Power level increased by 5.\n\n");
                break;
            }

            case 'c':{
                if(power >= 90){
                    printf("Cannot charge battery. Power level too high.\n\n");
                }
                else{
                    printf("\nCharging battery...");
                    delay(3);

                    int charge = (100 - battery_level) / 2;
                    if(charge < 5){
                        charge = 5;
                    }

                    printf("\nBattery level increased by %d.\n\n", charge);
                    battery_level += charge;
                    power -= 10;
                }
                break;
            }

            case 'q':{
                printf("\nShutting down...\n");
                system_status = 0;
                break;
            }

            default:{
                printf("\nInvalid command.\n\n");
                break;
            }
        }

        while(getchar() != '\n'); // Clear input buffer

    }

    return 0;
}