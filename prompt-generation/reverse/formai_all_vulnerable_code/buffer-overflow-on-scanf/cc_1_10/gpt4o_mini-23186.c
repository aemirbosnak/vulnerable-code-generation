//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_welcome() {
    printf("🌟🌈 Welcome to the Cheerful System Administration Tool! 🌈🌟\n");
    printf("✨ Let's make your server a happier place! ✨\n\n");
}

void create_user() {
    char username[100];
    printf("🎉 Let's create a shiny new user! 🎉\n");
    printf("Please enter the username you want to create: ");
    scanf("%s", username);
    
    // Use 'system' to add user in Linux
    char command[150];
    sprintf(command, "sudo adduser %s", username);
    
    printf("🌟 Creating user %s... Hold on a moment! 🌟\n", username);
    int result = system(command);
    
    if (result == 0) {
        printf("🎊 Wow! User %s has been created successfully! 🎊\n", username);
    } else {
        printf("🚨 Oops! Something went wrong while creating user %s... 🚨\n", username);
    }
}

void delete_user() {
    char username[100];
    printf("🚀 Ready to delete a user? 🚀\n");
    printf("Please enter the username you want to delete: ");
    scanf("%s", username);
    
    // Use 'system' to remove user in Linux
    char command[150];
    sprintf(command, "sudo deluser %s", username);
    
    printf("🌈 Deleting user %s... Almost done! 🌈\n", username);
    int result = system(command);
    
    if (result == 0) {
        printf("✨ Hooray! User %s has been deleted successfully! ✨\n", username);
    } else {
        printf("🛑 Oh no! I couldn't find user %s to delete! 🛑\n", username);
    }
}

void list_users() {
    printf("📜 Let's see who our happy users are! 📜\n");
    int result = system("cut -d: -f1 /etc/passwd");
    
    if (result == 0) {
        printf("🌟 Here they are! 🌟\n");
    } else {
        printf("🚫 Uh-oh! I couldn't list the users. 🚫\n");
    }
}

int main() {
    int choice;

    print_welcome();

    do {
        printf("\n🎈 Choose an action: 🎈\n");
        printf("1. Create a user\n");
        printf("2. Delete a user\n");
        printf("3. List all users\n");
        printf("4. Exit the program\n");
        printf("Please enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create_user();
                break;
            case 2:
                delete_user();
                break;
            case 3:
                list_users();
                break;
            case 4:
                printf("👋 Thank you for using the Cheerful System Administration Tool! Goodbye! 👋\n");
                break;
            default:
                printf("❓ That's not a valid choice. Please try again! ❓\n");
                break;
        }
    } while (choice != 4);

    return 0;
}