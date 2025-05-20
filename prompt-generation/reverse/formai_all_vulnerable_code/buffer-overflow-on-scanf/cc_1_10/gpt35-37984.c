//FormAI DATASET v1.0 Category: Smart home automation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining the struct for the smart device
typedef struct smartDevice
{
    int deviceId;
    bool isOn;
    int intensity;
} SmartDevice;

// Function to turn on/off the smart device
void switchDevice(SmartDevice *device, bool isOn)
{
    device->isOn = isOn;
}

// Function to adjust the intensity of the smart device
void adjustIntensity(SmartDevice *device, int intensity)
{
    if (device->isOn)
    {
        device->intensity = intensity;
    }
    else
    {
        printf("Device is not turned on!\n");
    }
}

int main()
{
    // Creating some sample smart devices
    SmartDevice light = {1, false, 0};
    SmartDevice fan = {2, false, 0};
    SmartDevice ac = {3, false, 0};

    int choice = 0;

    // Menu driven program
    while (choice != 4)
    {
        printf("Select an option:\n");
        printf("1. Turn on/off a device\n");
        printf("2. Adjust the intensity of a device\n");
        printf("3. Check the status of a device\n");
        printf("4. Exit the program\n");

        scanf("%d", &choice);

        // Turn on/off a device
        if (choice == 1)
        {
            int deviceId;
            bool isOn;

            printf("Enter the device id: ");
            scanf("%d", &deviceId);

            printf("Turn the device on or off (1 for on, 0 for off): ");
            scanf("%d", &isOn);

            // Performing the switchDevice operation
            switch (deviceId)
            {
            case 1:
                switchDevice(&light, isOn);
                break;
            case 2:
                switchDevice(&fan, isOn);
                break;
            case 3:
                switchDevice(&ac, isOn);
                break;
            default:
                printf("Invalid device id!\n");
            }
        }
        // Adjust the intensity of a device
        else if (choice == 2)
        {
            int deviceId;
            int intensity;

            printf("Enter the device id: ");
            scanf("%d", &deviceId);

            printf("Enter the intensity level: ");
            scanf("%d", &intensity);

            // Performing the adjustIntensity operation
            switch (deviceId)
            {
            case 1:
                adjustIntensity(&light, intensity);
                break;
            case 2:
                adjustIntensity(&fan, intensity);
                break;
            case 3:
                adjustIntensity(&ac, intensity);
                break;
            default:
                printf("Invalid device id!\n");
            }
        }
        // Check the status of a device
        else if (choice == 3)
        {
            int deviceId;

            printf("Enter the device id: ");
            scanf("%d", &deviceId);

            // Printing the status of the device
            switch (deviceId)
            {
            case 1:
                printf("Light status: %d\n", light.isOn);
                break;
            case 2:
                printf("Fan status: %d\n", fan.isOn);
                break;
            case 3:
                printf("AC status: %d\n", ac.isOn);
                break;
            default:
                printf("Invalid device id!\n");
            }
        }
        // Exit the program
        else if (choice == 4)
        {
            printf("Exiting smart home automation program...\n");
        }
        // Invalid choice
        else
        {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}