//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_DESCRIPTION_LENGTH 100

typedef struct Room_t Room;

struct Room_t{
    char description[MAX_DESCRIPTION_LENGTH];
    int exits[MAX_ROOMS];
};

void init_rooms(Room* rooms){
    // Initialize rooms with random descriptions
    char *descriptions[] = {"A spooky room with cobweb covered furniture", 
                            "A dimly lit hallway that echoes with every step",
                            "A dusty attic filled with old trunks and singed curtains",
                            "A damp cellar with water droplets echoing throughout",
                            "A cluttered library with dusty stacks of books",
                            "A gloomy bedroom with a lumpy bed and peeling wallpaper",
                            "A creepy dining room with dusty cobwebs and a long, dark table",
                            "A dark hallway with flickering lights and creaking floorboards",
                            "An old bathroom with rusted pipes and cracked tiles",
                            "A chilling music room with an ominous piano and eerie sounds"};
    srand(time(NULL));
    for(int i=0; i<MAX_ROOMS; i++){
        strcpy(rooms[i].description, descriptions[rand()%10]);
        for(int j=0; j<MAX_ROOMS; j++){
            rooms[i].exits[j] = (rand()%2==0)? 1:0;
        }
    }
}

void print_room_description(Room* room){
    // Print room description and exits
    printf("You are in %s.\n", room->description);
    printf("Exits: ");
    for(int i=0; i<MAX_ROOMS; i++){
        if(room->exits[i]){
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(){
    Room rooms[MAX_ROOMS];
    init_rooms(rooms);
    int current_room = rand()%MAX_ROOMS;
    printf("Welcome to the Haunted House Simulator.\n");
    while(1){
        print_room_description(&rooms[current_room]);
        int input;
        printf("Where do you want to go? ");
        scanf("%d", &input);
        if(input>=0 && input<MAX_ROOMS && rooms[current_room].exits[input]){
            printf("You move to room %d.\n", input);
            current_room = input;
        }
        else{
            printf("Sorry, you cannot go that way.\n");
        }
    }
    return 0;
}