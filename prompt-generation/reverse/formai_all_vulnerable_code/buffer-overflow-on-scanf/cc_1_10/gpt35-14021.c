//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

pthread_t tid[2];
int choice;
char item[20], location[20];
int location_unlocked = 0;
int cave_unlocked = 0;
int sword = 0;

void* player_thread(void *arg)
{
    printf("You find yourself in a dark forest.\n");
    sleep(2);
    printf("You can hear the sounds of creatures lurking in the shadows.\n");
    sleep(2);
    printf("You must find your way out of the forest before it's too late.\n");
    sleep(2);

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Search for items\n");
        printf("2. Search for a way out of the forest\n");
        printf("3. Quit the game\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (!location_unlocked) {
                    printf("You need to find a key to unlock the location.\n");
                } else {
                    printf("You have unlocked the location and found a %s.\n", item);
                    if (strcmp(item, "torch") == 0) {
                        printf("You can now see through the dark areas.\n");
                    } else if (strcmp(item, "map") == 0) {
                        printf("You can now see the layout of the forest.\n");
                    } else if (strcmp(item, "sword") == 0) {
                        sword = 1;
                        printf("You now have a sword to defend yourself.\n");
                    }
                }
                break;
            case 2:
                if (!cave_unlocked) {
                    printf("You need to find a key to unlock the cave.\n");
                } else {
                    printf("You have found the way out of the forest.\n");
                    return NULL;
                }
                break;
            case 3:
                printf("Leaving so soon?\n");
                return NULL;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
}

void* enemy_thread(void *arg)
{
    while (1) {
        printf("A monster appeared!\n");
        sleep(2);
        if (sword) {
            printf("You killed the monster with your sword.\n");
            sleep(2);
            continue;
        }
        printf("You don't have a sword to defend yourself.\n");
        sleep(2);
        printf("The monster attacked you and you died.\n");
        exit(EXIT_SUCCESS);
    }
}

int main(void)
{
    printf("Welcome to the Text-Based Adventure Game!\n");
    sleep(2);
    printf("You must navigate through a dark forest to find your way out.\n");
    sleep(2);

    // initialize location and item
    strcpy(location, "locked location");
    strcpy(item, "nothing");

    // create threads
    pthread_create(&tid[0], NULL, player_thread, NULL);
    pthread_create(&tid[1], NULL, enemy_thread, NULL);

    // wait for threads to join
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    return 0;
}