//FormAI DATASET v1.0 Category: Smart home automation ; Style: Cryptic
#include <stdio.h>
#include <stdbool.h>

#define ON 1
#define OFF 0

int main(){
    printf("Welcome to Smart Home!");
    int fridge = OFF, oven = OFF, ac = OFF, lights = OFF;
    bool isNight = false, isPartyMode = false;
    char userInput;
    while(1){
        printf("Enter your command (f: fridge, o: oven, a: AC, l: lights, n: night mode, p: party mode, q: quit): ");
        scanf("%c", &userInput);
        if(userInput == 'f'){
            if(fridge == OFF){
                fridge = ON;
                printf("Fridge is on.\n");
            } else{
                fridge = OFF;
                printf("Fridge is off.\n");
            }
        } else if(userInput == 'o'){
            if(oven == OFF){
                oven = ON;
                printf("Oven is on.\n");
            } else{
                oven = OFF;
                printf("Oven is off.\n");
            }
        } else if(userInput == 'a'){
            if(ac == OFF){
                ac = ON;
                printf("AC is on.\n");
            } else{
                ac = OFF;
                printf("AC is off.\n");
            }
        } else if(userInput == 'l'){
            if(lights == OFF){
                lights = ON;
                printf("Lights are on.\n");
            } else{
                lights = OFF;
                printf("Lights are off.\n");
            }
        } else if(userInput == 'n'){
            isNight = !isNight;
            printf("Night mode is %s.\n", isNight ? "on" : "off");
            if(isNight){
                lights = OFF;
                printf("Lights are off.\n");
                ac = ON;
                printf("AC is on.\n");
            }
        } else if(userInput == 'p'){
            isPartyMode = !isPartyMode;
            printf("Party mode is %s.\n", isPartyMode ? "on" : "off");
            if(isPartyMode){
                lights = ON;
                printf("Lights are on.\n");
                ac = OFF;
                printf("AC is off.\n");
            }
        } else if(userInput == 'q'){
            printf("Quitting Smart Home. Thank you!\n");
            break;
        } else{
            printf("Invalid command.\n");
        }
    }
    return 0;
}