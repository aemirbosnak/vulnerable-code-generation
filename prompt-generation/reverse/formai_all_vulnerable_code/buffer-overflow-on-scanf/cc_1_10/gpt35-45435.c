//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_COMMAND_LENGTH 50
#define MAX_DRONE_NUMBER 10

char drone_ip_addresses[MAX_DRONE_NUMBER][20] = {"192.168.0.1", "192.168.0.2", "192.168.0.3", "192.168.0.4", "192.168.0.5", "192.168.0.6", "192.168.0.7", "192.168.0.8", "192.168.0.9", "192.168.0.10"};
int drone_coordinates[MAX_DRONE_NUMBER][2] = {{0,0}, {1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6}, {7,7}, {8,8}, {9,9}};
int drone_battery_level[MAX_DRONE_NUMBER] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};

void print_menu()
{
    printf("Welcome to the drone remote control system!\n");
    printf("Commands:\n");
    printf("takeoff [drone number]\n");
    printf("land [drone number]\n");
    printf("move [drone number] [x-coordinate] [y-coordinate]\n");
    printf("status [drone number]\n");
    printf("exit\n");
}

void takeoff(int drone_number)
{
    printf("Drone %d is taking off\n", drone_number);
}

void land(int drone_number)
{
    printf("Drone %d is landing\n", drone_number);
}

void move(int drone_number, int x, int y)
{
    printf("Drone %d is moving to coordinates (%d,%d)\n", drone_number, x, y);
    drone_coordinates[drone_number-1][0] = x;
    drone_coordinates[drone_number-1][1] = y;
}

void status(int drone_number)
{
    printf("Drone %d status:\n", drone_number);
    printf("IP address: %s\n", drone_ip_addresses[drone_number-1]);
    printf("Coordinates: (%d,%d)\n", drone_coordinates[drone_number-1][0], drone_coordinates[drone_number-1][1]);
    printf("Battery level: %d%%\n", drone_battery_level[drone_number-1]);
}

int main()
{
    char command[MAX_COMMAND_LENGTH];
    int drone_number, x, y;
    while(1){
        print_menu();
        printf("Enter command: ");
        scanf("%s", command);
        if(strcmp(command, "exit") == 0){
            break;
        }
        else if(strcmp(command, "takeoff") == 0){
            scanf("%d", &drone_number);
            takeoff(drone_number);
        }
        else if(strcmp(command, "land") == 0){
            scanf("%d", &drone_number);
            land(drone_number);
        }
        else if(strcmp(command, "move") == 0){
            scanf("%d %d %d", &drone_number, &x, &y);
            move(drone_number, x, y);
        }
        else if(strcmp(command, "status") == 0){
            scanf("%d", &drone_number);
            status(drone_number);
        }
        else{
            printf("Invalid command, try again.\n");
        }
    }
    return 0;
}