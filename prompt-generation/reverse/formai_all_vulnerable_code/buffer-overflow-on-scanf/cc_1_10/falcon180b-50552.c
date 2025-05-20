//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int value;
} device;

int main() {
    int num_devices;
    char input[MAX_SIZE];
    device devices[MAX_SIZE];

    printf("Enter the number of devices: ");
    scanf("%d", &num_devices);

    for (int i = 0; i < num_devices; i++) {
        printf("Enter device name: ");
        scanf("%s", devices[i].name);
        printf("Enter device value: ");
        scanf("%d", &devices[i].value);
    }

    while (1) {
        printf("\nEnter command:\n");
        printf("1. Turn on/off device\n");
        printf("2. Set device value\n");
        printf("3. Exit\n");
        scanf("%s", input);

        if (strcmp(input, "1") == 0) {
            printf("Enter device name: ");
            scanf("%s", input);
            for (int i = 0; i < num_devices; i++) {
                if (strcmp(devices[i].name, input) == 0) {
                    printf("Enter device value (0 or 1): ");
                    scanf("%d", &devices[i].value);
                    break;
                }
            }
        } else if (strcmp(input, "2") == 0) {
            printf("Enter device name: ");
            scanf("%s", input);
            for (int i = 0; i < num_devices; i++) {
                if (strcmp(devices[i].name, input) == 0) {
                    printf("Enter new device value: ");
                    scanf("%d", &devices[i].value);
                    break;
                }
            }
        } else if (strcmp(input, "3") == 0) {
            exit(0);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}