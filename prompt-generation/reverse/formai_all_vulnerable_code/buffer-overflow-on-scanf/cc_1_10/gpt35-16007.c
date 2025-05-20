//FormAI DATASET v1.0 Category: Memory management ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

int main(){

//Creating a memory palace for the user
void* memory_palace = malloc(30000);

//Letting the user decide which room to enter
printf("Welcome to your surreal memory palace. Which room would you like to enter? ");
int room_choice;
scanf("%d", &room_choice);

//Assigning sizes to different rooms based on user choice
int room_size;
switch(room_choice){
    case 1:
        room_size = 100;
        printf("You have entered Room 1, which is 100 bytes in size.\n");
        break;
    case 2:
        room_size = 200;
        printf("You have entered Room 2, which is 200 bytes in size.\n");
        break;
    case 3:
        room_size = 300;
        printf("You have entered Room 3, which is 300 bytes in size.\n");
        break;
    default:
        printf("Sorry, that room is unavailable.\n");
        exit(0);
}

//Allocating memory for user in room
void* user_room = (char*)memory_palace + (100 * (room_choice-1)); //Calculating the address of user room 
void* user_mem = malloc(room_size); // Allocating memory to user

//Updating memory palace map
printf("Updating memory palace map...\n");
printf("+----------+----------+----------+\n");
printf("|   Room 1  |   Room 2  |   Room 3  |\n");
printf("+----------+----------+----------+\n");
if(room_choice == 1){
    printf("|    X     |          |          |\n");
}
else if(room_choice == 2){
    printf("|          |    X     |          |\n");
}
else{
    printf("|          |          |    X     |\n");
}
printf("+----------+----------+----------+\n");

//Freeing up the memory
printf("Leaving the room and freeing up memory...\n");
free(user_mem);
printf("Memory has been freed.\n");

return 0;
}