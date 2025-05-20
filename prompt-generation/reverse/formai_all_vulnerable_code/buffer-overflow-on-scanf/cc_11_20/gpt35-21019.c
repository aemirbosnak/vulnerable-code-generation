//FormAI DATASET v1.0 Category: Smart home automation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    int temperature = 25;
    int lightsOn = 1;
    int windowOpen = 0;
    int doorLocked = 1;
    int musicPlaying = 0;

    printf("Welcome to Smart Home Automation\n");

    // First puzzle
    printf("Temperature is set to %d degrees Celsius.\n", temperature);
    printf("Can you increase the temperature by 5 degrees? Enter 1 to increase or 0 to leave it as is.\n");
    int increaseTemperature;
    scanf("%d", &increaseTemperature);
    if(increaseTemperature) {
        temperature += 5;
        printf("Temperature is now set to %d degrees Celsius.\n", temperature);
    } else {
        printf("Temperature remains at %d degrees Celsius.\n", temperature);
    }

    // Second puzzle
    printf("Lights are currently %s.\n", lightsOn ? "on" : "off");
    printf("Can you turn them off? Enter 1 to turn them off or 0 to leave them on.\n");
    int turnOffLights;
    scanf("%d", &turnOffLights);
    if(turnOffLights) {
        lightsOn = 0;
        printf("Lights are now turned off.\n");
    } else {
        printf("Lights remain on.\n");
    }

    // Third puzzle
    printf("Window is currently %s.\n", windowOpen ? "open" : "closed");
    printf("Can you open it up? Enter 1 to open or 0 to leave it as is.\n");
    int openWindow;
    scanf("%d", &openWindow);
    if(openWindow) {
        windowOpen = 1;
        printf("Window is now open.\n");
    } else {
        printf("Window remains closed.\n");
    }

    // Fourth puzzle
    printf("Door is currently %s.\n", doorLocked ? "locked" : "unlocked");
    printf("Can you unlock it? Enter 1 to unlock or 0 to leave it as is.\n");
    int unlockDoor;
    scanf("%d", &unlockDoor);
    if(unlockDoor) {
        doorLocked = 0;
        printf("Door is now unlocked.\n");
    } else {
        printf("Door remains locked.\n");
    }

    // Fifth puzzle
    printf("Music is currently %s.\n", musicPlaying ? "playing" : "paused");
    printf("Can you play some music? Enter 1 to play or 0 to leave it paused.\n");
    int playMusic;
    scanf("%d", &playMusic);
    if(playMusic) {
        musicPlaying = 1;
        printf("Music is now playing.\n");
    } else {
        printf("Music remains paused.\n");
    }

    // Final status report
    printf("Final status report:\n");
    printf("Temperature: %d degrees Celsius.\n", temperature);
    printf("Lights: %s.\n", lightsOn ? "on" : "off");
    printf("Window: %s.\n", windowOpen ? "open" : "closed");
    printf("Door: %s.\n", doorLocked ? "locked" : "unlocked");
    printf("Music: %s.\n", musicPlaying ? "playing" : "paused");

    return 0;
}