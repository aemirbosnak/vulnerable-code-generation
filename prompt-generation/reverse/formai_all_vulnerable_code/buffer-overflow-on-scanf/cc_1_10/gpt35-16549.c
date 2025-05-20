//FormAI DATASET v1.0 Category: Smart home automation ; Style: secure
#include <stdio.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_NAME_LENGTH 20
#define MAX_PIN_LENGTH 10

struct device {
    char name[MAX_NAME_LENGTH];
    char pin[MAX_PIN_LENGTH];
    int state;
};

// Function to check if a pin is valid
int is_pin_valid(char pin[]) {
    // Check if pin is at least 4 characters long
    if (strlen(pin) < 4) {
        return 0;
    }
    
    // Check if pin contains only digits
    for (int i = 0; i < strlen(pin); i++) {
        if (!isdigit(pin[i])) {
            return 0;
        }
    }
    
    return 1;
}

// Function to authenticate user
int authenticate(char pin[]) {
    // Check if pin is valid
    if (!is_pin_valid(pin)) {
        return 0;
    }
    
    // Check if pin matches stored pin
    if (strcmp(pin, "1234") != 0) {
        return 0;
    }
    
    return 1;
}

// Function to turn device on/off
void toggle_device(struct device* d) {
    if (d->state == 0) {
        d->state = 1;
    } else {
        d->state = 0;
    }
}

// Main function
int main() {
    // Initialize devices
    struct device devices[MAX_DEVICES] = {
        {"Light", "1111", 0},
        {"Fan", "2222", 0},
        {"TV", "3333", 0},
        {"AC", "4444", 0},
        {"Oven", "5555", 0}
    };

    // Prompt user for pin
    char pin[MAX_PIN_LENGTH];
    printf("Enter your pin: ");
    scanf("%s", pin);

    // Authenticate user
    if (!authenticate(pin)) {
        printf("Invalid pin.\n");
        return 1;
    }

    // Show devices and their states
    printf("-------------------------\n");
    printf("Devices:\n");
    for (int i = 0; i < MAX_DEVICES; i++) {
        printf("%d. %s: %s\n", i+1, devices[i].name, devices[i].state ? "ON" : "OFF");
    }
    printf("-------------------------\n");

    // Prompt user for device number
    int device_num;
    printf("Enter device number to toggle: ");
    scanf("%d", &device_num);

    // Toggle device
    if (device_num < 1 || device_num > MAX_DEVICES) {
        printf("Invalid device number.\n");
        return 1;
    }
    toggle_device(&devices[device_num-1]);

    // Show updated device state
    printf("-------------------------\n");
    printf("%s toggled %s.\n", devices[device_num-1].name, devices[device_num-1].state ? "ON" : "OFF");
    printf("-------------------------\n");

    return 0;
}