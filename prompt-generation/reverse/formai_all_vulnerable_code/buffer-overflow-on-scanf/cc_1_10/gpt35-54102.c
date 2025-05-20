//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void display_instructions(void){
    printf("Welcome to Wi-Fi Signal Strength Analyzer. \nThis program will help you analyze the Wi-Fi signal strength of your router and connected devices. \nPlease provide the requested information to continue.\n");
}

int get_router_ssid(char *router_ssid){
    int len;
    printf("Enter the name of your router's SSID: ");
    fgets(router_ssid, 50, stdin);
    len = strlen(router_ssid);
    if(len > 0 && router_ssid[len - 1] == '\n')
        router_ssid[len - 1] = '\0';
    if(strcmp(router_ssid , "") == 0)
        return 0;
    else
        return 1;
}

int get_device_ssid(char *device_ssid){
    int len;
    printf("Enter the name of your device's SSID: ");
    fgets(device_ssid, 50, stdin);
    len = strlen(device_ssid);
    if(len > 0 && device_ssid[len - 1] == '\n')
        device_ssid[len - 1] = '\0';
    if(strcmp(device_ssid , "") == 0)
        return 0;
    else
        return 1;
}

int get_signal_strength(void){
    int signal_strength;
    printf("Enter the signal strength (in dBm): ");
    scanf("%d", &signal_strength);
    if(signal_strength < -100 || signal_strength > 0){
        printf("Invalid signal strength. Please enter a value between -100 and 0.\n");
        return 0;
    }
    else
        return signal_strength;
}

void check_warnings(int signal_strength, char *router_ssid, char *device_ssid){
    int len;
    char router_prefix[] = "router";
    char device_prefix[] = "device";
    if(signal_strength < -60){
        printf("WARNING: Low Wi-Fi signal strength detected.\n");
    }
    if(strncmp(router_ssid, router_prefix, strlen(router_prefix)) != 0){
        printf("WARNING: Your router's SSID does not start with the prefix 'router'.\n");
    }
    if(strncmp(device_ssid, device_prefix, strlen(device_prefix)) != 0){
        printf("WARNING: Your device's SSID does not start with the prefix 'device'.\n");
    }
}

int main(){
    char router_ssid[50], device_ssid[50];
    int signal_strength;
    display_instructions();
    while(1){
        if(get_router_ssid(router_ssid) == 1)
            break;
        printf("Please enter valid router SSID.\n");
    }
    while(1){
        if(get_device_ssid(device_ssid) == 1)
            break;
        printf("Please enter valid device SSID.\n");
    }
    while(1){
        if((signal_strength = get_signal_strength()) != 0)
            break;
    }
    check_warnings(signal_strength, router_ssid, device_ssid);
    printf("Wi-Fi signal strength analysis completed. Thank you for using our program.\n");
    return 0;
}