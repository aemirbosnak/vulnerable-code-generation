//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// defining global variables
int x,y;

// function to update the current location of the user
void update_location(int a, int b){
    x = a;
    y = b;
}

// function to give directions to the user to reach the desired location
void get_directions(int dest_x, int dest_y){
    printf("Welcome to GPS Navigation Simulation!\n");
    printf("Your current location is: (%d, %d)\n", x, y);
    printf("Your destination is: (%d, %d)\n", dest_x, dest_y);
    
    if(x == dest_x && y == dest_y){
        printf("You are already at the destination!\n");
    }
    else{
        printf("Follow the below directions to reach your destination:\n");
        while(x != dest_x || y != dest_y){
            if(x < dest_x && y < dest_y){
                printf("Move NE. ");
                x++;
                y++;
            }
            else if(x < dest_x && y == dest_y){
                printf("Move E. ");
                x++;
            }
            else if(x < dest_x && y > dest_y){
                printf("Move SE. ");
                x++;
                y--;
            }
            else if(x == dest_x && y < dest_y){
                printf("Move N. ");
                y++;
            }
            else if(x == dest_x && y > dest_y){
                printf("Move S. ");
                y--;
            }
            else if(x > dest_x && y < dest_y){
                printf("Move NW. ");
                x--;
                y++;
            }
            else if(x > dest_x && y == dest_y){
                printf("Move W. ");
                x--;
            }
            else{
                printf("Move SW. ");
                x--;
                y--;
            }
            printf("Current location: (%d, %d)\n", x, y);
        }
        printf("You have reached your destination!\n");
    }
}

// main function
int main(){
    int dest_x, dest_y;
    printf("Enter your current location (x y): ");
    scanf("%d %d", &x, &y);
    printf("Enter your destination location (x y): ");
    scanf("%d %d", &dest_x, &dest_y);
    update_location(x, y);
    get_directions(dest_x, dest_y);
    return 0;
}