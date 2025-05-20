//FormAI DATASET v1.0 Category: Smart home light control ; Style: puzzling
#include <stdio.h>

int main() {
    int password = 1234;
    int input;

    printf("Welcome to the Smart Home Light Control System!\n");
    printf("Please enter the password to access: ");
    scanf("%d", &input);

    if(input != password) {
        printf("Incorrect password. Program terminated.\n");
        return 0;
    }

    printf("Access granted! Please input the number of the room to control the lights in.\n");
    printf("1. Living Room\n2. Bedroom\n3. Kitchen\n4. Bathroom\n5. Guest Room\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Living room lights turned on.\n");
            printf("Please input the number of the desired brightness level (1-10): ");
            int brightness;
            scanf("%d", &brightness);
            printf("Living room lights set to brightness level %d.\n", brightness);
            break;
        case 2:
            printf("Bedroom lights turned on.\n");
            printf("Please input the number of the desired brightness level (1-10): ");
            scanf("%d", &brightness);
            printf("Bedroom lights set to brightness level %d.\n", brightness);
            break;
        case 3:
            printf("Kitchen lights turned on.\n");
            printf("Please input the number of the desired brightness level (1-10): ");
            scanf("%d", &brightness);
            printf("Kitchen lights set to brightness level %d.\n", brightness);
            break;
        case 4:
            printf("Bathroom lights turned on.\n");
            printf("Please input the number of the desired brightness level (1-10): ");
            scanf("%d", &brightness);
            printf("Bathroom lights set to brightness level %d.\n", brightness);
            break;
        case 5:
            printf("Guest room lights turned on.\n");
            printf("Please input the number of the desired brightness level (1-10): ");
            scanf("%d", &brightness);
            printf("Guest room lights set to brightness level %d.\n", brightness);
            break;
        default:
            printf("Invalid input. Program terminated.\n");
            break;
    }

    printf("Thank you for using the Smart Home Light Control System!\n");

    return 0;
}