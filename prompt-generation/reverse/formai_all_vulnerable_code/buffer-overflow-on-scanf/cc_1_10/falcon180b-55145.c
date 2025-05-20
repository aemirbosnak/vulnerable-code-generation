//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the maximum number of devices that can be controlled
#define MAX_DEVICES 10

// Define the device structure
typedef struct {
    char name[20];
    int status;
} device_t;

// Define the thread data structure
typedef struct {
    device_t *devices;
    int num_devices;
} thread_data_t;

// Function to turn on/off a device
void control_device(device_t *device) {
    if (device->status == 0) {
        printf("Turning on %s\n", device->name);
        device->status = 1;
    } else {
        printf("Turning off %s\n", device->name);
        device->status = 0;
    }
}

// Function executed by each thread
void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int i;

    // Loop through all devices and control them
    for (i = 0; i < data->num_devices; i++) {
        control_device(&data->devices[i]);
    }

    return NULL;
}

// Main function
int main() {
    pthread_t threads[MAX_DEVICES];
    device_t devices[MAX_DEVICES];
    thread_data_t thread_data[MAX_DEVICES];
    int i, num_devices;

    // Initialize devices
    num_devices = 0;
    printf("Enter the number of devices (max %d): ", MAX_DEVICES);
    scanf("%d", &num_devices);

    printf("Enter the device names and statuses (on/off):\n");
    for (i = 0; i < num_devices; i++) {
        scanf("%s %d", devices[i].name, &devices[i].status);
    }

    // Create one thread per device
    for (i = 0; i < num_devices; i++) {
        thread_data[i].devices = devices;
        thread_data[i].num_devices = num_devices;
        pthread_create(&threads[i], NULL, thread_func, &thread_data[i]);
    }

    // Join all threads
    for (i = 0; i < num_devices; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}