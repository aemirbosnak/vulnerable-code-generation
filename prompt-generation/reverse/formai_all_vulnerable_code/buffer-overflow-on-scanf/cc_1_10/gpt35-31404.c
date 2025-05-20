//FormAI DATASET v1.0 Category: Smart home automation ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>

/* The game is on! Time to solve a smart home robbery with code.*/

int main(){
    // Initializing the variables
    int rooms[5] = {1, 2, 3, 4, 5};
    int user_input;
    char user_name[20];

    printf("Welcome to your Smart Home. My name is Sherlock. What is your name? ");
    scanf("%s", user_name);
    printf("Hello %s, which room would you like to enter (1-5)? ", user_name);
    scanf("%d", &user_input);

    // Checking the input provided by the user
    if(user_input > 5 || user_input < 1){
        printf("Sorry %s, that room does not exist!\n", user_name);
    }
    else{
        printf("Access granted, %s!\n", user_name);
        printf("Entering room %d...\n", user_input);

        // Checking if the room is empty or not
        if(rooms[user_input-1] == 0){
            printf("This room is empty. No robbery here!\n");
        }
        else{
            printf("Oh no! This room has been robbed!\n");

            // Checking for evidence
            if(strstr(user_name, "sherlock") != NULL){
                printf("Wait a minute...I am Sherlock! I didn't rob this place!\n");
            }
            else{
                printf("Let me check for evidence...\n\n");

                // Simulating evidence collection
                printf("Collecting evidence...\n");
                printf("Found fingerprints on the door knob...\n");
                printf("Matched the fingerprints with the database...\n");
                printf("Suspect identified: %s\n", user_name);
                printf("You have been caught, %s! The police will be at your door shortly...\n", user_name);
            }
        }
    }

    return 0;
}