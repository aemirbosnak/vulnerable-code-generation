//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold user data in the cyberpunk world
struct User {
    char name[50];
    int age;
    char cyberID[50];
    float dataScore; // Score based on the data mining analysis
};

// Function to calculate the data score based on user activity
float calculateDataScore(int age, const char *cyberID) {
    float score = 0;
    // Just a simple example: score based on age and length of cyberID
    score += (age * 0.2);
    score += (strlen(cyberID) * 0.5);
    return score;
}

// Function to load user data from a file
int loadUserData(const char *filename, struct User **users) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    int count = 0;
    while (!feof(file)) {
        struct User user;
        if (fscanf(file, "%49s %d %49s", user.name, &user.age, user.cyberID) == 3) {
            user.dataScore = calculateDataScore(user.age, user.cyberID);
            users[count] = (struct User *)malloc(sizeof(struct User));
            memcpy(users[count], &user, sizeof(struct User));
            count++;
        }
    }
    fclose(file);
    return count; // Return the number of users loaded
}

// Function to display user data
void displayUserData(struct User **users, int count) {
    printf("=== Cyberpunk Data Mining Report ===\n");
    printf("Name                Age   CyberID                Data Score\n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-5d %-20s %.2f\n", users[i]->name, users[i]->age, users[i]->cyberID, users[i]->dataScore);
    }
    printf("==============================================================\n");
}

// Free dynamically allocated user data
void freeUserData(struct User **users, int count) {
    for (int i = 0; i < count; i++) {
        free(users[i]);
    }
}

int main() {
    struct User *users[100];
    int userCount;

    // Load user data from the "users.txt" file
    userCount = loadUserData("users.txt", users);
    if (userCount == -1) {
        return EXIT_FAILURE; // Exit if there's an error
    }

    // Display the mined data
    displayUserData(users, userCount);

    // Free allocated memory
    freeUserData(users, userCount);

    return EXIT_SUCCESS;
}