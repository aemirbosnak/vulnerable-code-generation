//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random numbers
int random_number(int min_num, int max_num){
    return (rand() % (max_num - min_num + 1)) + min_num;
}

//Function to display the menu
void display_menu(){
    printf("---------------------------\n");
    printf("    Remote Control Vehicle\n");
    printf("---------------------------\n");
    printf("Your options are:\n");
    printf("1. Turn Left\n");
    printf("2. Turn Right\n");
    printf("3. Move Forward\n");
    printf("4. Move Backward\n");
    printf("5. Stop\n");
    printf("6. Exit\n");
}

int main(){

    int option, direction = 0, position = 0;

    //Seed the random number generator
    srand(time(0));

    printf("Welcome to Remote Control Vehicle Simulation!\n");

    //Display the menu
    display_menu();

    //Loop until the user chooses to exit
    while (1) {

        //Get user input
        printf("Enter your choice: ");
        scanf("%d", &option);

        //Process user input
        switch (option) {
            case 1:
                printf("Turning left...\n");
                direction--;
                break;
            case 2:
                printf("Turning right...\n");
                direction++;
                break;
            case 3:
                printf("Moving forward...\n");
                position += random_number(1, 10);
                break;
            case 4:
                printf("Moving backward...\n");
                position -= random_number(1, 10);
                break;
            case 5:
                printf("Stopping...\n");
                break;
            case 6:
                printf("Exiting simulation. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }

        //Output vehicle position and direction
        printf("Current position: %d\n", position);
        printf("Current direction: %d degrees\n", direction*30);
        printf("\n");

        //Display the menu again
        display_menu();
    }

    return 0;
}