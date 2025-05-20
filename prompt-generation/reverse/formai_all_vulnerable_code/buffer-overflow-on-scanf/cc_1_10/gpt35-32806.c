//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Haunted House Simulator!");
    printf("\n\n");
    printf("You find yourself standing in front of an old, run-down haunted house.");
    printf("\n\n");
    printf("Do you dare enter? (yes/no)\n");
    
    char input[10];
    scanf("%s", input);
    
    if (strcmp(input, "yes") == 0) {
        printf("\nYou cautiously push open the creaky front door and step inside. The air is thick with musty odours and the only sound is the soft rustling of cobwebs.");
        printf("\nAs you make your way through the darkened hallway, you hear something moving in the shadows. Do you want to turn on your flashlight? (yes/no)\n");
        
        char input2[10];
        scanf("%s", input2);
        
        if (strcmp(input2, "yes") == 0) {
            printf("\nYou flick on your flashlight and shine it around the room. You see an old piano in the corner covered in dust and spider webs, and a strange mirror on the opposite wall.\n");
        } else {
            printf("\nYou decide to proceed without the flashlight and accidentally bump into something in the dark. Startled, you turn on the flashlight and see that it's just an old coat rack.\n");
        }
        
        printf("\nYou continue exploring the house and come across a staircase leading up to the second floor. Do you want to climb the stairs? (yes/no)\n");
        
        char input3[10];
        scanf("%s", input3);
        
        if (strcmp(input3, "yes") == 0) {
            printf("\nYou ascend the stairs and find yourself in a long hallway lined with doors. As you approach one of the doors, you hear faint whispers coming from the other side. Do you want to open the door? (yes/no)\n");
            
            char input4[10];
            scanf("%s", input4);
            
            if (strcmp(input4, "yes") == 0) {
                printf("\nYou slowly turn the handle and push open the door. Inside, you see a ghostly figure floating in the air, beckoning to you with a bony finger. You close the door quickly and run back downstairs, heart racing.\n");
            } else {
                printf("\nYou decide not to take any chances and head back downstairs.\n");
            }
        } else {
            printf("\nYou decide to explore the first floor some more.\n");
        }
        
        printf("\nAs you continue exploring, the air becomes colder and the whispers grow louder. Suddenly, you hear a loud crash from upstairs. Do you want to investigate? (yes/no)\n");
        
        char input5[10];
        scanf("%s", input5);
        
        if (strcmp(input5, "yes") == 0) {
            printf("\nYou cautiously climb the staircase again and follow the sound to a bedroom. Inside, you see a ghostly apparition tearing apart the room. You quickly turn and flee the haunted house, heart racing.\n");
        } else {
            printf("\nYou decide to leave the house without investigating any further.\n");
        }
        
        printf("\nYou make it back outside and breathe a sigh of relief. The haunted house simulator has come to an end.\n");
        
    } else {
        printf("\nYou turn and leave the haunted house without looking back. The simulator has come to an end.\n");
    }
    
    return 0;
}