//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void controlLights();
void controlTemperature();
void controlSecurity();
void showMenu();

int main() {
    int choice;
    do {
        showMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                controlLights();
                break;
            case 2:
                controlTemperature();
                break;
            case 3:
                controlSecurity();
                break;
            case 4:
                printf("Exiting the Smart Home Control System... Goodbye! 🌟\n");
                break;
            default:
                printf("Invalid choice, please try again! ❌\n");
        }
        printf("\n");

    } while(choice != 4);

    return 0;
}

void showMenu() {
    printf("Welcome to the Smart Home Control System! 🏡\n");
    printf("========================================\n");
    printf("1. Control Lights 💡\n");
    printf("2. Control Temperature 🌡️\n");
    printf("3. Control Security 🔐\n");
    printf("4. Exit 🚪\n");
    printf("========================================\n");
}

void controlLights() {
    int option;
    printf("Light Control Options:\n");
    printf("1. Turn On Lights\n");
    printf("2. Turn Off Lights\n");
    printf("3. Dim Lights\n");
    printf("4. Back to Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("💡 Lights have been turned ON! Enjoy the brightness!\n");
            break;
        case 2:
            printf("🌑 Lights have been turned OFF! Sweet dreams!\n");
            break;
        case 3:
            printf("💡 Dimmed lights for a cozy atmosphere! 🌙\n");
            break;
        case 4:
            return;
        default:
            printf("Invalid choice, please try again! ❌\n");
    }
}

void controlTemperature() {
    int temp, option;
    
    printf("Temperature Control Options:\n");
    printf("1. Set Temperature\n");
    printf("2. Increase Temperature\n");
    printf("3. Decrease Temperature\n");
    printf("4. Back to Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter desired temperature: ");
            scanf("%d", &temp);
            printf("🌡️ Temperature has been set to %d°C! Enjoy your comfort!\n", temp);
            break;
        case 2:
            printf("🌡️ Temperature increased by 2°C! Let’s heat things up! 🔥\n");
            break;
        case 3:
            printf("🌡️ Temperature decreased by 2°C! Time to cool down! ❄️\n");
            break;
        case 4:
            return;
        default:
            printf("Invalid choice, please try again! ❌\n");
    }
}

void controlSecurity() {
    int option;
    printf("Security System Options:\n");
    printf("1. Activate Security System\n");
    printf("2. Deactivate Security System\n");
    printf("3. Show Security Status\n");
    printf("4. Back to Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("🔐 Security system has been ACTIVATED! Your home is safe!\n");
            break;
        case 2:
            printf("🔓 Security system has been DEACTIVATED! Stay alert! \n");
            break;
        case 3:
            printf("🏠 Security status: SYSTEM ACTIVATED. All windows and doors are secured!\n");
            break;
        case 4:
            return;
        default:
            printf("Invalid choice, please try again! ❌\n");
    }
}