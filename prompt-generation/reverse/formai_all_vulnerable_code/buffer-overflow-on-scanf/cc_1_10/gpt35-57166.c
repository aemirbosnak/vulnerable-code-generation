//FormAI DATASET v1.0 Category: Smart home automation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void turn_on_lights(bool living_room, bool bedroom, bool kitchen);
void turn_on_heating(bool living_room, bool bedroom);
void turn_on_aircon(bool living_room, bool bedroom);
void play_music(bool living_room, bool bedroom);
void lock_doors(bool front_door, bool back_door);

int main() {
    // Initialize all devices to off
    bool living_room_lights = false;
    bool bedroom_lights = false;
    bool kitchen_lights = false;
    bool living_room_heating = false;
    bool bedroom_heating = false;
    bool living_room_aircon = false;
    bool bedroom_aircon = false;
    bool living_room_music = false;
    bool bedroom_music = false;
    bool front_door_locked = true;
    bool back_door_locked = true;

    // Prompt user for input
    printf("Welcome to your smart home automation system!\n\n");
    printf("Would you like to turn on the lights in the living room, bedroom, and kitchen? (Y/N)\n");
    char lights_input;
    scanf("%c", &lights_input);
    if (lights_input == 'Y') {
        living_room_lights = true;
        bedroom_lights = true;
        kitchen_lights = true;
    }

    printf("Would you like to turn on the heating in the living room and bedroom? (Y/N)\n");
    char heating_input;
    scanf("%c", &heating_input);
    if (heating_input == 'Y') {
        living_room_heating = true;
        bedroom_heating = true;
    }

    printf("Would you like to turn on the air conditioning in the living room and bedroom? (Y/N)\n");
    char aircon_input;
    scanf("%c", &aircon_input);
    if (aircon_input == 'Y') {
        living_room_aircon = true;
        bedroom_aircon = true;
    }

    printf("Would you like to play music in the living room and bedroom? (Y/N)\n");
    char music_input;
    scanf("%c", &music_input);
    if (music_input == 'Y') {
        living_room_music = true;
        bedroom_music = true;
    }

    printf("Would you like to lock the front and back doors? (Y/N)\n");
    char lock_input;
    scanf("%c", &lock_input);
    if (lock_input == 'Y') {
        front_door_locked = true;
        back_door_locked = true;
    }

    // Execute functions based on user input
    turn_on_lights(living_room_lights, bedroom_lights, kitchen_lights);
    turn_on_heating(living_room_heating, bedroom_heating);
    turn_on_aircon(living_room_aircon, bedroom_aircon);
    play_music(living_room_music, bedroom_music);
    lock_doors(front_door_locked, back_door_locked);

    return 0;
}

void turn_on_lights(bool living_room, bool bedroom, bool kitchen) {
    if (living_room) {
        printf("Turning on living room lights...\n");
    }
    if (bedroom) {
        printf("Turning on bedroom lights...\n");
    }
    if (kitchen) {
        printf("Turning on kitchen lights...\n");
    }
}

void turn_on_heating(bool living_room, bool bedroom) {
    if (living_room) {
        printf("Turning on living room heating...\n");
    }
    if (bedroom) {
        printf("Turning on bedroom heating...\n");
    }
}

void turn_on_aircon(bool living_room, bool bedroom) {
    if (living_room) {
        printf("Turning on living room air conditioning...\n");
    }
    if (bedroom) {
        printf("Turning on bedroom air conditioning...\n");
    }
}

void play_music(bool living_room, bool bedroom) {
    if (living_room) {
        printf("Playing music in the living room...\n");
    }
    if (bedroom) {
        printf("Playing music in the bedroom...\n");
    }
}

void lock_doors(bool front_door, bool back_door) {
    if (front_door) {
        printf("Locking the front door...\n");
    }
    if (back_door) {
        printf("Locking the back door...\n");
    }
}