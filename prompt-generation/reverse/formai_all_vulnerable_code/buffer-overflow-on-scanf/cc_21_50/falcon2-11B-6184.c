//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char choice[50];
    srand(time(NULL));
    printf("Welcome to the Adventure Game!\n");
    printf("You are in a dark forest. What do you want to do?\n");
    printf("1. Walk forward\n2. Walk backward\n3. Turn left\n4. Turn right\n5. Look around\n");
    scanf("%s", choice);
    printf("You chose: %s\n", choice);
    switch (choice[0]) {
        case '1':
            printf("You walked forward and found a river.\n");
            printf("Do you want to cross the river? (yes/no)\n");
            scanf("%s", choice);
            if (choice[0] == 'y') {
                printf("You crossed the river and found a castle.\n");
                printf("Do you want to enter the castle? (yes/no)\n");
                scanf("%s", choice);
                if (choice[0] == 'y') {
                    printf("You entered the castle and found a treasure chest.\n");
                    printf("Do you want to open the treasure chest? (yes/no)\n");
                    scanf("%s", choice);
                    if (choice[0] == 'y') {
                        printf("You opened the treasure chest and found a shiny object.\n");
                        printf("Do you want to take the shiny object? (yes/no)\n");
                        scanf("%s", choice);
                        if (choice[0] == 'y') {
                            printf("You took the shiny object and the game ended.\n");
                        } else {
                            printf("You left the shiny object and the game continued.\n");
                        }
                    } else {
                        printf("You left the treasure chest and the game continued.\n");
                    }
                } else {
                    printf("You left the castle and the game continued.\n");
                }
            } else {
                printf("You stayed on the river bank and the game continued.\n");
            }
            break;
        case '2':
            printf("You walked backward and found a cave.\n");
            printf("Do you want to enter the cave? (yes/no)\n");
            scanf("%s", choice);
            if (choice[0] == 'y') {
                printf("You entered the cave and found a ladder.\n");
                printf("Do you want to climb the ladder? (yes/no)\n");
                scanf("%s", choice);
                if (choice[0] == 'y') {
                    printf("You climbed the ladder and found a trapdoor.\n");
                    printf("Do you want to open the trapdoor? (yes/no)\n");
                    scanf("%s", choice);
                    if (choice[0] == 'y') {
                        printf("You opened the trapdoor and found a treasure chest.\n");
                        printf("Do you want to open the treasure chest? (yes/no)\n");
                        scanf("%s", choice);
                        if (choice[0] == 'y') {
                            printf("You opened the treasure chest and found a shiny object.\n");
                            printf("Do you want to take the shiny object? (yes/no)\n");
                            scanf("%s", choice);
                            if (choice[0] == 'y') {
                                printf("You took the shiny object and the game ended.\n");
                            } else {
                                printf("You left the shiny object and the game continued.\n");
                            }
                        } else {
                            printf("You left the treasure chest and the game continued.\n");
                        }
                    } else {
                        printf("You left the trapdoor and the game continued.\n");
                    }
                } else {
                    printf("You stayed on the ladder and the game continued.\n");
                }
            } else {
                printf("You stayed on the cave floor and the game continued.\n");
            }
            break;
        case '3':
            printf("You turned left and found a river.\n");
            printf("Do you want to cross the river? (yes/no)\n");
            scanf("%s", choice);
            if (choice[0] == 'y') {
                printf("You crossed the river and found a castle.\n");
                printf("Do you want to enter the castle? (yes/no)\n");
                scanf("%s", choice);
                if (choice[0] == 'y') {
                    printf("You entered the castle and found a treasure chest.\n");
                    printf("Do you want to open the treasure chest? (yes/no)\n");
                    scanf("%s", choice);
                    if (choice[0] == 'y') {
                        printf("You opened the treasure chest and found a shiny object.\n");
                        printf("Do you want to take the shiny object? (yes/no)\n");
                        scanf("%s", choice);
                        if (choice[0] == 'y') {
                            printf("You took the shiny object and the game ended.\n");
                        } else {
                            printf("You left the shiny object and the game continued.\n");
                        }
                    } else {
                        printf("You left the treasure chest and the game continued.\n");
                    }
                } else {
                    printf("You left the castle and the game continued.\n");
                }
            } else {
                printf("You stayed on the river bank and the game continued.\n");
            }
            break;
        case '4':
            printf("You turned right and found a cave.\n");
            printf("Do you want to enter the cave? (yes/no)\n");
            scanf("%s", choice);
            if (choice[0] == 'y') {
                printf("You entered the cave and found a ladder.\n");
                printf("Do you want to climb the ladder? (yes/no)\n");
                scanf("%s", choice);
                if (choice[0] == 'y') {
                    printf("You climbed the ladder and found a trapdoor.\n");
                    printf("Do you want to open the trapdoor? (yes/no)\n");
                    scanf("%s", choice);
                    if (choice[0] == 'y') {
                        printf("You opened the trapdoor and found a treasure chest.\n");
                        printf("Do you want to open the treasure chest? (yes/no)\n");
                        scanf("%s", choice);
                        if (choice[0] == 'y') {
                            printf("You opened the treasure chest and found a shiny object.\n");
                            printf("Do you want to take the shiny object? (yes/no)\n");
                            scanf("%s", choice);
                            if (choice[0] == 'y') {
                                printf("You took the shiny object and the game ended.\n");
                            } else {
                                printf("You left the shiny object and the game continued.\n");
                            }
                        } else {
                            printf("You left the treasure chest and the game continued.\n");
                        }
                    } else {
                        printf("You left the trapdoor and the game continued.\n");
                    }
                } else {
                    printf("You stayed on the ladder and the game continued.\n");
                }
            } else {
                printf("You stayed on the cave floor and the game continued.\n");
            }
            break;
        case '5':
            printf("You looked around and found a river.\n");
            printf("Do you want to cross the river? (yes/no)\n");
            scanf("%s", choice);
            if (choice[0] == 'y') {
                printf("You crossed the river and found a castle.\n");
                printf("Do you want to enter the castle? (yes/no)\n");
                scanf("%s", choice);
                if (choice[0] == 'y') {
                    printf("You entered the castle and found a treasure chest.\n");
                    printf("Do you want to open the treasure chest? (yes/no)\n");
                    scanf("%s", choice);
                    if (choice[0] == 'y') {
                        printf("You opened the treasure chest and found a shiny object.\n");
                        printf("Do you want to take the shiny object? (yes/no)\n");
                        scanf("%s", choice);
                        if (choice[0] == 'y') {
                            printf("You took the shiny object and the game ended.\n");
                        } else {
                            printf("You left the shiny object and the game continued.\n");
                        }
                    } else {
                        printf("You left the treasure chest and the game continued.\n");
                    }
                } else {
                    printf("You left the castle and the game continued.\n");
                }
            } else {
                printf("You stayed on the river bank and the game continued.\n");
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    printf("Game over.\n");
    return 0;
}