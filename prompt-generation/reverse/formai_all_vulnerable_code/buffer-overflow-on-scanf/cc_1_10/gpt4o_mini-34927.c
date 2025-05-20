//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_LIGHTS 10
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    int isOn;
    int brightness; // 0-100
    time_t timer; // in seconds
    time_t timer_start; // track when the timer started
} Light;

typedef struct {
    Light lights[MAX_LIGHTS];
    int lightCount;
} SmartHome;

// Function prototypes
void initializeHome(SmartHome *home);
void addLight(SmartHome *home, char *name);
void toggleLight(SmartHome *home, int index);
void adjustBrightness(SmartHome *home, int index, int brightness);
void setTimer(SmartHome *home, int index, int duration);
void updateLights(SmartHome *home);
void displayStatus(SmartHome *home);
void clearInputBuffer();

int main() {
    SmartHome myHome;
    initializeHome(&myHome);
    
    int choice, index, brightness, duration;
    char lightName[NAME_LENGTH];

    while(1) {
        printf("\n=== Smart Home Light Control ===\n");
        printf("1. Add a new light\n");
        printf("2. Toggle light\n");
        printf("3. Adjust brightness\n");
        printf("4. Set timer\n");
        printf("5. Display light status\n");
        printf("6. Update lights\n");
        printf("7. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                printf("Enter light name: ");
                fgets(lightName, NAME_LENGTH, stdin);
                strtok(lightName, "\n"); // Remove newline character
                addLight(&myHome, lightName);
                break;

            case 2:
                printf("Select light index (0 to %d): ", myHome.lightCount - 1);
                scanf("%d", &index);
                toggleLight(&myHome, index);
                break;

            case 3:
                printf("Select light index (0 to %d): ", myHome.lightCount - 1);
                scanf("%d", &index);
                printf("Enter brightness level (0-100): ");
                scanf("%d", &brightness);
                adjustBrightness(&myHome, index, brightness);
                break;

            case 4:
                printf("Select light index (0 to %d): ", myHome.lightCount - 1);
                scanf("%d", &index);
                printf("Enter timer duration in seconds: ");
                scanf("%d", &duration);
                setTimer(&myHome, index, duration);
                break;

            case 5:
                displayStatus(&myHome);
                break;

            case 6:
                updateLights(&myHome);
                break;

            case 7:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void initializeHome(SmartHome *home) {
    home->lightCount = 0;
}

void addLight(SmartHome *home, char *name) {
    if (home->lightCount >= MAX_LIGHTS) {
        printf("Cannot add more lights. Maximum limit reached.\n");
        return;
    }
    strcpy(home->lights[home->lightCount].name, name);
    home->lights[home->lightCount].isOn = 0;
    home->lights[home->lightCount].brightness = 0;
    home->lights[home->lightCount].timer = 0;
    home->lights[home->lightCount].timer_start = 0;
    home->lightCount++;
    printf("Light '%s' added successfully.\n", name);
}

void toggleLight(SmartHome *home, int index) {
    if (index < 0 || index >= home->lightCount) {
        printf("Invalid light index.\n");
        return;
    }
    home->lights[index].isOn = !home->lights[index].isOn;
    printf("Light '%s' is now %s.\n", home->lights[index].name, home->lights[index].isOn ? "ON" : "OFF");
}

void adjustBrightness(SmartHome *home, int index, int brightness) {
    if (index < 0 || index >= home->lightCount) {
        printf("Invalid light index.\n");
        return;
    }
    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100.\n");
        return;
    }
    home->lights[index].brightness = brightness;
    printf("Brightness of '%s' set to %d%%.\n", home->lights[index].name, brightness);
}

void setTimer(SmartHome *home, int index, int duration) {
    if (index < 0 || index >= home->lightCount) {
        printf("Invalid light index.\n");
        return;
    }
    home->lights[index].timer = duration;
    home->lights[index].timer_start = time(NULL);
    printf("Timer for '%s' set for %d seconds.\n", home->lights[index].name, duration);
}

void updateLights(SmartHome *home) {
    time_t current_time = time(NULL);
    for (int i = 0; i < home->lightCount; i++) {
        if (home->lights[i].timer > 0) {
            if (current_time - home->lights[i].timer_start >= home->lights[i].timer) {
                home->lights[i].isOn = 0;
                home->lights[i].timer = 0;
                printf("Timer expired for '%s'. Light turned OFF.\n", home->lights[i].name);
            }
        }
    }
}

void displayStatus(SmartHome *home) {
    printf("\n=== Light Status ===\n");
    for (int i = 0; i < home->lightCount; i++) {
        printf("Light %d: %s - Status: %s, Brightness: %d%%\n", 
               i, home->lights[i].name, 
               home->lights[i].isOn ? "ON" : "OFF", 
               home->lights[i].brightness);
        if (home->lights[i].timer > 0) {
            printf("  Timer: %d seconds remaining\n",
                   (int)(home->lights[i].timer - (time(NULL) - home->lights[i].timer_start)));
        }
    }
}

void clearInputBuffer() {
    while (getchar() != '\n');
}