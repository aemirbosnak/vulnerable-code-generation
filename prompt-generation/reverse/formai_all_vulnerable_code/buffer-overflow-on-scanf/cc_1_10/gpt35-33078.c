//FormAI DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>

// Function prototype
void turnOnLight(int lightNum);
void turnOffLight(int lightNum);
void toggleLight(int lightNum);

int main() {
    int lightNum;
    char choice;

    printf("Welcome to Smart Home Light Control\n");

    while (1) {
        printf("Enter the number of the light you want to control: ");
        scanf("%d", &lightNum);

        printf("\nChoose an option:\n");
        printf("1. Turn on the light\n");
        printf("2. Turn off the light\n");
        printf("3. Toggle the light\n");
        printf("4. Quit\n");

        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                turnOnLight(lightNum);
                break;
            case '2':
                turnOffLight(lightNum);
                break;
            case '3':
                toggleLight(lightNum);
                break;
            case '4':
                printf("Thank you for using Smart Home Light Control\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

// Function to turn on the specified light
void turnOnLight(int lightNum) {
    printf("Turning on light %d\n", lightNum);
}

// Function to turn off the specified light
void turnOffLight(int lightNum) {
    printf("Turning off light %d\n", lightNum);
}

// Function to toggle the specified light
void toggleLight(int lightNum) {
    printf("Toggling light %d\n", lightNum);
}