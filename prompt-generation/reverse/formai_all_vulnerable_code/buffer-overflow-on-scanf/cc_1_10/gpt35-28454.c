//FormAI DATASET v1.0 Category: Smart home light control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void romanticMood();
void celebrationMood();

int main(){
    int lightState = 0;
    int timeOfDay = 0;
    bool isCelebration = false;
    srand(time(NULL));

    printf("Welcome to your smart home light control system!\n");
    printf("It's a beautiful day outside, what mood are you in?\n");

    while(true){
        printf("1. Romantic Mood \n2. Celebration Mood\n");
        int choice;
        scanf("%d", &choice);

        if(choice == 1){
            romanticMood();
            printf("Your room is now set for a romantic night in.\n");
            lightState = 1;
            break;
        }
        else if(choice == 2){
            celebrationMood();
            printf("Congratulations on finding a reason to celebrate!\n");
            isCelebration = true;
            break;
        }
        else{
            printf("Invalid choice! Please try again.\n");
        }
    }

    while(true){
        printf("What time of the day is it? (24 hour format)\n");
        scanf("%d", &timeOfDay);

        if(timeOfDay >= 0 && timeOfDay <= 23){
            if(timeOfDay >= 19 || timeOfDay <= 5){
                if(lightState == 0){
                    printf("It's getting dark outside, turning on the lights..\n");
                    lightState = 1;
                }
                else{
                    printf("The lights are already on.\n");
                }
            }
            else{
                if(lightState == 1){
                    printf("It's daytime outside, turning off the lights..\n");
                    lightState = 0;
                }
                else{
                    printf("The lights are already off.\n");
                }
            }
            break;
        }
        else{
            printf("Invalid time! Please enter a valid time.\n");
        }
    }

    if(isCelebration){
        printf("The lights are now flashing in different colors to celebrate your happy occasion!\n");
    }

    return 0;
}

void romanticMood(){
    printf("Creating a romantic atmosphere...\n");

    for(int i=0; i<10; i++){
        printf("*flicker*\n");
    }

    printf("A warm orange glow fills your room.\n");
}

void celebrationMood(){
    printf("Let's celebrate with some colorful lights!\n");

    for(int i=0; i<10; i++){
        int color = rand() % 5;

        switch(color){
            case 0:
                printf("*flash* Red light\n");
                break;
            case 1:
                printf("*flash* Green light\n");
                break;
            case 2:
                printf("*flash* Blue light\n");
                break;
            case 3:
                printf("*flash* Yellow light\n");
                break;
            case 4:
                printf("*flash* Purple light\n");
                break;
        }
    }
}