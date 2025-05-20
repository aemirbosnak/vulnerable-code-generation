//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char command[50];
    int drone_x = 0;
    int drone_y = 0;
    int drone_z = 0;
    
    printf("\nWelcome to the Medieval Drone Remote Control System\n\n");
    printf("Use 'Takeoff' command to make the drone takeoff!\n");
    
    while (1) {
        printf("\nCommand: ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';
        
        if (strcmp(command, "Takeoff") == 0) {
            printf("\nThe drone takes off!\n");
            printf("Enter 'Up' or 'Down' command to change altitude\n");
            printf("Enter 'Forward', 'Backward', 'Left', or 'Right' command to move\n");
            printf("Enter 'Land' command to land the drone\n");
        }
        else if (strcmp(command, "Up") == 0) {
            drone_z++;
            printf("The drone ascends to altitude %d\n", drone_z);
        }
        else if (strcmp(command, "Down") == 0) {
            drone_z--;
            printf("The drone descends to altitude %d\n", drone_z);
        }
        else if (strcmp(command, "Forward") == 0) {
            drone_x++;
            printf("The drone moves forward to position (%d, %d, %d)\n", drone_x, drone_y, drone_z);
        }else if (strcmp(command, "Backward") == 0){
            drone_x--;
            printf("The drone moves backward to position (%d, %d, %d)\n", drone_x, drone_y, drone_z);            
         }else if (strcmp(command, "Left") == 0){
            drone_y--;
            printf("The drone moves left to position (%d, %d, %d)\n", drone_x, drone_y, drone_z);            
         }else if (strcmp(command, "Right") == 0){
            drone_y++;
            printf("The drone moves right to position (%d, %d, %d)\n", drone_x, drone_y, drone_z);            
         }else if (strcmp(command, "Land") == 0){
            printf("The drone lands safely!\n");
            break;
        }
        else {
            printf("Invalid command\n");
        }
    }

    printf("\nThank you for using the Medieval Drone Remote Control System!\n");
    return 0;
}