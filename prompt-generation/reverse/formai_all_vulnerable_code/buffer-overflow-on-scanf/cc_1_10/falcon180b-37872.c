//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_COMMANDS 50
#define MAX_COMMAND_LENGTH 50
#define MAX_DEVICE_NAME_LENGTH 20

typedef struct device{
    char name[MAX_DEVICE_NAME_LENGTH];
    char on_command[MAX_COMMAND_LENGTH];
    char off_command[MAX_COMMAND_LENGTH];
}device;

void execute_command(char* command){
    system(command);
}

void turn_on_device(device* device){
    execute_command(device->on_command);
}

void turn_off_device(device* device){
    execute_command(device->off_command);
}

int main(){
    device devices[MAX_COMMANDS];
    int num_devices;
    char input[MAX_COMMAND_LENGTH];

    printf("Enter number of devices: ");
    scanf("%d",&num_devices);

    printf("Enter device information:\n");
    for(int i=0;i<num_devices;i++){
        printf("Enter device name: ");
        scanf("%s",devices[i].name);
        printf("Enter on command: ");
        scanf("%s",devices[i].on_command);
        printf("Enter off command: ");
        scanf("%s",devices[i].off_command);
    }

    while(1){
        printf("Enter command: ");
        scanf("%s",input);
        for(int i=0;i<num_devices;i++){
            if(strcmp(input,devices[i].name)==0){
                printf("Turning on %s\n",devices[i].name);
                turn_on_device(&devices[i]);
            }
            else if(strcmp(input,devices[i].off_command)==0){
                printf("Turning off %s\n",devices[i].name);
                turn_off_device(&devices[i]);
            }
        }
    }

    return 0;
}