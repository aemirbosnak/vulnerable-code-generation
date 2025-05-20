//FormAI DATASET v1.0 Category: Smart home light control ; Style: immersive
#include <stdio.h>

// Immersive function to turn on light
void turnOnLight(int lightIndex, char* roomName) {
    printf("Turning on light %d in %s...\n", lightIndex, roomName);
    // code to send signal to turn on light
}

// Immersive function to turn off light
void turnOffLight(int lightIndex, char* roomName) {
    printf("Turning off light %d in %s...\n", lightIndex, roomName);
    // code to send signal to turn off light
}

// Main function
int main() {
    char livingRoom[] = "Living Room";
    char kitchen[] = "Kitchen";
    char bedroom[] = "Bedroom";

    // Greeting message
    printf("Welcome to the Smart Home Light Control System!\n");

    // Main menu
    int userChoice = 1;
    while (userChoice != 0) {
        printf("Please enter the number of the room you want to control the lights:\n");
        printf("1. Living Room\n");
        printf("2. Kitchen\n");
        printf("3. Bedroom\n");
        printf("0. Exit\n");
        scanf("%d", &userChoice);

        // Living Room
        if (userChoice == 1) {
            printf("\n--- Living Room ---\n");
            int lightChoice = 1;
            while (lightChoice != 0) {
                printf("Please enter the number of the light you want to control:\n");
                printf("1. Light 1\n");
                printf("2. Light 2\n");
                printf("0. Back\n");
                scanf("%d", &lightChoice);

                // Light 1
                if (lightChoice == 1) {
                    int actionChoice = 1;
                    while (actionChoice != 0) {
                        printf("Please enter the number of the action you want to perform:\n");
                        printf("1. Turn on\n");
                        printf("2. Turn off\n");
                        printf("0. Back\n");
                        scanf("%d", &actionChoice);

                        if (actionChoice == 1) {
                            turnOnLight(1, livingRoom);
                        } else if (actionChoice == 2) {
                            turnOffLight(1, livingRoom);
                        }
                    }
                }

                // Light 2
                else if (lightChoice == 2) {
                    int actionChoice = 1;
                    while (actionChoice != 0) {
                        printf("Please enter the number of the action you want to perform:\n");
                        printf("1. Turn on\n");
                        printf("2. Turn off\n");
                        printf("0. Back\n");
                        scanf("%d", &actionChoice);

                        if (actionChoice == 1) {
                            turnOnLight(2, livingRoom);
                        } else if (actionChoice == 2) {
                            turnOffLight(2, livingRoom);
                        }
                    }
                }
            }
        }

        // Kitchen
        else if (userChoice == 2) {
            printf("\n--- Kitchen ---\n");
            int lightChoice = 1;
            while (lightChoice != 0) {
                printf("Please enter the number of the light you want to control:\n");
                printf("1. Light 1\n");
                printf("0. Back\n");
                scanf("%d", &lightChoice);

                // Light 1
                if (lightChoice == 1) {
                    int actionChoice = 1;
                    while (actionChoice != 0) {
                        printf("Please enter the number of the action you want to perform:\n");
                        printf("1. Turn on\n");
                        printf("2. Turn off\n");
                        printf("0. Back\n");
                        scanf("%d", &actionChoice);

                        if (actionChoice == 1) {
                            turnOnLight(1, kitchen);
                        } else if (actionChoice == 2) {
                            turnOffLight(1, kitchen);
                        }
                    }
                }
            }
        }

        // Bedroom
        else if (userChoice == 3) {
            printf("\n--- Bedroom ---\n");
            int lightChoice = 1;
            while (lightChoice != 0) {
                printf("Please enter the number of the light you want to control:\n");
                printf("1. Light 1\n");
                printf("2. Light 2\n");
                printf("0. Back\n");
                scanf("%d", &lightChoice);

                // Light 1
                if (lightChoice == 1) {
                    int actionChoice = 1;
                    while (actionChoice != 0) {
                        printf("Please enter the number of the action you want to perform:\n");
                        printf("1. Turn on\n");
                        printf("2. Turn off\n");
                        printf("0. Back\n");
                        scanf("%d", &actionChoice);

                        if (actionChoice == 1) {
                            turnOnLight(1, bedroom);
                        } else if (actionChoice == 2) {
                            turnOffLight(1, bedroom);
                        }
                    }
                }

                // Light 2
                else if (lightChoice == 2) {
                    int actionChoice = 1;
                    while (actionChoice != 0) {
                        printf("Please enter the number of the action you want to perform:\n");
                        printf("1. Turn on\n");
                        printf("2. Turn off\n");
                        printf("0. Back\n");
                        scanf("%d", &actionChoice);

                        if (actionChoice == 1) {
                            turnOnLight(2, bedroom);
                        } else if (actionChoice == 2) {
                            turnOffLight(2, bedroom);
                        }
                    }
                }
            }
        }
    }
    printf("Exiting Smart Home Light Control System...\n");
    return 0;
}