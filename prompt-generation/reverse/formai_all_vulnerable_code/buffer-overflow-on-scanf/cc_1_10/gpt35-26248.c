//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char response;
    int random_number;
    
    srand(time(NULL));
    random_number = rand() % 10;     // Generate random number between 0 and 9
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Press 'y' to enter the house: ");
    scanf(" %c", &response);
    
    if (response == 'y') {
        printf("You enter the house...\n");
        printf("Suddenly, you hear creaking sounds coming from the floorboards beneath you.\n");
        printf("Press '1' to investigate the sound, press any other key to ignore it: ");
        scanf(" %c", &response);
        
        if (response == '1') {
            printf("You slowly make your way to the source of the sound and find yourself in a dark room.\n");
            printf("You hear breathing noises coming from the corner of the room...\n");
            printf("Press '2' to investigate the noise, press any other key to leave: ");
            scanf(" %c", &response);
            
            if (response == '2') {
                printf("You approach the corner of the room and find a ghostly figure staring back at you!\n");
            } else {
                printf("You quickly leave the room and head to the next area...\n");
            }
        } else {
            printf("You ignore the sound and continue exploring the house...\n");
        }
        
        printf("You arrive at a stairway leading to the basement. Do you want to descend? ");
        printf("Press '3' to descend the stairs, press any other key to stay on the main floor: ");
        scanf(" %c", &response);
        
        if (response == '3') {
            printf("You carefully descend the stairs, which groan under your weight.\n");
            printf("At the bottom of the stairway, you see a small flicker of light in the distance...\n");
            printf("Press '4' to investigate the light, press any other key to leave: ");
            scanf(" %c", &response);
            
            if (response == '4') {
                if (random_number < 5) {
                    printf("You find a candle burning on a pedestal, illuminating the area around it.\n");
                    printf("You take the candle and return to the main floor of the house...\n");
                } else {
                    printf("As you approach the light, you realize it is coming from a lantern held by a mysterious figure.\n");
                    printf("The figure grabs you and drags you into the darkness...\n");
                }
            } else {
                printf("You decide to leave the basement and return to the main floor of the house.\n");
            }
        } else {
            printf("You decide to stay on the main floor of the house.\n");
        }
    } else {
        printf("You chicken out and leave the area...\n");
    }
    
    printf("Thank you for playing the Haunted House Simulator!");
    
    return 0;
}