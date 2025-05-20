//FormAI DATASET v1.0 Category: Smart home automation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum RoomState {
    OFF,
    ON
};

void light_on() {
    printf("Turning on the lights...\n");
}

void light_off() {
    printf("Turning off the lights...\n");
}

void air_conditioner_on() {
    printf("Turning on the air conditioner...\n");
}

void air_conditioner_off() {
    printf("Turning off the air conditioner...\n");
}

void ceiling_fan_on() {
    printf("Turning on the ceiling fan...\n");
}

void ceiling_fan_off() {
    printf("Turning off the ceiling fan...\n");
}

int main() {
    int room_one_state = OFF;
    int room_two_state = OFF;
    int room_three_state = OFF;

    while(1) {
        int room_choice;
        int action_choice;

        printf("\nEnter the room number (1, 2, 3): ");
        scanf("%d", &room_choice);

        printf("Enter the action to perform (1 for light, 2 for air conditioner, 3 for ceiling fan): ");
        scanf("%d", &action_choice);

        switch(room_choice) {
            case 1:
                switch(action_choice) {
                    case 1:
                        if(room_one_state == OFF) {
                            light_on();
                            room_one_state = ON;
                        } else {
                            light_off();
                            room_one_state = OFF;
                        }
                        break;
                    case 2:
                        if(room_one_state == OFF) {
                            printf("Please turn on the lights before turning on the air conditioner.\n");
                        } else {
                            if(room_one_state == OFF) {
                                air_conditioner_on();
                                room_one_state = ON;
                            } else {
                                air_conditioner_off();
                                room_one_state = OFF;
                            }
                        }
                        break;
                    case 3:
                        if(room_one_state == OFF) {
                            printf("Please turn on the lights before turning on the ceiling fan.\n");
                        } else {
                            if(room_one_state == OFF) {
                                ceiling_fan_on();
                                room_one_state = ON;
                            } else {
                                ceiling_fan_off();
                                room_one_state = OFF;
                            }
                        }
                        break;
                    default:
                        printf("Invalid action choice.\n");
                        break;
                }
                break;
            case 2:
                switch(action_choice) {
                    case 1:
                        if(room_two_state == OFF) {
                            light_on();
                            room_two_state = ON;
                        } else {
                            light_off();
                            room_two_state = OFF;
                        }
                        break;
                    case 2:
                        if(room_two_state == OFF) {
                            printf("Please turn on the lights before turning on the air conditioner.\n");
                        } else {
                            if(room_two_state == OFF) {
                                air_conditioner_on();
                                room_two_state = ON;
                            } else {
                                air_conditioner_off();
                                room_two_state = OFF;
                            }
                        }
                        break;
                    case 3:
                        if(room_two_state == OFF) {
                            printf("Please turn on the lights before turning on the ceiling fan.\n");
                        } else {
                            if(room_two_state == OFF) {
                                ceiling_fan_on();
                                room_two_state = ON;
                            } else {
                                ceiling_fan_off();
                                room_two_state = OFF;
                            }
                        }
                        break;
                    default:
                        printf("Invalid action choice.\n");
                        break;
                }
                break;
            case 3:
                switch(action_choice) {
                    case 1:
                        if(room_three_state == OFF) {
                            light_on();
                            room_three_state = ON;
                        } else {
                            light_off();
                            room_three_state = OFF;
                        }
                        break;
                    case 2:
                        if(room_three_state == OFF) {
                            printf("Please turn on the lights before turning on the air conditioner.\n");
                        } else {
                            if(room_three_state == OFF) {
                                air_conditioner_on();
                                room_three_state = ON;
                            } else {
                                air_conditioner_off();
                                room_three_state = OFF;
                            }
                        }
                        break;
                    case 3:
                        if(room_three_state == OFF) {
                            printf("Please turn on the lights before turning on the ceiling fan.\n");
                        } else {
                            if(room_three_state == OFF) {
                                ceiling_fan_on();
                                room_three_state = ON;
                            } else {
                                ceiling_fan_off();
                                room_three_state = OFF;
                            }
                        }
                        break;
                    default:
                        printf("Invalid action choice.\n");
                        break;
                }
                break;
            default:
                printf("Invalid room choice.\n");
                break;
        }

        sleep(1); // Wait for one second before taking further input
    }

    return 0;
}