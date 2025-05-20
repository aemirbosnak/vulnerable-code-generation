//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//structure of the elevator
struct Elevator{
    int floor;
    int capacity;
}elevator;

//structure of the player
struct Player{
    char name[50];
    int current_floor;
    int destination_floor;
}player[5];

//function to get the random floor
int get_random_floor(){
    int floor = rand()%10 + 1;
    while(floor == elevator.floor)
        floor = rand()%10 + 1;
    return floor;
}

int main(){
    int i, j, num_players;
    srand(time(0));

    printf("*** Elevator Simulation ***\n\n");

    //initialize the elevator
    elevator.floor = 1;
    elevator.capacity = 5;

    //get the number of players
    printf("Enter the number of players (max 5): ");
    scanf("%d", &num_players);

    //initialize the players
    for(i=0; i<num_players; i++){
        printf("Enter the name of player %d: ", i+1);
        scanf("%s", player[i].name);
        player[i].current_floor = 1;
        player[i].destination_floor = get_random_floor();
    }

    //run the simulation
    for(i=1; i<=10; i++){
        printf("\n==============================\n");
        printf("Elevator is currently at floor %d\n", elevator.floor);

        //check if there are any players at the current floor
        int num_players_in_floor = 0;
        for(j=0; j<num_players; j++){
            if(player[j].current_floor == elevator.floor){
                num_players_in_floor++;
            }
        }

        //check if the elevator is full
        if(elevator.capacity == 0){
            printf("Elevator is full!\n");
        }
        else{
            //if there are players in the current floor and there is space in the elevator, ask them to board
            if(num_players_in_floor > 0){
                printf("Players at the current floor:\n");
                printf("Name\tDestination Floor\n");
                for(j=0; j<num_players; j++){
                    if(player[j].current_floor == elevator.floor){
                        printf("%s\t%d\n", player[j].name, player[j].destination_floor);
                    }
                }

                printf("Enter the number of players to board (max %d): ", elevator.capacity);
                int num_board;
                scanf("%d", &num_board);
                if(num_board > elevator.capacity){
                    num_board = elevator.capacity;
                }
                elevator.capacity -= num_board;

                printf("Enter the indices of the players to board: ");
                int player_index;
                for(j=0; j<num_board; j++){
                    scanf("%d", &player_index);
                    player[player_index].current_floor = -1; //mark the player as boarded
                }
            }
        }

        //move the elevator to the next floor
        if(i < 10){
            printf("Enter 0 to stay at the same floor or 1 to move to the next floor: ");
            int move;
            scanf("%d", &move);

            if(move == 1){
                elevator.floor++;
            }
        }

        //let the boarded players select the destination floor
        for(j=0; j<num_players; j++){
            if(player[j].current_floor == -1){
                printf("Player %s, enter your destination floor: ", player[j].name);
                int floor;
                scanf("%d", &floor);
                player[j].destination_floor = floor;
                player[j].current_floor = floor;
            }
        }

        //check if any players have reached their destination
        printf("Players who have reached their destination:\n");
        for(j=0; j<num_players; j++){
            if(player[j].current_floor == elevator.floor){
                printf("%s\n", player[j].name);
                elevator.capacity++;
                player[j].current_floor = 0; //let the player leave the elevator
            }
        }
        printf("==============================\n");
    }

    return 0;
}