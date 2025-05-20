//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: secure
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 5
#define PASSWORD_LENGTH 20

typedef struct {
    char username[20];
    char password[PASSWORD_LENGTH];
} User;

typedef struct {
    int isOn;
    int brightness; // 0 to 100
} SmartLight;

void initializeUsers(User users[], int *userCount) {
    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "admin123");
    
    strcpy(users[1].username, "user1");
    strcpy(users[1].password, "pass1234");

    *userCount = 2; // Two users initialized
}

int authenticate(User users[], int userCount) {
    char username[20];
    char password[PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%19s", username);
    printf("Enter password: ");
    scanf("%19s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; // Authentication successful
        }
    }
    printf("Authentication failed!\n");
    return 0; // Authentication failed
}

void turnLightOn(SmartLight *light) {
    light->isOn = 1;
    printf("Light is turned ON.\n");
}

void turnLightOff(SmartLight *light) {
    light->isOn = 0;
    printf("Light is turned OFF.\n");
}

void setBrightness(SmartLight *light, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100.\n");
        return;
    }
    light->brightness = brightness;
    printf("Brightness set to %d%%.\n", brightness);
}

void displayStatus(SmartLight light) {
    printf("Light Status: %s\n", light.isOn ? "ON" : "OFF");
    printf("Brightness Level: %d%%\n", light.brightness);
}

void delayTimer(int seconds) {
    while (seconds > 0) {
        printf("%d seconds remaining...\n", seconds);
        sleep(1);
        seconds--;
    }
}

int main() {
    User users[MAX_USERS];
    int userCount = 0;
    SmartLight livingRoomLight = {0, 100}; // Light is initially OFF with 100% brightness

    initializeUsers(users, &userCount);
    
    if (!authenticate(users, userCount)) {
        return 1; // Exit on failed authentication
    }

    int choice;
    do {
        printf("\nSmart Home Light Control Menu:\n");
        printf("1. Turn Light ON\n");
        printf("2. Turn Light OFF\n");
        printf("3. Set Brightness (0-100)\n");
        printf("4. Display Light Status\n");
        printf("5. Set Timer (in seconds)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                turnLightOn(&livingRoomLight);
                break;
            case 2: 
                turnLightOff(&livingRoomLight);
                break;
            case 3: {
                int brightness;
                printf("Enter brightness level (0-100): ");
                scanf("%d", &brightness);
                setBrightness(&livingRoomLight, brightness);
                break;
            }
            case 4: 
                displayStatus(livingRoomLight);
                break;
            case 5: {
                int seconds;
                printf("Set timer in seconds: ");
                scanf("%d", &seconds);
                delayTimer(seconds);
                turnLightOff(&livingRoomLight); // Automatically turn off after timer completes
                break;
            }
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 6);

    return 0;
}