//FormAI DATASET v1.0 Category: Smart home automation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define a structure to hold the smart home device information
typedef struct smart_dev {
    char name[20];
    char category[20];
    int status;
} smart_dev;

//declare function prototypes
void display_menu();
void add_device(smart_dev *devices, int count);
void remove_device(smart_dev *devices, int *count);
void toggle_device_status(smart_dev *devices, int count);
void display_devices(smart_dev *devices, int count);

int main() {
    //declare variables
    int choice, count = 0;
    smart_dev *devices = NULL;
    
    //display menu and get user choice
    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        //compare user choice with case options
        switch (choice) {
            case 1:
                add_device(devices, count);
                count++; //increment device count after adding a device
                break;
            case 2:
                remove_device(devices, &count);
                break;
            case 3:
                toggle_device_status(devices, count);
                break;
            case 4:
                display_devices(devices, count);
                break;
            case 5:
                printf("\nGoodbye!");
                break;
            default:
                printf("\nInvalid choice. Try again.");
                break;
        }
    } while (choice != 5);
    
    //free dynamically allocated memory before exiting
    free(devices);
    
    return 0;
}

//function to display menu options
void display_menu() {
    printf("\nSMART HOME AUTOMATION\n");
    printf("---------------------\n");
    printf("1. Add device\n");
    printf("2. Remove device\n");
    printf("3. Toggle device status\n");
    printf("4. Display devices\n");
    printf("5. Quit\n");
}

//function to add a new device
void add_device(smart_dev *devices, int count) {
    //allocate memory for the new device
    devices = realloc(devices, (count + 1) * sizeof(smart_dev));
    
    //get device information from user and add to devices array
    printf("\nEnter device name: ");
    scanf("%s", devices[count].name);
    printf("Enter device category: ");
    scanf("%s", devices[count].category);
    printf("Enter device status (0/1): ");
    scanf("%d", &devices[count].status);
}

//function to remove a device
void remove_device(smart_dev *devices, int *count) {
    //declare variables
    int i, index, found = 0;
    char name[20];
    
    //get device name from user and search for it in devices array
    printf("\nEnter device name to remove: ");
    scanf("%s", name);
    for (i = 0; i < *count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            found = 1;
            index = i;
            break;
        }
    }
    
    //if device is found, remove it from devices array
    if (found) {
        for (i = index; i < (*count - 1); i++) {
            devices[i] = devices[i+1];
        }
        *count = *count - 1; //decrement device count after removing a device
    } else {
        printf("Device not found. Try again.");
    }
}

//function to toggle device status
void toggle_device_status(smart_dev *devices, int count) {
    //declare variables
    int i;
    char name[20];
    
    //get device name from user and search for it in devices array
    printf("\nEnter device name to toggle status: ");
    scanf("%s", name);
    for (i = 0; i < count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].status = !devices[i].status; //toggle device status
            break;
        }
    }
}

//function to display all devices
void display_devices(smart_dev *devices, int count) {
    //declare variables
    int i;
    
    //display all devices in devices array
    printf("\nDEVICE NAME\tCATEGORY\tSTATUS\n");
    for (i = 0; i < count; i++) {
        printf("%s\t\t%s\t\t%s\n", devices[i].name, devices[i].category, devices[i].status ? "ON" : "OFF");
    }
}