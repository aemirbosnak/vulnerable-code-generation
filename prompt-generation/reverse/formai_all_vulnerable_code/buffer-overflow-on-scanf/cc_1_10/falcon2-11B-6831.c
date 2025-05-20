//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

// Global variables
int light_on = 0;
int temp_on = 0;
int music_on = 0;
int user_input = 0;

// Function prototypes
void print_help();
void print_status();
void turn_on_light();
void turn_off_light();
void set_temperature(int temp);
void play_music();
void stop_music();
void get_user_input();
void read_time();

// Main function
int main() {
    while(1) {
        print_status();
        get_user_input();
        if (user_input == '1') {
            turn_on_light();
        } else if (user_input == '2') {
            turn_off_light();
        } else if (user_input == '3') {
            set_temperature(25);
        } else if (user_input == '4') {
            play_music();
        } else if (user_input == '5') {
            stop_music();
        } else if (user_input == '6') {
            read_time();
        }
    }
    return 0;
}

// Function definitions
void print_help() {
    printf("Available commands:\n");
    printf("1. Turn on/off light\n");
    printf("2. Set temperature\n");
    printf("3. Play/stop music\n");
    printf("6. Read current time\n");
}

void print_status() {
    if (light_on) {
        printf("Lights are on.\n");
    } else {
        printf("Lights are off.\n");
    }

    if (temp_on) {
        printf("Temperature is set to %d degrees.\n", temp_on);
    } else {
        printf("Temperature is not set.\n");
    }

    if (music_on) {
        printf("Music is playing.\n");
    } else {
        printf("Music is not playing.\n");
    }
}

void turn_on_light() {
    light_on = 1;
    printf("Light turned on.\n");
}

void turn_off_light() {
    light_on = 0;
    printf("Light turned off.\n");
}

void set_temperature(int temp) {
    temp_on = temp;
    printf("Temperature set to %d degrees.\n", temp_on);
}

void play_music() {
    music_on = 1;
    printf("Music started playing.\n");
}

void stop_music() {
    music_on = 0;
    printf("Music stopped playing.\n");
}

void get_user_input() {
    printf("Enter command (1-6): ");
    scanf("%d", &user_input);
}

void read_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("Current time: %ld\n", tv.tv_sec);
}