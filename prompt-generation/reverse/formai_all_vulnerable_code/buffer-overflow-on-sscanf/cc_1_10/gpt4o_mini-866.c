//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_GLIMMERS 10
#define MAX_COMMAND_LENGTH 50

typedef struct {
    char name[20];
    int brightness;  // Range 1-10
    int speed;       // Range 1-10
    char mood[20];   // Happy, Sad, etc.
} Glimmer;

Glimmer glimmers[MAX_GLIMMERS];
int glimmerCount = 0;

void addGlimmer(char* name, int brightness, int speed, char* mood) {
    if (glimmerCount >= MAX_GLIMMERS) {
        printf("Cannot add more Glimmers!\n");
        return;
    }
    strcpy(glimmers[glimmerCount].name, name);
    glimmers[glimmerCount].brightness = brightness;
    glimmers[glimmerCount].speed = speed;
    strcpy(glimmers[glimmerCount].mood, mood);
    glimmerCount++;
    printf("Glimmer %s added!\n", name);
}

void listGlitters() {
    printf("Current Glimmers:\n");
    for (int i = 0; i < glimmerCount; i++) {
        printf("Name: %s, Brightness: %d, Speed: %d, Mood: %s\n", 
               glimmers[i].name, 
               glimmers[i].brightness, 
               glimmers[i].speed, 
               glimmers[i].mood);
    }
}

void updateGlimmer(char* name, int brightness, int speed, char* mood) {
    for (int i = 0; i < glimmerCount; i++) {
        if (strcmp(glimmers[i].name, name) == 0) {
            glimmers[i].brightness = brightness;
            glimmers[i].speed = speed;
            strcpy(glimmers[i].mood, mood);
            printf("Glimmer %s updated!\n", name);
            return;
        }
    }
    printf("Glimmer %s not found!\n", name);
}

void parseCommand(char* command) {
    char action[20], name[20], mood[20];
    int brightness, speed;
    
    if (sscanf(command, "add %s %d %d %s", name, &brightness, &speed, mood) == 4) {
        addGlimmer(name, brightness, speed, mood);
    } else if (sscanf(command, "list") == 0) {
        listGlitters();
    } else if (sscanf(command, "update %s %d %d %s", name, &brightness, &speed, mood) == 4) {
        updateGlimmer(name, brightness, speed, mood);
    } else {
        printf("Unknown command: %s\n", command);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    printf("Welcome to the Glimmer Command Parser!\n");
    printf("Available commands: add, list, update, exit\n");

    while (1) {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0;  // Remove newline character

        if (strcmp(command, "exit") == 0) {
            printf("Exiting the parser. Goodbye!\n");
            break;
        }

        parseCommand(command);
    }

    return 0;
}