//MISTRAL-7B DATASET v1.0 Category: Smart home automation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPLIANCES 10
#define APPLIANCE_NAME_LENGTH 20
#define USER_INPUT_LENGTH 10

typedef struct {
    char name[APPLIANCE_NAME_LENGTH];
    int state;
} Appliance;

Appliance appliances[MAX_APPLIANCES];

void init_appliances() {
    for (int i = 0; i < MAX_APPLIANCES; i++) {
        appliances[i].state = 0;
        printf("Enter name for appliance %d: ", i+1);
        fgets(appliances[i].name, APPLIANCE_NAME_LENGTH, stdin);
        appliances[i].name[strlen(appliances[i].name)-1] = '\0';
    }
}

void print_appliances() {
    printf("\nCurrent appliance state:\n");
    for (int i = 0; i < MAX_APPLIANCES; i++) {
        printf("%s: %s\n", appliances[i].name, (appliances[i].state == 0)?"OFF":"ON");
    }
}

void toggle_appliance(int appliance_index) {
    appliances[appliance_index].state = (appliances[appliance_index].state == 0)?1:0;
}

int main() {
    int num_appliances;
    char user_input[USER_INPUT_LENGTH];
    int appliance_index;

    init_appliances();
    print_appliances();

    while(1) {
        printf("\nEnter appliance index to toggle or type 'exit' to quit: ");
        fgets(user_input, USER_INPUT_LENGTH, stdin);
        user_input[strlen(user_input)-1] = '\0';

        if (strcmp(user_input, "exit") == 0) {
            break;
        }

        appliance_index = atoi(user_input);

        if (appliance_index < 0 || appliance_index >= MAX_APPLIANCES) {
            printf("Invalid appliance index\n");
            continue;
        }

        toggle_appliance(appliance_index);
        print_appliances();
    }

    return 0;
}