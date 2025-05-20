//FormAI DATASET v1.0 Category: Smart home automation ; Style: secure
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// predefined usernames and passwords
char usernames[2][20] = {"admin", "user"};
char passwords[2][20] = {"password1", "password2"};

// define structs 
typedef struct {
    char name[20];
    bool isDeviceOn; 
    int intensity;
} Light;

typedef struct {
    char name[20];
    int temperature;
} Thermostat;

typedef struct {
    char name[20];
    bool isDeviceOn; 
} Security;

// function declarations
bool authenticateUser(char username[], char password[]);
void turnLightOn(Light *light, int intensity);
void turnLightOff(Light *light);
void setTemperature(Thermostat *thermostat, int newTemperature);
void armSecurity(Security *security);
void disarmSecurity(Security *security);

int main() {
    // initialize devices
    Light livingRoomLight = {"Living Room Light", false, 0};
    Thermostat thermostat = {"Thermostat", 72};
    Security security = {"Security System", false};
    
    // authenticate user
    char username[20];
    char password[20];
    bool isAuthenticated = false;
    
    do {
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);
        isAuthenticated = authenticateUser(username, password);
        
        if (!isAuthenticated) {
            printf("Invalid username/password combination. Please try again.\n");
        }
    } while (!isAuthenticated);
    
    // user navigation menu
    int choice;
    char deviceName[20];
    
    do {
        printf("\n");
        printf("*** SMART HOME AUTOMATION ***\n");
        printf("1. Turn on a light\n");
        printf("2. Turn off a light\n");
        printf("3. Adjust thermostat temperature\n");
        printf("4. Arm security system\n");
        printf("5. Disarm security system\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the name of the light: ");
                scanf("%s", deviceName);
                if (strcmp(deviceName, livingRoomLight.name) == 0) {
                    int intensity;
                    printf("Enter light intensity (0-100): ");
                    scanf("%d", &intensity);
                    turnLightOn(&livingRoomLight, intensity);
                } else {
                    printf("Device not found.\n");
                }
                break;
            case 2:
                printf("Enter the name of the light: ");
                scanf("%s", deviceName);
                if (strcmp(deviceName, livingRoomLight.name) == 0) {
                    turnLightOff(&livingRoomLight);
                } else {
                    printf("Device not found.\n");
                }
                break;
            case 3:
                printf("Enter new temperature: ");
                int newTemperature;
                scanf("%d", &newTemperature);
                setTemperature(&thermostat, newTemperature);
                break;
            case 4:
                armSecurity(&security);
                break;
            case 5:
                disarmSecurity(&security);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);
    
    return 0;
}

bool authenticateUser(char username[], char password[]) {
    for (int i = 0; i < 2; i++) {
        if (strcmp(username, usernames[i]) == 0 && strcmp(password, passwords[i]) == 0) {
            return true;
        }
    }
    return false;
}

void turnLightOn(Light *light, int intensity) {
    light->isDeviceOn = true;
    light->intensity = intensity;
    printf("%s is turned on with intensity %d.\n", light->name, light->intensity);
}

void turnLightOff(Light *light) {
    light->isDeviceOn = false;
    printf("%s is turned off.\n", light->name);
}

void setTemperature(Thermostat *thermostat, int newTemperature) {
    thermostat->temperature = newTemperature;
    printf("%s temperature set to %d.\n", thermostat->name, thermostat->temperature);
}

void armSecurity(Security *security) {
    security->isDeviceOn = true;
    printf("%s is armed.\n", security->name);
}

void disarmSecurity(Security *security) {
    security->isDeviceOn = false;
    printf("%s is disarmed.\n", security->name);
}