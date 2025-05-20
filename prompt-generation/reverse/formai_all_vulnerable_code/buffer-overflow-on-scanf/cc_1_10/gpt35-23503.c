//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define FLOORS 5
#define MEDIEVAL_GREETINGS "Greetings, kind sir/madam. Welcome to the medieval elevator!"

int current_floor = 1;

void medieval_greetings(){
    printf("%s\n", MEDIEVAL_GREETINGS);
}

void wait_for_enter(){
    printf("Press Enter to continue...");
    getchar();
}

void goto_floor(int floor_number){
    if(floor_number <= 0 || floor_number > FLOORS){
        printf("Invalid floor selected!\n");
        return;
    }

    if(floor_number > current_floor){
        printf("Ascending...\n");
        while(floor_number > current_floor){
            printf("Elevator is at floor: %d\n", current_floor++);
        }
    }
    else if(floor_number < current_floor){
        printf("Descending...\n");
        while(floor_number < current_floor){
            printf("Elevator is at floor: %d\n", current_floor--);
        }
    }
    printf("You have reached floor: %d\n", current_floor);
}

int get_random_floor(){
    int random_floor;
    srand(time(NULL));
    random_floor = rand() % FLOORS + 1;
    return random_floor;
}

int main(){
    medieval_greetings();
    wait_for_enter();

    int option;
    do{
        system("clear");
        printf("Current Floor: %d\n", current_floor);
        printf("1. Select floor\n2. Random floor\n3. Exit\n");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter floor number: ");
                int floor_number;
                scanf("%d", &floor_number);
                goto_floor(floor_number);
                wait_for_enter();
                break;
            case 2:
                printf("You have selected a random floor!\n");
                int random_floor = get_random_floor();
                goto_floor(random_floor);
                wait_for_enter();
                break;
            case 3:
                printf("Thank you for using the medieval elevator. We hope to see you again soon!\n");
                break;
            default:
                printf("Invalid option selected!\n");
                wait_for_enter();
        }
    } while(option != 3);

    return 0;
}