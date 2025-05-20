//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_BATTERIES 10
#define MAX_RADIATION_LEVEL 100
#define MAX_DROIDS 20

typedef struct {
    char id[10];
    int health;
    int batteryLevel;
    int radiationResistance;
} Droid;

typedef struct {
    Droid droids[MAX_DROIDS];
    int count;
} DroidFleet;

void initDroid(Droid* droid, const char* id) {
    strcpy(droid->id, id);
    droid->health = 100;
    droid->batteryLevel = rand() % 101; // Random battery level from 0 to 100
    droid->radiationResistance = rand() % MAX_RADIATION_LEVEL; // Random resistance
}

void deployDroid(DroidFleet* fleet) {
    if (fleet->count >= MAX_DROIDS) {
        printf("Droid Fleet is full! Cannot deploy more droids.\n");
        return;
    }
    char id[10];
    sprintf(id, "Droid%d", fleet->count + 1);
    initDroid(&fleet->droids[fleet->count], id);
    fleet->count++;
    printf("Deployed %s with Battery Level: %d%%, Radiation Resistance: %d\n",
           id, fleet->droids[fleet->count - 1].batteryLevel, fleet->droids[fleet->count - 1].radiationResistance);
}

void rechargeDroid(Droid* droid) {
    if (droid->batteryLevel < 100) {
        droid->batteryLevel += 20; // Recharge by 20%
        if (droid->batteryLevel > 100) {
            droid->batteryLevel = 100; // Cap at 100%
        }
        printf("Recharged %s to Battery Level: %d%%\n", droid->id, droid->batteryLevel);
    } else {
        printf("%s is already at full battery!\n", droid->id);
    }
}

void monitorDroidStatus(DroidFleet* fleet) {
    printf("\n--- Droid Fleet Status ---\n");
    for (int i = 0; i < fleet->count; ++i) {
        printf("ID: %s | Health: %d%% | Battery: %d%% | Radiation Resistance: %d%%\n",
               fleet->droids[i].id, fleet->droids[i].health, fleet->droids[i].batteryLevel,
               fleet->droids[i].radiationResistance);
    }
    printf("--------------------------\n");
}

void simulateRadiation(DroidFleet* fleet) {
    for (int i = 0; i < fleet->count; ++i) {
        int radiationExposure = rand() % MAX_RADIATION_LEVEL;
        if (fleet->droids[i].radiationResistance < radiationExposure) {
            fleet->droids[i].health -= (radiationExposure - fleet->droids[i].radiationResistance);
            if (fleet->droids[i].health < 0) {
                fleet->droids[i].health = 0; // Health cannot drop below 0
            }
            printf("%s took radiation damage. Health is now: %d%%\n", fleet->droids[i].id, fleet->droids[i].health);
        } else {
            printf("%s resisted the radiation.\n", fleet->droids[i].id);
        }
    }
}

void wastelandSurvivorGame() {
    srand(time(NULL));
    DroidFleet fleet = {{0}, 0};

    while (1) {
        int choice;
        printf("\nWelcome to the Wasteland Droid Scheduler\n");
        printf("1. Deploy Droid\n");
        printf("2. Recharge Droid\n");
        printf("3. Monitor Droid Status\n");
        printf("4. Simulate Radiation Exposure\n");
        printf("5. Exit\n");
        
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                deployDroid(&fleet);
                break;
            case 2: {
                int index;
                printf("Enter Droid index to recharge (1-%d): ", fleet.count);
                scanf("%d", &index);
                if (index > 0 && index <= fleet.count) {
                    rechargeDroid(&fleet.droids[index - 1]);
                } else {
                    printf("Invalid index!\n");
                }
                break;
            }
            case 3:
                monitorDroidStatus(&fleet);
                break;
            case 4:
                simulateRadiation(&fleet);
                break;
            case 5:
                printf("Exiting Wasteland Scheduler. Good luck survivor!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    wastelandSurvivorGame();
    return 0;
}