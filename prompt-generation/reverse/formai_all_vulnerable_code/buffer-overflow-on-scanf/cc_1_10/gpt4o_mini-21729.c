//GPT-4o-mini DATASET v1.0 Category: Traffic Light Controller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum LightState { RED, GREEN, YELLOW };

void displayLight(enum LightState state) {
    switch (state) {
        case RED:
            printf("\n----------\n");
            printf("|   R    |\n");
            printf("----------\n");
            break;
        case GREEN:
            printf("\n----------\n");
            printf("|   G    |\n");
            printf("----------\n");
            break;
        case YELLOW:
            printf("\n----------\n");
            printf("|   Y    |\n");
            printf("----------\n");
            break;
    }
}

void trafficLightController(int cycles) {
    enum LightState currentLight = RED;
    for (int i = 0; i < cycles; i++) {
        switch (currentLight) {
            case RED:
                displayLight(RED);
                sleep(5);  // Red for 5 seconds
                currentLight = GREEN;
                break;
            case GREEN:
                displayLight(GREEN);
                sleep(5);  // Green for 5 seconds
                currentLight = YELLOW;
                break;
            case YELLOW:
                displayLight(YELLOW);
                sleep(2);  // Yellow for 2 seconds
                currentLight = RED;
                break;
        }
    }
}

void malfunctionHandler() {
    printf("!!! MALFUNCTION ALERT !!!\n");
    printf("All lights are flickering...\n");
    
    for (int i = 0; i < 5; i++) {
        printf("Lights flickering...\n");
        sleep(1);
        printf("\033[F\033[K"); // Move cursor up and clear line
        sleep(1);
    }

    printf("Returning to normal operation...\n");
    sleep(2);
}

void manualOverride() {
    char input;
    printf("\nManual Override Activated! Press 'E' to exit...\n");
    
    do {
        printf("Press 'R' for RED, 'G' for GREEN, 'Y' for YELLOW: ");
        scanf(" %c", &input);

        switch (input) {
            case 'R':
                displayLight(RED);
                break;
            case 'G':
                displayLight(GREEN);
                break;
            case 'Y':
                displayLight(YELLOW);
                break;
            case 'E':
                printf("Exiting Manual Override...\n");
                break;
            default:
                printf("Invalid Input! Try Again...\n");
                break;
        }
        sleep(2);
    } while (input != 'E');
}

int main() {
    int cycles;
    printf("Welcome to the Traffic Light Controller System!\n");
    printf("Enter number of cycles for normal operation (1-10): ");
    scanf("%d", &cycles);

    if (cycles < 1 || cycles > 10) {
        printf("Invalid number of cycles! Defaulting to 5 cycles...\n");
        cycles = 5;
    }

    printf("\nStarting Traffic Light Controller...\n");
    
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed!");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child Process for Malfunction Simulation
        sleep(8);  // Wait to initiate malfunction
        malfunctionHandler();
        exit(0);
    } else {
        // Parent Process
        trafficLightController(cycles);
        wait(NULL); // Wait for child process
        printf("Traffic Light Controller operation completed. Exiting...\n");
    }

    printf("\nWould you like to manually override? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        manualOverride();
    }

    printf("Thank you! Drive safely!\n");
    return 0;
}