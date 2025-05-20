//FormAI DATASET v1.0 Category: Smart home automation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct device {
    char name[20];
    int status;
};

int main() {
    struct device devices[10];
    char input[20];
    int i = 0;
    int j;
    int num_devices = 0;

    printf("Welcome to your Smart Home Automation System!\n");

    while (1) {
        printf("Enter the name of your device (or 'exit' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }
        else {
            strcpy(devices[num_devices].name, input);
            devices[num_devices].status = 0;
            num_devices++;
        }
    }

    printf("\nYour devices: \n");
    for (i = 0; i < num_devices; i++) {
        printf("%d. %s - %s\n", i+1, devices[i].name, (devices[i].status == 0 ? "off" : "on"));
    }

    printf("\nWhich device would you like to turn on or off? ");
    scanf("%s", input);

    for (j = 0; j < num_devices; j++) {
        if (strcmp(devices[j].name, input) == 0) {
            devices[j].status = !devices[j].status;
            printf("%s is now %s\n", devices[j].name, (devices[j].status == 0 ? "off" : "on"));
            break;
        }
    }

    printf("\nYour devices: \n");
    for (i = 0; i < num_devices; i++) {
        printf("%d. %s - %s\n", i+1, devices[i].name, (devices[i].status == 0 ? "off" : "on"));
    }

    return 0;
}