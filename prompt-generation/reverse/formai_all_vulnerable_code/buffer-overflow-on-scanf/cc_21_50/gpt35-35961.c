//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adventure();

int main() {
    printf("Welcome to the Happy Adventure Game!\n");
    printf("Are you ready to start your adventure? (y/n): ");

    char response[10];
    scanf("%s", response);

    if (strcmp(response, "y") == 0 || strcmp(response, "Y") == 0) {
        printf("\nGreat! Let's get started.\n\n");
        adventure();
    } else {
        printf("\nOh, that's too bad. Maybe next time!\n");
    }

    return 0;
}

void adventure() {
    char name[20];
    printf("What's your name? ");
    scanf("%s", name);
    printf("\nHello, %s! You are embarking on a happy adventure.\n", name);

    printf("\nYou find yourself in a beautiful, picturesque village.\n");

    printf("Do you want to (a) explore the village or (b) ask for directions? ");
    char choice[10];
    scanf("%s", choice);

    if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
        printf("\nYou explore the village and find a hidden treasure chest!\n");
        printf("Do you want to (a) open the treasure chest or (b) leave it alone? ");
        scanf("%s", choice);
        if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
            printf("\nYou open the chest and find a delicious cake! Yum!\n");
            printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
        } else {
            printf("\nYou leave the treasure chest alone and continue your adventure.\n");
            printf("\nYou come across a group of friendly villagers who invite you to a party!\n");
            printf("Do you want to (a) go to the party or (b) continue on your adventure? ");
            scanf("%s", choice);
            if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                printf("\nYou go to the party and have an amazing time!\n");
                printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
            } else {
                printf("\nYou continue on your adventure and come across a beautiful forest.\n");
                printf("Do you want to (a) explore the forest or (b) continue on your adventure? ");
                scanf("%s", choice);
                if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                    printf("\nYou explore the forest and find a magical unicorn!\n");
                    printf("Do you want to (a) ride the unicorn or (b) leave it alone? ");
                    scanf("%s", choice);
                    if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                        printf("\nYou ride the unicorn and have an amazing time!\n");
                        printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
                    } else {
                        printf("\nYou leave the unicorn alone and continue on your adventure.\n");
                        printf("\nYou come across a peaceful lake where you take a refreshing swim!\n");
                        printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
                    }
                } else {
                    printf("\nYou continue on your adventure and come across a beautiful beach.\n");
                    printf("Do you want to (a) relax on the beach or (b) continue on your adventure? ");
                    scanf("%s", choice);
                    if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                        printf("\nYou relax on the beach and soak up the sun!\n");
                        printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
                    } else {
                        printf("\nYou continue on your adventure and find yourself in a cozy cottage.\n");
                        printf("Do you want to (a) cozy up by the fire or (b) continue on your adventure? ");
                        scanf("%s", choice);
                        if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                            printf("\nYou cozy up by the fire and enjoy a warm cup of cocoa!\n");
                            printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
                        } else {
                            printf("\nYou continue on your adventure and stumble upon a magical portal!\n");
                            printf("Do you want to (a) go through the portal or (b) continue on your adventure? ");
                            scanf("%s", choice);
                            if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                                printf("\nYou go through the portal and find yourself in a land of unicorns and rainbows!\n");
                                printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
                            } else {
                                printf("\nYou continue on your adventure and come across a friendly dragon!\n");
                                printf("Do you want to (a) make friends with the dragon or (b) continue on your adventure? ");
                                scanf("%s", choice);
                                if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                                    printf("\nYou make friends with the dragon and go on many more adventures together!\n");
                                    printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
                                } else {
                                    printf("\nYou continue on your adventure and come across a magical fairy!\n");
                                    printf("Do you want to (a) ask the fairy for her magic or (b) continue on your adventure? ");
                                    scanf("%s", choice);
                                    if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                                        printf("\nThe fairy gives you her magic and you have amazing powers!\n");
                                        printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
                                    } else {
                                        printf("\nYou continue on your adventure and come across a beautiful garden.\n");
                                        printf("Do you want to (a) smell the flowers or (b) continue on your adventure? ");
                                        scanf("%s", choice);
                                        if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                                            printf("\nYou smell the flowers and they are the most amazing smelling flowers you have ever smelled!\n");
                                            printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
                                        } else {
                                            printf("\nYou continue on your adventure and find yourself back at the beginning of the village.\n");
                                            printf("Do you want to (a) start over or (b) end your adventure? ");
                                            scanf("%s", choice);
                                            if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                                                printf("\nYou start over and have even more amazing adventures!\n");
                                                adventure();
                                            } else {
                                                printf("\nYou end your adventure.\n");
                                                printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        printf("\nYou ask for directions and are told to go left.\n");
        printf("\nYou go left and find a friendly unicorn!\n");
        printf("Do you want to (a) ride the unicorn or (b) continue on your adventure? ");
        scanf("%s", choice);
        if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
            printf("\nYou ride the unicorn and have an amazing time!\n");
            printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
        } else {
            printf("\nYou continue on your adventure and come across a beautiful beach.\n");
            printf("Do you want to (a) relax on the beach or (b) continue on your adventure? ");
            scanf("%s", choice);
            if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                printf("\nYou relax on the beach and soak up the sun!\n");
                printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
            } else {
                printf("\nYou continue on your adventure and find yourself in a cozy cottage.\n");
                printf("Do you want to (a) cozy up by the fire or (b) continue on your adventure? ");
                scanf("%s", choice);
                if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                    printf("\nYou cozy up by the fire and enjoy a warm cup of cocoa!\n");
                    printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
                } else {
                    printf("\nYou continue on your adventure and stumble upon a magical portal!\n");
                    printf("Do you want to (a) go through the portal or (b) continue on your adventure? ");
                    scanf("%s", choice);
                    if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                        printf("\nYou go through the portal and find yourself in a land of unicorns and rainbows!\n");
                        printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
                    } else {
                        printf("\nYou continue on your adventure and come across a friendly dragon!\n");
                        printf("Do you want to (a) make friends with the dragon or (b) continue on your adventure? ");
                        scanf("%s", choice);
                        if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                            printf("\nYou make friends with the dragon and go on many more adventures together!\n");
                            printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
                        } else {
                            printf("\nYou continue on your adventure and come across a magical fairy!\n");
                            printf("Do you want to (a) ask the fairy for her magic or (b) continue on your adventure? ");
                            scanf("%s", choice);
                            if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                                printf("\nThe fairy gives you her magic and you have amazing powers!\n");
                                printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
                            } else {
                                printf("\nYou continue on your adventure and come across a beautiful garden.\n");
                                printf("Do you want to (a) smell the flowers or (b) continue on your adventure? ");
                                scanf("%s", choice);
                                if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                                    printf("\nYou smell the flowers and they are the most amazing smelling flowers you have ever smelled!\n");
                                    printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
                                } else {
                                    printf("\nYou continue on your adventure and find yourself back at the beginning of the village.\n");
                                    printf("Do you want to (a) start over or (b) end your adventure? ");
                                    scanf("%s", choice);
                                    if (strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                                        printf("\nYou start over and have even more amazing adventures!\n");
                                        adventure();
                                    } else {
                                        printf("\nYou end your adventure.\n");
                                        printf("\nCongratulations, %s! You have completed your happy adventure!\n", name);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}