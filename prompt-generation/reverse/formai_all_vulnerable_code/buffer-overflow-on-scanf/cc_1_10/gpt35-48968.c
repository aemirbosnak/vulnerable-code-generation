//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wait(int seconds){
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}

struct Spaceship {
    char name[20];
    int fuel;
    int health;
    int laser_power;
    int shield_power;
};

void travel(struct Spaceship* spaceship, int distance){
    spaceship->fuel -= distance;
    spaceship->health -= distance / 10;
    spaceship->laser_power -= distance / 5;
    spaceship->shield_power -= distance / 2;
}

void refuel(struct Spaceship* spaceship){
    int fuel_amount = 100 - spaceship->fuel;
    spaceship->fuel += fuel_amount;
    printf("Refuelled %d fuel\n", fuel_amount);
}

void repair(struct Spaceship* spaceship){
    int health_points = 100 - spaceship->health;
    spaceship->health += health_points;
    printf("Repaired %d health points\n", health_points);
}

void upgrade(struct Spaceship* spaceship){
    spaceship->laser_power += 10;
    spaceship->shield_power += 10;
    printf("Upgraded laser_power and shield_power by 10 each\n");
}

int main() {
    struct Spaceship spaceship = {"USS Enterprise", 100, 100, 50, 50};
    int distance = 0;
    
    printf("Welcome to Procedural Space Adventure!\n");
    
    while(1){
        printf("\n===== Options =====\n");
        printf("1. Travel to a planet\n");
        printf("2. Refuel spaceship\n");
        printf("3. Repair spaceship\n");
        printf("4. Upgrade spaceship\n");
        printf("5. Quit game\n");
        printf("===================\n");
        printf("Select an option:");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter distance to planet:");
                scanf("%d", &distance);
                travel(&spaceship, distance);
                printf("Travelling to planet...\n");
                wait(2);
                printf("Arrived at planet %d light years away\n", distance);
                break;
            case 2:
                refuel(&spaceship);
                break;
            case 3:
                repair(&spaceship);
                break;
            case 4:
                upgrade(&spaceship);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option selected. Please try again.\n");
        }
    }
    return 0;
}