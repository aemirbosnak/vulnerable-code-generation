//FormAI DATASET v1.0 Category: Mailing list manager ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#define MAX_MEMBER 1000
#define EMAIL_LENGTH 50

// Structure for a Member
typedef struct member {
    char name[50];           // Member's name
    char email[EMAIL_LENGTH]; // Member's email ID
} Member;

// Function to display the menu
void displayMenu() {
    printf("\n***************************************");
    printf("\n Welcome to Mailing List Manager");
    printf("\n***************************************");
    printf("\n 1. Add Member");
    printf("\n 2. Remove Member");
    printf("\n 3. Display All Members");
    printf("\n 4. Exit");
    printf("\n***************************************\n");
}

// Function to add a member
void addMember(Member members[], int *numMembers) {
    if (*numMembers == MAX_MEMBER) {
        printf("The mailing list has reached its maximum capacity!");
        return;
    }
    printf("Enter member name: ");
    scanf("%s", members[*numMembers].name);
    printf("Enter member email: ");
    scanf("%s", members[*numMembers].email);
    printf("Member has been added successfully!\n");
    *numMembers += 1;
}

// Function to remove a member
void removeMember(Member members[], int *numMembers) {
    char emailToRemove[EMAIL_LENGTH];
    int i, j;

    printf("Enter the member's email to be removed: ");
    scanf("%s", emailToRemove);

    // Loop through the members and remove the member with matching email
    for (i = 0; i < *numMembers; i++) {
        if (strcmp(members[i].email, emailToRemove) == 0) {
            printf("Removing member %s with email %s\n", members[i].name, members[i].email);
            // Shift all the elements to the left to fill the space
            for (j = i; j < *numMembers-1; j++) {
                members[j] = members[j+1];
            }
            *numMembers -= 1; // Reduce the number of members
            printf("Member has been removed successfully!\n");
            return;
        }
    }
    printf("No member found with this email.\n");
}

// Function to display all the members
void displayAllMembers(Member members[], int numMembers) {
    int i;
    printf("\n*******************\n");
    printf("List of Members\n");
    printf("*******************\n");
    for (i = 0; i < numMembers; i++) {
        printf("%s\t%s\n", members[i].name, members[i].email);
    }
    printf("Total number of members: %d\n", numMembers);
}

// Main function
int main() {
    int choice;
    Member members[MAX_MEMBER];
    int numMembers = 0;
    do {
        // Display the menu
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMember(members, &numMembers);
                break;
            case 2:
                removeMember(members, &numMembers);
                break;
            case 3:
                displayAllMembers(members, numMembers);
                break;
            case 4:
                printf("Exiting Mailing List Manager\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.");
        }
    } while (choice !=4);

    return 0;
}