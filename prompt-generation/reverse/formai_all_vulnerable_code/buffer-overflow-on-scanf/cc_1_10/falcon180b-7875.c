//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a number
int isNumber(char *str) {
    for (int i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert a string to an integer
int stringToInt(char *str) {
    int num = 0;
    for (int i = 0; str[i]!= '\0'; i++) {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

// Function to set the brightness of the lights
void setBrightness(int brightness) {
    printf("Setting brightness to %d\n", brightness);
}

// Function to set the color of the lights
void setColor(char *color) {
    printf("Setting color to %s\n", color);
}

// Function to turn the lights on or off
void setLights(char *status) {
    if (strcmp(status, "on") == 0) {
        printf("Turning lights on\n");
    } else if (strcmp(status, "off") == 0) {
        printf("Turning lights off\n");
    } else {
        printf("Invalid status\n");
    }
}

// Function to parse user input and call appropriate functions
void parseInput(char *input) {
    char *token = strtok(input, " ");
    while (token!= NULL) {
        if (strcmp(token, "brightness") == 0) {
            token = strtok(NULL, " ");
            if (isNumber(token)) {
                setBrightness(stringToInt(token));
            } else {
                printf("Invalid brightness\n");
            }
        } else if (strcmp(token, "color") == 0) {
            token = strtok(NULL, " ");
            setColor(token);
        } else if (strcmp(token, "lights") == 0) {
            token = strtok(NULL, " ");
            setLights(token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char input[100];
    while (1) {
        printf("Enter command (brightness value color lights on/off): ");
        scanf("%s", input);
        parseInput(input);
    }
    return 0;
}