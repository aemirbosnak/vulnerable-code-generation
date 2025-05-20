//FormAI DATASET v1.0 Category: Smart home light control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define LIGHTS 10 //max number of lights

int light_status[LIGHTS]; //0 for off, 1 for on

//function to turn on/off lights
void toggle_light(int light_num){
    if(light_status[light_num-1] == 1){
        printf("Light %d turned off\n", light_num);
        light_status[light_num-1] = 0;
    }
    else{
        printf("Light %d turned on\n", light_num);
        light_status[light_num-1] = 1;
    }
}

int main(){
    int choice, light_num;
    for(int i = 0; i < LIGHTS; i++){
        light_status[i] = 0; //set all lights to off initially
    }
    printf("Welcome to Smart Home Light Control System\n\n");
    do{
        printf("Enter your choice:\n1. Turn on light\n2. Turn off light\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter light number (1-%d): ", LIGHTS);
                scanf("%d", &light_num);
                if(light_num < 1 || light_num > LIGHTS){
                    printf("Invalid light number\n\n");
                }
                else{
                    toggle_light(light_num);
                }
                break;
            case 2:
                printf("Enter light number (1-%d): ", LIGHTS);
                scanf("%d", &light_num);
                if(light_num < 1 || light_num > LIGHTS){
                    printf("Invalid light number\n\n");
                }
                else{
                    toggle_light(light_num);
                }
                break;
            case 3:
                printf("\nThank you for using Smart Home Light Control System\n");
                exit(0);
            default:
                printf("Invalid choice\n\n");
        }
    }while(1);
    return 0;
}