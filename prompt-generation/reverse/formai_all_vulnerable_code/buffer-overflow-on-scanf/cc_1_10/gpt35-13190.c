//FormAI DATASET v1.0 Category: Smart home automation ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void turnOnLight(char* room){
    printf("My love, I have turned on the light in %s\n", room);
}

void turnOffLight(char* room){
    printf("Darling, I have turned off the light in %s\n", room);
}

void activateMovieMode(){
    printf("Honey, I have activated movie mode. Enjoy the show!\n");
}

void setTemperature(int temp){
    printf("My sweetie, I have set the thermostat to %d degrees Celsius.\n", temp);
}

int main(){

    char response[50];
    int temp;

    printf("Welcome home, my love. How was your day?\n");
    scanf("%s", response);

    if(strcmp(response, "good") == 0){
        printf("I'm delighted to hear that, darling!\n");
    }else{
        printf("Oh no, what happened? I'm here for you.\n");
    }

    printf("Before we go any further, let me take care of the essentials first.\n");
    turnOnLight("Living Room");

    printf("There, now that we have some light, would you like to watch a movie?\n");
    scanf("%s", response);

    if(strcmp(response, "yes") == 0){
        activateMovieMode();
    }else{
        printf("That's okay, my love. Let me set the temperature for you.\n");
        printf("What temperature would you prefer, darling?\n");
        scanf("%d", &temp);
        setTemperature(temp);
    }

    printf("Is there anything else you would like me to do, my love?\n");
    scanf("%s", response);

    if(strcmp(response, "no") == 0){
        printf("Alright, darling. Just let me know if you need me to do anything else.\n");
    }else{
        printf("Of course, my love. What would you like me to do?\n");
        scanf("%s", response);
        printf("I'm sorry, my love. I don't know how to do that yet. But I'm always learning, just for you.\n");
    }

    turnOffLight("Living Room");

    return 0;
}