//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: recursive
#include <stdio.h>
#include <string.h>

void controlLights(int action);
void controlThermostat(int action);
void controlSecurity(int action);
void smartHomeMenu(void);
void executeCommand(int option);
void continueMenu(void);

int main() {
    printf("Welcome to Smart Home Automation System!\n");
    smartHomeMenu();
    return 0;
}

void smartHomeMenu(void) {
    int option;

    printf("\nSelect an option to control your smart home:\n");
    printf("1. Control Lights\n");
    printf("2. Control Thermostat\n");
    printf("3. Control Security System\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    if(option >= 0 && option <= 3) {
        executeCommand(option);
    } else {
        printf("Invalid option, please try again.\n");
        smartHomeMenu();
    }
}

void executeCommand(int option) {
    int action;

    switch(option) {
        case 1:
            printf("\nChoose action for Lights:\n");
            printf("1. Turn On\n");
            printf("2. Turn Off\n");
            printf("0. Back to Menu\n");
            printf("Enter your choice: ");
            scanf("%d", &action);
            controlLights(action);
            break;

        case 2:
            printf("\nChoose action for Thermostat:\n");
            printf("1. Increase Temperature\n");
            printf("2. Decrease Temperature\n");
            printf("0. Back to Menu\n");
            printf("Enter your choice: ");
            scanf("%d", &action);
            controlThermostat(action);
            break;

        case 3:
            printf("\nChoose action for Security:\n");
            printf("1. Activate\n");
            printf("2. Deactivate\n");
            printf("0. Back to Menu\n");
            printf("Enter your choice: ");
            scanf("%d", &action);
            controlSecurity(action);
            break;

        case 0:
            printf("Exiting Smart Home Automation System. Goodbye!\n");
            return;
        
        default:
            printf("Error: Invalid option, returning to main menu.\n");
            smartHomeMenu();
            return;
    }

    continueMenu();
}

void controlLights(int action) {
    if (action == 1) {
        printf("Lights are turned ON.\n");
    } else if (action == 2) {
        printf("Lights are turned OFF.\n");
    } else if (action == 0) {
        printf("Returning to main menu...\n");
        smartHomeMenu();
        return;
    } else {
        printf("Invalid action for Lights.\n");
    }
}

void controlThermostat(int action) {
    if (action == 1) {
        printf("Temperature is INCREASED.\n");
    } else if (action == 2) {
        printf("Temperature is DECREASED.\n");
    } else if (action == 0) {
        printf("Returning to main menu...\n");
        smartHomeMenu();
        return;
    } else {
        printf("Invalid action for Thermostat.\n");
    }
}

void controlSecurity(int action) {
    if (action == 1) {
        printf("Security System is ACTIVATED.\n");
    } else if (action == 2) {
        printf("Security System is DEACTIVATED.\n");
    } else if (action == 0) {
        printf("Returning to main menu...\n");
        smartHomeMenu();
        return;
    } else {
        printf("Invalid action for Security System.\n");
    }
}

void continueMenu(void) {
    char choice[4];

    printf("\nDo you want to perform another action? (yes/no): ");
    scanf("%s", choice);
    
    if (strcmp(choice, "yes") == 0) {
        smartHomeMenu();
    } else if (strcmp(choice, "no") == 0) {
        printf("Exiting Smart Home Automation System. Goodbye!\n");
        return;
    } else {
        printf("Invalid choice. Please enter 'yes' or 'no'.\n");
        continueMenu();
    }
}