//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROBOTS 100
#define MAX_ROBOT_NAME_LENGTH 20
#define MAX_ROBOT_AGE 1000

// Function to generate a random robot name
char* generateRobotName() {
    char* name = (char*) malloc(MAX_ROBOT_NAME_LENGTH * sizeof(char));
    for (int i = 0; i < MAX_ROBOT_NAME_LENGTH; i++) {
        name[i] = 'A' + rand() % 26;
    }
    name[MAX_ROBOT_NAME_LENGTH - 1] = '\0';
    return name;
}

// Function to generate a random robot age
int generateRobotAge() {
    return rand() % MAX_ROBOT_AGE;
}

// Function to print a robot's information
void printRobotInfo(char* name, int age) {
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
}

// Main function
int main() {
    srand(time(NULL));

    // Initialize an array of robots
    char* robotNames[MAX_ROBOTS];
    int robotAges[MAX_ROBOTS];

    // Generate random names and ages for each robot
    for (int i = 0; i < MAX_ROBOTS; i++) {
        robotNames[i] = generateRobotName();
        robotAges[i] = generateRobotAge();
    }

    // Print information for each robot
    for (int i = 0; i < MAX_ROBOTS; i++) {
        printf("Robot %d:\n", i + 1);
        printRobotInfo(robotNames[i], robotAges[i]);
    }

    return 0;
}