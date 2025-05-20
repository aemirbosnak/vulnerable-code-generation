//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void spaceAdventure() {
    char name[20];
    int option;
    int health = 100;
    int enemy_health = 80;
    int num_of_enemies = 3;
    int num_of_items = 4;
    int item_found = 0;
    int enemy_defeated = 0;
    int escape_chance;
    int attack_chance;

    printf("Welcome to the Surreal Space Adventure!\n");
    printf("What is your name, adventurer? ");
    scanf("%s", name);
    printf("\nWelcome, %s! Your journey begins now.\n", name);

    printf("You find yourself on a strange planet with a crashed ship and nothing else around.\n");
    printf("You see three caves in the distance. Which do you choose to explore?\n");
    printf("1. The small cave\n");
    printf("2. The medium cave\n");
    printf("3. The large cave\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("You enter the small cave and find a strange artifact. It looks valuable!\n");
            printf("You hear something in the distance, and see a small creature approaching you aggressively.\n");
            printf("Do you:\n");
            printf("1. Attack the creature\n");
            printf("2. Try to escape\n");
            printf("Enter your choice: ");
            scanf("%d", &option);

            if (option == 1) {
                printf("You attack the creature and defeat it in battle, taking minimal damage.\n");
                enemy_defeated++;
            } else if (option == 2) {
                escape_chance = rand() % 2;
                if (escape_chance == 0) {
                    printf("You try to escape, but the creature catches up to you and attacks. You defeat it in battle but take some damage.\n");
                    health -= 20;
                    enemy_defeated++;
                } else {
                    printf("You successfully escape the creature and head back to the landing spot.\n");
                    return;
                }
            }
            break;
        case 2:
            printf("You enter the medium cave and find a pile of food rations. You have enough to last a week!\n");
            printf("You hear a strange noise in the distance and see a group of %d creatures approaching you.\n", num_of_enemies);
            printf("Do you:\n");
            printf("1. Try to escape\n");
            printf("2. Attack the creatures\n");
            printf("Enter your choice: ");
            scanf("%d", &option);

            if (option == 1) {
                escape_chance = rand() % 2;
                if (escape_chance == 0) {
                    printf("You successfully escape the group of creatures and head back to the landing spot.\n");
                    return;
                } else {
                    printf("You try to escape, but the creatures catch up to you and attack.\n");

                    while (num_of_enemies > 0 && health > 0) {
                        attack_chance = rand() % 2;
                        if (attack_chance == 0) {
                            printf("You dodge the enemy's attack!\n");
                        } else {
                            printf("You take damage in battle!\n");
                            health -= 10;
                        }

                        attack_chance = rand() % 2;
                        if (attack_chance == 0) {
                            printf("You attack and defeat one of the creatures.\n");
                            num_of_enemies--;
                            enemy_defeated++;
                        } else {
                            printf("You miss your opponent's attack!\n");
                        }
                    }

                    if (num_of_enemies == 0) {
                        printf("You have defeated all of the creatures with minimal damage.\n");
                    } else {
                        printf("You have been defeated in battle!\n");
                        printf("Game over!\n");
                        exit(0);
                    }
                }
            } else if (option == 2) {
                printf("You attack the group of creatures and defeat them all in battle, taking minimal damage.\n");
                enemy_defeated += num_of_enemies;
            }
            break;
        case 3:
            printf("You enter the large cave, but it is completely dark. You hear a strange noise in the distance.\n");
            printf("Do you:\n");
            printf("1. Turn on your flashlight\n");
            printf("2. Try to find your way out without using a flashlight\n");
            printf("Enter your choice: ");
            scanf("%d", &option);

            if (option == 1) {
                printf("You turn on your flashlight and see a giant mechanical robot in the distance.\n");
                printf("It seems to be guarding something valuable.\n");

                while (enemy_health > 0 && health > 0) {
                    attack_chance = rand() % 2;
                    if (attack_chance == 0) {
                        printf("The robot takes damage from your attack!\n");
                        enemy_health -= 20;
                    } else {
                        printf("You miss the robot's attack!\n");
                    }

                    attack_chance = rand() % 2;
                    if (attack_chance == 0) {
                        printf("You take damage from the robot's attack!\n");
                        health -= 30;
                    } else {
                        printf("You dodge the robot's attack!\n");
                    }
                }

                if (enemy_health == 0) {
                    printf("You have defeated the robot and found a rare item!\n");
                    item_found++;
                    enemy_defeated++;
                } else {
                    printf("You have been defeated in battle!\n");
                    printf("Game over!\n");
                    exit(0);
                }
            } else if (option == 2) {
                printf("You try to find your way in the dark, but run into a group of %d creatures.\n", num_of_enemies);
                printf("Do you:\n");
                printf("1. Attack the creatures\n");
                printf("2. Try to escape\n");
                printf("Enter your choice: ");
                scanf("%d", &option);

                if (option == 1) {
                    printf("You attack the creatures and defeat them all in battle, taking minimal damage.\n");
                    enemy_defeated += num_of_enemies;
                } else if (option == 2) {
                    escape_chance = rand() % 2;
                    if (escape_chance == 0) {
                        printf("You successfully escape the group of creatures and head back to the landing spot.\n");
                        return;
                    } else {
                        printf("You try to escape, but the creatures catch up to you and attack.\n");

                        while (num_of_enemies > 0 && health > 0) {
                            attack_chance = rand() % 2;
                            if (attack_chance == 0) {
                                printf("You dodge the enemy's attack!\n");
                            } else {
                                printf("You take damage in battle!\n");
                                health -= 10;
                            }

                            attack_chance = rand() % 2;
                            if (attack_chance == 0) {
                                printf("You attack and defeat one of the creatures.\n");
                                num_of_enemies--;
                                enemy_defeated++;
                            } else {
                                printf("You miss the opponent's attack!\n");
                            }
                        }

                        if (num_of_enemies == 0) {
                            printf("You have defeated all of the creatures with minimal damage.\n");
                        } else {
                            printf("You have been defeated in battle!\n");
                            printf("Game over!\n");
                            exit(0);  
                        }
                    }
                }
            }
            break;
        default:
            printf("Invalid option!\n");
            return;
    }

    printf("You have defeated %d enemies and found %d rare items so far.\n", enemy_defeated, item_found);
    printf("You head back to your ship to continue your journey through space!\n");
}

int main() {
    srand(time(0));
    spaceAdventure();

    return 0;
}