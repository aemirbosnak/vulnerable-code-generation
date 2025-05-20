//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold our friendly user data
typedef struct {
    int id;
    char name[50];
    char email[50];
} User;

// Function prototypes
void add_user(User users[], int *count);
void display_users(User users[], int count);
void save_to_file(User users[], int count);
void load_from_file(User users[], int *count);

// Constants
#define MAX_USERS 100
#define DATA_FILE "users.dat"

// Main function
int main() {
    User users[MAX_USERS];
    int count = 0;
    int choice;

    // Load data from file if it exists
    load_from_file(users, &count);

    while (1) {
        // Cheerful menu display
        printf("\n🎉 Welcome to the Cheerful User Database! 🎉\n");
        printf("1. Add a New User\n");
        printf("2. Display All Users\n");
        printf("3. Save Users to File\n");
        printf("4. Load Users from File\n");
        printf("5. Exit\n");
        printf("Please choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user(users, &count);
                break;
            case 2:
                display_users(users, count);
                break;
            case 3:
                save_to_file(users, count);
                break;
            case 4:
                load_from_file(users, &count);
                break;
            case 5:
                printf("🎈 Thank you for using the Cheerful User Database! Goodbye! 🎈\n");
                exit(0);
            default:
                printf("✨ Oops! Please choose a valid option. ✨\n");
        }
    }

    return 0;
}

// Function to add a user
void add_user(User users[], int *count) {
    if (*count >= MAX_USERS) {
        printf("😢 User limit reached! Cannot add more users.\n");
        return;
    }
    User new_user;
    new_user.id = *count + 1; // Simple ID assignment
    printf("Enter Name: ");
    scanf("%s", new_user.name);
    printf("Enter Email: ");
    scanf("%s", new_user.email);
    users[(*count)++] = new_user; // Store and increment count
    printf("🎉 User %s added successfully! 🎉\n", new_user.name);
}

// Function to display all users
void display_users(User users[], int count) {
    if (count == 0) {
        printf("😢 No users found! Add some users first.\n");
        return;
    }
    
    printf("\n🌟 List of Users 🌟\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", users[i].id, users[i].name, users[i].email);
    }
}

// Function to save users to a file
void save_to_file(User users[], int count) {
    FILE *file = fopen(DATA_FILE, "wb");
    if (!file) {
        printf("😢 Failed to open file for writing! 🎈\n");
        return;
    }
    fwrite(users, sizeof(User), count, file);
    fclose(file);
    printf("🎉 User data saved to file! 🎉\n");
}

// Function to load users from file
void load_from_file(User users[], int *count) {
    FILE *file = fopen(DATA_FILE, "rb");
    if (!file) {
        printf("🙁 No data file found to load! Starting fresh.\n");
        return;
    }
    *count = fread(users, sizeof(User), MAX_USERS, file);
    fclose(file);
    printf("🎉 User data loaded from file! 🎉\n");
}