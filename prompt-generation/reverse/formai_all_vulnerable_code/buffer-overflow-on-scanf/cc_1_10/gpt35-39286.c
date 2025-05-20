//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_DEVICES 10

typedef struct {
    char name[20];
    double frequency;
    int signal_strength;
} Device;

void to_lower(char *str) {
    int i;
    for(i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

bool compare_devices(Device a, Device b) {
    return strcmp(a.name, b.name) == 0 && a.frequency == b.frequency && a.signal_strength == b.signal_strength;
}

bool is_device_in_list(Device device, Device devices[MAX_DEVICES], int num_devices) {
    int i;
    for(i = 0; i < num_devices; i++) {
        if(compare_devices(device, devices[i])) {
            return true;
        }
    }

    return false;
}

void add_device(Device device, Device devices[MAX_DEVICES], int *num_devices) {
    devices[*num_devices] = device;
    *num_devices += 1;
}

void print_devices(Device devices[MAX_DEVICES], int num_devices) {
    int i;
    printf("Wireless devices found:\n");
    for(i = 0; i < num_devices; i++) {
        printf("%s\n", devices[i].name);
        printf("Frequency: %.2f GHz\n", devices[i].frequency);
        printf("Signal strength: %d dBm\n\n", devices[i].signal_strength);
    }
}

void scan_network(char *output) {
    //simulate a wireless network scan
    strcpy(output, "Network scanned.\n");

    int num_devices = 0;
    Device devices[MAX_DEVICES];

    Device device1 = {"Apple TV", 5.0, -25};
    add_device(device1, devices, &num_devices);

    Device device2 = {"Samsung Smart TV", 2.4, -30};
    add_device(device2, devices, &num_devices);

    Device device3 = {"HP Printer", 2.4, -40};
    add_device(device3, devices, &num_devices);

    Device device4 = {"LG Smart TV", 5.0, -35};
    add_device(device4, devices, &num_devices);

    Device device5 = {"Dell Laptop", 2.4, -45};
    add_device(device5, devices, &num_devices);

    Device device6 = {"Sony PlayStation", 2.4, -50};
    add_device(device6, devices, &num_devices);

    Device device7 = {"Google Chromecast", 5.0, -55};
    add_device(device7, devices, &num_devices);

    Device device8 = {"Amazon Echo", 2.4, -60};
    add_device(device8, devices, &num_devices);

    Device device9 = {"Microsoft Surface", 5.0, -65};
    add_device(device9, devices, &num_devices);

    Device device10 = {"Nest Thermostat", 2.4, -70};
    add_device(device10, devices, &num_devices);

    print_devices(devices, num_devices);
}

int main() {
    char output[100];
    char command[20];

    printf("---Wireless Network Scanner---\n");
    printf("Type \"scan\" to scan the wireless network or \"exit\" to quit.\n");

    while(true) {
        printf(">");
        scanf("%s", command);
        to_lower(command);

        if(strcmp(command, "scan") == 0) {
            scan_network(output);
            printf("%s", output);
        }
        else if(strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}