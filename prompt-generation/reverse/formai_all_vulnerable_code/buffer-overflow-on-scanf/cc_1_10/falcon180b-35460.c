//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[100];
    int status;
    int last_updated;
} device;

device devices[100];

void update_device(int index, int status) {
    devices[index].status = status;
    devices[index].last_updated = time(0);
}

void check_devices() {
    for (int i = 0; i < 100; i++) {
        if (devices[i].status == 1) {
            printf("Device %s is on.\n", devices[i].name);
        } else if (devices[i].status == 0) {
            printf("Device %s is off.\n", devices[i].name);
        } else {
            printf("Device %s is unknown.\n", devices[i].name);
        }
    }
}

int main() {
    int choice;
    do {
        printf("Smart Home Automation\n");
        printf("1. Turn on/off device\n");
        printf("2. Check devices\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter device name: ");
            scanf("%s", devices[0].name);
            printf("Enter status (1 for on, 0 for off): ");
            scanf("%d", &devices[0].status);
            update_device(0, devices[0].status);
        } else if (choice == 2) {
            check_devices();
        }
    } while (choice!= 3);

    return 0;
}