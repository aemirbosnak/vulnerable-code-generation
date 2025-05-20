//FormAI DATASET v1.0 Category: Color Code Converter ; Style: invasive
#include <stdio.h>
#include <string.h>

// Function to convert RGB to HEX
void RGBtoHEX(int red, int green, int blue)
{
    // Ensure values are within accepted range
    if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255)
    {
        printf("Invalid RGB values. Exiting program.\n");
        return;
    }

    // Convert RGB to HEX
    char hex[7];
    sprintf(hex, "%02X%02X%02X", red, green, blue);

    printf("RGB (%d,%d,%d) to HEX: #%s\n", red, green, blue, hex);
}

// Function to convert HEX to RGB
void HEXtoRGB(char hex[])
{
    // Ensure correct HEX format
    if (strlen(hex) != 6)
    {
        printf("Invalid HEX format. Exiting program.\n");
        return;
    }

    // Convert HEX to RGB
    int red, green, blue;
    sscanf(hex, "%02X%02X%02X", &red, &green, &blue);

    printf("HEX #%s to RGB: (%d,%d,%d)\n", hex, red, green, blue);
}

int main()
{
    int choice, red, green, blue;
    char hex[7];

    printf("Welcome to the RGB to HEX and HEX to RGB converter!\n");

    while (1)
    {
        // Menu options
        printf("\nSelect an option:\n");
        printf("1. Convert RGB to HEX\n");
        printf("2. Convert HEX to RGB\n");
        printf("3. Exit program\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter the RGB values (separated by spaces): ");
                scanf("%d %d %d", &red, &green, &blue);
                RGBtoHEX(red, green, blue);
                break;
            case 2:
                printf("\nEnter the HEX value: ");
                scanf("%s", hex);
                HEXtoRGB(hex);
                break;
            case 3:
                printf("\nExiting program. Thank you for using the converter!\n");
                return 0;
            default:
                printf("\nInvalid selection. Please try again.\n");
                break;
        }
    }
}