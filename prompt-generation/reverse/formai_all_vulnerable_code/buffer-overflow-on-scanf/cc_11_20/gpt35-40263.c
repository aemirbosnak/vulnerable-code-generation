//FormAI DATASET v1.0 Category: Smart home automation ; Style: surprised
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool is_light_on = false;
    bool is_security_enabled = true;
    int temperature = 25;

    printf("Welcome to Smart Home Automation!\n");

    while (true) {
        printf("-------------------------------------------\n");
        printf("Current status:\n");
        printf("Light is %s\n", is_light_on ? "on" : "off");
        printf("Security is %s\n", is_security_enabled ? "enabled" : "disabled");
        printf("Temperature: %dC\n", temperature);

        printf("Select the action you want to perform:\n");
        printf("1. Turn Light %s\n", is_light_on ? "Off" : "On");
        printf("2. Enable/Disable Security\n");
        printf("3. Set Temperature\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                is_light_on = !is_light_on;
                printf("The light is %s now!\n", is_light_on ? "on" : "off");
                break;
            
            case 2:
                is_security_enabled = !is_security_enabled;
                printf("The security is %s now!\n", is_security_enabled ? "enabled" : "disabled");
                break;

            case 3:
                printf("Enter the temperature: ");
                scanf("%d", &temperature);
                printf("The temperature is set to %dC now!\n", temperature);
                break;

            case 4:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}