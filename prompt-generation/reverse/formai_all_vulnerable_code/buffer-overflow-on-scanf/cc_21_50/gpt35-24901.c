//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You enter the house and the door suddenly slams shut behind you...\n");
    printf("You notice that there's no electricity in the house.\n");
    printf("You have a flashlight with some spare batteries.\n");
    printf("Press any key to continue...\n");
    getchar();
    system("clear");
    
    int ghostCount = rand() % 5 + 1;
    printf("You hear strange noises from the upstairs...\n");
    printf("It sounds like there are %d ghosts up there!\n", ghostCount);
    printf("You have to find a way to escape the house!\n");
    printf("Press any key to continue...\n");
    getchar();
    system("clear");
    
    int flashlightBattery = 100;
    int ghostHealth[5];
    for (int i = 0; i < ghostCount; i++) {
        ghostHealth[i] = rand() % 100 + 1;
    }
    
    printf("You are now on the ground floor.\n");
    printf("You can either go to the kitchen, living room or dining room!\n");
    printf("Where would you like to go? (1 for kitchen, 2 for living room, 3 for dining room):\n");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You enter the kitchen...\n");
        printf("You hear strange noises coming from the fridge...\n");
        printf("Do you want to open it? (y for yes, n for no):\n");
        char fridgeChoice;
        scanf(" %c", &fridgeChoice);
        if (fridgeChoice == 'y') {
            int ghostNumber = rand() % ghostCount;
            ghostHealth[ghostNumber] -= 20;
            printf("You see a ghost inside the fridge!\n");
            printf("You use your flashlight to attack the ghost!\n");
            printf("The ghost's health is now %d.\n", ghostHealth[ghostNumber]);
        } else {
            printf("You leave the fridge alone and go back to the ground floor!\n");
        }
    } else if (choice == 2) {
        printf("You enter the living room...\n");
        printf("You see a small table in the corner with a ouija board on it.\n");
        printf("Do you want to try it? (y for yes, n for no):\n");
        char ouijaChoice;
        scanf(" %c", &ouijaChoice);
        if (ouijaChoice == 'y') {
            int ghostNumber = rand() % ghostCount;
            ghostHealth[ghostNumber] -= 50;
            printf("You start communicating with the ghosts...\n");
            printf("Suddenly, a ghost appears in front of you!\n");
            printf("You use your flashlight to attack the ghost!\n");
            printf("The ghost's health is now %d.\n", ghostHealth[ghostNumber]);
        } else {
            printf("You leave the Ouija board and go back to the ground floor!\n");
        }
    } else if (choice == 3) {
        printf("You enter the dining room...\n");
        printf("You notice that there's a door that leads to the outside!\n");
        printf("However, there's a locked chest in the way.\n");
        printf("Do you want to try to open it? (y for yes, n for no):\n");
        char chestChoice;
        scanf(" %c", &chestChoice);
        if (chestChoice == 'y') {
            int ghostNumber = rand() % ghostCount;
            ghostHealth[ghostNumber] -= 80;
            printf("You successfully open the chest!\n");
            printf("Suddenly, a ghost appears in front of you!\n");
            printf("You use your flashlight to attack the ghost!\n");
            printf("The ghost's health is now %d.\n", ghostHealth[ghostNumber]);
        } else {
            printf("You leave the chest alone and go back to the ground floor!\n");
        }
    }
    
    printf("Press any key to continue...\n");
    getchar();
    system("clear");
    
    printf("You've explored the ground floor, but it's time to head upstairs!\n");
    printf("Press any key to continue...\n");
    getchar();
    system("clear");
    
    printf("You are now on the second floor.\n");
    printf("You can either go to the master bedroom, guest bedroom or bathroom!\n");
    printf("Where would you like to go? (1 for master bedroom, 2 for guest bedroom, 3 for bathroom):\n");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You enter the master bedroom...\n");
        if (ghostCount >= 1) {
            printf("You see a ghost standing in front of you!\n");
            printf("You use your flashlight to attack the ghost!\n");
            ghostHealth[0] -= 100;
            printf("The ghost's health is now %d.\n", ghostHealth[0]);
            if (ghostHealth[0] <= 0) {
                ghostCount--;
                printf("You've defeated the ghost!\n");
            }
        } else {
            printf("There's nothing worth exploring in the master bedroom for now!\n");
        }
    } else if (choice == 2) {
        printf("You enter the guest bedroom...\n");
        if (ghostCount >= 2) {
            printf("You see two ghosts standing in front of you!\n");
            printf("You use your flashlight to attack the ghosts!\n");
            ghostHealth[0] -= 50;
            ghostHealth[1] -= 50;
            printf("The first ghost's health is now %d.\n", ghostHealth[0]);
            printf("The second ghost's health is now %d.\n", ghostHealth[1]);
            if (ghostHealth[0] <= 0 && ghostHealth[1] <= 0) {
                ghostCount -= 2;
                printf("You've defeated both ghosts!\n");
            } else if (ghostHealth[0] <= 0) {
                ghostCount--;
                printf("You've defeated the first ghost!\n");
            } else if (ghostHealth[1] <= 0) {
                ghostCount--;
                printf("You've defeated the second ghost!\n");
            }
        } else if (ghostCount == 1) {
            printf("You see a ghost standing in front of you!\n");
            printf("You use your flashlight to attack the ghost!\n");
            ghostHealth[0] -= 100;
            printf("The ghost's health is now %d.\n", ghostHealth[0]);
            if (ghostHealth[0] <= 0) {
                ghostCount--;
                printf("You've defeated the ghost!\n");
            }
        } else {
            printf("There's nothing worth exploring in the guest bedroom for now!\n");
        }
    } else if (choice == 3) {
        printf("You enter the bathroom...\n");
        if (ghostCount >= 3) {
            printf("You see three ghosts standing in front of you!\n");
            printf("You use your flashlight to attack the ghosts!\n");
            ghostHealth[0] -= 20;
            ghostHealth[1] -= 20;
            ghostHealth[2] -= 20;
            printf("The first ghost's health is now %d.\n", ghostHealth[0]);
            printf("The second ghost's health is now %d.\n", ghostHealth[1]);
            printf("The third ghost's health is now %d.\n", ghostHealth[2]);
            if (ghostHealth[0] <= 0 && ghostHealth[1] <= 0 && ghostHealth[2] <= 0) {
                ghostCount -= 3;
                printf("You've defeated all three ghosts!\n");
            } else if (ghostHealth[0] <= 0) {
                ghostCount--;
                printf("You've defeated the first ghost!\n");
            } else if (ghostHealth[1] <= 0) {
                ghostCount--;
                printf("You've defeated the second ghost!\n");
            } else if (ghostHealth[2] <= 0) {
                ghostCount--;
                printf("You've defeated the third ghost!\n");
            }
        } else if (ghostCount == 2) {
            printf("You see two ghosts standing in front of you!\n");
            printf("You use your flashlight to attack the ghosts!\n");
            ghostHealth[0] -= 50;
            ghostHealth[1] -= 50;
            printf("The first ghost's health is now %d.\n", ghostHealth[0]);
            printf("The second ghost's health is now %d.\n", ghostHealth[1]);
            if (ghostHealth[0] <= 0 && ghostHealth[1] <= 0) {
                ghostCount -= 2;
                printf("You've defeated both ghosts!\n");
            } else if (ghostHealth[0] <= 0) {
                ghostCount--;
                printf("You've defeated the first ghost!\n");
            } else if (ghostHealth[1] <= 0) {
                ghostCount--;
                printf("You've defeated the second ghost!\n");
            }
        } else if (ghostCount == 1) {
            printf("You see a ghost standing in front of you!\n");
            printf("You use your flashlight to attack the ghost!\n");
            ghostHealth[0] -= 100;
            printf("The ghost's health is now %d.\n", ghostHealth[0]);
            if (ghostHealth[0] <= 0) {
                ghostCount--;
                printf("You've defeated the ghost!\n");
            }
        } else {
            printf("There's nothing worth exploring in the bathroom for now!\n");
        }
    }
    
    printf("Press any key to continue...\n");
    getchar();
    system("clear");
    
    if (ghostCount == 0) {
        printf("You've successfully defeated all the ghosts in the house!\n");
        printf("You quickly escape the house and make it out in one piece!\n");
    } else {
        printf("Oh no! There are still %d ghosts left in the house!\n", ghostCount);
        printf("You need to keep exploring to defeat them all!\n");
    }
    
    return 0;
}