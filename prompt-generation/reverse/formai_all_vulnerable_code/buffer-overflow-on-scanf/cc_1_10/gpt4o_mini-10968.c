//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROFILES 100
#define MAX_NAME_LENGTH 50
#define MAX_HACKER_TAG_LENGTH 20
#define MAX_MOTIVATION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char hackerTag[MAX_HACKER_TAG_LENGTH];
    char motivation[MAX_MOTIVATION_LENGTH];
} CyberProfile;

CyberProfile database[MAX_PROFILES];
int profileCount = 0;

void addProfile();
void searchProfile();
void displayProfiles();
void clearInputBuffer();

int main() {
    int choice;
    
    printf("=== Cyberpunk Database Console ===\n");
    printf("Welcome, Agent. What will you do?\n");

    do {
        printf("\n1. Add Profile\n");
        printf("2. Search Profile\n");
        printf("3. Display All Profiles\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addProfile();
                break;
            case 2:
                searchProfile();
                break;
            case 3:
                displayProfiles();
                break;
            case 4:
                printf("Logging off... Stay safe out there.\n");
                break;
            default:
                printf("Invalid choice. Try again, netrunner.\n");
        }
    } while (choice != 4);

    return 0;
}

void addProfile() {
    if (profileCount >= MAX_PROFILES) {
        printf("Database full! Cannot add more profiles.\n");
        return;
    }

    CyberProfile newProfile;

    printf("Enter name: ");
    fgets(newProfile.name, MAX_NAME_LENGTH, stdin);
    newProfile.name[strcspn(newProfile.name, "\n")] = 0; // Remove newline

    printf("Enter hacker tag: ");
    fgets(newProfile.hackerTag, MAX_HACKER_TAG_LENGTH, stdin);
    newProfile.hackerTag[strcspn(newProfile.hackerTag, "\n")] = 0; // Remove newline

    printf("Enter motivation: ");
    fgets(newProfile.motivation, MAX_MOTIVATION_LENGTH, stdin);
    newProfile.motivation[strcspn(newProfile.motivation, "\n")] = 0; // Remove newline

    database[profileCount++] = newProfile;
    printf("Profile added to the database. Welcome, [%s] aka [%s]\n", newProfile.name, newProfile.hackerTag);
}

void searchProfile() {
    char tag[MAX_HACKER_TAG_LENGTH];
    printf("Enter hacker tag to search: ");
    fgets(tag, MAX_HACKER_TAG_LENGTH, stdin);
    tag[strcspn(tag, "\n")] = 0; // Remove newline

    for (int i = 0; i < profileCount; i++) {
        if (strcmp(database[i].hackerTag, tag) == 0) {
            printf("Profile found!\n");
            printf("Name: %s\n", database[i].name);
            printf("Hacker Tag: %s\n", database[i].hackerTag);
            printf("Motivation: %s\n", database[i].motivation);
            return;
        }
    }
    printf("No profile found with hacker tag [%s]. Maybe they're hiding in the shadows.\n", tag);
}

void displayProfiles() {
    if (profileCount == 0) {
        printf("No profiles in the database. It’s a quiet night in the grid...\n");
        return;
    }

    printf("\n=== All Cyber Profiles ===\n");
    for (int i = 0; i < profileCount; i++) {
        printf("Profile %d:\n", i + 1);
        printf("Name: %s\n", database[i].name);
        printf("Hacker Tag: %s\n", database[i].hackerTag);
        printf("Motivation: %s\n", database[i].motivation);
        printf("------------------\n");
    }
}

void clearInputBuffer() {
    while (getchar() != '\n');
}