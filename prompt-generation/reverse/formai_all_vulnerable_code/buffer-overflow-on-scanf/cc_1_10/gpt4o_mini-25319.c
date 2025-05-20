//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100 // Maximum number of email subscribers

// Structure to hold subscriber information
typedef struct {
    char email[100];
} Member;

// Global array to hold list of subscribers
Member members[MAX_MEMBERS];
int member_count = 0;

// Function prototypes
void add_member();
void remove_member();
void display_members();
void save_members_to_file();
void load_members_from_file();

int main() {
    load_members_from_file(); // Load members from a file if it exists

    int choice;
    do {
        printf("\n--- Mailing List Manager ---\n");
        printf("1. Add a Member\n");
        printf("2. Remove a Member\n");
        printf("3. Display Members\n");
        printf("4. Save Members\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_member();
                break;
            case 2:
                remove_member();
                break;
            case 3:
                display_members();
                break;
            case 4:
                save_members_to_file();
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

// Function to add a new member to the mailing list
void add_member() {
    if (member_count >= MAX_MEMBERS) {
        printf("Error: Maximum member limit reached!\n");
        return;
    }
    
    printf("Enter the email address to add: ");
    scanf("%s", members[member_count].email);
    member_count++;
    printf("Member added successfully.\n");
}

// Function to remove a member from the mailing list
void remove_member() {
    char email[100];
    printf("Enter the email address to remove: ");
    scanf("%s", email);
    
    for (int i = 0; i < member_count; i++) {
        if (strcmp(members[i].email, email) == 0) {
            // Shift remaining members to fill the gap
            for (int j = i; j < member_count - 1; j++) {
                members[j] = members[j + 1];
            }
            member_count--;
            printf("Member removed successfully.\n");
            return;
        }
    }
    printf("Error: Member with email %s not found!\n", email);
}

// Function to display all the members in the mailing list
void display_members() {
    printf("\n--- Mailing List Members ---\n");
    if (member_count == 0) {
        printf("No members in the mailing list.\n");
    } else {
        for (int i = 0; i < member_count; i++) {
            printf("%d. %s\n", i + 1, members[i].email);
        }
    }
}

// Function to save the current members to a file
void save_members_to_file() {
    FILE *file = fopen("members.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for (int i = 0; i < member_count; i++) {
        fprintf(file, "%s\n", members[i].email);
    }
    
    fclose(file);
    printf("Members saved to file successfully.\n");
}

// Function to load members from a file
void load_members_from_file() {
    FILE *file = fopen("members.txt", "r");
    if (file == NULL) {
        printf("No existing members file found. Starting fresh.\n");
        return;
    }
    
    while (fgets(members[member_count].email, sizeof(members[member_count].email), file)) {
        // Remove newline character from email
        members[member_count].email[strcspn(members[member_count].email, "\n")] = '\0';
        member_count++;
        if (member_count >= MAX_MEMBERS) {
            printf("Warning: Maximum member limit reached while loading!\n");
            break;
        }
    }
    
    fclose(file);
    printf("Members loaded from file successfully.\n");
}