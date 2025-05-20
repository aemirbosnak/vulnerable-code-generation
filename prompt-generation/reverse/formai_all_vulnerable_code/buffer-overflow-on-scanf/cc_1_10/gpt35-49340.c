//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

//function to generate a random number between min and max (inclusive)
int randInRange(int min, int max){
    return rand() % (max - min + 1) + min;
}

//function to simulate a haunted house with given number of rooms and ghosts
void simulateHauntedHouse(int numRooms, int numGhosts){
    //initialize random number generator
    srand(time(NULL));
    
    //initialize array to store if each room has been visited or not
    int visitedRooms[numRooms];
    for(int i=0; i<numRooms; i++){
        visitedRooms[i] = 0;
    }
    
    //generate array to store location of each ghost
    int ghostLocations[numGhosts];
    for(int i=0; i<numGhosts; i++){
        ghostLocations[i] = randInRange(0, numRooms-1);
    }
    
    //start simulation
    int currentRoom = 0;
    visitedRooms[0] = 1;
    printf("You are in room %d.\n", currentRoom+1);
    int numVisitedRooms = 1;
    while(numVisitedRooms < numRooms){
        //check if there are ghosts in current room
        int numGhostsInRoom = 0;
        for(int i=0; i<numGhosts; i++){
            if(ghostLocations[i] == currentRoom){
                numGhostsInRoom++;
            }
        }
        
        //print number of ghosts in room
        if(numGhostsInRoom == 0){
            printf("There are no ghosts in this room.\n");
        }else if(numGhostsInRoom == 1){
            printf("There is 1 ghost in this room.\n");
        }else{
            printf("There are %d ghosts in this room.\n", numGhostsInRoom);
        }
        
        //check if all rooms have been visited
        if(numVisitedRooms == numRooms){
            printf("Congratulations! You have visited all the rooms and escaped the haunted house.\n");
            return;
        }
        
        //prompt user to choose next room
        printf("Which room do you want to go next? (Enter room number)\n");
        int nextRoom;
        scanf("%d", &nextRoom);
        nextRoom--;
        if(nextRoom < 0 || nextRoom >= numRooms){
            printf("Invalid room number. Please try again.\n");
            continue;
        }
        if(visitedRooms[nextRoom]){
            printf("You have already visited this room. Please choose another room.\n");
            continue;
        }
        
        //move to next room and mark as visited
        currentRoom = nextRoom;
        visitedRooms[currentRoom] = 1;
        numVisitedRooms++;
        printf("You are in room %d.\n", currentRoom+1);
    }
    
    //if all rooms have been visited but ghosts are still present
    printf("You have visited all the rooms, but there are still ghosts in the haunted house.\n");
    printf("You have been haunted forever!\n");
}

int main(){
    printf("Welcome to the Haunted House Simulator!\n");
    printf("How many rooms does the haunted house have? (Enter a number)\n");
    int numRooms;
    scanf("%d", &numRooms);
    if(numRooms < 1){
        printf("Invalid number of rooms. Please try again.\n");
        return 0;
    }
    
    printf("How many ghosts are in the haunted house? (Enter a number between 1 and %d)\n", MAX_GHOSTS);
    int numGhosts;
    scanf("%d", &numGhosts);
    if(numGhosts < 1 || numGhosts > MAX_GHOSTS){
        printf("Invalid number of ghosts. Please try again.\n");
        return 0;
    }
    
    simulateHauntedHouse(numRooms, numGhosts);
    
    return 0;
}