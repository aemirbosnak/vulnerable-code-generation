//FormAI DATASET v1.0 Category: Smart home automation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lamp1 = 0, lamp2 = 0, ac = 0, tv = 0, door = 0;
    int option, player;
    char name[30];
    
    printf("Welcome to the Smart Home Automation Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! You are Player 1.\n", name);
    printf("Please wait for Player 2 to join.\n\n");

    // Wait for Player 2
    printf("Waiting for Player 2...\n");
    // TODO: Implement network code to wait for Player 2 to join
    printf("Player 2 joined the game!\n\n");

    // Game loop
    while (1)
    {
        printf("Player %d's turn:\n", (player % 2) + 1);
        printf("1. Toggle Lamp 1 (currently %s)\n", lamp1 ? "ON" : "OFF");
        printf("2. Toggle Lamp 2 (currently %s)\n", lamp2 ? "ON" : "OFF");
        printf("3. Toggle AC (currently %s)\n", ac ? "ON" : "OFF");
        printf("4. Toggle TV (currently %s)\n", tv ? "ON" : "OFF");
        printf("5. Toggle Door (currently %s)\n", door ? "OPEN" : "CLOSED");
        printf("6. Quit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                lamp1 = !lamp1;
                printf("Lamp 1 is now %s.\n", lamp1 ? "ON" : "OFF");
                break;
            case 2:
                lamp2 = !lamp2;
                printf("Lamp 2 is now %s.\n", lamp2 ? "ON" : "OFF");
                break;
            case 3:
                ac = !ac;
                printf("AC is now %s.\n", ac ? "ON" : "OFF");
                break;
            case 4:
                tv = !tv;
                printf("TV is now %s.\n", tv ? "ON" : "OFF");
                break;
            case 5:
                door = !door;
                printf("Door is now %s.\n", door ? "OPEN" : "CLOSED");
                break;
            case 6:
                printf("Game over. Thanks for playing!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }

        // TODO: Implement network code to send updated state to other player
        player++;
    }
    
    return 0;
}