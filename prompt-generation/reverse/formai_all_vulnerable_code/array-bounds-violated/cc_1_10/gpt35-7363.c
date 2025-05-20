//FormAI DATASET v1.0 Category: Smart home automation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>

#define MAX_DEVICES 10

typedef struct{
    bool state;
    int brightness;
} Light;

typedef struct{
    bool state;
    int temperature;
} Thermostat;

typedef struct{
    bool state;
} Security;

typedef struct{
    bool state;
} Watering;

void setUpLights(Light[]);
void setUpThermostat(Thermostat*);
void setUpSecurity(Security*);
void setUpWatering(Watering*);
void printMenu(Light[], Thermostat*, Security*, Watering*);
void setDeviceState(bool*, char*);
void setDeviceProperty(int*, char*);
void powerCycle(bool*);
void adjustBrightness(int*);
void adjustTemperature(int*);
void activateSecurity(Security*);
void startWatering(Watering*);

int main(){
    Light lights[MAX_DEVICES];
    Thermostat thermostat;
    Security security;
    Watering watering;
    int choice, deviceNo;

    srand(time(NULL));
    setUpLights(lights);
    setUpThermostat(&thermostat);
    setUpSecurity(&security);
    setUpWatering(&watering);

    do{
        printf("\n\n");
        printf("Welcome to Smart Home Automation System\n");
        printf("----------------------------------------\n");
        printMenu(lights, &thermostat, &security, &watering);
        printf("What would you like to do?\n");
        scanf("%d",&choice);

        switch(choice){
            case 1: // Turn On/Off a Light
                printf("\nWhich Light do you want to turn On/Off? (1-%d)\n", MAX_DEVICES);
                scanf("%d",&deviceNo);
                setDeviceState(&lights[deviceNo-1].state, "Light");
                break;

            case 2: // Adjust Brightness of a Light
                printf("\nWhich light do you want to Adjust brightness? (1-%d)\n", MAX_DEVICES);
                scanf("%d",&deviceNo);
                setDeviceState(&lights[deviceNo-1].state, "Light");
                if(lights[deviceNo-1].state){
                    adjustBrightness(&lights[deviceNo-1].brightness);
                }
                break;

            case 3: // Power Cycle a Light
                printf("\nWhich Light do you want to Power Cycle? (1-%d)\n", MAX_DEVICES);
                scanf("%d",&deviceNo);
                powerCycle(&lights[deviceNo-1].state);
                break;

            case 4: // Adjust Thermostat Temperature
                setDeviceState(&thermostat.state, "Thermostat");
                if(thermostat.state){
                    adjustTemperature(&thermostat.temperature);
                }
                break;

            case 5: // Activate Security System
                activateSecurity(&security);
                break;

            case 6: // Start Watering Process
                startWatering(&watering);
                break;

            case 7: // Exit
                printf("\nExiting Smart Home Automation System...\n");
                exit(EXIT_SUCCESS);
                break;

            default:
                printf("\nInvalid Choice! Please Try again ...\n");
                break;
        }
    }while(true);
    return 0;
}

void setUpLights(Light lights[MAX_DEVICES]){
    int i;
    for(i=0;i<MAX_DEVICES;i++){
        lights[i].state = false;
        lights[i].brightness = 0;
    }
}

void setUpThermostat(Thermostat *thermostat){
    thermostat->state = false;
    thermostat->temperature = 25;
}

void setUpSecurity(Security *security){
    security->state = false;
}

void setUpWatering(Watering *watering){
    watering->state = false;
}

void printMenu(Light lights[MAX_DEVICES], Thermostat *thermostat, Security *security, Watering *watering){
    int i;
    printf("\nCurrently Available Devices:\n");
    printf("\tLights\n");
    for(i=0;i<MAX_DEVICES;i++){
        printf("\t\tLight %d is %s and Brightness is %d%\n", i+1, (lights[i].state?"On":"Off"), lights[i].brightness);
    }
    printf("\tThermostat is %s and Temperature is %dC\n", (thermostat->state?"On":"Off"), thermostat->temperature);
    printf("\tSecurity System is %s\n", (security->state?"Activated":"Deactivated"));
    printf("\tWatering System is %s\n", (watering->state?"Running":"Stopped"));

    printf("\nOptions:\n");
    printf("\t1. Turn On/Off a Light\n");
    printf("\t2. Adjust Brightness of a Light\n");
    printf("\t3. Power Cycle a Light\n");
    printf("\t4. Adjust Thermostat Temperature\n");
    printf("\t5. Activate/Deactivate Security System\n");
    printf("\t6. Start/Stop Watering Process\n");
    printf("\t7. Exit\n");
}

void setDeviceState(bool *state, char* deviceName){
    int choice;
    printf("\nDo you want to turn %s On or Off? (1/0)\n", deviceName);
    scanf("%d", &choice);
    *state = (choice==1)?true:false;
    printf("\n%s is turned %s!\n", deviceName, (*state?"On":"Off"));
}

void setDeviceProperty(int *property, char* deviceName){
    int value;
    printf("\nWhat value do you want to set for %s?\n", deviceName);
    scanf("%d", &value);
    *property = value;
    printf("\n%s value is set to %d!\n", deviceName, *property);
}

void powerCycle(bool *state){
    *state = !(*state);
    printf("\nDevice is Power Cycled! Now it is %s.\n", (*state?"On":"Off"));
}

void adjustBrightness(int *brightness){
    int choice;
    printf("\nWhat brightness do you want to set? (0-100)\n");
    scanf("%d", &choice);
    *brightness = choice;
    printf("\nBrightness is set to %d!\n", *brightness);
}

void adjustTemperature(int *temperature){
    int choice;
    printf("\nWhat temperature do you want to set? (0-50)\n");
    scanf("%d", &choice);
    *temperature = choice;
    printf("\nTemperature is set to %dC!\n", *temperature);
}

void activateSecurity(Security *security){
    int choice;
    printf("\nDo you want to activate or deactivate Security System? (1/0)\n");
    scanf("%d", &choice);
    security->state = (choice==1)?true:false;
    printf("\nSecurity System is %s now!\n", (security->state?"Activated":"Deactivated"));
}

void startWatering(Watering *watering){
    int choice;
    printf("\nDo you want to start or stop Watering? (1/0)\n");
    scanf("%d", &choice);
    watering->state = (choice==1)?true:false;
    printf("\nWatering System is %s now!\n", (watering->state?"Running":"Stopped"));
}