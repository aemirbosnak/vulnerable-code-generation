//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function for printing the menu
void print_menu(){
    printf("Welcome to Procedural Space Adventure Game\n\n");
    printf("1. Start the game\n");
    printf("2. Exit\n");
}

// function for generating random coordinates
int generate_coordinate(){
    srand(time(NULL));
    int coord = rand() % 11;
    return coord;
}

// function for checking if user reached the planet
int reached_planet(int x, int y, int planet_x, int planet_y){
    if(x == planet_x && y == planet_y){
        return 1;
    }
    return 0;
}

// function for printing the coordinates
void print_coordinates(int x, int y, int planet_x, int planet_y){
    printf("Your current coordinates: (%d,%d)\n", x, y);
    printf("Planet coordinates: (%d,%d)\n\n", planet_x, planet_y);
}

// main function
int main(){
    // initializing variables
    int choice, x = 0, y = 0, planet_x = 0, planet_y = 0, steps = 0;

    // loop for the menu
    do{
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                // generating the planet coordinates
                planet_x = generate_coordinate();
                planet_y = generate_coordinate();
                printf("Planet coordinates generated.\n\n");

                // loop for the game
                while(1){
                    // printing the coordinates and asking for the direction
                    print_coordinates(x, y, planet_x, planet_y);
                    printf("Enter direction (1-North, 2-East, 3-South, 4-West): ");
                    int direction;
                    scanf("%d", &direction);
                    steps++;
                    
                    // moving the user based on the direction
                    switch(direction){
                        case 1:
                            y++;
                            break;
                        case 2:
                            x++;
                            break;
                        case 3:
                            y--;
                            break;
                        case 4:
                            x--;
                            break;
                        default:
                            printf("Invalid direction.\n\n");
                            continue;
                    }
                    
                    // checking if user reached the planet
                    if(reached_planet(x, y, planet_x, planet_y)){
                        printf("Congratulations! You reached the planet in %d steps.\n\n", steps);
                        break;
                    }
                }
                break;
            case 2:
                printf("Exiting the game.");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }while(choice != 2);
    
    return 0;
}