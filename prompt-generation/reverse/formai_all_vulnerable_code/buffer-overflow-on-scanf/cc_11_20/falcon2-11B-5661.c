//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char* name = "Player";
    char* location = "The Dark Forest";
    char* item = "A map";
    char* enemy = "A giant spider";

    srand(time(0));

    printf("Welcome to the adventure, %s!\n", name);
    printf("You are in %s.\n", location);
    printf("You have %s with you.\n", item);
    printf("There is an %s nearby.\n", enemy);

    char choice;
    int num;

    while (1) {
        printf("1. Look around\n2. Move\n3. Fight\n4. Use\n5. Quit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (strcmp(location, "The Dark Forest") == 0) {
                    printf("You see a path leading to the left and a path leading to the right.\n");
                    printf("Which way do you want to go?\n");
                    scanf(" %d", &num);

                    if (num == 1) {
                        location = "The Dark Forest - Left Path";
                        printf("You are now in %s.\n", location);
                    } else if (num == 2) {
                        location = "The Dark Forest - Right Path";
                        printf("You are now in %s.\n", location);
                    } else {
                        printf("Invalid choice. Try again.\n");
                    }
                } else {
                    printf("You can't see anything around you.\n");
                }
                break;

            case '2':
                if (strcmp(location, "The Dark Forest") == 0) {
                    printf("You can't move anywhere.\n");
                } else {
                    printf("You move to %s.\n", location);
                    location = "The Dark Forest";
                }
                break;

            case '3':
                if (strcmp(location, "The Dark Forest") == 0) {
                    printf("You can't fight anything.\n");
                } else if (strcmp(location, "The Dark Forest - Left Path") == 0) {
                    printf("You encounter a %s.\n", enemy);
                    printf("Do you want to fight? (Y/N)\n");
                    char choice2;
                    scanf(" %c", &choice2);

                    if (choice2 == 'Y' || choice2 == 'y') {
                        printf("You engage in combat with the %s.\n", enemy);
                        printf("You attack!\n");
                        printf("The %s attacks back!\n", enemy);
                        printf("You have %d health points.\n", 100);
                        printf("The %s has %d health points.\n", enemy, 50);
                        printf("1. Attack\n2. Defend\n3. Flee\n");
                        scanf(" %d", &num);

                        if (num == 1) {
                            printf("You attack the %s!\n", enemy);
                            printf("You have %d health points.\n", 100 - 5);
                            printf("The %s has %d health points.\n", enemy, 50 - 10);
                        } else if (num == 2) {
                            printf("You defend yourself!\n");
                            printf("You have %d health points.\n", 100);
                            printf("The %s has %d health points.\n", enemy, 50);
                        } else if (num == 3) {
                            printf("You flee!\n");
                            printf("You are now in %s.\n", location);
                        } else {
                            printf("Invalid choice. Try again.\n");
                        }
                    } else {
                        printf("You can't fight anything.\n");
                    }
                } else {
                    printf("You can't fight anything.\n");
                }
                break;

            case '4':
                if (strcmp(item, "A map") == 0) {
                    printf("You use the %s.\n", item);
                    item = "A torn map";
                } else {
                    printf("You can't use anything.\n");
                }
                break;

            case '5':
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

        printf("1. Look around\n2. Move\n3. Fight\n4. Use\n5. Quit\n");
        scanf(" %c", &choice);
    }

    return 0;
}