//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct definition for a crew member
typedef struct CrewMember {
    char name[50];
    int id;
    float experience; // Years of space travel experience
    struct CrewMember* next; // Pointer to the next crew member
} CrewMember;

// Function prototypes
CrewMember* createCrewMember(const char* name, int id, float experience);
void addCrewMember(CrewMember** head, const char* name, int id, float experience);
void displayCrewMembers(CrewMember* head);
void deleteCrewMembers(CrewMember** head);
void allocateFleet(CrewMember** head, int numCrewMembers);

int main() {
    int numCrewMembers;
    CrewMember* fleet = NULL;

    // Welcome to the Galactic Fleet Management System
    printf("Welcome to the Galactic Fleet Management System\n");
    printf("Enter the number of crew members you'd like to allocate: ");
    scanf("%d", &numCrewMembers);
    
    // Allocate memory for crew members
    allocateFleet(&fleet, numCrewMembers);
    
    // Display the crew members
    printf("\nCurrently allocated crew members in the fleet:\n");
    displayCrewMembers(fleet);
    
    // Deallocate memory for the crew members
    deleteCrewMembers(&fleet);
    
    return 0;
}

// Function to create a new crew member
CrewMember* createCrewMember(const char* name, int id, float experience) {
    CrewMember* newCrewMember = (CrewMember*)malloc(sizeof(CrewMember));
    if (newCrewMember == NULL) {
        fprintf(stderr, "Memory allocation failed for crew member.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newCrewMember->name, name, sizeof(newCrewMember->name));
    newCrewMember->id = id;
    newCrewMember->experience = experience;
    newCrewMember->next = NULL;
    return newCrewMember;
}

// Function to add a new crew member to the list
void addCrewMember(CrewMember** head, const char* name, int id, float experience) {
    CrewMember* newCrewMember = createCrewMember(name, id, experience);
    newCrewMember->next = *head;
    *head = newCrewMember;
}

// Function to display the crew members
void displayCrewMembers(CrewMember* head) {
    CrewMember* current = head;
    while (current != NULL) {
        printf("Crew Member ID: %d, Name: %s, Experience: %.2f years\n", 
                current->id, current->name, current->experience);
        current = current->next;
    }
}

// Function to free the allocated memory for crew members
void deleteCrewMembers(CrewMember** head) {
    CrewMember* current = *head;
    CrewMember* nextMember;
    
    while (current != NULL) {
        nextMember = current->next;
        free(current);
        current = nextMember;
    }
    
    *head = NULL; // Set head to NULL after all members are deleted
}

// Function to allocate multiple crew members
void allocateFleet(CrewMember** head, int numCrewMembers) {
    for (int i = 0; i < numCrewMembers; i++) {
        char name[50];
        int id = i + 1; // Assign a unique ID to each member
        float experience;

        printf("Enter name for crew member %d: ", id);
        scanf("%s", name);
        
        printf("Enter years of experience for %s: ", name);
        scanf("%f", &experience);
        
        addCrewMember(head, name, id, experience);
    }
}