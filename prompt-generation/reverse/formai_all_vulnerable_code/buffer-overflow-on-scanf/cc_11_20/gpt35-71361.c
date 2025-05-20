//FormAI DATASET v1.0 Category: System boot optimizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_PLAYERS 4
#define MAX_BOOT_TIME 30

int main(void) {
    int players_online = 0;
    int boot_time = 0;
    int player_id = 0;
    int max_boot_time = 0;
    int winner_id = 0;
    
    srand(time(NULL)); // initialize random seed
    
    printf("Welcome to the C System Boot Optimizer game!\n");
    printf("Up to %d players can play.\n", MAX_PLAYERS);
    
    // get number of players
    while (players_online < 1 || players_online > MAX_PLAYERS) {
        printf("Enter number of players: ");
        scanf("%d", &players_online);
        
        if (players_online < 1 || players_online > MAX_PLAYERS) {
            printf("Invalid number of players. Please enter between 1 and %d.\n", MAX_PLAYERS);
        }
    }
    
    // get maximum boot time
    while (max_boot_time < players_online || max_boot_time > MAX_BOOT_TIME) {
        printf("Enter the maximum boot time (in seconds): ");
        scanf("%d", &max_boot_time);
        
        if (max_boot_time < players_online || max_boot_time > MAX_BOOT_TIME) {
            printf("Invalid maximum boot time. Please enter between %d and %d (inclusive of number of players).\n", players_online, MAX_BOOT_TIME);
        }
    }
    
    printf("Starting game with %d players and a maximum boot time of %d seconds...\n", players_online, max_boot_time);
    sleep(2); // wait for 2 seconds for suspense
    
    // game loop
    while (player_id < players_online) {
        printf("\nPlayer %d, it's your turn to try and optimize the system boot time!\n", player_id+1);
        printf("Remember, you only have a maximum of %d seconds to optimize the boot time.\n", max_boot_time);
        
        boot_time = rand() % max_boot_time + 1; // generate random boot time
        
        printf("\nYour current boot time is %d seconds. Do you want to optimize? (Y/N): ", boot_time);
        char choice;
        scanf(" %c", &choice);
        
        if (choice == 'Y' || choice == 'y') {
            int optimize_time = rand() % (max_boot_time - boot_time) + 1; // generate time to optimize boot time
            printf("You optimized the boot time by %d seconds. Your new boot time is %d seconds.\n", optimize_time, boot_time+optimize_time);
            boot_time += optimize_time;
        } else {
            printf("You chose not to optimize. Your boot time is still %d seconds.\n", boot_time);
        }
        
        if (boot_time < max_boot_time) {
            max_boot_time = boot_time; // update maximum boot time
            winner_id = player_id; // update winner id
        }
        
        sleep(2); // wait for 2 seconds for suspense
        
        player_id++; // move on to next player
    }
    
    printf("\nAll players have played.\n");
    sleep(2); // wait for 2 seconds for suspense
    
    printf("\nThe winner is Player %d with a boot time of %d seconds!\n", winner_id+1, max_boot_time);
    
    return 0; // end of program
}