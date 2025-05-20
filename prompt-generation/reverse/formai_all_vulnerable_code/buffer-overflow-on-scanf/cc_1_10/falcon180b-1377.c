//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10
#define MAX_SENSOR_READINGS 10

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int arguments[MAX_ARGUMENTS];
    int num_arguments;
    float sensor_readings[MAX_SENSOR_READINGS];
    int num_sensor_readings;
} Command;

int parse_command(char* input, Command* command) {
    int i = 0;
    char* token = strtok(input, " ");
    while(token!= NULL && i < MAX_COMMAND_LENGTH) {
        strcpy(command->command, token);
        i++;
        token = strtok(NULL, " ");
    }
    command->num_arguments = i;
    return 0;
}

int parse_arguments(char* input, int* arguments) {
    int i = 0;
    char* token = strtok(input, " ");
    while(token!= NULL && i < MAX_ARGUMENTS) {
        arguments[i] = atoi(token);
        i++;
        token = strtok(NULL, " ");
    }
    return i;
}

int parse_sensor_readings(char* input, float* readings) {
    int i = 0;
    char* token = strtok(input, " ");
    while(token!= NULL && i < MAX_SENSOR_READINGS) {
        readings[i] = atof(token);
        i++;
        token = strtok(NULL, " ");
    }
    return i;
}

int main() {
    Command command;
    char input[MAX_COMMAND_LENGTH];
    while(1) {
        printf("Enter command: ");
        scanf("%s", input);
        parse_command(input, &command);
        switch(command.num_arguments) {
            case 0:
                printf("Invalid command.\n");
                break;
            case 1:
                if(strcmp(command.command, "light") == 0) {
                    printf("Light turned on.\n");
                } else if(strcmp(command.command, "light_off") == 0) {
                    printf("Light turned off.\n");
                } else {
                    printf("Invalid command.\n");
                }
                break;
            case 2:
                if(strcmp(command.command, "temperature") == 0) {
                    printf("Temperature: %f\n", command.sensor_readings[0]);
                } else {
                    printf("Invalid command.\n");
                }
                break;
            default:
                printf("Invalid command.\n");
        }
    }
    return 0;
}